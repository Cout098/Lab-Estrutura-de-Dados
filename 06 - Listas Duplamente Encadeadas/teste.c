#include <stdio.h>
#include <stdlib.h>


typedef struct ep
{
    int numeroEpisodio;
    char titulo[50];
} tipoEpisodio;

typedef struct itemDaLista{
    tipoEpisodio episodio;
    tipoEpisodio *proximo;
    tipoEpisodio *anterior;
} tipoItem;

typedef struct listaDupla
{
    tipoItem *primeiro;
    tipoItem *ultimo;

    int quantidade;

} tipoLista;

void cadastrarEpisodio(tipoEpisodio *episodio){
    episodio = malloc(sizeof(tipoEpisodio));

    printf("Digite o titulo do ep: ");
    fflush(stdin);
    gets(episodio->titulo);

    episodio->numeroEpisodio = 
}

