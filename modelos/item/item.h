/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Gabriel Dutra Dias
Matricula: 201622040198
Descricao do programa: Algoritmo para resolver o problema da mochila
Data: 14/09/2017
************************************************/

typedef struct item{
    int numero;
    int valor;
    int peso;
    struct item *proximo;
} Item;

Item *item_criaLista(Item primeiroItem);
void item_adicionaItem(Item item, Item *lista);
Item *item_removeItem(Item *item, Item *anterior, Item *lista);
Item *item_copiaEInsere(Item item, Item *lista);