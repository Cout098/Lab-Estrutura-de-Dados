#include <stdio.h>
#include <stdlib.h>
#include "serie.h"

// Inicializa a lista
void inicializarLista(Lista *lista) {
    lista->cabeca = NULL;
    lista->cauda = NULL;
    lista->total = 0;
}

// Cadastra um novo episódio
void cadastrarEpisodio(Lista *lista, const char *titulo) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) {
        printf("Erro ao alocar memória para o nó.\n");
        exit(1);
    }

    inicializarEpisodio(&novo->episodio, lista->total + 1, titulo);
    novo->anterior = lista->cauda;
    novo->proximo = NULL;

    if (lista->cauda) {
        lista->cauda->proximo = novo;
    } else {
        lista->cabeca = novo; // Primeiro nó
    }

    lista->cauda = novo; // Atualiza a cauda
    lista->total++;
    printf("Episódio %d cadastrado: %s\n", novo->episodio.numero, titulo);
}

// Remove o último episódio
void removerUltimoEpisodio(Lista *lista) {
    if (!lista->cauda) {
        printf("Nenhum episódio para remover.\n");
        return;
    }

    No *remover = lista->cauda;
    if (remover->anterior) {
        remover->anterior->proximo = NULL;
    } else {
        lista->cabeca = NULL; // Lista ficou vazia
    }

    lista->cauda = remover->anterior;
    liberarEpisodio(&remover->episodio);
    free(remover);
    lista->total--;

    printf("Último episódio removido com sucesso.\n");
}

// Exibe os episódios com navegação
void exibirSerie(Lista *lista) {
    if (!lista->cabeca) {
        printf("Nenhum episódio cadastrado.\n");
        return;
    }

    No *atual = lista->cabeca;
    char opcao;

    while (1) {
        printf("\nEpisódio %d: %s\n", atual->episodio.numero, atual->episodio.titulo);
        printf("Opções: [N] Próximo, [A] Anterior, [S] Sair: ");
        scanf(" %c", &opcao);

        if (opcao == 'N' || opcao == 'n') {
            if (atual->proximo) {
                atual = atual->proximo;
            } else {
                printf("Este é o último episódio.\n");
            }
        } else if (opcao == 'A' || opcao == 'a') {
            if (atual->anterior) {
                atual = atual->anterior;
            } else {
                printf("Este é o primeiro episódio.\n");
            }
        } else if (opcao == 'S' || opcao == 's') {
            break;
        } else {
            printf("Opção inválida.\n");
        }
    }
}

// Libera a memória da lista
void liberarLista(Lista *lista) {
    No *atual = lista->cabeca;
    while (atual) {
        No *remover = atual;
        atual = atual->proximo;

        liberarEpisodio(&remover->episodio);
        free(remover);
    }

    lista->cabeca = NULL;
    lista->cauda = NULL;
    lista->total = 0;
}
