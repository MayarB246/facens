#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h> 
#include <EEPROM.h>

// ================= CONFIGURAÇÕES DE REDE =================
const char* ssid = "S24";
const char* password = "fazaprova";

// Substitua pelo IP local do computador rodando o FastAPI
const char* serverUrl = "http://10.24.151.130:8000/receber-dados"; 

// ================= CONFIGURAÇÕES DO CHUVEIRO =============
#define PINO_SENSOR 2
#define PULSOS_POR_LITRO 450.0

#define POTENCIA_CHUVEIRO_W 5500.0
#define CUSTO_KWH 0.90

// ================= VARIÁVEIS GLOBAIS =====================
volatile unsigned long pulsos = 0;

unsigned long tempoLigadoSeg = 0;
unsigned long ultimoPulsoMillis = 0;
float litrosTotal = 0;

// Controle de tempo
unsigned long ultimoSalvamento = 0;
const unsigned long intervaloSalvamento = 10000; // Salva na EEPROM a cada 10s

unsigned long ultimoEnvioAPI = 0;
const unsigned long intervaloEnvioAPI = 5000; // Envia para o FastAPI a cada 5s

// ================= INTERRUPÇÃO ===========================
// Obrigatório usar IRAM_ATTR no ESP32 para funções de interrupção
void IRAM_ATTR contarPulso() {
  pulsos++;
}

// ================= EEPROM ================================
void salvarDados() {
  EEPROM.put(0, tempoLigadoSeg);
  EEPROM.put(10, litrosTotal);
  EEPROM.commit(); // OBRIGATÓRIO NO ESP32 para gravar na flash
  Serial.println("Dados salvos na EEPROM.");
}

void carregarDados() {
  EEPROM.get(0, tempoLigadoSeg);
  EEPROM.get(10, litrosTotal);

  // Proteção contra lixo de memória
  if (isnan(tempoLigadoSeg) || tempoLigadoSeg > 10000000) tempoLigadoSeg = 0;
  if (isnan(litrosTotal) || litrosTotal > 100000) litrosTotal = 0;
}

// ================= WIFI ==================================
void conectarWiFi() {
  Serial.print("Conectando ao WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Conectado! IP do ESP: " + WiFi.localIP().toString());
}

// ================= ENVIO PARA FASTAPI ====================
void enviarParaFastAPI() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");

    // Prepara os cálculos de energia e custo
    float horas = tempoLigadoSeg / 3600.0;
    float potenciaKW = POTENCIA_CHUVEIRO_W / 1000.0;
    float energiaKWh = potenciaKW * horas;
    float custoRs = energiaKWh * CUSTO_KWH;

    // Monta o JSON para enviar
    StaticJsonDocument<200> doc;
    doc["tempo_ligado_s"] = tempoLigadoSeg;
    doc["litros_total"] = round(litrosTotal * 100) / 100.0;
    doc["energia_kwh"] = energiaKWh;
    doc["custo_rs"] = custoRs;

    String requestBody;
    serializeJson(doc, requestBody);

    // Envia os dados (POST)
    int httpResponseCode = http.POST(requestBody);

    if (httpResponseCode > 0) {
      Serial.print("✅ Enviado p/ API! HTTP Code: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("❌ Erro no POST: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("❌ WiFi desconectado. Tentando reconectar...");
    WiFi.reconnect();
  }
}

// ================= SETUP =================================
void setup() {
  Serial.begin(115200);

  EEPROM.begin(512); // Inicializa EEPROM com 512 bytes no ESP32
  carregarDados();

  conectarWiFi();

  pinMode(PINO_SENSOR, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PINO_SENSOR), contarPulso, FALLING);

  Serial.println("✅ Sistema do Chuveiro Iniciado");
}

// ================= LOOP ==================================
void loop() {
  static unsigned long ultimoCheck = 0;

  if (millis() - ultimoCheck >= 1000) {
    ultimoCheck = millis();

    // Pausa interrupção rapidamente para leitura segura dos pulsos
    unsigned long pulsosAtuais;
    noInterrupts(); 
    pulsosAtuais = pulsos;
    pulsos = 0;
    interrupts();

    if (pulsosAtuais > 0) {
      tempoLigadoSeg++;

      float litrosSegundo = pulsosAtuais / PULSOS_POR_LITRO;
      litrosTotal += litrosSegundo;

      ultimoPulsoMillis = millis();
      mostrarDados();
    }
  }

  // Detecta chuveiro desligado
  if (millis() - ultimoPulsoMillis > 5000 && ultimoPulsoMillis != 0) {
    Serial.println("🚿 Chuveiro desligado.\n");
    ultimoPulsoMillis = 0; 
  }

  // Envia os dados para a API periodicamente
  if (millis() - ultimoEnvioAPI > intervaloEnvioAPI) {
    ultimoEnvioAPI = millis();
    enviarParaFastAPI();
  }

  // Salva periodicamente (evita desgaste da EEPROM)
  if (millis() - ultimoSalvamento > intervaloSalvamento) {
    ultimoSalvamento = millis();
    salvarDados();
  }
}

// ================= EXIBIÇÃO ==============================
void mostrarDados() {
  float horas = tempoLigadoSeg / 3600.0;
  float potenciaKW = POTENCIA_CHUVEIRO_W / 1000.0;
  float energiaKWh = potenciaKW * horas;
  float custo = energiaKWh * CUSTO_KWH;

  Serial.println("===== DADOS DO BANHO =====");
  Serial.print("Tempo ligado (s): "); Serial.println(tempoLigadoSeg);
  Serial.print("Litros usados: "); Serial.println(litrosTotal, 2);
  Serial.print("Energia gasta (kWh): "); Serial.println(energiaKWh, 3);
  Serial.print("Custo (R$): "); Serial.println(custo, 2);
  Serial.println("==========================\n");
}