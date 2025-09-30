#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct{

    char nome[30];
    int idade, ra;


}aluno;

char opcao();
void aloca(aluno **p, int q);
void recebe(aluno *p, int q);
void mostra(aluno *p, int q);

int main(){

    char op;
    aluno *pa = NULL;
    int qtd = 0;

    do{
        aloca(&pa, qtd+1);
        recebe(pa+qtd, qtd);
        op = opcao();
        qtd++;
    }
    while(toupper(op) != 'N');

    mostra(pa, qtd);

    return 0;
}

void aloca(aluno **p, int q){

        if((*p = (aluno *) realloc(*p,q*sizeof(aluno))) == NULL){

            printf("\nErro na alocacao");
            exit(1);
        }

}

char opcao(){

    char c;
    printf("\nDeseja continuar? (S|N): ");
    scanf(" %c", &c);
    fflush(stdin);

    return c;
}

void recebe(aluno *p, int q){

    printf("Insira o nome do aluno %i: ", q+1);
    gets((p)->nome);
    fflush(stdin);
    printf("Insira a idade do aluno %i: ", q+1);
    scanf("%i", &(p)->idade);
    fflush(stdin);
    printf("Insira o RA do aluno %i: ", q+1);
    scanf("%i", &(p)->ra);
    fflush(stdin);

}

void mostra(aluno *p, int q){

    int i;
    for(i = 0; i<q; i++){

        printf("\nNome do aluno %i: %s\nIdade do aluno %i: %i\nRA do aluno %i: %i\n", i+1, (p+i) ->nome, i+1, (p+i)->idade, i+1, (p+i)->ra);

    }


}
