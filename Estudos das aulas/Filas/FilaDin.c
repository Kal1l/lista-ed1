#include <stdlib.h>
#include <stdio.h>
#include "FilaDin.h"


struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Fila* cria_fila(){
    Fila *fi=(Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->final=NULL;
        fi->inicio=NULL;
        fi->qtd=NULL;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi!= NULL){
        Elem* no;
        while(fi->inicio != NULL) {
            no= fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int tamanho_Fila(Fila* fi){
    if(fi==NULL)
        return 0;
    return fi->qtd;
}

int insere_Fila(Fila *fi,struct aluno al){
    if(fi==NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no==NULL)
        return 0;
    no->dados=al;
    no->prox=NULL;
    if(fi->final==NULL) //fila vaiza
        fi->inicio=no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio= NULL) //fila vazia
        return 0;

    Elem *no= fi->inicio;
    fi->inicio = fi->inicio->prox;
    free(no);

    if(fi->inicio == NULL)
        fi->final = NULL;
    fi->qtd--;
    return 1;
}

int consulta_Fila(Fila* fi,struct aluno *al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL) //fila vazia
        return 0;
    *al= fi->inicio->dados;
    return 1;
}

