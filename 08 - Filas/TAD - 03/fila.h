#include "no.h"

typedef struct fila
{
    tpNo *primeiro;
    tpNo *ultimo;
    int quantidade;
}tpFila;


void inicializarFila(tpFila *fila);
void inserirProgramaFila(tpFila *fila, char *programa);
void removerProgramaFila(tpFila *fila);
void executarFila(tpFila *fila);
void executarFilaAutomatica(tpFila *fila);
