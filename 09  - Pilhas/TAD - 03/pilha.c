#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void inicializarPilha(tpPilha *pilha){
    pilha->topo = NULL;
}

void comprarLivro(tpPilha *pilha){
    tpNo *novo = malloc(sizeof(tpNo));

    printf("Digite o titulo do livro: ");
    fflush(stdin);
    gets(novo->titulo);

    novo->proximo = pilha->topo;
    pilha->topo = novo;

    printf("O livro '%s' foi adicionado na pilha.\n", novo->titulo);
}

void exibirLivroTopo(tpPilha *pilha){
    if (pilha->topo == NULL)
    {
        printf("Voce nao esta lendo nenhum livro no momento.\n");
        return;
    }
    
    printf("Voce esta lendo o Livro '%s'.\n", pilha->topo->titulo);
}

void livroLido(tpPilha *pilha){
    if (pilha->topo == NULL) {
        printf("Maria nao tem livros para doar.\n");
        return;
    }

    tpNo *temp = pilha->topo;

    printf("Voce leu e doou o livro: '%s'\n", temp->titulo);

    pilha->topo = pilha->topo->proximo;
    free(temp);
}