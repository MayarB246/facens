//Integrantes: 


//primeiro a inclusão das bibliotecas básicas
#include <stdio.h>
#include <stdlib.h>

//biblioteca de matemática
#include <math.h>

//struct para guardar o ponto e o resultado da função
typedef struct funcao{
    float p1;
    float p2;         //pontos da função

    float resultado1;  //resultado a partir da conta
    float resultado2;

    float med;	   //dados da média
    float rmed;

    char sinal1;        //se rmed*p1 dá + ou -
    char sinal2;

}funcao;


//area de protótipos:

//----------------------------
//void aloca novo:
//void *aloca(void *ptr, size_t quant, size_t tam); medo do prof descontar nota
//já q esse n usa chamda por referencia ;-;
//(tem como fazer ele usando #define, mas aí sim ele descontaria nota, eu acho?
//----------------------------

//----------------------------
//retorna ponteiro void *
//obs size_t segundo o gpt é usado para representar tamanhos de memoria
//por isso usamos ele aqui (usamos ele na quant tb mas poderia usar int)
//o void deixa ela generica
//acitando qualquer tipo de variavel,a função retorna o ponteiro por isso
//*aloca, antes eu fazia cast de void, mas me falaram q não era muito seguro
//void *aloca(void *ptr, size_t quant, size_t tam); (antigo) deixei o antigo
//no código comentado se quiser ver
//----------------------------

//voids aloca novos2 seguindo padrão do prof:
//sem cast pq n é seguro
void aloca_int(int **p, size_t quant);
void aloca_float(float **p, size_t quant);
void aloca_funcao(funcao **p, size_t quant);
//já expliquei o size_t no textão acima

//explicação rápida do q cada um faz (isso é para o prof, galera do grupo ler e entender)
void print_func(int *grau, float *mult); //printa a função inteira   
void calcula_pontos(float *mult, int *grau, float *resultado1, float *p1); //calula o ponto e armazena no resultado
void verifica(funcao *f); //verifica casos que dão errado
void media(funcao *f);  //calcula média de dois pontos e guarda o resultado em med
void calcular_k(float *erro, funcao *f); //calula o numero de iterações com base no "e"
void troca(funcao *f); //troca p1 ou p2 por med (depende se der - ou +)
void tabela(float *k, float *mult, int *grau, funcao *f); //loop da tabela e dos outros calculos (todos menos o 1°)
void def_sinal(funcao *f);  //salva num char se a rmed*resultado1 vai dar - ou +

int main()
{

    //declarações
    funcao *f = NULL;
    int *grau = NULL;
    float *mult = NULL;
    float *k = NULL; 

    //limpa tela linux + windows
    system("clear || cls"); 


    //vamos alocar o ponteiro grau

    //----------------------------
    //(antigo)
    //aloca((void**)&grau, 1, sizeof(int));
    //novo: mais seguro pois n usa cast de void ("conversão de ponteiro")
    //grau = aloca(grau, 1, sizeof(int));
    //----------------------------

    //novo 2 seguindo padrões do prof:
    aloca_int(&grau, 1);
    aloca_funcao(&f, 1);
    aloca_float(&k, 1);

    do{
    //podemos receber o grau da função agora
    //1° grau tem 2x (x⁰ x¹) , 2° tem 3x e assim vai
    printf("informar o grau da função (suportamos 2-6): ");
    scanf(" %i", grau); //n precisa de &, grau já tem o endereço (é um ponteiro)
    }while (*grau > 6 || *grau < 2);

    //agora com base no grau da função recebemos X multiplicadores
    //reservar o espaço para mult:

    //----------------------------
    //aloca((void**)&mult, 7, sizeof(float)); //(antigo)
    //mult = aloca(mult, *grau+1, sizeof(float)); //novo (grau p deixar dinamico)
    //----------------------------

    //novo 2 nos padrões do prof
    aloca_float(&mult, *grau + 1); 	//grau + 1 pois como o primeiro grau já tem 2 "x" dois multiplicadores no caso, ent sempre
    					//terá 1 multiplicador a mais q o numero de graus
   					//e tb pq já aloca com base no grau e fica dinamico
    					//sem ter q incluir a alocação dentro de um for

    //for para repetir "grau" vezes a incerção dos multiplicadores (dá p por em função, não achei necessário)
    for(int i = 0; i <= *grau; i++)
    {
        printf("\ninforme o %i° multiplicador: ", i);
        scanf(" %f", mult+i);
        printf("\n");
    }//for

    system("clear || cls"); 
    
    //função para printar na tela a equação inserida
    print_func(grau, mult);

    do{
        //1° receber do usuario os valors A e B num loop até um desses provar a
        //exitencia de 0 na função, obs valor de A menor q B sempre

        printf("\ncomecando calculo...\n insira os pontos A e B\n A: ");
        scanf(" %f", &((*f).p1)); //ponto 1
        printf("\n B: ");
        scanf(" %f", &((*f).p2));  //ponto 2

        //encontra os primeiros pontos (tipo a funcaoX do prof)
        calcula_pontos(mult, grau, &((*f).resultado1), &((*f).p1));
        calcula_pontos(mult, grau, &((*f).resultado2), &((*f).p2));

        verifica(f); //ver se as condições de existencia batem, ou caso vc já achar o 0 no chute etc...

        if((*f).p1 != (*f).p2){
            //calcula a média dos pontos e guarda em (*f).med
            media(f);
            calcula_pontos(mult, grau, &((*f).rmed), &((*f).med)); //manda a f(med) guarda em rmed
            def_sinal(f); //vê qual p1 ou p2 vai dar - com med

            printf("\ninsira a precisao do calculo: ");
            scanf(" %f", k);
            calcular_k(k, f);
        }

        //se não encontrar pontos retornar p1 = p2, mantendo o loop até alcançar as condições
    }while((*f).p1 == (*f).p2);

    tabela(k, mult, grau, f);
    //imprir uma tabela até chegar no valor 0.0... q k aceita

    //libera as variaveis
    free(grau);
    free(mult);
    free(f);
    free(k);
    //encerra o programa
    return 0;
}//main ------------------------------------------------------------------------------- (esse monte de "-" para encontrar o main mais fácil)

