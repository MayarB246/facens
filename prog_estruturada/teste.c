#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void aloca(int **p, int tam);
void leitura(int *p);
char continuar();
void mostra(int *p, int tam);
int negativo(int *p, int tam, int **pneg);

int main(){
    int *ptr=NULL, cont=0, *ptrneg=NULL, qneg;
    char op;

    do{
        aloca(&ptr,cont+1);
        leitura(ptr+cont);
        cont++;
        op=continuar();
    }while('N'!=toupper(op));

    system("cls");
    mostra(ptr, cont);

    qneg=negativo(ptr, cont, &ptrneg);

    mostra(ptrneg, qneg);

    return 0;
}

void aloca(int **p, int tam){
    if((*p=(int*)realloc(*p,tam*sizeof(int)))==NULL){
        exit(1);        
    }
}

void leitura(int *p){
    printf("Digite o valor: ");
    scanf(" %i", p);
}

char continuar(){
    char op;
    printf("Deseja continuar? [S/N]: ");
    scanf(" %c", &op);
    return op;
}

void mostra(int *p, int tam){
    for(int i=0; i<tam;i++){
        printf("%i\n", *(p+i));
    }
    printf("\n");
    system("pause");
}

int negativo(int *p, int tam, int **pneg){
    int sub, qn=0;
    for(int i=0;i<tam/2;i++){
        sub=*(p+i)-*(p+tam-i-1);
        if(sub<0){
            aloca(pneg, qn+1);
            *(*pneg+qn)=sub;
            qn++;
        }
    }
    
    if(tam%2==1 && *(p+tam/2)<0){
         aloca(pneg, qn+1);
        *(*pneg+qn)=*(p+tam/2);
        qn++;
    }

    return qn;
}