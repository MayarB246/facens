#include <stdio.h>
int main(){
    int num[5] ,*p_num, i, n;
    char sn;
    p_num = num; 
    n=0;

    printf(" Lendo os elementos da matriz ");

    while (toupper(sn) == 'S' || n == 0){
        printf(" \n %i elemento :", n + 1);
        scanf("%i", p_num++);
        fflush(stdin);
        printf("Deseja continuar? (S/N): ");
        scanf("%c", &sn);
        fflush(stdin);
        n++;
    }

    p_num = num;
    
    printf(" Imprime os elementos da matriz ");
    for (i = 0; i < n; i++)
        printf("\n num[%i] = %i", i, *(p_num++));
}