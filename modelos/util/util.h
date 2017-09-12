typedef struct entrada{
    int n; // número de itens na loja
    int W; // peso máximo da mochila
    Item *itens; // Conjunto de itens
} Entrada;

Entrada util_carregaDados(FILE *arquivo);