#include <stdlib.h>
#include <stdio.h>
#include "playlist.h"

void inicializarPlaylist(tpPlaylist *playlist){
    playlist->primeira = NULL;
    playlist->ultima = NULL;
    playlist->quantidade = 0;
}

void cadastrarMusicas(tpPlaylist *playlist){
    tpMusica *novo = malloc(sizeof(tpMusica));

    printf("Digite o titulo da musica: ");
    fflush(stdin);
    gets(novo->titulo);

    printf("Digite o artista: ");
    fflush(stdin);
    gets(novo->artista);

    printf("Digite a duracao da musica: ");
    scanf("%f", &novo->duracao);

    if (playlist->primeira == NULL)
    {
        playlist->primeira = novo;
        playlist->ultima = novo;
        novo->proxima = novo;
        novo->anterior = novo;
    } else
    {
        novo->anterior = playlist->ultima;
        novo->proxima = playlist->primeira;
        playlist->ultima->proxima = novo;
        playlist->primeira->anterior = novo;
        playlist->ultima = novo;
    }
    playlist->quantidade++;
    novo->id = playlist->quantidade;
}

void tocarMusicas(tpPlaylist *playlist){
    if (playlist->primeira == NULL)
    {
        printf("A playlist de musica esta vazia.\n");
        return;
    }

    float tempoTotal;
    float tempoAtual = 0;
    tpMusica *temp = playlist->primeira;

    printf("Digite por quanto tempo gostaria de reproduzir as musicas: ");
    scanf("%f", &tempoTotal);

    while (tempoAtual < tempoTotal)
    {
        printf("\nMusica [%d]\n", temp->id);
        printf("Titulo: %s\n", temp->titulo);
        printf("Artista: %s\n", temp->artista);
        printf("Duracao: %.2f\n", temp->duracao);
        printf("Tempo acumulado: %.2f minutos\n", tempoAtual);

        tempoAtual += temp->duracao;

        temp = temp->proxima;
    }
    printf("Tempo total alcançado: %.2f minutos\n", tempoAtual);
}