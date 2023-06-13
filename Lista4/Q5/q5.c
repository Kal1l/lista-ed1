#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q5.h"

No* criarNo(int codigo,char* nome,float preco,int qtd){
    No* novo=(No*)malloc(sizeof(No));
    novo->produto.codigo=codigo;
    novo->produto.nome=strdup(nome);
    novo->produto.preco=preco;
    novo->produto.qtd=qtd;
    novo->prox=NULL;
    return novo;
}

Tabela* criarTabela(){
    Tabela* tabela_hash = (Tabela*)malloc(sizeof(Tabela));
    tabela_hash->elemento=(No**)malloc(sizeof(No*)*SIZE);
    tabela_hash->tam=SIZE;

    for(int i=0;i<SIZE;i++){
        tabela_hash->elemento[i] = NULL;
    }

    return tabela_hash;
}

unsigned int hash(int codigo,int size){
    return codigo%size;
}

void inserir(Tabela* tabela,int codigo,char* nome,float preco,int qtd){
    unsigned int pos=hash(codigo,tabela->tam);
    No* novo=criarNo(codigo,nome,preco,qtd);

    if(tabela->elemento[pos]==NULL){
        tabela->elemento[pos]=novo;
    }
    else{
        No* atual=tabela->elemento[pos];
        while(atual->prox!=NULL){
            atual=atual->prox;
        }
        atual->prox=novo;
    }
}

No* procurar(Tabela* tabela,int codigo ){
    unsigned int pos=hash(codigo,tabela->tam);
    No* atual= tabela->elemento[pos];
    while(atual!=NULL){
        if(atual->produto.codigo==codigo){
            return atual;
        }
        atual=atual->prox;
    }
    return NULL;
}

void remover(Tabela* tabela,int codigo){
    unsigned int pos=hash(codigo,tabela->tam);
     No* atual= tabela->elemento[pos];
     No* ant= NULL;

     while(atual!=NULL){
        if(atual->produto.codigo==codigo){
            if(ant==NULL){
                tabela->elemento[pos]=atual->prox;
            }
            else{
                ant->prox=atual->prox;
            }
        free(atual);
        return;
        }
        ant=atual;
        atual=atual->prox;
     }
}
void atualizarpreco(Tabela* tabela,int codigo,float preconovo){
    Produto* produto = procurar(tabela,codigo);
    if(produto!=NULL){
        produto->preco=preconovo;
    }
}

No* precomax(Tabela* tabela){
    No* max=NULL;
    for(int i=0;i<tabela->tam;i++){
        No* atual=tabela->elemento[i];
        while(atual!=NULL){
            if(max==NULL||atual->produto.preco>max->produto.preco){
                max=atual;
            }
            atual=atual->prox;
        }
    }
    return max;
}