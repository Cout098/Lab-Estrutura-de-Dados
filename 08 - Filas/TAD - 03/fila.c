#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"


void inicializarFila(tpFila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->quantidade = 0;
}

void inserirProgramaFila(tpFila *fila, char *programa){
    tpNo *novo = malloc(sizeof(tpNo));

    strcpy(novo->programa, programa);

    if (fila->primeiro == NULL)
    {
        fila->primeiro = novo;
        fila->ultimo = novo;
    }

    fila->ultimo->proximo = novo;
    fila->ultimo = novo;

    fila->quantidade++;
}

void removerProgramaFila(tpFila *fila){
    if (fila->primeiro == NULL)
    {
        printf("Nenhum programa na fila para executar.\n");
        return;
    }

    tpNo *temp = fila->primeiro;
    printf("Executando programa: %s\n", temp->programa);

    fila->primeiro = fila->primeiro->proximo;

    if (fila->primeiro == NULL)
    {
        fila->ultimo = NULL;
    }
    
    free(temp);
    fila->quantidade--;
}

void executarFila(tpFila *fila){
    if (fila->quantidade == 0) {
        printf("Nenhum programa para executar.\n");
        return;
    }

    printf("Executando programas da fila...\n");
    while (fila->quantidade > 0) {
        removerProgramaFila(fila);
    }
}

void executarFilaAutomatica(tpFila *fila){
    if (fila->quantidade >= 3)
    {
        printf("Fila cheia. Executando programas...\n");
        executarFila(fila);
    }
}