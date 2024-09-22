#include <stdio.h>
#include <stdlib.h>
#include "video.h"

void inicializar(tp_gerenciador *gerenciador){
    gerenciador->quantidade = 0;
}

void menu(tp_gerenciador *gerenciador){
    int opc;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar vídeo\n");
        printf("2. Exibir vídeos cadastrados\n");
        printf("3. Exibir duração total dos vídeos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                cadastrarVideo(gerenciador);
                break;
            case 2:
                exibirVideos(gerenciador);
                break;
            case 3:
                exibirDuracaoTotal(gerenciador);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while(opc != 4);
}


void cadastrarVideo(tp_gerenciador *gerenciador){

    if (gerenciador->quantidade >= TAM_MAX)
    {
        printf("Quantidade maxima atingida!\n");
        return;
    }
    
    tp_video *video = &gerenciador->video[gerenciador->quantidade];
    
    video->id = gerenciador->quantidade + 1;

    printf("Nome:");
    fflush(stdin);
    gets(video->nome);
    printf("Duracao: ");
    scanf("%d", &video->duracao);

    gerenciador->quantidade++;

    printf("Video cadastrado\n");
}

void exibirVideos(tp_gerenciador *gerenciador){
    if (gerenciador->quantidade == 0)
    {
        printf("Nao existem videos cadastrados!!");
        return;
    }

    for (int i = 0; i < gerenciador->quantidade; i++)
    {
        printf("Video %d\n", i+1);
        printf("ID: %d\n", gerenciador->video[i].id);
        printf("Nome: %s\n", gerenciador->video[i].nome);
        printf("Duracao: %d\n", gerenciador->video[i].duracao);
    }
}

void exibirDuracaoTotal(tp_gerenciador *gerenciador){
    int soma = 0;
    for (int i = 0; i < gerenciador->quantidade; i++)
    {
        soma += gerenciador->video[i].duracao;
    }

    printf("A duracao total dos videos e: %d minutos\n", soma);
}
