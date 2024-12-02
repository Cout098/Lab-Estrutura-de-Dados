#include "no.h"

typedef struct pilha
{
    tpNo *topo;
}tpPilha;

void inicializarPilha(tpPilha *pilha);
void comprarLivro(tpPilha *pilha);
void exibirLivroTopo(tpPilha *pilha);
void livroLido(tpPilha *pilha);