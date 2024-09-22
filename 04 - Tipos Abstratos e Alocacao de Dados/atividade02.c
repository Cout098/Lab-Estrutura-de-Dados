#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vetor = NULL;
    int numInicial = 3;
    int numSecundario = 10;
    int numMaximo = numInicial;
    int opc;

    vetor = malloc(numInicial * sizeof(int));

    for (int i = 0; i < numInicial; i++)
    {
        printf("Digite um numero inteiro: ");
        scanf("%d", &vetor[i]);
    }

    printf("Deseja digitar mais numeros?\n");
    printf("[1] - Sim\n[2] - Nao\n");
    scanf("%d", &opc);

    if (opc == 1)
    {
        numMaximo += numSecundario;

        vetor = realloc(vetor, numMaximo * sizeof(int)); 
        
        for (int i = numInicial; i < numMaximo; i++)
        {
            printf("Digite um numero inteiro: ");
            scanf("%d", &vetor[i]);
        }   

    }

    for (int i = 0; i < numMaximo; i++)
    {
        printf("Posicao [%d]: %d\n", i, vetor[i]);
    }
    
    free(vetor);    
    return 0;
}