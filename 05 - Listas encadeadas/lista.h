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

void iniciarLista(tpLista *lista);
void inserirItemLista(tpLista *lista);
tpItemLista *retornaItemDaLista(tpLista *lista, char *nome);
tpItemLista *retornaItemAnterior(tpLista *lista, char *nome);
void removerCidade(tpLista *lista);
tpItemLista *buscaDeCidades(tpLista *lista);
void trocarOrdemCidades(tpLista *lista);
void editarCidade(tpLista *lista);
void imprimirLista(tpLista *lista);