#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int num;
    char categoria, status;
}quarto;

typedef struct{
    int quarto, acompanhante, dias;
    char nome[10], categoria;
}hospede;

void alocaq(quarto **p, int tam);
void alocah(hospede **p, int tam);
void cadastraq(quarto *p);
void cadastrah(hospede *p, quarto *pq);
void mostraq(quarto *p);
int buscaq(quarto *pq, char cat);
void checkout(quarto *pq, hospede *p, int nhos);
int buscah(hospede *p ,int nhos);


int main(){
    quarto *pqua=NULL;
    hospede *phos=NULL;
    int qqua=0, qhos=0, op;
    alocaq(&pqua, 15);
    

    cadastraq(pqua);
    

    do{
        printf("\n[1] - check in\n[2] - check out\n[3] - mostrar quartos\n[4] - cadastrar quarto\n[5] - sair\n");
        scanf("%i", &op);
        fflush(stdin);

        switch(op){
        case 1:
            alocah(&phos, qhos+1);
            cadastrah(phos+qhos, pqua);
            qhos++;
            break;
        case 2:
            checkout(pqua, phos, qhos);
            break;

        case 3:
            mostraq(pqua);
            break;

        case 4:
            break;

        case 5:
            printf("\nSaindo...\n");
            break;

        default:
            break;
        }

    }while(op!=5);



    return 0;
}



void alocaq(quarto **p, int tam){
    if((*p=(quarto*)realloc(*p, tam*sizeof(quarto)))==NULL){
        exit(1);
    }
}

void alocah(hospede **p, int tam){
    if((*p=(hospede*)realloc(*p, tam*sizeof(hospede)))==NULL){
        exit(1);
    }
}

void cadastraq(quarto *p){
    for(int i=0;i<15;i++){
        (p+i)->num = i+1;
        (p+i)->status = 'L';

        if(i<5)
            (p+i)->categoria = 'S';
        else
            (p+i)->categoria = 'F';
    }
}

void mostraq(quarto *p){
    for(int i=0;i<15;i++, p++){
         printf("\nNumero = %i - Cat = %c - Status = %c\n", p->num, p->categoria, p->status);
    }
}

void cadastrah(hospede *p, quarto *pq){
    char cat;
    int pos;
    printf("Digite o nome do ocupante: ");
    gets(p->nome);
    fflush(stdin);
    do{
        printf("Quantidade de acompanhantes [MAX=3]: ");
        scanf("%i", &(p->acompanhante));
        fflush(stdin);
    }while(p->acompanhante>=3 && p->acompanhante<=0);
    if(p->acompanhante==0)
        cat = 'S';
    else
        cat = 'F';

    printf("Quantos dias ira ocupar: ");
    scanf("%i", &(p->dias));
    fflush(stdin);

    pos = buscaq(pq, cat);

    if(pos== -1){
        printf("\nTodos os quartos ocupados!\n");
    }
    else{
        p->quarto = pos;
        (pq+pos)->status = 'O';
        printf("\nVoce esta no quarto %i\n", (p->quarto)+1);
    }
    
}

int buscaq(quarto *pq, char cat){
    for(int i=0;i<15; i++,pq++){
        if(cat==pq->categoria && pq->status=='L'){
            return i;
        }
    }
    return -1;
}

void checkout(quarto *pq, hospede *p, int nhos){

    float preco;
    int c;
    c = buscah(p, nhos);
    if((pq+c)->categoria == 'S'){
        preco = (85*((p+c)->dias));
        printf("Voce deve pagar %.2f reais", preco);
    }
    else{
        preco = (65*((p+c)->dias));
        printf("Voce deve pagar %.2f reais", preco);
    }

}

int buscah(hospede *p ,int nhos){
    char nomeh[10];
    printf("\nDigite o seu nome: ");
    gets(nomeh);
    fflush(stdin);
    for(int i = 0; i<nhos; i++){

        if(strcmp((p+i)->nome, nomeh) == 0){
            return i;
        }

    }

}

