#include <stdio.h>
#include <stdlib.h>

typedef struct banco{

    char nome[10];
    int conta;
    float saldo;

}banco;

void aloca(banco **p, int q);
void cadastro(banco *p);
void deposito(banco *p, int opcao);
int busca(banco *p, int q);
void mostra(banco *p, int q);

int main(){

    banco *ptr = NULL;
    int qtd = 0, op = 0, pos = 0;

    printf("Selecione a sua opcao");


    do{

        printf("\n[1] - Cadastro\n[2] - Deposito\n[3] - Retirada\n[4] - Mostrar Contas\n[5] - Sair\n");
        scanf("%i", &op);
        fflush(stdin);
        switch(op){
            case 1:
                aloca(&ptr,qtd+1);
                cadastro(ptr+qtd);
                qtd++;
                break;
            case 2:
            case 3:
                pos = busca(ptr,qtd);
                if(pos != -1){
                deposito(ptr+pos, op);}
                else{
                    printf("\nNumero de conta inexsistente.");
                }
                break;
            case 4:
                    mostra(ptr, qtd);
            case 5:
                    printf("\nSaindo do banco...");
                    break;
            default:
                printf("\nOPCAO INVALIDA");

        }

        printf("\n\n");
        system("pause");
        system("cls");
    }
    while(op != 5);
    

    return 0;
}

void aloca(banco **p, int q){

  if((*p =  (banco *)realloc(*p,q*sizeof(banco))) == NULL){
    printf("\nErro na alocacao");
    exit(1);
  }

}

void cadastro(banco *p){
    static int numero = 1000;
    
    printf("\nDigite o seu nome: ");
    gets(p->nome);
    fflush(stdin);
    
    p->conta = numero;
    numero +=100;
    
    p->saldo = 0;
    
    
    printf("\nPrazer em te conhecer %s!\nO numero de sua conta \x82 %i", p->nome, p->conta);
}

void deposito(banco *p, int opcao){

    float val;

    printf("\nO saldo atual \x82 de: %.2f", p->saldo);
    
    if(opcao == 2){
        printf("\nInsira o valor que deseja depositar: ");
        scanf("%f", &val);
        
        p->saldo += val;
        
        printf("\nO novo saldo \x82 de %.2f", p->saldo);
    }
    
    
    else{
        
        printf("\nInsira o valor que deseja retirar: ");
    scanf("%f", &val);

    p->saldo -= val;

    printf("\nO novo saldo \x82 de %.2f", p->saldo);
}

    }

int busca(banco *p, int q){

    int aux;
    printf("Digite o numero de sua conta: ");
    scanf("%i", &aux);
    fflush(stdin);
    for(int i = 0; i<q; i++){
        if(aux == (p+i)->conta){
            return i;
        }
    }
    return -1;

}

void mostra(banco *p, int q){

    for(int i = 0; i<q; i++){
        printf("\nConta %i\nNome: %s\nsaldo %.2f\n\n", (p+i)->conta, (p+i)->nome, (p+i)->saldo);
    }
        system("pause");

}



