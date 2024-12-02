#ifndef EPISODIO_H
#define EPISODIO_H

typedef struct {
    int numero;
    char *titulo;
} Episodio;

void inicializarEpisodio(Episodio *episodio, int numero, const char *titulo);
void liberarEpisodio(Episodio *episodio);

#endif // EPISODIO_H
