#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"


void inicializaPilha(tpPilha *pilha){
    pilha->topo = -1; //para informar que a pilha ta vazia.
}

void adicionarPrograma(tpPilha *pilha){
    if (pilha->topo == TAM -1)
    {
        printf("A pilha de programas ja esta cheia.\n");
        return;
    }
    
    pilha->topo++;

    printf("Digite o nome do programa:");
    gets(pilha->programa[pilha->topo]);
}

void executarPrograma(tpPilha *pilha){
    if (pilha->topo == -1)
    {
        printf("A pilha de programas esta vazia.\n");
        return;
    }
    
    while (pilha->topo != -1)
    {
        printf("Executando: %s\n", pilha->programa[pilha->topo]);
        pilha->topo--;
    }
}