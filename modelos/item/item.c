/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Gabriel Dutra Dias
Matricula: 201622040198
Descricao do programa: Algoritmo para resolver o problema da mochila
Data: 14/09/2017
************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "item.h"

/** Item - Cria Lista com o primeiro item
* @param primeiroItem - Primeiro item da lista
* @return Item* - inicialização da lista de itens
**/
Item *item_criaLista(Item primeiroItem){
    Item *novoItem = (Item *) malloc(sizeof(Item));
    novoItem->numero = primeiroItem.numero;
    novoItem->valor = primeiroItem.valor;
    novoItem->peso = primeiroItem.peso;
    novoItem->proximo = NULL;
    return novoItem;
}


/** Item - Adiciona Item no final da lista
* @param item - Item a ser adicionado
* @param lista - Lista a ter o elemento adicionado
**/
void item_adicionaItem(Item item, Item *lista){
    Item *novoItem = (Item *) malloc(sizeof(Item));
    while(lista->proximo != NULL) lista = lista->proximo; // vai até o final da lista
    novoItem->numero = item.numero;
    novoItem->valor = item.valor;
    novoItem->peso = item.peso;
    novoItem->proximo = NULL;
    lista->proximo = novoItem;
}

/** Item - Remove Item
* @param item - Item a ser removido
* @param anterior - Item anterior
* @param lista - Lista de itens
* @return Item* - Nova lista de itens
**/
Item *item_removeItem(Item *item, Item *anterior, Item *lista){
    if(anterior == NULL) return item->proximo;
    anterior->proximo = item->proximo;
    return lista;
}

/** Item - Copia e insere (Copia a lista e insere um elemento ao final)
* @param item - Item a ser inserido
* @param lista - lista de itens
* @return Item* - Nova Lista
**/
Item *item_copiaEInsere(Item item, Item *lista){
    if(lista == NULL) return item_criaLista(item);
    Item *novaLista = item_criaLista(*lista);
    Item *novaListaAtual = novaLista;
    if(lista != NULL) lista=lista->proximo;
    while(lista != NULL){
        item_adicionaItem(*lista, novaListaAtual);
        novaListaAtual = novaListaAtual->proximo;
        lista = lista->proximo;
    }
    item_adicionaItem(item, novaListaAtual);
    return novaLista;
}