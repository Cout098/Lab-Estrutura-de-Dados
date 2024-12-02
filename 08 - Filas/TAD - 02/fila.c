#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializarFila(tpFila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->quantidade = 0;
}

void inserirCarrosSemaforo(tpFila *fila){
    tpCarro *novo = malloc(sizeof(tpCarro));

    printf("Digite a placa do veiculo: ");
    fflush(stdin);
    gets(novo->placa);


    if (fila->primeiro == NULL)
    {
        fila->primeiro = novo;
        fila->ultimo = novo;
    } else {
        fila->ultimo->proximo = novo;
        fila->ultimo = novo;
    }

    fila->quantidade++;

    printf("O Carro com a placa '%s' adicionado com sucesso.\n", novo->placa);
}

void removerCarrosSemaforo(tpFila *fila){
    if (fila->primeiro == NULL)
    {
        printf("A fila do semaforo esta vazia.\n");
        return;
    }

    tpCarro *temp = fila->primeiro;
    printf("\nSemaforo aberto: carro com a placa %s liberado.\n", fila->primeiro->placa);

    fila->primeiro = fila->primeiro->proximo;

    if (fila->primeiro == NULL)
    {
        fila->ultimo = NULL;
    }

    free(temp);

    fila->quantidade--;
}

void controleSemaforo(tpFila *fila){
    if (fila->quantidade < 5)
    {
        printf("\nSemaforo fechado: apenas %d carros na fila.\n", fila->quantidade);
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        removerCarrosSemaforo(fila);
    }

    printf("\nTodos os carros liberados!\n");
    printf("Semaforo fechado novamente!\n");
}