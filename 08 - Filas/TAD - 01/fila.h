#include <stdio.h>
#include <stdlib.h>


typedef struct itemFila
{
    char nome[100];
    char cpf[15];
    struct itemFila *proximo;
}tpItem;

typedef struct 
{
    tpItem *primeiro;
    tpItem *ultimo;
    int quantidade; 
}tpFila;


void inicializarFila(tpFila *fila);
void adicionarPessoaFila(tpFila *fila);
void removerPessoaFila(tpFila *fila);
void exibirQuantidade(tpFila *fila);