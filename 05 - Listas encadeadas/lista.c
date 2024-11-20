#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void iniciarLista(tpLista *lista){
    lista->quantidade = 0;
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}

void inserirItemLista(tpLista *lista){
    tpItemLista *novoItemLista;
    tpCidade *novacidade;

    novoItemLista = malloc(sizeof(tpItemLista));
    novacidade = malloc(sizeof(tpCidade));

    novoItemLista->cidade = novacidade;

    criarCidade(novacidade);

    if (lista->quantidade == 0)
    {
        lista->primeiro = novoItemLista;
        lista->ultimo = novoItemLista;
        lista->quantidade++;
    } else {
        lista->ultimo->proximo = novoItemLista;
        lista->ultimo = novoItemLista;
        lista->quantidade++;
    }

    novoItemLista->ordem = lista->quantidade;
}

tpItemLista *retornaItemDaLista(tpLista *lista, char *nome){
    tpItemLista *itemLista, *itemAtual;

    itemLista = NULL;
    itemAtual = lista->primeiro;
    
    for (int i = 0; i < lista->quantidade; i++)
    {
        if(strcmp(itemAtual->cidade->nomeCidade, nome) == 0){
            itemLista = itemAtual;
            break;
        } 
        itemAtual = itemAtual->proximo;
    }
    
    return itemLista;
}

tpItemLista *retornaItemAnterior(tpLista *lista, char *nome){
    tpItemLista *itemLista, *itemAtual;
    
    itemLista = NULL;
    itemAtual = lista->primeiro;
    while (itemAtual != NULL)
    {
        if(strcmp(itemAtual->proximo->cidade->nomeCidade, nome) == 0){
            itemLista = itemAtual;
            break;
        }
        itemAtual = itemAtual->proximo;
    }

    return itemLista;
}

void removerCidade(tpLista *lista){

    if (lista->primeiro == NULL)
    {
        printf("Roteiro Vazio!\n");
        return;
    }
    
    char nomeBuscado[100];
    tpItemLista *itemLista, *anterior;

    printf("Digite o nome da cidade: ");
    fflush(stdin);
    gets(nomeBuscado);

    anterior = retornaItemAnterior(lista, nomeBuscado);
    itemLista = retornaItemDaLista(lista, nomeBuscado);

    if (anterior == NULL) //item buscado é o primeiro da lista.
    {
        if (lista->quantidade == 1)
        {
            printf("Item removido!");
            free(itemLista);

            iniciarLista(lista);
        }else {
            lista->primeiro = itemLista->proximo;
            
            printf("Item removido!");
            free(itemLista);

            lista->quantidade--;
        }
    } else {
        if (itemLista->proximo == NULL)//item a ser removido é o ultimo da lista
        {
            lista->ultimo = anterior;
        }

        anterior->proximo = itemLista->proximo;

        printf("Item removido!");
        free(itemLista);

        lista->quantidade--;
    }
}

void trocarOrdemCidades(tpLista *lista){
    tpItemLista *item1, *item2, *anterior1, *anterior2;
    char nome1[100];
    char nome2[100];

    printf("Digite a 1 cidade: ");
    fflush(stdin);
    gets(nome1);

    printf("Digite a 2 cidade: ");
    fflush(stdin);
    gets(nome2);


    item1 = retornaItemDaLista(lista, nome1);
    anterior1 = retornaItemAnterior(lista, nome1);

    item2 = retornaItemDaLista(lista, nome2);
    anterior2 = retornaItemAnterior(lista, nome2);

    printf("passou, %s %s", item1->cidade, item2->cidade);

    if(item1 == NULL || item2 == NULL){
       
        printf("Uma ou as duas cidades nao foram encontradas.\n");
        return;
    }
    
    if (anterior1 != NULL){
        anterior1->proximo = item2;
    } else {
        lista->primeiro = item2;
    }

    if (anterior2 != NULL){
        anterior2->proximo = item1;
    } else {
        lista->primeiro = item1;
    }
    
    tpItemLista *temp = item1->proximo;
    item1->proximo = item2->proximo;
    item2->proximo = temp;
}

tpItemLista *buscaDeCidades(tpLista *lista){
    tpItemLista *item;
    char busca[100];

    printf("Digite o nome da cidade:");
    fflush(stdin);
    gets(busca);

    item = retornaItemAnterior(lista, busca);

    return item;
}

void editarCidade(tpLista *lista){
    tpItemLista *item;
    char busca[100];

    do
    {
        printf("Digite o nome da cidade:");
        fflush(stdin);
        gets(busca);

        item = retornaItemDaLista(lista, busca);
    } while (item == NULL);
    
    printf("O item a ser editado e: %s\n", item->cidade);

    printf("Qual o valor da hospedagem?");
    scanf("%f", &item->cidade->valor);
}

void imprimirLista(tpLista *lista){
    tpItemLista *itemAtual;
    
    itemAtual = lista->primeiro;

    for (int i = 0; i < lista->quantidade; i++)
    {
        printf("\nOrdem %d\n", itemAtual->ordem);
        printf("Cidade: %s\n", itemAtual->cidade->nomeCidade);
        printf("Valor: %.2f\n",itemAtual->cidade->valor);

        itemAtual = itemAtual->proximo;
    }
      
}