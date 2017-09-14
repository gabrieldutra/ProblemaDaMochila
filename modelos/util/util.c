/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Gabriel Dutra Dias
Matricula: 201622040198
Descricao do programa: Algoritmo para resolver o problema da mochila
Data: 14/09/2017
************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
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
        novoItem.numero = i+1;
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
    int pesoTotal=0;
    int valorTotal=0;
    while(solucao != NULL){
        pesoTotal+=solucao->peso;
        valorTotal+=solucao->valor;
        fprintf(arquivo, "%d %d %d\n", solucao->numero, solucao->peso, solucao->valor);
        solucao = solucao->proximo;
    }
    fprintf(arquivo, "Peso Total: %d Valor Total: %d\n", pesoTotal, valorTotal);
}

/** Tempo Atual
* @return long long - Tempo atual em milisegundos
**/
long long util_tempoAtual(){
    struct timeval te; 
    gettimeofday(&te, NULL);
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000;
    return milliseconds;
}