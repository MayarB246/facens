#include <stdio.h>
int main(){
    int n ,*p_num, d;

    printf("Quantos numeros deseja escrever? ");
    scanf("%i", &n);

    int num[n];
    p_num = num; 

    printf(" Lendo os elementos da matriz ");
    for (d = 0; d < n; d++){
        printf(" \n %i elemento :", d + 1);
        scanf("%i", p_num++);
    }
    p_num = num;
    
    printf(" Imprime os elementos da matriz ");
    for (d = 0; d < n; d++)
        printf("\n num[%i] = %i", d, *(p_num++));
}