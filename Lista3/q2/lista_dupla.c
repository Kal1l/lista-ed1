#include "lista_dupla.h"
#include <stdlib.h>

ListaDupla* cria_lista_dupla(){
    ListaDupla* lista=(ListaDupla*) malloc(sizeof(ListaDupla));
    lista->inicio=NULL;
    lista->fim=NULL;
    lista->qtd=0;
    return lista;
}

void insere_lista_dupla(ListaDupla* lista,int valor){
    No* novo=(No*) malloc(sizeof(No));
    novo->valor=valor;
    novo->ant=NULL;
    novo->prox=lista->inicio;
    if(lista->inicio!=NULL){
        lista->inicio->ant=novo;
    }
    else{
        lista->fim=novo;
    }
    lista->inicio=novo;
    lista->qtd++;
}

void remove_lista_dupla(ListaDupla* lista, int valor){
    No* atual=lista->inicio;
    while(atual!=NULL){
        if(atual->valor==valor){
            if(atual->ant!=NULL){
                atual->ant->prox=atual->prox;
            }
            else{
                lista->inicio=atual->prox;
            }
            if(atual->prox!=NULL){
                atual->prox->ant=atual->ant;
            }
            else{
                lista->fim=atual->ant;
            }
            free(atual);
            lista->qtd--;
            return;
        }
        atual=atual->prox;
    }
}