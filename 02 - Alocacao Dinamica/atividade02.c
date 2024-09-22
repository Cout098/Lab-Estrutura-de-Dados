#include <stdio.h>
#include <stdlib.h>

void preencherVetor(int *vetor, int tamanho);
void exibirVetor(int *vetor, int tamanho);

int main(){
    int *vetor;
    int tamanho = 0;

    printf("Digite o tamanho do vetor que gostaria de preencher: \n");
    scanf("%d", &tamanho);

    vetor = (int*) malloc(tamanho * sizeof(int));

    preencherVetor(vetor, tamanho);
    exibirVetor(vetor, tamanho);
    
    free(vetor);
    return 0;
}

void preencherVetor(int *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &vetor[i]);
    }
}

void exibirVetor(int *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        printf("Posicao [%d]: %d\n", i+1, vetor[i]);
    }
}