#include <stdio.h>
#include <stdlib.h>
#define NUM_MAX 2

typedef struct {
    int id;
    char titulo[30];
    int duracao;
}tp_video;

void cadastrarVideo(tp_video *video);
void exibirVideo(tp_video video[NUM_MAX]);


int main(){
    tp_video video[NUM_MAX];
    int total = 0;
    int opc;

    do
    {
        printf("\nEscolha a opcao:\n[1] - Cadastrar Video.\n[2] - Exibir Video.\n[3] - Sair\n");
        scanf("%d", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            if (total < NUM_MAX)
            {
                cadastrarVideo(&video[total]);
                total++;
            }
            else{
                printf("Numero maximo atingido");
            }
            
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
    fflush(stdin); 
}

void exibirVideo(tp_video video[NUM_MAX]){
    int i;
    for (i = 0; i < NUM_MAX; i++)
    {   
        printf("VIDEO: %d\n", i+1);
        printf("ID: %d\n", video[i].id);
        printf("TITULO: %s\n", video[i].titulo);
        printf("DURACAO: %d\n\n", video[i].duracao);  
    }
}