#include <stdio.h>
#include <stdlib.h>
#include "modelos/item/item.h"
#include "modelos/util/util.h"
#include "algoritmos/guloso/guloso.h"
#include "algoritmos/backtracking/backtracking.h"

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

    Entrada entrada = util_carregaDados(arquivo);

    // Backtracking
    if(algoritmoEscolhido == 1){
        Global global;
        global.entrada = entrada;
        global.solucaoOtima = NULL;
        global.valorOtimo = 0;
        global.pesoOtimo = 0;
        backtracking(entrada.itens, 0, 0, NULL, &global);
        Item *solucao = global.solucaoOtima;
        int pesoTotal=0;
        int valorTotal=0;
        while(solucao != NULL){
            pesoTotal+=solucao->peso;
            valorTotal+=solucao->valor;
            printf("%d %d\n", solucao->peso, solucao->valor);
            solucao = solucao->proximo;
        }
        printf("Peso Total: %d Valor Total: %d\n", pesoTotal,valorTotal);
    }

    // Algoritmo Guloso
    if(algoritmoEscolhido == 2){
        Item *solucao = guloso(entrada);        
        int pesoTotal=0;
        int valorTotal=0;
        while(solucao != NULL){
            pesoTotal+=solucao->peso;
            valorTotal+=solucao->valor;
            printf("%d %d\n", solucao->peso, solucao->valor);
            solucao = solucao->proximo;
        }
        printf("Peso Total: %d Valor Total: %d\n", pesoTotal,valorTotal);
    }
    
    return 0;
}