//função aloca (antiga) descomentar se quiser usar
/*
 v oid alo*ca(void **ptr, size_t quant, size_t tam)
 {
 if((*ptr = realloc(*ptr, quant*tam))==NULL)
     exit(1);
 }
 */

//função aloca (novo)
/*
 v oid *al*oca(void *ptr, size_t quant, size_t tam)
 {
 ptr = realloc(ptr, quant * tam);
 if (ptr == NULL)
     exit(1);

 return ptr;
 }
 */

//funções aloca novo2:

void aloca_int(int **p, size_t quant){

    if((*p = realloc(*p, quant * sizeof(int)))==NULL) exit(1);

}//aloca_int

void aloca_float(float **p, size_t quant){

    if((*p = realloc(*p, quant * sizeof(float))) == NULL) exit(1);

}//aloca_float

void aloca_funcao(funcao **p, size_t quant){

    if((*p = realloc(*p, quant * sizeof(funcao))) == NULL) exit(1);

}//aloca_funcao

void print_func(int *grau, float *mult){

    printf("\nfunção recebida:\n");
    for(int i = 0; i <= *grau; i++)
    {
        if(i == 0){
            printf("f(x) = ");
            printf("%.2f", *(mult+i)); //tirei o x^0 já q fica sempre 1.mult
        }

        else{
            printf("%.2f*X^%i", *(mult+i), i);
        }

        if(i < *grau)
            printf("+");
        else
            printf("\n\n");
    }//for

}//print_func

void calcula_pontos(float *mult, int *grau, float *resultado1, float *p1){

    //define igual a zero pq vai q tem algo neles
    *resultado1 = 0;

    for(int i = 0; i<= *grau; i++){

        *resultado1 = *resultado1 + *(mult+i) * pow(*p1, i);

    }//for

}//calcula_pontos

void calcular_k(float *erro, funcao *f){

    if(((*f).p2 - (*f).p1) > 0 && *erro > 0){

        float vk;
        vk= (log10((*f).p2-(*f).p1) - log10(*erro))/(log10(2));
        *erro = ceil(vk);

    }//if
    else{
        printf("\nprecisao deve ser > 0 e a subtração entre os pontos não pode dar 0");
        (*f).p1 = (*f).p2;
    }

}//calcular_k arredondar p cima

void tabela(float *k, float *mult, int *grau, funcao *f){

    //cabeçalho
    printf("I |\ta\t|\tb\t|\tm\t|\tf(a)\t|\tf(b)\t|\tf(m)\t|fa*fm\t|fm*fb\t|\n");
    printf("--+-------------+---------------+---------------+---------------+---------------+---------------+-------+-------+\n");

    for(int i = 1; i < *k+1; i++){

        //imprime corpo
        printf("%i |%.5f\t|%.5f\t|%.5f\t|%.5f\t|%.5f\t|%.5f\t|%c\t|%c\t|\n", i, (*f).p1, (*f).p2, (*f).med, (*f).resultado1, (*f).resultado2, (*f).rmed, (*f).sinal1, (*f).sinal2);


        if((*f).rmed == 0){ //sai caso rmed dar 0, gpt ajudou aq
            break;
        }

        //calcula o próximo
        troca(f); //troca p2 OU p1 por med mantendo o que passa pelo 0
        calcula_pontos(mult, grau, &((*f).resultado1), &((*f).p1));
        calcula_pontos(mult, grau, &((*f).resultado2), &((*f).p2));
        media(f);
        calcula_pontos(mult, grau, &((*f).rmed), &((*f).med));
        def_sinal(f);

    }//for
}//tabela

void verifica(funcao *f){

    if((*f).p1 < (*f).p2){

        if((*f).resultado1 * (*f).resultado2 > 0){  //pois + com - tem q dar negativo, deu possitivo é erro (-- ou ++)
            printf("\nerro, sem 0 no intervalo\n");
            (*f).p1 = (*f).p2;
        }
        else if( (*f).resultado1 == 0 || (*f).resultado2 == 0){
            printf("o p1 resulta em:%.2f\np2 resulta em:%.2f logo já se tem o zero da função", (*f).resultado1, (*f).resultado2);
            (*f).p1 = (*f).p2;
        }

    }
    else{
        printf("\nerro, valor de A deve ser sempre menor que B\n");
        (*f).p1 = (*f).p2;
    }

}//verifica


void media(funcao *f){

    (*f).med = ((*f).p1 + (*f).p2) / 2;

}//media

void troca(funcao *f){

    if((*f).rmed * (*f).resultado1 < 0){  //p1*rmed = neg, troca p2 com rmed

        (*f).p2 = (*f).med;
    }
    else{
        (*f).p1 = (*f).med;
    }
}//media

void def_sinal(funcao *f){

    if((*f).rmed * (*f).resultado1 < 0){
        (*f).sinal1 = '-';
        (*f).sinal2 = '+';
    }
    else{
        (*f).sinal1 = '+';
        (*f).sinal2 = '-';
    }

}//sinal
