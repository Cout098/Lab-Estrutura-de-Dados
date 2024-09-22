#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

tpLista* criarlista(){
    tpLista *lista = malloc(sizeof(tpLista));
    lista->primeiroItem = NULL;
    lista->contador = 1;
    return lista;
}

tpItem* criarItem(tpLista *lista){
    tpItem *novoItem = malloc(sizeof(tpItem));

    novoItem->id = lista->contador++;
    novoItem->prox = NULL;
    printf("Digite um nome: ");
    gets(novoItem->nome);
    printf("Digite um valor: ");
    scanf("%f", &novoItem->valor);

    return novoItem;
}

void adicionarFinal(tpLista *lista){   //adiciona o item que foi criado
    tpItem* novoItem = criarItem(lista);// cria um item novo e aloca ele em qualquer lugar da memória 

    if (lista->primeiroItem == NULL)
    {
        lista->primeiroItem = novoItem;
    } else
    {
        tpItem* itemAtual = lista->primeiroItem;
        while (itemAtual->prox != NULL) // quando ele sair desse laço é pq encontrou o ultimo
        {
            itemAtual = itemAtual->prox;
        }
        itemAtual->prox = novoItem;//chega no ultimo e fala para ele apontar para o novo item que foi criado.
    }
}

void adicionarInicio(tpLista *lista){
    tpItem *novoItem = criarItem(lista); //cria um item como na funcao anterior

    novoItem->prox = lista->primeiroItem; //coloca o novo item apontando para o item que ocupava a primeira posicao
    lista->primeiroItem = novoItem;//coloca a lista apontando par o novo item como primeiro da lista
}


//tenho que conferir todos os elementos da lista e olhar se o nome digitado é igual ao procurado.
//Pode acontecer duas coisas nesse momento, o nome ser encontrado e o nao ser.
//caso não seja é só retornar que não foi encontrado.
//caso seja é preciso retirar os nós do elemento anterior a ele e ligá-lo ao próximo elemento. Mas também temos casos a avaliuar aqui.
//caso o elemento não seja o primeiro está tudo certo em fazer a recomendação anterior.
//mas caso ele seja o primeiro elemento da lista é preciso direcionar o nó do cabeçalho da lista para o próximo, 
//já que não existe um elemento a ser tratado como anterior.
//depois de remover os nós do elemento é preciso liberar a memória alocada.

void removerItem(tpLista *lista, char nome[]){ 
    tpItem *itemAtual = lista->primeiroItem;   
    tpItem *itemAnterior = NULL;//VAZIO

    while (itemAtual != NULL && strcmp(itemAtual->nome, nome)!=0)//busca o item com o mesmo nome procurado
    {
        itemAnterior = itemAtual;   //Passa o elemento em que o compilador está comparando como anterior
        itemAtual = itemAtual->prox;//Passa o nó do proximo como atual para poder pular para o proximo elemento.
    }                               //A ideia aqui é ficar marcando o caminho, referenciando onde estamos, o anterior e o proximo.
                                    //Assim conseguimos ligar os pontos e retirar um elemento sem perder os nós da lista.
    if (itemAtual == NULL)//quando percorri tudo e nao achei
    {
        printf("Nao foi possivel encontrar o item.\n");
        return; 
    }
    
    if (itemAnterior == NULL)
    {
        lista->primeiroItem = itemAtual->prox;
    }
    else
    { 
        itemAnterior->prox = itemAtual->prox;
    }
    
    free(itemAtual); //libera a memoria para aquele elemento realmente "sumir"
    printf("Removido comsucesso.");
}

void exibirLista(tpLista *lista){
    tpItem *itemAtual = lista->primeiroItem;

    if (lista->primeiroItem == NULL)//confere se a lista está vazia
    {
        printf("A lista esta vazia!");
        return;
    }
    
    while (itemAtual != NULL)//Vaga por todos elementos da lista imprimindo na tela os dados
    {
        printf("ID: %d, Nome: %s, Valor: %.2f\n", itemAtual->id, itemAtual->nome, itemAtual->valor);

        itemAtual = itemAtual->prox;
    }
    
}


void exibirSoma(tpLista *lista){
    float soma = 0;
    
    tpItem *itemAtual = lista->primeiroItem;

    while (itemAtual != NULL)
    {
        soma += itemAtual->valor;
        itemAtual = itemAtual->prox;
    }
    
    printf("A soma dos valores e %.2f\n", soma);

}

void menu(tpLista *lista){
    int opc;
    char nome[100];

    do
    {
        printf("\nEscolha uma opcao:\n");
        printf("[1] - Adicionar item no Inicio\n");
        printf("[2] - Adicionar item no Final\n");
        printf("[3] - Remover item da Lista\n");
        printf("[4] - Exibir Lista Completa\n");
        printf("[5] - exibir soma dos valores\n");
        printf("[0] - Sair\n");
        scanf("%d", &opc);

        fflush(stdin);

        switch (opc)
        {
        case 1:
            adicionarInicio(lista);
        break;
        case 2:
            adicionarFinal(lista);
        break;
        case 3:
            printf("Digite o nome do item: ");
            gets(nome);

            removerItem(lista, nome);
        break;
        case 4:
            exibirLista(lista);
        break;
        case 5:
            exibirSoma(lista);
        break;
        case 0:
            printf("Saindo...\n");
        break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    } while (opc != 0);
}