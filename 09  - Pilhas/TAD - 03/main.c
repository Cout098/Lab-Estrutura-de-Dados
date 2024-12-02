#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main() {
    tpPilha pilha;
    inicializarPilha(&pilha);

    int opc;
    char titulo[100];

    do {
        printf("\n--- Gerenciador de Livros da Maria ---\n");
        exibirLivroTopo(&pilha);
        printf("\n1. Adicionar Livro Comprado\n2. Doar Livro\n3. Sair\nEscolha uma opção: ");
        scanf("%d", &opc);
        getchar(); // Limpa o buffer do teclado

        switch (opc) {
        case 1:
            comprarLivro(&pilha);
            break;
        case 2:
            livroLido(&pilha);
            break;
        case 3:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opc != 3);

    return 0;
}



