#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct produto{
    char descricao[12];
    int numreg, qtd;
    float preco;
}produto;

typedef struct loja{
    int regprod;
    char cnpj[13];
    char nome[12];
    int qtd;
}loja;

void aloca_produto(produto **pp, int q);
void aloca_loja(loja **pl, int q);
void cadastra_produto(produto *p, int q);
void mostra_produto(produto *p, int q);
void cadastra_loja(loja *pl, produto *p, int qprod);
int busca_produto(produto *p, char *aux, int qprod);
void mostra_loja(loja *pl, produto *p, int qloja);

int main()
{
    produto *ppro = NULL;
    loja *ploj = NULL;
    int op, cont = 0;

    aloca_produto(&ppro,5);
    cadastra_produto(ppro,5);

    do{
        printf("[1] - Mostra produto\n[2] - Mostra cliente\n[3] - Sair\n");
        scanf(" %i", &op);
        fflush(stdin);
        system("cls");
        switch(op){
            case 1:
            mostra_produto(ppro, 5);
            aloca_loja(&ploj, cont+1);
            cadastra_loja(ploj+cont,ppro,5);
            cont++;
            break;
            case 2:
            mostra_loja(ploj, ppro, cont);
            break;
            case 3:
            printf("Saindo...\n");
            break;
            default:
            printf("Opcao invalida\n");
            break;
        }

    }while(op != 3);
    
    return 0;
}

void aloca_produto(produto **pp, int q){
    if((*pp = (produto *)realloc(*pp,q*sizeof(produto))) == NULL){
        printf("\nErro na alocacao de produto");
        exit(1);
    }
}//aloca produto

void aloca_loja(loja **pl, int q){
    if((*pl = (loja *)realloc(*pl,q*sizeof(loja))) == NULL){
        printf("\nErro na alocacao de loja");
        exit(1);
    }
}//aloca loja

void cadastra_produto(produto *p, int q){

    for(int i = 0; i<q; i++){
        (p+i)->qtd = 1000;
        (p+i)->numreg = i+1;
        switch(i){
            case 0:
            strcpy((p+i)->descricao,"calca");
            (p+i)->preco = 150;
            break;
            case 1:
            strcpy((p+i)->descricao,"camisa");
            (p+i)->preco = 100;
            break;
            case 2:
            strcpy((p+i)->descricao,"saia");
            (p+i)->preco = 150;
            break;
            case 3:
            strcpy((p+i)->descricao,"vestido");
            (p+i)->preco = 250;
            break;
            case 4:
            strcpy((p+i)->descricao,"meia");
            (p+i)->preco = 10;
            break;
        }
    }

}//cadastra produto

void mostra_produto(produto *p, int q){
    for(int i = 0; i<q; i++){
        printf("Numero de registro do produto: %i\nDescricao: %s\nQuantidade: %i\nPreco: %.2f",(p+i)->numreg,(p+i)->descricao,(p+i)->qtd,(p+i)->preco);
        printf("\n\n\n");
    }
}//mostra produto

void cadastra_loja(loja *pl, produto *p, int qprod){
    char aux[12];
    int pos;

    printf("\nInsira o CNPJ de sua empresa: ");
    gets(pl->cnpj);
    fflush(stdin);
    printf("Insira o nome de sua empresa: ");
    gets(pl->nome);
    fflush(stdin);
    printf("\nQue produto deseja comprar: ");
    gets(aux);
    fflush(stdin);
    pos = busca_produto(p, aux, 5);
    if(pos == -1)
        printf("O produto nao existe");
    else{
        printf("Insira quantos deseja comprar: ");
        scanf("%i", &pl->qtd);
        (p+pos)->qtd = (p+pos)->qtd-pl->qtd;
        pl->regprod = (p+pos)->numreg;
        printf("\n\nLoja cadastrada com sucesso!!\n\n1");
        system("pause");
        printf("\n\n");
    }

}//cadastra loja

int busca_produto(produto *p, char *aux, int qprod){
    for(int i=0;i<strlen(aux);i++){
        aux[i]=tolower(aux[i]);
    }
    for(int i = 0; i<qprod; i++){
        if(strcmp((p+i)->descricao, aux) == 0)
            return i;
    }
    return -1;
}//busca produto

void mostra_loja(loja *pl, produto *p, int qloja){
    for(int i = 0; i<qloja; i++){
        printf("Loja %i\nCNPJ: %s\nNome: %s\nProduto comprado: %s\nQuantidade comprada: %i\nPreco que pagou: %.2f\n\n", i+1, (pl+i)->cnpj, (pl+i)->nome, (p+(pl+i)->regprod -1)->descricao, (pl+i)->qtd, (p+(pl+i)->regprod -1)->preco * (pl+i)->qtd);
    }
    system("pause");
    system("cls");
}
