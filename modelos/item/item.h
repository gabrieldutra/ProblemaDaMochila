typedef struct item{
    int valor;
    int peso;
    struct item *proximo;
} Item;

Item *item_criaLista(Item primeiroItem);
void item_adicionaItem(Item item, Item *lista);
Item *item_removeItem(Item *item, Item *anterior, Item *lista);