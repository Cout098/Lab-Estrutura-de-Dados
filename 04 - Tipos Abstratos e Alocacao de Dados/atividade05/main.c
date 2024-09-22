#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(){
    tpLista *lista = criarlista();
    
    menu(lista);

    return 0;
}