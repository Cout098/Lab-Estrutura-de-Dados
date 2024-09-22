#include <stdio.h>
#include <stdlib.h>
//#include "canal.h"

typedef struct video{
    int id;
    char titulo[100];
    int vizualizacao;
    struct video *proximo;
}tpVideo;

typedef struct canal {
    int id;
    char titulo[100];
    char descricao[256];
    char proprietario[100];
    int qntInscritos;
    tpVideo *primeiro;
}tpCanal;

tpCanal* criarCanal(){
    tpCanal *canal = malloc(sizeof(tpCanal));

    canal->id = 1;
    canal->qntInscritos = 0;
    canal->primeiro = NULL;

    printf("Titulo: ");
    gets(canal->titulo);
    printf("Descricao: ");
    gets(canal->descricao);
    printf("Proprietario: ");
    gets(canal->proprietario);
    
    return canal;
}

tpVideo* criarVideo(tpCanal *canal){
    tpVideo *videoNovo = malloc(sizeof(tpVideo));

    videoNovo->id = canal->id++;
    videoNovo->vizualizacao = 0;
    videoNovo->proximo = NULL;

    printf("Titulo: ");
    gets(videoNovo->titulo);

    return videoNovo;
}

void inserirVideo(tpCanal *canal){

    tpVideo *novoVideo = criarVideo(canal);

    if (canal->primeiro == NULL)
    {
        canal->primeiro = novoVideo;
    }
    else
    {
        tpVideo *videoAtual = canal->primeiro;

        while (videoAtual->proximo != NULL)
        {
            videoAtual = videoAtual->proximo;
        }
        
        videoAtual->proximo = novoVideo;
    }
    
}

void assistirVideo(tpCanal *canal){
    int busca;
    tpVideo *videoAtual = canal->primeiro;

    printf("Digite o id do video: ");
    scanf("%d", &busca);

    while (videoAtual != NULL && videoAtual->id != busca)
    {
        videoAtual = videoAtual->proximo;
    }
    
    if (videoAtual == NULL)
    {
        printf("Video nao encontrado\n");
        return;
    }
    
    videoAtual->vizualizacao++;
}

void exibirInformacoes(tpCanal *canal){
    if (canal == NULL)
    {
        printf("O canal nao foi criado\n");
        return;
    }else
    {
        printf("Canal: %s\n", canal->titulo);
        printf("Descricao: %s\n", canal->descricao);
        printf("Propritario: %s\n", canal->proprietario);
        printf("Quantidade de inscritos %d\n", canal->qntInscritos);

        if (canal->primeiro == NULL)
        {
            printf("O canal nao possui videos!\n");
            return;
        }else
        {
            tpVideo *videoAtual = canal->primeiro;

            while (videoAtual != NULL)
            {
                printf("ID: %d\nTitulo: %s\nVisualizacao: %d\n", videoAtual->id, videoAtual->titulo, videoAtual->vizualizacao);
                videoAtual = videoAtual->proximo;
            }
        }

    }

}


void menu(tpCanal *canal){
    int opc;

    do
    {
        printf("\nMenu:\n");
        printf("[1] - Inserir vídeos\n");
        printf("[2] - Assistir Video\n");
        printf("[3] - Exibir o canal completo\n");
        printf("[0] - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);
        fflush(stdin);

        switch (opc) {
            case 1:
                inserirVideo(canal);
                break;
            case 2:
                assistirVideo(canal);
                break;
            case 3:
                exibirInformacoes(canal);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opc != 0);
    
}


int main(){
    tpCanal *canal = criarCanal();

    menu(canal);
    
    return 0;
}