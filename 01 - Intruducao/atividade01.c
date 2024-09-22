#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char titulo[30];
    int duracao;
}tp_video;

void cadastrarVideo(tp_video *video);
void exibirVideo(tp_video video);


int main(){
    tp_video video;
    int opc;

    do
    {
        printf("\nEscolha a opcao:\n[1] - Cadastrar Video.\n[2] - Exibir Video.\n[3] - Sair\n");
        scanf("%d", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            cadastrarVideo(&video);
            break;
        case 2:
            exibirVideo(video);
            break;
        case 3:
            printf("Saindo...");
            break;
        default:
            printf("\nOpcao invalida\n");
            break;
        }  
    } while (opc != 3);
    
    return 0;
}


void cadastrarVideo(tp_video *video){

    printf("CADASTRAR\n");
    printf("Digite o titulo do video: ");
    gets(video->titulo);
    printf("Digite a ID: ");
    scanf("%d", &video->id);
    printf("Digite a duracao do video: ");
    scanf("%d", &video->duracao);
}

void exibirVideo(tp_video video){

    printf("ID: %d\n", video.id);
    printf("TITULO: %s\n", video.titulo);
    printf("DURACAO: %d\n", video.duracao);
}