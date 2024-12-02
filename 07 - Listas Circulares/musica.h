typedef struct musica
{
    char titulo[30];
    char artista[30];
    float duracao;
    int id;
    struct musica *proxima;
    struct musica *anterior;
}tpMusica;

