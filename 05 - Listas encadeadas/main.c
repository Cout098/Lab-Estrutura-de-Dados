#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main(){
    tpLista *lista = malloc(sizeof(tpLista));
    iniciarLista(lista);

    inserirItemLista(lista);
    inserirItemLista(lista);
    inserirItemLista(lista);

    trocarOrdemCidades(lista);

    imprimirLista(lista);

    free(lista);
    return 0;
}