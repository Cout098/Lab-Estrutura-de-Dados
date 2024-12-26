#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main(){
    tpLista *lista = malloc(sizeof(tpLista));
    int escolha;
    iniciarLista(lista);
    
    do {
        printf("\n Menu \n");
        printf("1. Inserir cidade\n");
        printf("2. Remover cidade\n");
        printf("3. Trocar cidades\n");
        printf("4. Editar cidade\n");
        printf("5. Listar cidades\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                inserirItemLista(lista);
                break;
            case 2:
                removerCidade(lista);
                break;
            case 3:
                trocarOrdemCidades(lista);
                break;
            case 4:
                editarCidade(lista);
                break;
            case 5:
                imprimirLista(lista);
                break;
            case 6:
                printf("Saindo do programa...\n");
                exit(0);
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (1);
    
    free(lista);
    return 0;
}