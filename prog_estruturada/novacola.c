#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct turma{
    int reg;
    int qtd;
    char tipo;
    float valor;
}turma;

typedef struct aluno{
    char RA[7];
    char nome[12];
    int numt;
}aluno;

void aloca_turma(turma **pt, int q);
void aloca_aluno(aluno **pa, int q);
void cadastra_turma(turma *pt, int q);
void mostra_turma(turma *pt, int q);
void matricula_aluno(aluno *pa, turma *pt, int q);
int busca_turma(turma *pt, char cat, int q);
void mostra_aluno(aluno *pa, turma *pt, int q);

int main(){

    turma *ptur = NULL;
    aluno *palu = NULL;
    int op, cont = 0;

    aloca_turma(&ptur, 6);
    cadastra_turma(ptur, 6);

    do{
        system("cls");
        printf("[1] - Matricula\n[2] - Mostrar aluno\n[3] - Sair\n");
        scanf(" %i", &op);
        fflush(stdin);
        switch(op){
            case 1:
            mostra_turma(ptur, 6);
            aloca_aluno(&palu, cont+1);
            matricula_aluno(palu+cont, ptur, 6);
            cont++;
            break;
            case 2:
            mostra_aluno(palu, ptur, cont);
            break;
            case 3:
            printf("\nSaindo...");
            break;
            default:
            printf("\nOpcao invalida");
            break;
        }

    }while(op != 3);


    return 0;
}

void aloca_turma(turma **pt, int q){
    if((*pt = (turma *)realloc(*pt, q*sizeof(turma))) == NULL){
        printf("\nErro na alocacao de turma");
        exit(1);
    }
}// aloca turma

void aloca_aluno(aluno **pa, int q){
    if((*pa = (aluno *)realloc(*pa, q*sizeof(aluno))) == NULL){
        printf("\nErro na alocacao de aluno");
        exit(1);
    }
}// aloca aluno

void cadastra_turma(turma *pt, int q){
    for(int i = 0; i<q; i++){
        (pt+i)->reg = i+1;
        (pt+i)->qtd = 0;
        if(i<2)
            {(pt+i)->tipo = 'B';
            (pt+i)->valor = 250;
        }
        else if(i<4){
            (pt+i)->tipo = 'I';
            (pt+i)->valor = 300;
        }
        else{
            (pt+i)->tipo = 'A';
            (pt+i)->valor = 350;
        }
    }
}// cadastra turma

void mostra_turma(turma *pt, int q){
    for(int i = 0; i<q; i++){
        printf("\nTurma de registro : %i\nNivel da turma: %c\nValor da mensalidade: %.2f\nQuantidade de alunos: %i\n", (pt+i)->reg, (pt+i)->tipo, (pt+i)->valor, (pt+i)->qtd);
    }
}// mostra turma

void matricula_aluno(aluno *pa, turma *pt, int q){
    char cat;
    int pos;

    printf("\nDigite a categoria desejada (B, I ou A): ");
    scanf(" %c", &cat);
    fflush(stdin);
    pos = busca_turma(pt, cat, q);
    if(pos == -1)
        printf("\nNao ha vagas disponiveis para a categoria %c", cat);
    else{
        printf("\nO aluno participara da turma: %i", pos+1);
        printf("\nDigite o nome do aluno: ");
        gets(pa->nome);
        fflush(stdin);
        pa->numt = pos;
        printf("Digite o RA do aluno: ");
        gets(pa->RA);
        fflush(stdin);
        (pt+pos)->qtd += 1;
        printf("\nAluno matriculado com sucesso!!\n");
        system("pause");
    }
}// matricula aluno

int busca_turma(turma *pt, char cat, int q){
    for(int i = 0; i<q; i++){
        if((pt+i)->tipo == toupper(cat) && (pt+i)->qtd < 20){
            return i;
        }
    }
    return -1;
}//busca turma

void mostra_aluno(aluno *pa, turma *pt, int q){

    for(int i = 0; i<q; i++){
        printf("\nNome: %s\nRA: %s\nTurma: %i\n", (pa+i)->nome, (pa+i)->RA, (pa+i)->numt+1);
    }
    system("pause");
}// busca turma
