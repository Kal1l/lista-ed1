#include <stdio.h>
#include <stdlib.h>
#include "inverte_fila.h"

struct fila
{
    int inicio,final,qtd;
    int *array;
};

Fila* cria_Fila(){
    Fila *fi=(Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio=0;
        fi->final=-1;
        fi->qtd=0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    free(fi->array);
    free(fi);
}

int Fila_vazia(Fila* fi) {
    return fi->qtd == 0;
}

void insere_Fila(Fila *fi,int valor){
    if(fi==NULL||fi->qtd == MAX) return;
    fi->final=(fi->final+1)%MAX;
    fi->array[fi->final] = valor;
    fi->qtd++;
}

int remove_Fila(Fila* fi){
    if(fi==NULL||fi->qtd==0) return 0;
    int valor= fi->array[fi->inicio];
    fi->inicio=(fi->inicio+1)%MAX;
    fi->qtd--;
    return valor;
}

struct pilha{
    int qtd;
    int *array;
};

Pilha* cria_Pilha(){
    Pilha *pi= (Pilha*) malloc(sizeof(struct pilha));
    if(pi!=NULL){
        pi->qtd = -1;
    }
    return pi;
}

void libera_Pilha(Pilha* pi){
    free(pi->array);
    free(pi);
}

int Pilha_vazia(Pilha pi) {
return pi->qtd == -1;
}

void insere_Pilha(Pilha* pi,int valor){
    if(pi==NULL||pi->qtd == MAX) return;
    pi->qtd;
    pi->array[pi->qtd]=valor;
}

int remove_Pilha(Pilha* pi){
    if(pi==NULL||pi->qtd==-1) return 0;
    int valor=pi->array[pi->qtd];
    pi->qtd--;
    return valor;
}

void inverte_fila(Fila *fi){
    Pilha* pi=cria_Fila();
    while(fi!=fi->qtd!=0){
        int valor=remove_Fila(fi);
        insere_Pilha(pi,valor);
    }
    while(!Pilha_vazia(pi)){
        int valor = remove_Pilha(pi);
        insere_Fila(pi,valor);
    }
    libera_Pilha(pi);
}

