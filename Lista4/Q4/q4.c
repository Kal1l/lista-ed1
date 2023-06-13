#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q4.h"

No* criarNo(int mat,const char*nome){
    No* novo=(No*)malloc(sizeof(No));
    novo->aluno.matricula=mat;
    novo->aluno.nome=strdup(nome);
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

unsigned int hash(int matricula,int size){
    return matricula%size;
}

void inserir(Tabela* tabela,int mat, char* nome){
    unsigned int pos=hash(mat,tabela->tam);
    No* novo=criarNo(mat,nome);

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
No* procura(Tabela* tabela,int mat){
    unsigned int pos=hash(mat,tabela->tam);
    No* atual= tabela->elemento[pos];
    while(atual!= NULL){
        if(atual->aluno.matricula==mat){
            return atual;
        }
        atual=atual->prox;
    }
    return NULL;
}

void remover(Tabela* tabela,int mat){
    unsigned int pos=hash(mat,tabela->tam);
     No* atual= tabela->elemento[pos];
     No* ant= NULL;

     while(atual!=NULL){
        if(atual->aluno.matricula==mat){
            if(ant==NULL){
                tabela->elemento[pos]=atual->prox;
            }
            else{
                ant->prox=atual->prox;
            }
        free(atual->aluno.nome);
        free(atual);
        return;
        }
        ant=atual;
        atual=atual->prox;
     }
}

float media(Tabela* tabela){
    int totalmat,numalunos=0;

    for(int i=0;i<tabela->tam;i++){
        No* atual=tabela->elemento[i];
        while(atual!=NULL){
            totalmat+=atual->aluno.matricula;
            numalunos++;
            atual=atual->prox;
        }
    }
    if(numalunos > 0){
        return (float)totalmat/numalunos;
    }
    else{
        return 0.0;
    }
}