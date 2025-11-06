#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dados
{
    int reg;
    char produto[20];
    int qtde;
    float preco;
} dados;
void aloca(dados **p, int tam);
int verifica();
void cadastro(dados *p);
void altera(dados *p, int op);
int busca(dados *p, int aux_reg);
void grava(dados *p, char *str, int pos);
void mostra(dados *p);
int main()
{
    dados *pd = NULL;
    int op;
    aloca(&pd, 1);
    do
    {
        system("cls");
        printf("\n[1]Cadastro\n[2]Altera\n[3]Deleta\n[4]Mostra\n[5]Fim\nOpcao: ");
        scanf("%i", &op);
        fflush(stdin);
        switch (op)
        {
        case 1:
            cadastro(pd);
            break;
        case 2:
        case 3:
            altera(pd, op);
            break;
        case 4:
            mostra(pd);
            break;
        } // switch
    } while (op != 5);
} // main
void aloca(dados **p, int tam)
{
    if ((*p = (dados *)realloc(*p, tam * sizeof(dados))) == NULL)
        exit(1);
} // aloca
int verifica()
{
    FILE *fptr = NULL;
    long int cont = 0;
    if ((fptr = fopen("estoque.bin", "rb")) == NULL)
        return cont;
    else
    {
        fseek(fptr, 0, 2);                  // posiciona no fim do arquivo
        cont = ftell(fptr) / sizeof(dados); // qtde de elementos
        fclose(fptr);                       // dentro do ELSE por conta do rb
        return cont;
    } // else
} // verifica
void cadastro(dados *p)
{
    int qreg, pos;
    qreg = verifica();
    pos = busca(p, -1); //-1 = busca vago
    if (pos == -1)      // nao tem vago
        p->reg = qreg + 1;
    printf("\nRegistro: %i", p->reg);
    printf("\nProduto: ");
    gets(p->produto);
    fflush(stdin);
    printf("Qtde estoque: ");
    scanf("%i", &(p->qtde));
    fflush(stdin);
    printf("Preco: ");
    scanf("%f", &(p->preco));
    fflush(stdin);
    if (pos != -1)
        grava(p, "rb+", pos);
    else
        grava(p, "ab", 1);
} // cadastro
void altera(dados *p, int op)
{
    int aux_reg, pos;
    mostra(p);
    printf("\nRegistro a ser alterado/deletado: ");
    scanf("%i", &aux_reg);
    fflush(stdin);
    pos = busca(p, aux_reg);
    if (pos == -1)
        printf("\nRegistro invalido\n\n");
    else
    {
        printf("\nRegistro: %i\nProduto: %s\nQtde: %i\nPreco: %.2f\n\n", p->reg, p->produto, p->qtde, p->preco);
        if (op == 2) // altera
        {
            printf("\nNOVO preco: ");
            scanf("%f", &p->preco);
            fflush(stdin);
        } // if
        else
            p->qtde = -1;
        grava(p, "rb+", pos);
        printf("\nRegistro alterado/deletado com sucesso\n\n");
    } // else
    system("pause");
} // altera
int busca(dados *p, int aux_reg)
{
    FILE *fptr = NULL;
    int qreg, i, achou = -1;
    qreg = verifica();
    if ((fptr = fopen("estoque.bin", "rb")) == NULL)
        achou = -1;
    else
    {
        for (i = 0; i < qreg; i++)
        {
            fseek(fptr, i * sizeof(dados), 0); // posiciona fptr
            fread(p, sizeof(dados), 1, fptr);
            if (p->reg == aux_reg || p->qtde == aux_reg)
            {
                achou = i;
                i = qreg; // forca a saida do for
            } // if
        } // for
        fclose(fptr); // dentro do else - rb
    } // else
    return achou;
} // busca
void grava(dados *p, char *str, int pos)
{
    FILE *fptr = NULL;
    if ((fptr = fopen("estoque.bin", str)) == NULL)
        printf("\nErro ao abrir o arquivo");
    else
    {
        if (strcmp(str, "rb+") == 0)
            fseek(fptr, pos * sizeof(dados), 0);
        fwrite(p, sizeof(dados), 1, fptr);
    } // else
    fclose(fptr); // fora do ELSE por conta do ab, rb+
} // grava
void mostra(dados *p)
{
    FILE *fptr = NULL;
    int i, qreg;
    qreg = verifica();
    system("cls");
    if ((fptr = fopen("estoque.bin", "rb")) == NULL)
        printf("\nErro ao abrir o arquivo");
    else
    {
        for (i = 0; i < qreg; i++)
        {
            fseek(fptr, i * sizeof(dados), 0);
            fread(p, sizeof(dados), 1, fptr);
            printf("\nRegistro: %i\nProduto: %s\nQtde: %i\nPreco: %.2f\n\n", p->reg, p-> produto, p->qtde, p->preco);
        } // for
        fclose(fptr);
    } // else
    system("pause");
} // mostra
