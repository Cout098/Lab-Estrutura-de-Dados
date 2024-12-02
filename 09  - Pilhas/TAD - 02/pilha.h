#define TAM 10

typedef struct pilha
{
    char programa[TAM][50];
    int topo;
}tpPilha;


void inicializaPilha(tpPilha *pilha);
void adicionarPrograma(tpPilha *pilha);
void executarPrograma(tpPilha *pilha);
