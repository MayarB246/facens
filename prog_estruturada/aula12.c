#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct{
    char status, tipo;
    int reg_carro;
} carro;

typedef struct{
    char CPF[13], nome[20];
    int num_reg, dias;
} cliente;

void alocac(carro **p, int tam);
void cadastrac(carro *p, int tam);
void alocacli(cliente **p, int tam);
void cadastracli(cliente *p, carro *pcar, int qcar);
void mostrac(carro *p, int tam);
void mostracli(cliente *p, int tam);
int buscacar(carro *pcar, int qcar, char tipo);
int buscacpf(cliente *p, int qcli, char *cpf);
void devolucao(cliente *p, carro *pcar, int qcli);

int main(){
    cliente *pcli=NULL;
    carro *pcar=NULL;
    int cont=0, op=0;

    alocac(&pcar,15);
    cadastrac(pcar, 15);
    do{
        printf("[1] Cadastro\n[2] Devolucao\n[3] Mostrar Clientes\n[4] Sair\n[5] Mostrar Carros\n");
        scanf("%i", &op);
        fflush(stdin);
        switch(op){
            case 1:
                alocacli(&pcli, cont+1);
                cadastracli(pcli+cont, pcar, 15);
                cont++;
                break;
            case 2:
                devolucao(pcli, pcar, cont);
                break;

            case 3:
                mostracli(pcli, cont);
                break;

            case 4:
                printf("Saindo...\n");
                break;

            case 5:
                mostrac(pcar, 15);
                break;

            default:
            break;
        }
        system("cls");
    }while(op!=4);

    return 0;
}

void alocac(carro **p, int tam){
    if((*p=(carro*)realloc(*p,tam*sizeof(carro)))==NULL){
        exit(1);
        printf("Problema na realocacao\n");
    }
}

void alocacli(cliente **p, int tam){
    if((*p=(cliente*)realloc(*p,tam*sizeof(cliente)))==NULL){
        exit(1);
        printf("Problema na realocacao\n");
    }
}

void cadastrac(carro *p, int tam){
    for(int i=0;i<tam;i++,p++){
        p->reg_carro=i+1;
        p->status='L';
        if(i<5)
            p->tipo='P';
        else if(i<10)
            p->tipo='M';
        else
            p->tipo='G';
    }
}

void mostrac(carro *p, int tam){
    printf("Listando os carros...\n\n");
    for(int i=0;i<tam;i++, p++){
        printf("Numero de Registro: %i\nTipo: %c\nStatus: %c\n\n", p->reg_carro, p->tipo, p->status);
    }
    system("pause");
}

void cadastracli(cliente *p, carro *pcar, int qcar){
    char tipo;
    printf("Digite seu CPF: ");
    gets(p->CPF);
    fflush(stdin);
    printf("Digite seu nome: ");
    gets(p->nome);
    fflush(stdin);
    printf("Escolha o tipo de carro: [P - M - G] ");
    scanf("%c", &tipo);
    fflush(stdin);
    tipo=toupper(tipo);
    p->num_reg=buscacar(pcar, qcar, tipo);
        if(p->num_reg==-1){
            printf("Nenhum carro encontrado!\n");
        }
        else{
            printf("Quantos dias: ");
            scanf("%i", &p->dias);
            fflush(stdin);
            printf("Carro %i alugado com sucesso!\n", p->num_reg);
        }
    system("pause");
}

int buscacar(carro *pcar, int qcar, char tipo){
    for(int i=0;i<qcar;i++, pcar++){
        if(pcar->tipo==tipo && pcar->status=='L'){
            pcar->status='O';
            return i;
        }
    }
    return -1;
}

void devolucao(cliente *p, carro *pcar, int qcli){
    char cpf[13];
    int pos;
    float valor;

    printf("CPF: ");
    gets(cpf);
    fflush(stdin);

    pos=buscacpf(p, qcli, cpf);
    if(pos==-1)
        printf("CPF invalido!\n");
    else{
        switch((pcar+((p+pos)->num_reg-1))->tipo){
            case 'P':
                valor = 150;
                break;
            case 'M':
                valor = 200;
                break;
            case 'G':
                valor = 250;
                break;
        }
        valor = valor*p->dias;
        printf("Nome: %s\nRegistro do carro: %i\nTipo do carro: %c\nTotal de dias alugado: %i\nPreco total: %.2f\n", (p+pos)->nome, (p+pos)->num_reg, (pcar+((p+pos)->num_reg-1))->tipo, p->dias, valor);

        (pcar+((p+pos)->num_reg-1))->status='L';
    }
    system("pause");
}

int buscacpf(cliente *p, int qcli, char *cpf){
    for(int i=0;i<qcli;i++, p++){
        if(strcmp(p->CPF, cpf)==0)
            return i;
    }
    return -1;
}

void mostracli(cliente *p, int tam){
    printf("Listando os clientes:\n\n");
    for(int i=0;i<tam;i++,p++){
        printf("Nome: %s\nCPF: %s\nRegistro Carro: %i\nDias: %i\n\n", p->nome, p->CPF, p->num_reg,p->dias);
    }
    system("pause");
}