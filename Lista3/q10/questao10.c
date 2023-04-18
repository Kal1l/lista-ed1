#include "questao10.h"
#include <stdio.h>

void insere_pilha(int i,int valor){
    if(topo1 == topo2 -1){
        printf("Pilhas cheias!\n");
        return;
    }

    if(i==1){
        topo1++;
        pilha[topo1]=valor;
    }
    else if(i==2){
        topo2--;
        pilha[topo2]=valor;
    }
    else{
        printf("Pilha invalida!\n");
    }
}

int remove_pilha(int i){
    if(i==1){
        if(topo1== -1){
            printf("Pilha vazia!");
            return -1;
        }
        else{
            int valor = pilha[topo1];
            topo1--;
            return valor;
        }
    }
    else if(i==2){
        if(topo2==MAX){
            printf("Pilha vazia!");
        }
        else {
            int valor = pilha[topo2];
            topo2++;
            return valor;
        }
    }
    else{
        printf("Erro: Pilha invalida\n");
        return -1;
    }
}