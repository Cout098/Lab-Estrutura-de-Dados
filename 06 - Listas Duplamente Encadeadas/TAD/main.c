#include <stdio.h>
#include "serie.h"

int main() {
    Lista minhaLista;
    inicializarLista(&minhaLista);

    int opcao;
    char titulo[100];

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Episódio\n");
        printf("2. Remover Último Episódio\n");
        printf("3. Exibir Série\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o título do episódio: ");
                getchar(); // Limpa o buffer
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0'; // Remove o \n do título
                cadastrarEpisodio(&minhaLista, titulo);
                break;
            case 2:
                removerUltimoEpisodio(&minhaLista);
                break;
            case 3:
                exibirSerie(&minhaLista);
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    liberarLista(&minhaLista);
    return 0;
}
