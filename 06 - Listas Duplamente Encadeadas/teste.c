#include <stdio.h>
#include <stdlib.h>


typedef struct ep
{
    int numeroEpisodio;
    char titulo[50];
} tipoEpisodio;

typedef struct itemDaLista{
    tipoEpisodio episodio;
    tipoEpisodio *proximo;
    tipoEpisodio *anterior;
} tipoItem;

typedef struct listaDupla
{
    tipoItem *primeiro;
    tipoItem *ultimo;

    int quantidade;

} tipoLista;

void iniciarLista(tipoLista *lista){
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->quantidade = 0;
}

void cadastrarEpisodio(tipoLista *lista){
    tipoItem *novo = malloc(sizeof(tipoItem));

    printf("Digite o titulo do ep: ");
    fflush(stdin);
    gets(novo->episodio.titulo);
}


void removerEpisodio(tipoLista *lista){

}

void exibirSerie(tipoLista *lista){
}