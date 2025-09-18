#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void recebe(int *p, int q);
void aloca(int **p, int q);
void mostra(int *p, int q);
void organiza(int *p, int q, int **pr);
void menor(int *p, int q);

int main(){

    int x, *ptr = NULL, *pres = NULL;


    printf("Insira quantos numeros deseja digitar: ");
    scanf(" %i", &x);
    for(int i = 0; i<x; i++){

        aloca(&ptr, i+1);
        recebe(ptr+i,i+1);

    }
    printf("\n\n");
    mostra(ptr, x);

    printf("\nOrganizando vetor...");
    system("pause");
    organiza(ptr, x, &pres);
    mostra(ptr, x);

    return 0;
}

void aloca(int **p, int q){

  if((*p =  (int *) realloc(*p,q*sizeof(int))) == NULL)
  {
    printf("\nErro na alocacao");
    exit(1);
  }

}

void recebe(int *p, int q){

    printf("Digite o numero %i: ", q);
    scanf(" %i", p);

}

void mostra(int *p, int q){

    for(int i = 0; i<q; i++){

        printf("Valor %i: %i\n", i+1, *(p+i));

    }

}

void organiza(int *p, int q, int **pr){

    for(int i = 0; i<q-1; i++){

        menor(p+i, q);

    }
   
}

void menor(int *p, int q){

    int men = *p, aux;
    for(int i = 0; i<q; i++)
    {

        if(*(p+i) < men){
            men = *(p+i); 
            *(p+i) = *p;
            *p = men;  
        }

    }
}