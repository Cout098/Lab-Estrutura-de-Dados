#include "cidade.h"

typedef struct item
{
    int ordem;
    tpCidade *cidade;
    struct item *proximo;
}tpItemLista;

typedef struct lista
{
    int quantidade;
    tpItemLista *primeiro;
    tpItemLista *ultimo;
    
}tpLista;
