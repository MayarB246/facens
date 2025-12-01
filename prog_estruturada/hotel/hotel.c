#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct quarto{
    int num;
    char cat, status;
}quarto;
typedef struct hospede{
    int numq, qhos, dias;
    char nome[50], cat;
}hospede;

void alocah(hospede **ph, int qh);
void alocaq(quarto **pq, int qq);
void registraq(quarto *pq);
void cadastrah(quarto *pq, hospede *ph);
void gravah(hospede *ph);
void gravaq(quarto *pq);
int verificaq();
int verificah();
void mostraq(quarto *pq);
void mostrah(hospede *ph);
void buscaq(hospede *ph,  quarto *pq);
void atualizaq(quarto *pq, hospede *ph);
void checkout(quarto *pq, hospede *ph);

int main(){
    quarto *pqua=NULL;
    hospede *phos=NULL;
    int op;

    alocaq(&pqua, 1);
    alocah(&phos, 1);

    registraq(pqua);
    do{
        printf("\nqtd de quartos: %i", verificaq());
        printf("\n[1]-Cadadstrar hospede\n[2]-Saida\n[3]-Sair\n[4]-Mostrar Quartos\n[5]-Mostrar Hospedes\n\n");
        scanf("%i", &op);
        fflush(stdin);
        
        switch (op){
            case 1:
                cadastrah(pqua, phos);
                break;
            case 2:
                checkout(pqua,phos);
                break;
            case 4:
                mostraq(pqua);
                break;
            case 5:
                mostrah(phos);
                break;
            default:
                break;
        }
    }while(op!=3);
        
        return 0;
    }
    
void alocah(hospede **ph, int qh){
    if((*ph = (hospede *) realloc(*ph, qh*sizeof(hospede))) == NULL){
        printf("\nErro na alocacao de hospede");
        exit(1);
    }
}//aloca hospede

void alocaq(quarto **pq, int qq){
    if((*pq = (quarto *) realloc(*pq, qq*sizeof(quarto))) == NULL){
        printf("\nErro na alocacao de quarto");
        exit(1);
    }
}//aloca quarto

void registraq(quarto *pq){
    int val;
    val = verificaq();
    if(val == 0){
        for(int i = 0; i<15; i++){
            pq->num = i+1;
            if(i<5){
                pq->cat = 'S';
            }
            else{
                pq->cat = 'F';
            }
            pq->status = 'L';
            gravaq(pq);
        }
    }
}//registra quarto

int verificaq(){
    FILE *fptr = NULL;
    int x=0;

    if((fptr = fopen("quartos.bin","rb")) != NULL){
        fseek(fptr,0,2);
        x = ftell(fptr)/sizeof(quarto);
        fclose(fptr);
        return x;
    }
    else{
        printf("\nErro na verificacao de quarto");
    }
    return x;
}// verifica quarto

int verificah(){
    FILE *fptr=NULL;
    int x=0;

    if((fptr=fopen("hospedes.bin", "rb"))==NULL){
        printf("\nErro na verificacao de hospede");
    }
    else{
        fseek(fptr, 0, 2);
        x=ftell(fptr)/sizeof(hospede);
        fclose(fptr);
    }
    return x;
}

void gravaq(quarto *pq){
    FILE *fptr = NULL;

    if((fptr = fopen("quartos.bin","ab")) != NULL){
        fwrite(pq,sizeof(quarto),1,fptr);
    }
    else{
        printf("\nErro na gravacao de quarto");
    }
    fclose(fptr);
}

void mostraq(quarto *pq){
    FILE *fptr=NULL;
    int qtd=verificaq();        
    if((fptr=fopen("quartos.bin", "rb"))!=NULL){
        for(int i=0;i<qtd;i++){
            fseek(fptr, i*sizeof(quarto), 0);
            fread(pq, sizeof(quarto), 1, fptr);
            printf("Numero: %i\nStatus: %c\nCategoria: %c\n\n", pq->num, pq->status, pq->cat);
        }
        fclose(fptr);
    }
    else{
        printf("\nErro na mostra quarto");
    }
}

void mostrah(hospede *ph){
    FILE *fptr=NULL;
    int q=verificah();

    if((fptr=fopen("hospedes.bin", "rb"))!=NULL && q != 0){
        for(int i=0;i<q;i++){
            fseek(fptr, i*sizeof(hospede), 0);
            fread(ph, sizeof(hospede), 1, fptr);
            printf("Nome: %s\nQtd de acompanhantes: %i\nCategoria: %c\nNumero do Quarto: %i\nQtd de dias: %i\n\n", ph->nome, ph->qhos, ph->cat, ph->numq, ph->dias);
        }
        fclose(fptr);
    }
    else{
        printf("Erro no mostra hospedes");
    }
}

