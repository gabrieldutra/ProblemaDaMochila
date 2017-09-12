#include <stdio.h>
#include <stdlib.h>
#include "modelos/item/item.h"
#include "modelos/util/util.h"

/** Carrega Dados - Função para carregar e estruturar a entrada a partir de um arquivo
* @param arquivo - Arquivo a ter a entrada carregada
* @return Entrada - Estrutura com os dados para o problema
**/
Entrada carregaDados(FILE *arquivo){
    Entrada entrada;

    Item *itens = NULL;
    Item *itemAtual = NULL;
    int pesoMochila;
    fscanf(arquivo, "%d", &pesoMochila); // Lê o peso máximo que a mochila aguenta

    int n;
    fscanf(arquivo, "%d", &n); // Lê o número de itens da loja

    // Lê o peso e valor de cada item e insere na lista
    int i;
    for(i = 0; i < n; i++){
        Item *novoItem = (Item *) malloc(sizeof(Item));
        fscanf(arquivo, "%d %d", &novoItem->peso, &novoItem->valor);
        novoItem->proximo = NULL;
        if(itens == NULL){ // Caso não exista o primeiro elemento da lista, cria ele
            itens = novoItem;
            itemAtual = novoItem;
        } else {
            itemAtual->proximo = novoItem; // Posiciona o novoItem na lista
            itemAtual = novoItem;
        }
    }

    entrada.n = n;
    entrada.W = pesoMochila;
    entrada.itens = itens;

    return entrada;
}

int main(int argc, char *argv[]){
    
    // Checa o número de argumentos passados
    if(argc < 3){
        printf("Ops, você não passou todos os parâmetros!\nUso: %s [arquivo-de-entrada] [1 - Backtracking | 2 - Algoritmo guloso]\n", argv[0]);
        return 0;
    }

    char *arquivoEntrada = argv[1];
    int algoritmoEscolhido = atoi(argv[2]);

    FILE *arquivo = fopen(argv[1], "r");
    // Verifica caso não tenha sido possível abrir o arquivo
    if(!arquivo){
        printf("Não foi possível abrir o arquivo '%s'.\n", argv[1]);
        return 0;
    }

    // Verifica se o número do algoritmo passado é válido
    if(algoritmoEscolhido != 1 && algoritmoEscolhido != 2){
        printf("Algoritmo escolhido inválido !\nUse 1 para Backtracking ou 2 para Algoritmo guloso!\n%s %s [1|2]\n", argv[0], argv[1]);
        return 0;
    }

    Entrada entrada = carregaDados(arquivo);

    Item *solucao = NULL;
    Item *solucaoAtual = NULL;
    int pesoTotal = 0;

    // Implementação do algoritmo Guloso
    while(1){
        Item *maisValioso = NULL;
        double custoBeneficioMV = 0;
        
        Item *item = entrada.itens;
        while(item != NULL){ // Percorre todos os itens para encontrar o ótimo local
            double custoBeneficio = (double) item->valor/item->peso;
            if(custoBeneficio > custoBeneficioMV && pesoTotal + item->peso < entrada.W){
                maisValioso = item;
                custoBeneficioMV = custoBeneficio;
            }
        }
        if(maisValioso == NULL) break; // Caso não tenha maisValioso, sai do loop

        if(solucao == NULL){
            solucao = maisValioso;
            solucaoAtual = maisValioso;
        } else {
            // TODO - S = S + maisValioso e C = C - maisValioso
        }

    }
    
    return 0;
}