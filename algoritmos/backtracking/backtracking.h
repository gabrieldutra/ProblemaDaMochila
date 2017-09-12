typedef struct global {
    Entrada entrada;
    Item *solucaoOtima;
    int valorOtimo;
    int pesoOtimo;
} Global;

void backtracking(Item *item, int acumuladorValor, int acumuladorPeso, Item *solucao, Global *global);