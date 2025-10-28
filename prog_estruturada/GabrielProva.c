#include <stdio.h>
#include <stdlib.h>


int main(){

    int vet[5];

    for(int i = 0; i<5; i++){
        scanf("%i", &vet[i]);
        printf("\nValor %i: %i\n",i+1 ,vet[i]);
        system("pause");
    }


    printf("%i", vet[2]);
    return 0;
}