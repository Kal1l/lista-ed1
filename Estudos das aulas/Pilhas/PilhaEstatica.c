#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaEstatica.h" //inclui os protótipos

struct pilha{
    int qtd;
    struct aluno dados [MAX];
};

Pilha* cria_filha(){
    Pilha *pi;
    pi= (Pilha*) malloc(sizeof(struct pilha));
    if(pi!=NULL){
        pi->qtd=0;
    }
    return pi;
}

void libera_Pilha(Pilha* pi){
    free(pi);
}

int tamanho_Pilha(Pilha* pi){
    if(pi=NULL)
        return -1;
    else
        return pi->qtd;
}

int insere_Pilha(Pilha* pi,struct aluno al){
    if(pi==NULL)
        return 0;
    if(pi->qtd==MAX) //pilha cheia
        return 0;
    pi->dados[pi->qtd] = al;
    pi->qtd++;
    return 1;
}

int remove_Pilha(Pilha* pi){
    if(pi==NULL|| pi->qtd==0)
        return 0;
    pi->qtd--;
    return 1;
}

int acessa_topo_Pilha(Pilha* pi,struct aluno* al){
    if(pi==NULL||pi->qtd==0)
        return 0;
    *al= pi->dados[pi->qtd-1];
    return 1;
}