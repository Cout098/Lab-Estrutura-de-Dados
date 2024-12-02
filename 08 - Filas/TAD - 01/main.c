#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    tpFila fila;
    inicializarFila(&fila);

    int opc;

    do {
        printf("\n--- Gerenciador de Fila ---\n");
        printf("1. Inserir pessoa na fila\n2. Remover pessoa da fila\n3. Exibir quantidade de pessoas\n4. Sair\nEscolha uma opção: ");
        scanf("%d", &opc);
        getchar(); 

        switch (opc) {
        case 1:
            adicionarPessoaFila(&fila);
            break;
        case 2:
            removerPessoaFila(&fila);
            break;
        case 3:
            exibirQuantidade(&fila);
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opc != 4);

    return 0;
}
