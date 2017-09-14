/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Gabriel Dutra Dias
Matricula: 201622040198
Descricao do programa: Algoritmo para resolver o problema da mochila
Data: 14/09/2017
************************************************/

typedef struct entrada{
    int n; // número de itens na loja
    int W; // peso máximo da mochila
    Item *itens; // Conjunto de itens
} Entrada;

Entrada util_carregaDados(FILE *arquivo);
void util_salvaSolucao(FILE *arquivo, Item *solucao);
long long util_tempoAtual();