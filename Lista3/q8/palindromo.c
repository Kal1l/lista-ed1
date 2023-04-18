#include "palindromo.h"
#include <stdio.h>
#include<stdlib.h>



void insere(No **topo,char letra){
    No *novo=(No*) malloc(sizeof(No));
    novo->letra=letra;
    novo->prox=*topo;
    *topo=novo;
}

char remover(No **topo){
    char c='\0';
    if(*topo != NULL){
        No *aux = *topo;
        c = aux->letra;
        *topo=aux->prox;
        free(aux);
    }
    return c;
}

int palindromo(char *str){
    No *topo=NULL;
    int len=0;
    int i;

    while(str[len]!= '\0'){
        insere(&topo,str[len]);
        len++;
    }

    for(i=0;i<len;i++){
        if(remover(&topo) !=str[i]){
            return 0;
        }
    }

    return 1;
}