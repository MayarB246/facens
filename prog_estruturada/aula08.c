#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente{
    char nome[30];
    int conta;
    float saldo;
};

void aloca(struct cliente **p, int x);
void cadastro(struct cliente *p);
int busca(struct cliente *p, int tam);
void movimenta(struct cliente *p, int num);
void mostra(struct cliente *p, int tam);

int main(){
    struct cliente *pcli=NULL;
    int cont = 0, op, pos=0;

    do{
        system("cls");
        printf("Menu:\n\n[1]: Cadastro\n[2]: Deposito\n[3]: Retirada\n[4]: Listar\n[5]: Sair\n");
        scanf("%i", &op);
        fflush(stdin);

        switch (op){
            case 1:
                if(cont<10){
                    aloca(&pcli, cont+1);
                    cadastro(pcli+cont);
                    cont++;
                }
                else{
                    printf("\n##CADASTRO CHEIO##\n");
                }
                break;

            case 2:
            case 3:
                pos=busca(pcli,cont);
                if(pos==-1){
                    printf("\nCONTA NAO ENCONTRADA!\n");
                }
                else{
                    movimenta((pcli+pos), op);
                }
                break;

            case 4:
                mostra(pcli, cont);
                break;

            case 5:
                printf("\n## FINALIZANDO O PROGRAMA ##\n");
                break;

            default:
            printf("\nEscolha uma opcao valida!!!");
                break;
            }
            system("pause");
        }while(op!=5);


    return 0;
}

void aloca(struct cliente **p, int x){
    if((*p=(struct cliente*)realloc(*p, x*sizeof(struct cliente)))==NULL){
        printf("##ERRO NA ALOCACAO##");
        exit(1);
    }
}

void cadastro(struct cliente *p){
    static int n=1000;
    printf("Nome: ");
    gets(p->nome);
    fflush(stdin);
    p->conta = n;
    n+=100;
    p->saldo=0;
    printf("\nCadastro efetuado com sucesso - conta: %i\n", p->conta);
}

int busca(struct cliente *p, int tam){
    int aux_conta;
    printf("Digite a conta: ");
    scanf("%i", &aux_conta);
    fflush(stdin);
    for(int i=0;i<tam;i++){
        printf("%i\n", (p+i)->conta);
        if(aux_conta == (p+i)->conta){
            return i;
        }
    }
    return -1;
}

void movimenta(struct cliente *p, int num){
    float aux;
    printf("Nome: %s - Saldo: %.2f\n", p->nome, p->saldo);
    printf("Valor a ser depositado/retirado: ");
    scanf("%f", &aux);
    fflush(stdin);
    if(num==2)
        p->saldo+=aux;
    else
        if(p->saldo >= aux){
            p->saldo-=aux;
        }
        else{
            printf("\nSaldo insuficiente!\n");
        }
}

void mostra(struct cliente *p, int tam){
    for(int i=0;i<tam;i++, p++){
        printf("\nNome : %s - Saldo : %.2f - Conta : %i", p->nome, p->saldo, p->conta);
    }
    printf("\n");
}