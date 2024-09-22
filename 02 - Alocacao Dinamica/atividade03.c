#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nome[30];
    char fabricante[30];
    float preco;
}tp_celular;

void preencherCelular(tp_celular *vetor);
void exibirCelular(tp_celular vetor);
void exibirTodos(tp_celular *vetor, int tamanho);

int main(){
    tp_celular *vetor;
    int tamanho = 0;
    int contador = 0;
    int posicao;
    int opc;

    printf("Digite a quantidade de celulares que quer alocar:");
    scanf("%d", &tamanho);

    vetor = malloc(tamanho * sizeof(tp_celular));

    do
    {
        printf("Escolha uma opcao:\n");
        printf("[1] - Preencher Celular\n");
        printf("[2] - Exibir Celular\n");
        printf("[3] - Exibir Todos\n");
        printf("[4] - Sair\n");
        scanf("%d", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            if (contador < tamanho)
            {
                preencherCelular(&vetor[contador]);
                contador++;
            } else{
                printf("\nQuantidade Maxima atingida\n");
            }
            break;
        case 2:
            printf("Qual dispositivo deseja exibir: ");
            scanf("%d", &posicao);
            if(posicao <= contador){
                exibirCelular(vetor[posicao - 1]);
            }
            break;
        case 3: 
            exibirTodos(vetor, tamanho);

        default:
            printf("\nOpcao invalida\n");
            break;
        }
    } while (opc != 4);
    
    free(vetor);
    return 0;
}

void preencherCelular(tp_celular *vetor){
    printf("Digite o ID: ");
    scanf("%d",&vetor->id);
    fflush(stdin);
    printf("Digite o nome do aparelho: ");
    gets(vetor->nome);
    printf("Digite o Fabricante: ");
    gets(vetor->fabricante);
    printf("Digite o Preco Sugerido: ");
    scanf("%f", &vetor->preco);
    fflush(stdin);
}

void exibirCelular(tp_celular vetor){

    printf("Id: %d\n",vetor.id);
    printf("Nome: %s\n",vetor.nome);
    printf("Fabricante: %s\n",vetor.fabricante);
    printf("Preco: %2.f\n",vetor.preco);
}

void exibirTodos(tp_celular *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {   
        printf("\nCELULAR %d\n", i+1);
        exibirCelular(vetor[i]);
    }
}
