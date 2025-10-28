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
void sair(hospede *p, quarto *pq, int qhos);
int buscah(hospede *p, char *nome, int qhos);
void mostraq(quarto *p);
int buscaq(quarto *pq, char cat);
void mostrah(hospede *p, int qhos);



int main(){
    quarto *pqua=NULL;
    hospede *phos=NULL;
    int qqua=0, qhos=0, op;
    alocaq(&pqua, 15);
    cadastraq(pqua);

    do{
        system("cls");
        printf("\n[1] - check in\n[2] - check out\n[3] - mostrar quartos\n[4] - sair\n[5] - Mostrar hospedes\n");
        scanf("%i", &op);
        fflush(stdin);

        switch(op){
        case 1:
            alocah(&phos, qhos+1);
            cadastrah(phos+qhos, pqua);
            qhos++;
            break;

        case 2:
            sair(phos, pqua, qhos);
            break;

        case 3:
            mostraq(pqua);
            break;

        case 4:
            printf("\nSaindo...\n");
            break;

        case 5:
            mostrah(phos, qhos);
            break;

        default:
            break;
        }
    }while(op!=4);

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
    printf("\nListando os quartos...\n");
    for(int i=0;i<15;i++, p++){
         printf("Numero = %i - Cat = %c - Status = %c\n", p->num, p->categoria, p->status);
    }
    system("pause");
}

void cadastrah(hospede *p, quarto *pq){
    char cat;
    int pos;

    printf("Digite o nome do ocupante: ");
    gets(p->nome);
    fflush(stdin);
    
    do{
        printf("Quantidade de acompanhantes [MAX=3]: ");
        scanf("%i", &p->acompanhante);
        fflush(stdin);
    }while(p->acompanhante>3 || p->acompanhante<0);

    if(p->acompanhante==0)
        p->categoria = 'S';
    else
        p->categoria = 'F';

    printf("Quantos dias ira ocupar: ");
    scanf("%i", &p->dias);
    fflush(stdin);

    pos = buscaq(pq, p->categoria);
    if(pos==-1){
        printf("\nTodos os quartos ocupados!\n");
    }
    else{
        p->quarto = pos;
        printf("Quarto %i solicitado com sucesso!\n", p->quarto+1);
    }
    system("pause");
}

int buscaq(quarto *pq, char cat){
    for(int i=0;i<15; i++,pq++){
        if(cat==pq->categoria && pq->status=='L'){
            pq->status='O';
            return i;
        }
    }
    return -1;
}

void mostrah(hospede *p, int qhos){
    for(int i =0;i<qhos;i++,p++){
        printf("Nome: %s\nQuarto: %i\nQtd de acompanhantes: %i\nCategoria: %c\nQtd de dias: %i\n\n",p->nome,p->quarto+1,p->acompanhante, p->categoria, p->dias);
    }
    system("pause");
}

void sair(hospede *p, quarto *pq, int qhos){
    char nome[10];
    int pos;
    float valor;
    printf("Digite seu nome: ");
    gets(nome);
    fflush(stdin);

    pos=buscah(p, nome, qhos);

    if(pos==-1){
        printf("Nome nao encontrado!\n");
    }
    else{
        switch(p->categoria){
            case 'S':
                valor = 80;
                break;
            case 'F':
                valor = 150;
                break;
        }
        valor*=p->dias;
        printf("Quarto: %i\nValor total: %.2f\n", p->quarto+1, valor);

        (pq+(p->quarto))->status='L';
    }
    system("pause");
}

int buscah(hospede *p, char *nome, int qhos){
    for(int i=0;i<qhos;i++,p++){
        if(strcmp(p->nome,nome)==0){
            return i;
        }
    }
    return -1;
}