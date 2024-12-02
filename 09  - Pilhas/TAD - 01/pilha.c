#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void inicializaPilha(tpPilha *pilha){
    pilha->topo = NULL;
}

void inserirNaPilha (tpPilha *pilha){
    tpNo *novo = malloc(sizeof(tpNo));

    printf("Digite o Nome do Planeta: ");
    fflush(stdin);
    gets(novo->planeta);

    novo->prox = pilha->topo;
    pilha->topo = novo;
}

void removerDaPilha(tpPilha *pilha){
    if (pilha->topo == NULL)
    {
        printf("A pilha esta vazia.\n");
        return;
    }
    
    tpNo *temp = pilha->topo;
    pilha->topo = pilha->topo->prox;

    printf("Removendo: %s\n", temp->planeta);
    free(temp);
}

void exibirrTopoPilha(tpPilha *pilha){
    if (pilha->topo == NULL)
    {
        printf("A pilha esta vazia.\n");
        return;
    }

    printf("O topo da pilha e o planeta: %s\n", pilha->topo->planeta);
}

void exibirTodaPilha(tpPilha *pilha){
    if (pilha->topo == NULL)
    {
        printf("A pilha esta vazia.\n");
        return;
    }

    while (pilha->topo != NULL)
    {
        exibirrTopoPilha(pilha);
        removerDaPilha(pilha);
    }
}