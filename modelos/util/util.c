#include <stdio.h>
#include <stdlib.h>
#include "../item/item.h"
#include "util.h"

/** Carrega Dados - Função para carregar e estruturar a entrada a partir de um arquivo
* @param arquivo - Arquivo a ter a entrada carregada
* @return Entrada - Estrutura com os dados para o problema
**/
Entrada util_carregaDados(FILE *arquivo){
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
        Item novoItem;
        fscanf(arquivo, "%d %d", &novoItem.peso, &novoItem.valor);
        if(itens == NULL){ // Caso não exista o primeiro elemento da lista, cria ele
            itens = item_criaLista(novoItem);
            itemAtual = itens;
        } else {
            item_adicionaItem(novoItem, itemAtual);
            itemAtual = itemAtual->proximo;
        }
    }

    entrada.n = n;
    entrada.W = pesoMochila;
    entrada.itens = itens;

    return entrada;
}

/** Salva Solução - salva solução em arquivo 
* @param arquivo - Arquivo para salvar
* @param solucao - Solução a ser salva
**/
void util_salvaSolucao(FILE *arquivo, Item *solucao){
    int contador=1;
    int pesoTotal=0;
    int valorTotal=0;
    while(solucao != NULL){
        pesoTotal+=solucao->peso;
        valorTotal+=solucao->valor;
        fprintf(arquivo, "%d %d %d\n", contador, solucao->peso, solucao->valor);
        contador++;
        solucao = solucao->proximo;
    }
    fprintf(arquivo, "Peso Total: %d Valor Total: %d\n", pesoTotal, valorTotal);
}