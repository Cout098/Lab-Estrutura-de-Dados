#include <stdio.h>
#include <stdlib.h>

typedef struct episodio
{
    char nome[30];
}tipoEpisodio;

typedef struct itemLIsta
{
    int id;
    tipoEpisodio *episodio;
    struct itemLista *proximo;
    struct itemLista *anterior;
}tipoItem;

typedef struct lista
{
    int quantidade;
    tipoItem *cabeca;
    tipoItem *fim;
}tipoLista;

void inicializar(tipoLista *lista){
    lista->quantidade = 0;
    lista->cabeca = NULL;
    lista->fim = NULL;
}

void criarEpisodio(tipoEpisodio *episodio){
    printf("Digite o Titulo o filme: ");
    fflush(stdin);
    gets(episodio->nome);
}

void inserirNovoEpisodio(tipoLista *lista){
    tipoItem *novoItem;
    tipoEpisodio *episodio;

    novoItem = malloc(sizeof(tipoItem));
    episodio = malloc(sizeof(tipoEpisodio));

    criarEpisodio(episodio);

    if(lista->quantidade == 0){
        lista->cabeca = novoItem;
        lista->fim = novoItem;
        novoItem->id = lista->quantidade++;
        novoItem->anterior = NULL;
        novoItem->proximo = NULL;
    } else {
        lista->fim->proximo = novoItem;
        novoItem->anterior = lista->fim;
        lista->fim = novoItem;
        novoItem->id = lista->quantidade++;
    }
}

void removerNovoEpisodio(tipoLista *lista){
    tipoItem *itemAtual;

    if (lista->quantidade == 0)
    {
        printf("A lista esta vazia\n");
    }
    if(lista->quantidade == 1){
        itemAtual = lista->fim;
        free(itemAtual);
        inicializar(lista);
    } else if(lista->quantidade > 1){
        tipoItem *itemRemover;
        itemRemover = lista->fim;
        lista->fim = lista->fim->anterior;
        lista->fim->proximo = NULL;

        free(itemRemover);
    }
}

void imprimeLista(tipoLista *lista){
    tipoItem *itemAtual;
    itemAtual = lista->cabeca;

    while (itemAtual != NULL)
    {
        printf("Id: %d\n", itemAtual->id);
        printf("Titulo: %s", itemAtual->episodio->nome);

        itemAtual = itemAtual->proximo;
    }
}

int main(){
    tipoLista *lista = malloc(sizeof(tipoLista));
    inicializar(lista);

    inserirNovoEpisodio(lista);

    return 0;
}

