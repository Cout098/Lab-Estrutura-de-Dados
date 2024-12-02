#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main() {
    tpPilha pilha;
    inicializaPilha(&pilha);

    int opc;
    char planeta[50];
    do {
        printf("\n1. Inserir na pilha\n2. Remover da pilha\n3. Exibir topo da pilha\n4. Exibir toda a pilha\n5. Sair\nEscolha uma opcao: ");
        scanf("%d", &opc);
        getchar();

        switch (opc) {
        case 1:
            inserirNaPilha(&pilha);
            break;
        case 2:
            removerDaPilha(&pilha);
            break;
        case 3:
            exibirrTopoPilha(&pilha);
            break;
        case 4:
            exibirTodaPilha(&pilha);
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opc != 5);

    return 0;
}
