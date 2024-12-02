#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main() {
    tpFila fila;
    inicializarFila(&fila);

    int opc;

    do {
        controleSemaforo(&fila);
        printf("\nMenu do Semaforo:\n");
        printf("1. Adicionar carro na fila\n2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                inserirCarrosSemaforo(&fila);
                break;
            case 2:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opc != 3);

    return 0;
}
