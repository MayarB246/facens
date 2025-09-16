#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void aloca(int **p, int tam);
void leitura(int *p);
void mostra(int *p, int tam);
int subtarcao(int *p, int tam, int **pp);

int main(){
    char op;
    int *ptr=NULL, cont=0, *ppos=NULL, qpos=0;

    do{
        aloca(&ptr, cont+1);
        printf("Digite um numero: ");
        leitura(ptr+cont);
        cont++;
        printf("Deseja continuar? [S/N]: ");
        scanf(" %c", &op);
    }while('N'!=toupper(op));
    
    system("cls");
    mostra(ptr, cont);
    qpos=subtarcao(ptr, cont, &ppos);
    printf("\n");
    mostra(ppos,qpos);

    return 0;
}

void aloca(int **p, int tam){
    if((*p=(int*)realloc(*p, tam*sizeof(int)))==NULL){
        exit(1);
    }
}

void leitura(int *p){
    scanf(" %i", p);
}

void mostra(int *p, int tam){
    for(int i=0;i<tam;i++,p++){
        printf("%i\n", *p);
    }
    printf("\n");
    system("pause");
}

int subtarcao(int *p, int tam, int **pp){
    int sub, qp=0;
    for(int i=0;i<tam/2;i++){
        sub=*(p+i)-*(p+tam-i-1);
        if(sub >= 0){
            aloca(pp,qp+1);
            *(*pp+qp)=sub;
            qp++;
        }

    }
    if(tam%2==1){
        if(*(p+tam/2)>=0){
            aloca(pp,qp+1);
            *(*pp+qp)=*(p+tam/2);
            qp++;
        }
    }

    return qp;
}