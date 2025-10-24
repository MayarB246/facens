#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int reg, qmilitar;
    float salario;
    char org[20], patente[20]; 
}carreira;

typedef struct{
    char CPF[13], nome[20];
    int numreg;
}militar;

void alocap(carreira **pc, int tam);
void alocam(militar **pm, int tam);
void cadastrap(carreira *pc, int tam);
void cadastram(militar *pm, carreira *pc, int tam);
void M(char *p);
int busca_pat(carreira *pc, int qc, char *aux_pat, char *aux_org);
int busca_CPF(militar *pm, int qm, char *aux_CPF);
void troca_pat(militar *pm, int qm, carreira *pc, int qc);
void mostra_pat(carreira *pc, int tam);

int main(){
    carreira *pcar=NULL;
    militar *pmil=NULL;
    int op, cont=0;
    alocap(&pcar, 5);
    cadastrap(pcar, 5);

    do{
    system("cls");
    printf("\n[1] - Cadastro Militar\n[2] - Troca Patente\n[3] - Mostra Patente\n[4] - Sair");
    scanf("%i", &op);
    fflush(stdin);

    switch(op){
        case 1:
        alocam(&pmil, cont+1);
        cadastram(pmil, pcar, cont);
        cont++;
        break;
        case 3:
        mostra_pat(pcar, 5);
        case 4:
        printf("SAINDO...");
        break;
    };
    
    }while(op!=4);

    return 0;
}

void alocap(carreira **pc, int tam){
    if((*pc=(carreira*)realloc(*pc, tam*sizeof(carreira)))==NULL){
        exit(1);  
    }
}

void alocam(militar **pm, int tam){
    if((*pm=(militar*)realloc(*pm, tam*sizeof(militar)))==NULL){
        exit(1);
    }
}

void cadastrap(carreira *pc, int tam){
    for(int i=0;i<tam; i++, pc++){
        pc->reg=i+1;
        pc->qmilitar=0;
        printf("Digite a organizacao: Exercito/Aeronautica/Marinha");
        gets(pc->org);
        fflush(stdin);
        M(pc->org);
        printf("Digite a patente:");
        gets(pc->patente);
        fflush(stdin);
        M(pc->patente);
        printf("Digite o salario: ");
        scanf("%f", pc->salario);
    }
}

void cadastram(militar *pm, carreira *pc, int tam){
    char aux_org[20], aux_pat[20];
    printf("Digite seu CPF: ");
    gets(pm->CPF);
    fflush(stdin);
    printf("Nome: ");
    gets(pm->nome);
    fflush(stdin);
    printf("Digite a organizacao: Exercito/Aeronautica/Marinha");
    gets(aux_org);
    fflush(stdin);
    M(aux_org);
    printf("Digite a patente:");
    gets(aux_pat);
    fflush(stdin);
    M(aux_pat);
    pm->numreg = busca_pat(pc, 5, aux_pat, aux_org);

    if(pm->numreg == -1){
        printf("Organizacao e Patente invalidos!\n");
    }
    else{
        printf("Militar cadastrado com sucesso - salario: R$ %.2f\n", (pc+(pm->numreg)-1)->salario);
    }
    system("pause");
}

int busca_pat(carreira *pc, int qc, char *aux_pat, char *aux_org){
    for(int i=0;i<qc;i++,pc++){
        if(strcmp(pc->org, aux_org)==0 && strcmp(pc->patente, aux_pat)==0){
            pc->qmilitar++;
            return (pc->reg);
        }
    }
    return -1;
}

int busca_CPF(militar *pm, int qm, char *aux_CPF){
    for(int i=0;i<qm;i++,pm++){
        if(strcmp(pm->CPF,aux_CPF)==0){
            return i;
        }
    }
    return -1;
}

void M(char *p){
    int x;
    x=strlen(p);
    for(int i = 0;i<x;i++, p++){
        if(*p>='a' && *p<='z'){
            *p-=32;
        }
    }
}

void troca_pat(militar *pm, int qm, carreira *pc, int qc){
    char aux_cpf[13], aux_org[20], aux_pat[20];
    int pos;
    printf("Digite o cpf: ");
    gets(aux_cpf);
    fflush(stdin);
    pos=busca_CPF(pm, qm, aux_cpf);
    if(pos=-1){
        printf("CPF inexistente!\n");
    }
    else{
        printf("Nome: %s\nOrganizacao atual: %s\nPatente atual: %s\n", (pm+pos)->nome, ((pc+(pm+pos)->numreg)-1)->org, ((pc+(pm+pos)->numreg)-1)->patente);
        ((pc+(pm+pos)->numreg)-1)->qmilitar--;
        printf("Digite a nova organizacao: Exercito/Aeronautica/Marinha");
        gets(aux_org);
        fflush(stdin);
        M(aux_org);
        printf("Digite a nova patente:");
        gets(aux_pat);
        fflush(stdin);
        M(aux_pat);

        (pm+pos)->numreg = busca_pat(pc, 5, aux_pat, aux_org);

        if((pm+pos)->numreg == -1){
            printf("Organizacao e Patente invalidos!\n");
        }
        else{
            printf("Militar cadastrado com sucesso - salario: R$ %.2f\n", (pc+((pm+pos)->numreg)-1)->salario);
        }
        system("pause");
        }
}

void mostra_pat(carreira *pc, int tam){
    for(int i=0;i<tam;i++, pc++){
        printf("");
    }
}