//integrantes:


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 1. ESTRUTURA DE DADOS
// struct para guardar os vetores, o grau e os resultados

typedef struct{
    int grau;
    int pontos;

    float *x;
    float *fx;
    float *L;

    float x_alvo;
    float px;
} lagrange_data;

// 2. PROTÓTIPOS

void aloca_float(float **p,size_t quant);
void aloca_lagrange(lagrange_data **p, size_t quant);
void recebe_dados(lagrange_data *dados);
void calcula_lagrange(lagrange_data *dados);

// 3. MAIN

int main() {
    lagrange_data *dados = NULL;
    char resp;

    system("clear || cls"); //Limpa tela linux e Windows

    aloca_lagrange(&dados, 1); //aloca espaço para a struct 

    (*dados).x = NULL; //problema na alocação
    (*dados).fx = NULL;
    (*dados).L = NULL;

    recebe_dados(dados);//recebe grau, aloca vetores e preenche a tabela

    //loop para calcular os x's
    do{
        printf("\n----------------------------------\n");
        printf("Digite o valor de x que deseja interpolar/calcular: \n");
        scanf(" %f", &((*dados).x_alvo));

        calcula_lagrange(dados); //aplica a matematica

        printf("\nRESULTADO FINAL: P(%.4f) = %.4f ;\n", (*dados).x_alvo, (*dados).px);
        printf("\n----------------------------------\n");

        printf("\nDeseja calcular outro valor de X (s/n)? ");
        scanf(" %c", &resp);
    }while(resp == 'S' || resp =='s');

    free((*dados).x); //libera a memoria
    free((*dados).fx);
    free((*dados).L);
    free(dados);

    printf("\nPROGRAMA ENCERRADO. MEMORIA LIBERADA!\n");
    return 0;
}

// 4. FUNÇÕES
void aloca_float(float **p, size_t quant) {
    if((*p=realloc(*p, quant*sizeof(float)))==NULL){
        printf("##ERRO NA MEMORIA##\n");
        exit(1);
    }
}

void aloca_lagrange(lagrange_data **p, size_t quant){
    if((*p=realloc(*p, quant*sizeof(lagrange_data)))==NULL){
        printf("##ERRO NA MEMORIA##\n");
        exit(1);
    }
}

void recebe_dados(lagrange_data *dados){
    printf("Digite o valor do polinomio que deseja obter: ");
    scanf(" %i", &((*dados).grau));

    (*dados).pontos = (*dados).grau+1;

    //aloca espaço para os dados a serem recebidos
    aloca_float(&((*dados).x), (*dados).pontos);
    aloca_float(&((*dados).fx), (*dados).pontos);
    aloca_float(&((*dados).L), (*dados).pontos);

    printf("\n--- Preenchimento da tabela ---\n");
    printf("Insira os valores de x e f(x): \n");

    for(int i=0;i<(*dados).pontos;i++){
        printf("Digite o %i.o valor de x: ", i+1);
        scanf(" %f", (*dados).x+i);

        printf("Digite o valor de f(x) correspondente: ");
        scanf(" %f", (*dados).fx+i);
    }
}

void calcula_lagrange(lagrange_data *dados){
    (*dados).px = 0; //zera a variável

    printf("\nCalculando Lk(x)...\n");

    //loop de calculo do Li (externo)
    for(int i=0;i<(*dados).pontos; i++){
        *((*dados).L+i)=1.0; //"zera" o valor de Li (multiplicação)

        for(int j=0;j<(*dados).pontos;j++){
            if(i!=j){
                // Li = Li * ((X - Xj) / (Xi - Xj))
                // multiplica por Li para acomular as respostas passadas
                float numerador = (*dados).x_alvo - *((*dados).x+j);
                float denominador = *((*dados).x+i) - *((*dados).x+j);

                if(denominador==0){
                    printf("\n##DIVISAO POR 0 DETECTADA | x DUPLICADO##\n");
                    exit(1);
                }
                *((*dados).L+i)=*((*dados).L+i)*(numerador/denominador);
            }
        }

        printf("L%i(%.2f) = %.5f\n", i, (*dados).x_alvo, *((*dados).L+i)); //Exibe o valor de Lk(x) calculado
        (*dados).px = (*dados).px + (*((*dados).L+i)**((*dados).fx+i));
    }

}