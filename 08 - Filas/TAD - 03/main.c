#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#define TAM 12

const char *listaPrograma[TAM] = {
        "Chrome", "Firefox", "Word", "Excel", 
        "PowerPoint", "Photoshop", "CorelDraw", "Evernote", 
        "Spotify", "Premiere", "AutoCad", "uTorrent"
};

void exibirMenu(){
    printf("\nMenu de Programas\n");

    for (int i = 0; i < TAM; i++)
    {
        printf("[%d] - %s\n", i+1, listaPrograma[i]);
    }
    printf("0 - Executar programas manualmente\n");
    printf("13 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main(){
    tpFila fila;
    inicializarFila(&fila);

    int opc;

    do
    {
        exibirMenu();
        scanf("%d", &opc);

        if (opc == 13)
        {
            printf("Saindo...\n");
            break;
        } else if (opc == 0) {
            executarFila(&fila);
        } else if (opc >=1 && opc <= TAM){
            inserirProgramaFila(&fila, (char *)listaPrograma[opc-1]); //tive que pesquisar sobre o uso de cast, revisar isso já que o conceito nao foi bem absorvido.
            executarFilaAutomatica(&fila);
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }
        
    } while (1);
    
    return 0;
}