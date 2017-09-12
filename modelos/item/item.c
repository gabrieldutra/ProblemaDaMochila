#include <stdio.h>
#include <stdlib.h>

/** Item - Cria Lista com o primeiro item
* @param primeiroItem - Primeiro item da lista
* @return Item* - inicialização da lista de itens
**/
Item *item_criaLista(Item primeiroItem){
    Item *novoItem = (Item *) malloc(sizeof(Item));
    novoItem->valor = item.valor;
    novoItem->peso = item.peso;
    novoItem->proximo = NULL;
    return novoItem;
}


/** Item - Adiciona Item no final da lista
* @param item - Item a ser adicionado
* @param lista - Lista a ter o elemento adicionado
**/
void *item_adicionaItem(Item item, Item *lista){
    Item *novoItem = (Item *) malloc(sizeof(Item));
    while(lista->proximo != NULL) lista = lista->proximo; // vai até o final da lista
    novoItem->valor = item.valor;
    novoItem->peso = item.peso;
    novoItem->proximo = NULL;
    lista->proximo = novoItem;
}