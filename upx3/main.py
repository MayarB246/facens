from fastapi import FastAPI
from pydantic import BaseModel
from typing import List

app = FastAPI()

# Lista que funcionará como nosso "banco de dados" temporário
historico_dados = []

class DadosChuveiro(BaseModel):
    tempo_ligado_s: int
    litros_total: float
    energia_kwh: float
    custo_rs: float

@app.post("/receber-dados")
async def receber_dados(dados: DadosChuveiro):
    global historico_dados
    
    # Adiciona o novo dado no final da lista
    historico_dados.append(dados.dict())
    
    # Se a lista tiver mais de 50 itens, remove o primeiro (o mais antigo)
    if len(historico_dados) > 50:
        historico_dados.pop(0)
    
    print(f"📥 Dados recebidos! Total no histórico: {len(historico_dados)}")
    return {"status": "sucesso"}

@app.get("/")
async def mostrar_historico():
    # Agora, ao acessar a raiz, você vê a lista com os últimos 50 dados
    return historico_dados