#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    int RA, reg;
    char nome[10];
    float media;
}aluno;

void aloca(aluno **p, int q);
void recebe(aluno *p);
void grava(aluno *p);
void mostra(aluno *p);
int verifica();

int main(){

    aluno *pa = NULL;
    char op;

    aloca(&pa, 1);

    do{
        recebe(pa);
        printf("\nDeseja continuar? (S|N): ");
        scanf("%c", &op);
        fflush(stdin);
    }
    while(op != 'n' && op != 'N');

    mostra(pa);
    return 0;
}

void aloca(aluno **p, int q){
    if((*p = (aluno *)realloc(*p,q*sizeof(aluno))) == NULL){
        printf("\nErro na alocacao");
        exit(1);
    }
}

void recebe(aluno *p){

    p->reg = verifica() + 1;
    printf("\nAluno de registro [%i]\n", p->reg);
    printf("\nInsira o nome do aluno: ");
    gets(p->nome);
    fflush(stdin);
    printf("\nInsira o RA do aluno: ");
    scanf("%i", &p->RA);
    fflush(stdin);
    printf("\nInsira a media final do aluno: ");
    scanf("%f", &p->media);
    fflush(stdin);
    grava(p);
}

void grava(aluno *p){
    FILE *fptr = NULL;

    if((fptr = fopen("alunos.bin", "ab")) == NULL){
        printf("\nErro na gravacao");
    }
    else{
        fwrite(p, sizeof(aluno), 1, fptr);
    }
    fclose(fptr);
}

int verifica(){
    FILE *fptr = NULL;
    long int cont = 0;
    if((fptr = fopen("alunos.bin","rb")) != NULL){
        fseek(fptr,0,2);
        cont = ftell(fptr)/sizeof(aluno);
        fclose(fptr);
    }
    return cont;
}

void mostra(aluno *p){

    FILE *fptr = NULL;
    int qtde = verifica();

    system("cls");

    if((fptr = fopen("alunos.bin", "rb"))== NULL){
        printf("\nErro ao acessar o arquivo");
    }
    else{
        for(int i = 0; i<qtde; i++){
            fseek(fptr,i*sizeof(aluno),0);
            fread(p,sizeof(aluno),1,fptr);
            printf("\nRegistro [%i]\nNome: %s\nRA: %i\nMedia: %.2f\n", p->reg,p->nome,p->RA,p->media);
        }
        fclose(fptr);
    }
    system("pause");
}