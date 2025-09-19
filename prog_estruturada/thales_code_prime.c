#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void aloca(float **p, int q);
void recebe(float *p, int q);
char continua();
void mostra(float *p, int q);
void bagunca(float *p, int q, float **pr);

int main(){

    float *ptr = NULL, *pres = NULL;
    int cont = 0;
    char op;

    do{
        aloca(&ptr,cont+1);
        recebe(ptr+cont, cont +1);
        op = continua();
        cont++;
    }
    while(toupper(op) != 'N');

    mostra(ptr,cont);

    printf("\n");
    system("pause");

    bagunca(ptr,cont,&pres);
    mostra(pres,cont/2+1);

    return 0;
}

void aloca(float **p, int q){

    if((*p=(float *)realloc(*p,q*sizeof(float))) == NULL){
        printf("\nErro na alocacao");
        exit(1);
    }
}
void recebe(float *p, int q){

    printf("Insira o %i numero: ", q);
    scanf(" %f", p);
}

char continua(){
    char opc;
    printf("Deseja continuar? (s|n): ");
    scanf(" %c", &opc);
    return opc;
}

void mostra(float *p, int q){

    for(int i = 0; i<q; i++){
        printf("numero %i: %.2f\n", i+1, *(p+i));
    }
}

void bagunca(float *p, int q, float **pr){

    for(int i = 0; i<q/2; i++){

        aloca(pr,i+1);
        *(*pr+i) = *(p+i)*2+*(p+q-i-1);
    }

    if(q%2 != 0){
        aloca(pr,q+1/2);
        *(*pr+q/2) = *(p+q/2)*(*(p+q/2));
     }

}
