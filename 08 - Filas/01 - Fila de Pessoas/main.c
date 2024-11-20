#include <stdio.h>
#include <stdlib.h>


typedef struct pessoa{
    char nome[60];
    char cpf[11];
} tipoPessoa;

typedef struct itemFila
{
    tipoPessoa *pessoa;
    struct itemFila *proximo;
}tipoItem;

typedef struct 
{
    tipoItem *primeiro;
    tipoItem *ultimo;
    int quantidade; 
}tipoFila;

void cadastrarPessoa(tipoItem *novo){
    novo->pessoa = malloc(sizeof(tipoPessoa));
    
    printf("Escreva o nome: ");
    fflush(stdin);
    gets(novo->pessoa->nome);

    printf("Digite o CPF: ");
    fflush(stdin);
    gets(novo->pessoa->nome);
}

void inicializaFila(tipoFila *fila){

    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->quantidade = 0;
}

void inserirNaFila(tipoFila *fila){
    tipoItem *novo = malloc(sizeof(tipoItem));

    cadastrarPessoa(novo);


    fila->quantidade++;


}