#include <stdio.h>
#include <stdlib.h>
#include "../../modelos/item/item.h"
#include "../../modelos/util/util.h"

/** Algoritmo guloso
* @param entrada - Dados da entrada do problema
* @return Item* - Conjunto solução de itens
**/ 
Item *guloso(Entrada entrada){

    int pesoTotal = 0;
    Item *solucao = NULL;
    Item *solucaoAtual = NULL;
    // Implementação do algoritmo Guloso
    while(1){
        Item *maisValioso = NULL;
        Item *anteriorAoMaisValioso = NULL; // posição do anterior ao mais valioso
        double custoBeneficioMV = 0;
        
        Item *item = entrada.itens;
        Item *itemAnterior = NULL;
        while(item != NULL){ // Percorre todos os itens para encontrar o ótimo local
            double custoBeneficio = (double) item->valor/item->peso;
            if(custoBeneficio > custoBeneficioMV && pesoTotal + item->peso < entrada.W){
                maisValioso = item;
                anteriorAoMaisValioso = itemAnterior;
                custoBeneficioMV = custoBeneficio;
            }
            itemAnterior = item; // Armazena a posição do anterior
            item = item->proximo;
        }
        if(maisValioso == NULL) break; // Caso não tenha maisValioso, sai do loop

        Item novoItem;
        novoItem.valor = maisValioso->valor;
        novoItem.peso = maisValioso->peso;

        if(solucao == NULL){
            solucao = item_criaLista(novoItem);
            solucaoAtual = solucao;
        } else {
            item_adicionaItem(novoItem, solucaoAtual); // solucao = solucao + maisValioso
            solucaoAtual = solucaoAtual->proximo;            
        }
        pesoTotal+=maisValioso->peso; // pesoTotal = pesoTotal + maisValioso->peso
        entrada.itens = item_removeItem(maisValioso, anteriorAoMaisValioso, entrada.itens); // itens = itens - maisValioso
    }
    return solucao;
}