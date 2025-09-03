#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);
void recebe(float *p, int tam);
void soma(float *o, int tam);
void exibir(float *p, int tam);

int main(){
    int x;

    printf("Digite o tamanho do vetor: ");
    scanf("%i", &x);

    float *ptr=NULL;

    aloca(&ptr, x);
    recebe(ptr, x);
    soma(ptr, x);
    exibir(ptr,x);
    
    free(ptr);
    
    return 0;
}

void aloca(float **p, int tam){
    if((*p=(float*)realloc(*p, tam*sizeof(float)))==NULL){
        printf("Erro");
        exit(1);
    }
    printf("\nFuncao aloca - Endereco: %u\n", *p);
}

void recebe(float *p, int tam){
    printf("\nFuncao recebe - Digite os valores: \n");
    for (int i = 0; i < tam; i++, p++){
        printf("Endereco: %u - Valor= ", p);
        scanf("%f", p);
    }
}

void soma(float *p, int tam){
    printf("\nFuncao soma - +30 para todos do vetor\n");
    for (int i = 0; i < tam; i++, p++){
        *p+=30;
    }
}

void exibir(float *p, int tam){
    printf("\nFuncao exibir - exibindo o vetor:\n");
    for (int i = 0; i < tam; i++, p++){
        printf("Numero = %.2f - Posicao = %u\n",*p ,p);
    }
}