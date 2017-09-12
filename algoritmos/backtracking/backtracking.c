#include <stdio.h>
#include <stdlib.h>
#include "../../modelos/item/item.h"
#include "../../modelos/util/util.h"
#include "backtracking.h"

/** Backtracking
* @param item - Item atual
* @param acumuladorValor - Valor acumulado ao descer na árvore
* @param acumuladorPeso - Peso acumulado ao descer na árvore
* @param solucao - Solução atual
* @param global - Solução ótima global
**/ 
void backtracking(Item *item, int acumuladorValor, int acumuladorPeso, Item *solucao, Global *global){
    Entrada entrada = global->entrada;
    int valorAtual = acumuladorValor + item->valor;
    int pesoAtual = acumuladorPeso + item->peso;
    Item *solucaoAtual = item_copiaEInsere(*item, solucao); // solucaoAtual = solucao + C(i)
    if(pesoAtual <= entrada.W){
        if(valorAtual > global->valorOtimo){ // Atualiza a solução ótima global
            global->valorOtimo = valorAtual;
            global->pesoOtimo = pesoAtual;
            global->solucaoOtima = solucaoAtual;
        }        
    }
    if(item->proximo != NULL && acumuladorPeso < entrada.W){
        backtracking(item->proximo, valorAtual, pesoAtual, solucaoAtual, global);
        backtracking(item->proximo, acumuladorValor, acumuladorPeso, solucao, global);
    }
}