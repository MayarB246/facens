#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char opcao();
void aloca(float **p, int q);
void recebe(float *p, int q);
void mostra(float *p, int q);
void bagunca(float *p, int q, float **pr);

int main()
{

    float *ptr = NULL, *pres = NULL;
    int cont = 0;
    char op;

    do{
        aloca(&ptr, cont+1);
        recebe(ptr+cont, cont+1);
        op = opcao();
        cont++;
    }
    while('N' != toupper(op));

    mostra(ptr, cont);

    system("pause");
    system("cls");

    bagunca(ptr, cont, &pres);
    mostra(pres, cont-cont/2);

        return 0;
}

char opcao(){
    char o;
    printf("\nDeseja continuar? (s|n): ");
    scanf(" %c", &o);
    return o;
}

void aloca(float **p, int q){
    if((*p= (float *)realloc(*p,q*sizeof(float))) == NULL){
        printf("\nErro na alocacao!!");
        exit(1);
    }
}

void recebe(float *p, int q){

    printf("\nInsira o valor [%i]: ", q);
    scanf(" %f", p);

}

void mostra(float *p, int q){

    for(int i = 0; i<q; i++){

        printf("\nValor[%i]: %.2f", i+1, *(p+i));

    }
}

void bagunca(float *p, int q, float **pr){

    float res;
    int x = 0;

    for(int i = 0; i<q/2 ; i++){
        if(x == 0){
            x++;
            res = *(p+2*i)+*(p+2*i+1);
        }

        else{
            x--;
            res = *(p+2*i)-*(p+2*i+1);
        }

        aloca(pr, i+1);
        *(*pr+i) = res;
    }

    if(q%2 != 0){
        aloca(pr, ((q+1)/2));
        *(*pr+q/2) = (*(p+q-1))/2;
    }

}