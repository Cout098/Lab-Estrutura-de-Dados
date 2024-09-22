#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
}tpData;

typedef struct 
{
    int numero;
    tpData data;
    char texto[256];
}tpMensagens;

typedef struct 
{
    tpMensagens *mensagem;
    int contador;
    int qntUsuario;
}tpControlador;


//Inicializar o controlador e os contadores;
void inicializarControlador(tpControlador *controlador, int capacidade){
    controlador->mensagem = malloc(capacidade * sizeof(tpMensagens));
    if (controlador->mensagem == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    controlador->contador = 0;
    controlador->qntUsuario = capacidade;
}

void enviarMensagem(tpControlador *controlador){

    if (controlador->contador >= controlador->qntUsuario)
    {
        printf("Quantidade maxima atingida\n");
        return;
    }

    tpMensagens *m = &controlador->mensagem[controlador->contador];

    printf("Numero do destinatario: ");
    scanf("%d", &m->numero);
    
    printf("Hora de envio (HH:MM):\n");
    printf("Horas: ");
    scanf("%d", &m->data.hora);
    printf("Minutos: ");
    scanf("%d",&m->data.minuto);

    printf("Data do envio (DD/MM/AAAA):\n");
    printf("Dia: ");
    scanf("%d", &m->data.dia);
    printf("Mes: ");
    scanf("%d",  &m->data.mes);
    printf("Ano: ");
    scanf("%d", &m->data.ano);
    getchar();

    printf("Digite o texto: ");
    fgets(m->texto, 256, stdin);

    controlador->contador++;

    printf("Mensagem enviada!\n");
}

void exibirMensagens(tpControlador *controlador){
    if (controlador->contador == 0)
    {
        printf("Nenhuma mensagem foi enviada\n");
        return;
    }

    for (int i = 0; i < controlador->contador; i++) {
        tpMensagens *m = &controlador->mensagem[i];
        printf("\nMensagem %d:\n", i + 1);
        printf("Destinatario: %d\n", m->numero);
        printf("Hora de envio: %d:%d\n", m->data.hora, m->data.minuto);
        printf("Data de envio: %d/%d/%d\n", m->data.dia, m->data.mes, m->data.ano);
        printf("Texto: %s\n", m->texto);
        printf("-----------------------\n");
    }
    
}

void menu(tpControlador *controlador){
    int opc;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Enviar nova mensagem\n");
        printf("2. Visualizar mensagens enviadas\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                enviarMensagem(controlador);
                break;
            case 2:
                exibirMensagens(controlador);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opc != 3);
}
void liberarGerenciador(tpControlador *controlador) {
    free(controlador->mensagem);  // Libera a memória alocada para as mensagens
    controlador->mensagem = NULL;
    controlador->contador = 0;
    controlador->qntUsuario = 0;
}

int main(){
    tpControlador controlador;
    int capacidade = 0;

    printf("Qual a quantidade de mensagens:");
    scanf("%d", &capacidade);

    inicializarControlador(&controlador, capacidade);

    menu(&controlador);

    liberarGerenciador(&controlador);

    return 0;
}