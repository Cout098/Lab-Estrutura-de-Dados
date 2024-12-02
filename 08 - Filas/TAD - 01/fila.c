#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializarFila(tpFila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->quantidade = 0;
}

void adicionarPessoaFila(tpFila *fila){
    tpItem *novo = malloc(sizeof(tpItem));

    printf("Digite o nome da Pessoa: ");
    fflush(stdin);
    gets(novo->nome);

    printf("Digite o CPF da Pessoa, sem pontos ou tracos:");
    fflush(stdin);
    gets(novo->cpf);

    fila->quantidade++;

    if (fila->primeiro == NULL)
    {
        fila->primeiro = novo;
        fila->ultimo = novo;
    } else {
        fila->primeiro->proximo = novo;
        fila->ultimo = novo;
    }

    printf("Pessoa: '%s' adicionada na fila.\n", novo->nome);
}

void removerPessoaFila(tpFila *fila) {
    if (fila->quantidade == 0)
    {
        printf("A fila esta vazia.\n");
        return;
    }

    tpItem *temp = fila->primeiro;
    printf("Voce esta removendo a pessoa '%s' da fila.\n", temp->nome);
    fila->primeiro = fila->primeiro->proximo;

    free(temp);
    fila->quantidade--;

    if (fila->primeiro == NULL)
    {
        fila->ultimo = NULL;
    }
}

void exibirQuantidade(tpFila *fila){
    printf("Tem %d pessoa(as) aguardando na fila.\n", fila->quantidade);    
}