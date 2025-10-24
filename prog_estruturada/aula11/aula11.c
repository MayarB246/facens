#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int reg, qtde;
    char produto[20];
    float preco;
}dados;

void aloca(dados **p, int tam);
void leitura(dados *p);
int verifica();
void grava(dados *p);
void mostra(dados *p);

int main(){
    char op;
    dados *ptr=NULL;

    aloca(&ptr, 1);
    
    do{
        leitura(ptr);
        printf("Deseja continuar? [S/N]: ");
        scanf("%c", &op);
        fflush(stdin);
    }while(op!='N' && op!='n');
    
    mostra(ptr);

    return 0;
}

void aloca(dados **p, int tam){
    if((*p=(dados*)realloc(*p, tam*sizeof(dados)))==NULL){
        printf("Erro na alocacao!\n");
        exit(1);
    }
}

void leitura(dados *p){
    p->reg=verifica()+1;
    printf("Registro: %i\n", p->reg);

    printf("Digite o nome do seu produto: ");
    gets(p->produto);
    fflush(stdin);

    printf("Digite o preco: ");
    scanf("%f", &(p->preco));
    fflush(stdin);

    printf("Digite a quantidade: ");
    scanf("%i", &(p->qtde));
    fflush(stdin);

    grava(p);
}

int verifica(){
    FILE *fptr=NULL;
    long int cont=0;

    if((fptr=fopen("estoque.bin", "rb"))!=NULL){
        fseek(fptr, 0, 2);
        cont = ftell(fptr)/sizeof(dados);
        fclose(fptr);
    }
    return cont;
}

void grava(dados *p){
    FILE *fptr=NULL;
    if((fptr=fopen("estoque.bin", "ab"))==NULL)
        printf("Erro ao abrir o arquivo!\n");
    else
        fwrite(p,sizeof(dados), 1, fptr);
    fclose(fptr);
}

void mostra(dados *p){
    int qreg=verifica();
    FILE *fptr=NULL;

    system("cls");

    if((fptr=fopen("estoque.bin", "rb"))==NULL)
        printf("Erro ao acessar o arquivo\n");
    else{
        for(int i=0; i<qreg;i++){
            fseek(fptr, i*sizeof(dados), 0);
            fread(p, sizeof(dados), 1, fptr);
            printf("Registro: %i\nProduto: %s\nQuantidade: %i\nPreco: %.2f\n\n", p->reg,p->produto,p->qtde,p->preco);
        }
        fclose(fptr);
    }
    system("pause");
}