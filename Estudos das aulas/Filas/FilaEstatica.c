#include <stdlib.h>
#include <stdio.h>
#include "FilaEstatica.h"

struct fila
{
    int inicio,final,qtd;
    struct aluno dados[MAX];
};

Fila* cria_fila(){
    Fila *fi;
    fi=(Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio=0;
        fi->final=0;
        fi->qtd=0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    free(fi);
}

int tamanho_Fila(Fila* fi){
    if(fi==NULL)
        return -1;
    return fi->qtd;
}

int insere_Fila(Fila *fi,struct aluno al){
    if(fi==NULL)
        return 0;
    if(fi->qtd-1 == MAX)
        return 0;
    fi->dados[fi->final] = al;
    fi->final=(fi->final+1)%MAX;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi==NULL||fi->qtd==0)
        return 0;
    fi->inicio=(fi->inicio+1)%MAX;
    fi->qtd--;
    return 1;
}

int consulta_Fila(Fila* fi,struct aluno* al){
    if(fi==NULL || fi->qtd==0)
        return 0;

    *al = fi->dados[fi->inicio];
    return 1;
}

