#include "musica.h"

typedef struct playlist
{
    int quantidade;
    tpMusica *primeira;
    tpMusica *ultima;
}tpPlaylist;

void inicializarPlaylist(tpPlaylist *playlist);
void cadastrarMusicas(tpPlaylist *playlist);
void tocarMusicas(tpPlaylist *playlist);
