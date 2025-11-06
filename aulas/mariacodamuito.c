#include <stdio.h>

int main(){
    int i, soma = 0, impar = 0;
    int vet[10];


    for(i = 0; i < 10; i++){
        printf("Digite o %d numero: ", i+1);
        scanf("%d", &vet[i]);
        if(vet[i] > 5 && vet[i] < 15){
            vet[i] = 10;
        }
    }
    for(i = 0; i < 10; i++){
        if(vet[i] %2 == 0){
            soma = vet[i] + soma;
        }
        else{
            impar = 1 + impar;
        }
    }
    printf("A soma eh:%i\nA quantidade de impares eh:%i", soma, impar);


    return 0;
}