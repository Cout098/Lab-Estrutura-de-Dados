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

    while (itemAtual != NULL && itemAtual->proximo != NULL)
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

tpItemLista *buscaDeCidades(tpLista *lista){
    tpItemLista *item;
    char busca[100];

    printf("Digite o nome da cidade:");
    fflush(stdin);
    gets(busca);

    item = retornaItemAnterior(lista, busca);

    return item;
}

void trocarOrdemCidades(tpLista *lista){
    tpItemLista *item1, *item2, *anterior1, *anterior2, *proximo1, *proximo2;
    char busca[100];

    printf("passou");

    if (lista->primeiro == NULL)
    {
        printf("Roteiro Vazio!\n");
        return;
    }

    anterior1 = buscaDeCidades(lista);
    item1 = anterior1->proximo;
    proximo1 = item1->proximo;

    anterior2 = buscaDeCidades(lista);
    item2 = anterior2->proximo;
    proximo2 = item2->proximo;

    anterior1->proximo = item2;
    item2->proximo = proximo1;

    anterior2->proximo = item1;
    item1->proximo = proximo2;
}

void editarCidade(tpLista *lista){
    tpItemLista *item;
    char busca[100];

    printf("Digite o nome da cidade:");
    fflush(stdin);
    gets(busca);

    item = retornaItemDaLista(lista, busca);

    printf("Qual o valor da hospedagem?");
    scanf("%f", &item->cidade->valor);
}

void imprimirLista(tpLista *lista){
    tpItemLista *itemAtual;
    
    itemAtual = lista->primeiro;

    while (itemAtual != NULL)
    {
        printf("Cidade %d\n", itemAtual->ordem);
        printf("Cidade: %s\n", itemAtual->cidade->nomeCidade);
        printf("Valor: %.2f\n",itemAtual->cidade->valor);

        itemAtual = itemAtual->proximo;
    }  

}