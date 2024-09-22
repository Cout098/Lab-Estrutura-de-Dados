
typedef struct item
{
    int id;
    char nome[100];
    float valor;
    struct item *prox;
}tpItem;

typedef struct lista
{
    tpItem *primeiroItem; //aponta para o primeiro item da lista
    int contador;
}tpLista;


tpLista* criarlista();
tpItem* criarItem(tpLista *lista);
void adicionarFinal(tpLista *lista);
void adicionarInicio(tpLista *lista);
void removerItem(tpLista *lista, char nome[]);
void exibirLista(tpLista *lista);
void exibirSoma(tpLista *lista);
void menu(tpLista *lista);