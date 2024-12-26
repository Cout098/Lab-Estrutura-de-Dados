#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "episodio.h"


void inicializarEpisodio(Episodio *episodio, int numero, const char *titulo) {
    episodio->numero = numero;
    episodio->titulo = malloc(strlen(titulo) + 1);
    if (!episodio->titulo) {
        printf("Erro ao alocar memória para o título.\n");
        exit(1);
    }
    strcpy(episodio->titulo, titulo);
}

// Libera a memória do episódio
void liberarEpisodio(Episodio *episodio) {
    if (episodio->titulo) {
        free(episodio->titulo);
        episodio->titulo = NULL;
    }
}



