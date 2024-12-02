typedef struct carro
{
    char placa[6];
    struct carro *proximo;
}tpCarro;

typedef struct fila
{
    tpCarro *primeiro;
    tpCarro *ultimo;
    int quantidade;
}tpFila;


void inicializarFila(tpFila *fila);
void inserirCarrosSemaforo(tpFila *fila);
void removerCarrosSemaforo(tpFila *fila);
void controleSemaforo(tpFila *fila);
