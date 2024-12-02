#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


int main() {
    tpPilha pilha;
    inicializaPilha(&pilha);

    int opc;
    
    do {
        printf("\n1. Adiconar programa\n2. Executar programa\n3. Sair\nEscolha uma opcao: ");
        scanf("%d", &opc);
        getchar(); 
        switch (opc) {
        case 1:
            adicionarPrograma(&pilha);
            break;
        case 2:
            executarPrograma(&pilha);
            break;
        case 3:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opc != 3);

    return 0;
}