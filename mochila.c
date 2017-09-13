/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Gabriel Dutra Dias
Matricula: 201622040198
Descricao do programa: Algoritmo para resolver o problema da mochila
Data: 14/09/2017
************************************************/

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

    FILE *arquivo = fopen(arquivoEntrada, "r");
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
    fclose(arquivo);

    // Extrai só o nome do arquivo de entrada sem a extensão
    char *nomeArquivoEntrada = arquivoEntrada;
    char *iterador = nomeArquivoEntrada;
    char *extensao = NULL;
    while(*iterador != '\0'){
        if(*iterador == '/') nomeArquivoEntrada = iterador+1;
        if(*iterador == '.') {
            extensao = iterador;
        }
        iterador++;
    } 
    *extensao = '\0';

    // Backtracking
    if(algoritmoEscolhido == 1){
        Global global;
        global.entrada = entrada;
        global.solucaoOtima = NULL;
        global.valorOtimo = 0;
        global.pesoOtimo = 0;
        backtracking(entrada.itens, 0, 0, NULL, &global);
        Item *solucao = global.solucaoOtima;

        char arquivoSaida[200];
        sprintf(arquivoSaida, "./dataset/out/%s-out-backtracking.txt",nomeArquivoEntrada);
        FILE *arquivoS = fopen(arquivoSaida, "w");
        util_salvaSolucao(arquivoS, solucao);
        fclose(arquivoS);
    }

    // Algoritmo Guloso
    if(algoritmoEscolhido == 2){
        Item *solucao = guloso(entrada);   
        
        char arquivoSaida[200];
        sprintf(arquivoSaida, "./dataset/out/%s-out-guloso.txt",nomeArquivoEntrada);
        FILE *arquivoS = fopen(arquivoSaida, "w");  
        util_salvaSolucao(arquivoS, solucao);
        fclose(arquivoS);
    }
    
    return 0;
}