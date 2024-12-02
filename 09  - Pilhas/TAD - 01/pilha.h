#include <stdlib.h>
#include <string.h>
#include "no.h"

typedef struct pilha
{
    tpNo *topo;
}tpPilha;


void inicializaPilha(tpPilha *pilha);
void inserirNaPilha (tpPilha *pilha);
void removerDaPilha(tpPilha *pilha);
void exibirrTopoPilha(tpPilha *pilha);
void exibirTodaPilha(tpPilha *pilha);