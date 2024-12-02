#include <stdlib.h>
#include <stdio.h>
#include "playlist.h"


int main() {
    tpPlaylist playlist;
    inicializarPlaylist(&playlist);

    int opc;

    do {
        printf("\n MENU \n");
        printf("1. Cadastrar musica\n");
        printf("2. Tocar musicas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                cadastrarMusicas(&playlist);
                break;
            case 2:
                tocarMusicas(&playlist);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
        
    } while (opc != 0);

    return 0;
}