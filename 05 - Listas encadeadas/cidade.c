#include <stdio.h>
#include <stdlib.h>
#include "cidade.h"

void criarCidade(tpCidade *cidade){
    printf("Digite o nome da cidade: ");
    fflush(stdin);
    gets(cidade->nomeCidade);

    printf("Valor da hospedagem: ");
    scanf("%f",&cidade->valor);
}

