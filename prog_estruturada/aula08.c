#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente{
    char nome[30];
    int conta;
    float saldo;
};

void cadastro(struct cliente *p);
int busca(struct cliente *p, int tam);
void movimenta(struct cliente *p);

int main(){
    struct cliente cli[10], *pcli;
    int cont = 0, op, pos;
    pcli = cli;

    do{
        system("cls");
        printf("Menu:\n\n[1]: Cadastro\n[2]: Deposito\n[3]: Retirada\n[4]: Sair\n");
        scanf("%i", &op);
        fflush(stdin);

        switch (op){
            case 1:
                if(cont<10){
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
                    printf("\nCONTA NAO ENCONTRADA\n");
                }
                else{
                    movimenta(pcli+pos);
                }
                break;

            case 4:
                printf("\n## FINALIZANDO O PROGRAMA ##\n");
                break;

            default:
            printf("\nEscolha uma opcao valida!!!");
                break;
            }
            system("pause");
        }while(op!=4);


    return 0;
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
    for(int i=0;i<tam;i++,p++){
        if(aux_conta == p->conta){
            return i;
        }
    }
    return -1;
}

void movimenta(struct cliente *p){
    float aux;
    printf("Nome: %s\nSaldo: %.2f", p->nome, p->saldo);
    printf("Valor a ser depositado: ");
    scanf("%f", &aux);
    fflush(stdin);
    p->saldo+=aux;
}