#include "parentese.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cria_Pilha(Pilha* pi,int tamanho){
    pi->qtd= -1;
    pi->dados=(char*) malloc (tamanho*sizeof(char));
}
void deleta_Pilha(Pilha* pi){
    free(pi->dados);
    free(pi);
}
void insere_Pilha(Pilha* pi,char dado){
    pi->qtd++;
    pi->dados[pi->qtd]=dado;
}
char remove_Pilha(Pilha* pi){
    char dado=pi->dados[pi->qtd];
    pi->qtd--;
    return dado;
}
int pilha_vazia(Pilha* pi){
    return(pi->qtd==-1);
}