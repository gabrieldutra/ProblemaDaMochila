#include <stdio.h>
#include <stdlib.h>
#include "../../modelos/item/item.h"

/** Algoritmo guloso
* @param entrada - Dados da entrada do problema
* @return Item* - Conjunto solução de itens
**/ 
Item *guloso(Entrada entrada){
    Item *solucao = NULL;
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
}