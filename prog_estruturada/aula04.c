#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);
void leitura(float *p);
void mostra(float *p, int tam);
int maior(float *p, int tam, float **pM);

int main(){
    int x=0, qMaior=0;
    float *ptr=NULL, *pM=NULL;
    char op;

    do{
        aloca(&ptr, x+1);
        leitura(ptr+x);
        x++;
        printf("Deseja continuar digitando? (S/N)");
        scanf(" %c", &op);
    }while(toupper(op)!='N');
    
    mostra(ptr, x);
    qMaior=maior(ptr, x, &pM);
    printf("\nQtd de numeros maior que a media: %i", qMaior);
    mostra(pM,qMaior);

    return 0;
}

void aloca(float **p, int tam){
    if ((*p=(float*)realloc(*p,tam*sizeof(float)))==NULL){
        printf("##ERROR##");
        exit(1);
    }
}

void leitura(float *p){
        printf("Digite o valor: ");
        scanf(" %f", p);
}

void mostra(float *p, int tam){
    for(int i=0;i<tam;i++,p++){
        printf("\n%.2f", *p);
    }
}

int maior(float *p, int tam, float **pM){
    float m=0;
    int j=0;

    for(int i=0;i<tam;i++,p++)
        m+=*p;
    m/=tam;
    printf("\nMedia = %.2f", m);

    p-=tam;
    for(int i=0;i<tam;i++,p++){
        if(*p > m){
            aloca(pM, j+1);
            *(*pM+j)=*p;
            j++;
        }
    }
    
    return j;
}