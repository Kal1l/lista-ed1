#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q2.h"
#define SIZE 7

No* criarNo(char*dado){
    No* novoNo=(No*)malloc(sizeof(No));
    novoNo->dado=stdupo(dado);
    novoNo->prox=NULL;
    return novoNo;
}

unsigned int hash(char* chave){
    unsigned int valorHash=0;
    for(int i=0;i<strlen(chave);i++){
        valorHash+=chave[i];
    }
    return valorHash % SIZE;
}

Tabela* criaTabela(){
    Tabela* tabela_hash=(Tabela*)malloc(sizeof(Tabela));
    tabela_hash-> elemento = (No**)malloc(sizeof(No*)*SIZE);
    for(int i=0;i<SIZE;i++){
        tabela_hash->elemento[i]=NULL;
    }
    return tabela_hash;
}

void insere(Tabela* tabela,char* dado){
    unsigned int pos=hash(dado);
    No* novoNo=criarNo(dado);
    //Se a posição estiver vazia insere nó
    if(tabela->elemento[pos]==NULL){
        tabela->elemento[pos]=novoNo;
    }
    //em caso de colisão, insere novo nó no inicio da lista encadeada
    else{
        //atual aponta pro primeiro como o próximo nó na lista
        novoNo->prox=tabela->elemento[pos];
        //atual sobrescreve o primeiro
        tabela->elemento[pos]=novoNo;
    }
}

void remove(Tabela* tabela,char* dado){
    unsigned int pos=hash(dado);
    No* atual=tabela->elemento[pos];
    No* anterior=NULL;

    while(atual!=NULL){
        if(strcmp(atual->dado,dado)==0){
            //Primeiro elemento a ser eliminado
            if(anterior==NULL){
                tabela->elemento[pos] = atual->prox;
            }
            //Elemento a ser eliminado é outro
            else{
                anterior->prox = atual->prox;
            }
            free(atual->dado);
            free(atual);
            return;
        }
        anterior=atual;
        atual=atual->prox;
    }
}

int busca(Tabela* tabela, char* dado){
    unsigned int pos=hash(dado);
    No* atual=tabela->elemento[pos];

    while(atual!=NULL){
        if(strcmp(atual->dado,dado)==0){
            //Elemento encontrado
            return 1;
        }
        atual=atual->prox;
    }
    //Elemento não encontado
    return 0;
}