#include <stdio.h>
#include <stdlib.h>

void leitura(float *t, int tam);
void maior(float *t, int tam);
float media(float *t, int tam);
int inf_media(float *t, int tam, float media, int *pos);
void imprime(int *pos, int qtde, float *t);

int main(){
    float temp[31], m;
    int dias, pos_inf[31], qtde;

    printf("Qtde de dias: ");
    scanf("%i", &dias);

    leitura(temp, dias);
    maior(temp, dias);
    m = media(temp, dias);
    qtde = inf_media(temp, dias, m, pos_inf);
    imprime(pos_inf, qtde, temp);

    return 0;
}


void leitura(float *t, int tam){
    for (int i=0;i<tam;i++){
        printf("Temperatura do dia %i: ", i+1);
        scanf("%f", t++);
        fflush(stdin);
    }   
}

void maior(float *t, int tam){
    float maior;
    int dia;
    maior = *t;
    dia = 1;
    for (int i=0;i<tam;i++){
        if (maior < *(t+i)){
            maior = *(t+i);
            dia = i+1;
        }   
    }
    printf("\n\nA maior temperatura foi de %.2f graus no dia %i\n", maior, dia);
}

float media(float *t, int tam){
    float soma, media;
    soma=0;
    for (int i=0;i<tam;i++, t++){
        soma+=*t;
    }
    media = soma / (float)tam;

printf("A media e %.2f graus\n", media);

    return media;
}

int inf_media(float *t, int tam, float media, int *pos){
    int j=0;
    for (int i=0;i<tam;i++){
        if(*(t+i)<media){
            *(pos+j)=i;
            j++;
        }
    }
    return j;
}

void imprime(int *pos, int qtde, float *t){
    for(int i=0;i<qtde;i++){
        printf("\nTemperatura : %.2f - Dia : %i\n", *(t+*(pos+i)), *(pos+i));
    }
}