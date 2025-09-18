#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void aloca(int **p, int tam);
void leitura(int *p);
void mostra(int *p, int tam);
int impar(int *p, int tam, int **pi);
int main()
{
    int *ptr = NULL, cont = 0, *pimp = NULL, qimp;
    char op;
    do
    {
        aloca(&ptr, cont + 1);
        leitura(ptr + cont);
        cont++;
        printf("Deseja continuar? [S/N]: ");
        scanf(" %c", &op);
    } while ('N' != toupper(op));
    system("cls");
    mostra(ptr, cont);
    qimp = impar(ptr, cont, &pimp);
    mostra(pimp, qimp);
    return 0;
}
void aloca(int **p, int tam)
{
    if ((*p = (int *)realloc(*p, tam * sizeof(int))) == NULL)
    {
        printf("##ERROR##");
        exit(1);
    }
}
void leitura(int *p)
{
    printf("Digite o numero: ");
    scanf(" %i", p);
}
void mostra(int *p, int tam)
{
    int i;
    for (i = 0; i < tam; i++, p++)
    {
        printf("%i\n", *p);
    }
    system("pause");
}
int impar(int *p, int tam, int **pi)
{
    int i, qimp = 0, sub;
    for (i = 0; i < tam/2; i++)
    {
        sub = *(p + i*2) - *(p + i*2 + 1);
        if (sub % 2 != 0)
        {
            aloca(pi, qimp + 1);
            *((*pi) + qimp) = sub;
            qimp++;
        }
    }
    if (tam % 2 == 1)
    {
        if (*(p + tam-1) % 2 != 0)
        {
            aloca(pi, qimp + 1);
            *((*pi) + qimp) = *(p + tam - 1);
            qimp++;
        }
    }
    return qimp;
}
