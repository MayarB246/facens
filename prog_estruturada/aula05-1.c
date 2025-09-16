#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void aloca(float **p, int tam);
void leitura(float  *p);
float media(float *p, int tam);

int main(){
    float *ptr=NULL, m;
    int x=0;
    char op;

    do{
    aloca(&ptr, x+1);
    leitura(ptr+x);
    x++;
    printf("Deseja continuar? [S/N]: ");
    scanf(" %c", &op);
    }while('N'!=toupper(op));
    m=media(ptr, x);
    printf("\nA media e %.2f", m);
    return 0;
}

void aloca(float **p, int tam){
    if((*p=(float*)realloc(*p, tam*sizeof(float)))==NULL){
        printf("##ERROR##");
        exit(1);
    }
}

void leitura(float  *p){
    printf("digite o valor: ");
    scanf(" %f", p);
}

float media(float *p, int tam){
    int j=0;
    float m=0;
    for(int i=0;i<tam;i++,p++){
        if ( *p != 0 ){
            m+=*p;
            j++;
        }
    }
    m/=j;
    return m;
}