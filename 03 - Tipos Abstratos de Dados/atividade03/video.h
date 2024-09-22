#ifndef VIDEO_H
#define VIDEO_H

#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 5

typedef struct
{
  int id;
  char nome[80];
  int duracao;  
}tp_video;

typedef struct
{
  tp_video video [TAM_MAX];
  int quantidade;
}tp_gerenciador;


void inicializar(tp_gerenciador *gerenciador);
void menu(tp_gerenciador *gerenciador);
void cadastrarVideo(tp_gerenciador *gerenciador);
void exibirVideos(tp_gerenciador *gerenciador);
void exibirDuracaoTotal(tp_gerenciador *gerenciador);

#endif