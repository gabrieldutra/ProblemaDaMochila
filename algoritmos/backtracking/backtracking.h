/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Gabriel Dutra Dias
Matricula: 201622040198
Descricao do programa: Algoritmo para resolver o problema da mochila
Data: 14/09/2017
************************************************/

typedef struct global {
    Entrada entrada;
    Item *solucaoOtima;
    int valorOtimo;
    int pesoOtimo;
} Global;

void backtracking(Item *item, int acumuladorValor, int acumuladorPeso, Item *solucao, Global *global);