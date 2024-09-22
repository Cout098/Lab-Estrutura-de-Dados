#include <stdio.h>
#include <stdlib.h>
#define  NUM_MAX 2

typedef struct 
{
    char nomeFantasia[60];
    char razaoSocial[60];
    char cnpj[22];
}tpEmpresa;

void cadastrarEmpresa(tpEmpresa *vetor){
    for (int i = 0; i < NUM_MAX; i++)
    {
        printf("Nome: ");
        gets(vetor[i].nomeFantasia);
        fflush(stdin);
        printf("Razao Social: ");
        gets(vetor[i].razaoSocial);
        printf("CNPJ: ");
        gets(vetor[i].cnpj);
    }
}

void exibirEmpresa(tpEmpresa *vetor){
     for (int i = 0; i < NUM_MAX; i++)
    {
        printf("\nNome: %s", vetor[i].nomeFantasia);
        printf("\nRazao Social: %s", vetor[i].razaoSocial);
        printf("\nCNPJ: %s", vetor[i].cnpj);
    }
}

int main(){ 
    tpEmpresa *vetor;

    vetor = malloc(NUM_MAX * sizeof(tpEmpresa));

    cadastrarEmpresa(vetor);
    exibirEmpresa(vetor);

    free(vetor);
    return 0;
}

