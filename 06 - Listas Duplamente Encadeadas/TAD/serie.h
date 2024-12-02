#ifndef SERIE_H
#define SERIE_H

#include "episodio.h"

// Estrutura para um nó da lista
typedef struct No {
    Episodio episodio;
    struct No *anterior;
    struct No *proximo;
} No;

// Estrutura para a lista de episódios
typedef struct {
    No *cabeca;
    No *cauda;
    int total;
} Lista;

// Funções para manipular a lista
void inicializarLista(Lista *lista);
void cadastrarEpisodio(Lista *lista, const char *titulo);
void removerUltimoEpisodio(Lista *lista);
void exibirSerie(Lista *lista);
void liberarLista(Lista *lista);

#endif // SERIE_H
