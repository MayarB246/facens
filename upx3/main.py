from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel
from typing import List

app = FastAPI()

# Permite que o seu arquivo index.html converse com o servidor
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

# A nossa lista na MEMÓRIA RAM (O novo "banco de dados")
historico_dados = []

class DadosChuveiro(BaseModel):
    tempo_ligado_s: int
    litros_total: float
    energia_kwh: float
    custo_rs: float

@app.post("/receber-dados")
async def receber_dados(dados: DadosChuveiro):
    global historico_dados
    
    # model_dump substitui o antigo .dict()
    historico_dados.append(dados.model_dump())
    
    if len(historico_dados) > 50:
        historico_dados.pop(0)
    
    # ESTE é o comando que faz o texto aparecer no terminal
    print(f"📥 Dados recebidos! Total no histórico: {len(historico_dados)}")
    return {"status": "sucesso"}

@app.get("/")
async def mostrar_historico():
    # O [::-1] inverte a lista: o dado mais recente aparece no TOPO
    return historico_dados[::-1]