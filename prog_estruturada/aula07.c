#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade, ra;
}aluno;

void aloca(aluno **p, int tam);
void leitura(aluno *p, int tam);
void mostra(aluno *p, int tam);

int main(){
    char op;
    int x=0;
    aluno *pa=NULL;

    do{
    aloca(&pa, x+1);
    leitura(pa+x, x);
    x++;
     mostra(pa, x);
    printf("Continuar? [S/N]: ");
    scanf(" %c", &op);
    }while(op!='n');
    
    //system("cls");

    mostra(pa, x);
    
    return 0;
}

void aloca(aluno **p, int tam){
    if((*p=(aluno*)realloc(*p,tam*sizeof(aluno)))==NULL){
        exit(1);
    }
}

void leitura(aluno *p, int tam){
    printf("Digite o nome do Aluno %i: ", tam+1);
    scanf("%s",(p)->nome);
    fflush(stdin);

    printf("Digite a idade do Aluno %i: ", tam+1);
    scanf("%i",&(p)->idade);
    fflush(stdin);

    printf("Digite o RA do Aluno %i: ", tam+1);
    scanf("%i",&(p)->ra);   
    fflush(stdin);
}

void mostra(aluno *p, int tam){
    printf("\n\n");
    for(int i=0;i<tam;i++){
        printf("Nome : %s\n", (p+i)->nome);
        printf("Idade : %i\n", (p+i)->idade);
        printf("RA : %i\n", (p+i)->ra);
        printf("Ponteiro: %u\n", p+i);
        printf("\n");
        
    }
}