void cadastrah(quarto *pq, hospede *ph){
    int val;
    printf("Digite o nome do hospede: ");
    gets(ph->nome);
    fflush(stdin);
    do{
        printf("Digite a quantidade de acompanhantes: [entre 0 e 3] ");
        scanf("%i", &ph->qhos);
        fflush(stdin);
    }while(ph->qhos>3 || ph->qhos<0);
    if(ph->qhos==0)
        ph->cat='S';
    else
        ph->cat='F';

    printf("Digite quantidade de Dias: ");
    scanf("%i", &ph->dias);
    fflush(stdin);

    buscaq(ph, pq);
    if(ph->numq==0){
        printf("\nNao foi possivel alocar um quarto. Operacao cancelada");
    }
    else{
        atualizaq(pq, ph);
        gravah(ph);
        printf("\nQuarto %i cadastrado com sucesso!", ph->numq);
    }
}

void buscaq(hospede *ph, quarto *pq){
    FILE *fptr=NULL;
    int qtd=verificaq(), enc=0;

    if((fptr=fopen("quartos.bin", "rb"))!=NULL){
        for(int i=0;i<qtd;i++){
            fseek(fptr,i*sizeof(quarto), 0);
            fread(pq, sizeof(quarto), 1, fptr);

            if(pq->status=='L' && ph->cat==pq->cat){
                ph->numq=pq->num;
                pq->status='O';
                i=qtd;
                enc=1;
            }
        }
        fclose(fptr);
    }
    else{
        printf("\nErro no busca quarto");
    }
    if(enc){
        printf("\nQuarto %i encontrado", ph->numq);
    }
    else{
        printf("\nNenhum quarto disponivel na categoria %c", ph->cat);
        ph->numq=0;
    }
}

void atualizaq(quarto *pq, hospede *ph){
    FILE *fptr=NULL;
    if((fptr=fopen("quartos.bin", "rb+"))!=NULL){
        if(ph->numq<=0){
            printf("\nNumero de quarto invalido para atualizacao");
        }
        else{
            fseek(fptr, (ph->numq-1)*sizeof(quarto),0);
            fwrite(pq, sizeof(quarto), 1, fptr);
            printf("\nquartos.bin atualizado com sucesso");
        }
    }
    fclose(fptr);
}

void gravah(hospede *ph){
    FILE *fptr=NULL;
    if((fptr=fopen("hospedes.bin", "ab"))==NULL){
        printf("\nErro na grava hospede");
    }
    else{
        fwrite(ph, sizeof(hospede), 1, fptr);
    }
    fclose(fptr);
    printf("\nhospede gravado com sucesso");
}

void checkout(quarto *pq, hospede *ph){
    int num;
    FILE *fptr=NULL, *fptr2=NULL;
    int qh = verificah();
    int achei = 0;

    printf("Digite o numero do quarto para checkout: ");
    scanf("%i", &num);
    fflush(stdin);

    fptr = fopen("quartos.bin", "rb+");
    fptr2 = fopen("hospedes.bin", "rb+");

    if(fptr == NULL || fptr2 == NULL){
        printf("\nErro ao abrir arquivos");
        return;
    }

    /* --- PROCURA O HÓSPEDE QUE ESTA NO QUARTO --- */
    for(int i=0;i<qh;i++){
        fseek(fptr2, i*sizeof(hospede), 0);
        fread(ph, sizeof(hospede), 1, fptr2);

        if(ph->numq == num){
            achei = 1;
            ph->numq = 0;   // remove o quarto do hóspede
            fseek(fptr2, i*sizeof(hospede), 0);
            fwrite(ph, sizeof(hospede), 1, fptr2);
            break;
        }
    }

    if(!achei){
        printf("\nNao ha hospede neste quarto!");
        fclose(fptr);
        fclose(fptr2);
        return;
    }

    /* --- ATUALIZA STATUS DO QUARTO PARA 'L' --- */
    fseek(fptr, (num-1)*sizeof(quarto), 0);
    fread(pq, sizeof(quarto), 1, fptr);
    pq->status = 'L';

    fseek(fptr, (num-1)*sizeof(quarto), 0);
    fwrite(pq, sizeof(quarto), 1, fptr);

    fclose(fptr);
    fclose(fptr2);

    printf("\nCheckout realizado com sucesso!\n");
}
