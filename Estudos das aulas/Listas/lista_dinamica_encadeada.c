#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica_encadeada.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li=(Lista* )malloc(sizeof(Lista));
    if(li!=NULL)
        *li=NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li!= NULL){
        Elem* no;
        while((*li)!= NULL) {
            no=*li;
            *li=(*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li==NULL)
        return 0;
    int cont=0;
    Elem* no=*li;
    while(no !=NULL){
        cont++;
        no=no->prox;
    }
    return cont;
}

int insere_lista_inicio(Lista*li,struct aluno al){
    if(li==NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc (sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li=no;
    return 1;
}

int insere_lista_inicio(Lista*li,struct aluno al){
    if(li==NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc (sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li=no;
    return 1;
}

int insere_lista_final(Lista* li,struct aluno al){
    if(li==NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc (sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li)==NULL){//lista vazia: insere início
        *li=no;
    }else{
        Elem *aux;
        aux=*li;
        while(aux->prox != NULL){
            aux= aux->prox;
        }
        aux->prox=no;
    }
    return 1;
}

int insere_lista_ordenada(Lista *li,struct aluno al){
    if(li==NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc (sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;

    if((*li)==NULL){//lista vazia: insere início
        no->prox = NULL;
        *li=no;
        return 1;
    }else{
        Elem *anterior,*atual =*li;
        while(atual!=NULL && atual->dados.matricula < al.matricula){
            anterior=atual;
            atual= atual -> prox;
        } 

        if(atual == *li){//insere inicio
            no->prox = (*li);
            *li=no;
        }else{
            no->prox=atual;
            anterior->prox=no;
        }
    }
    return 1;
}

int remove_lista_inicio(Lista *li){
    if(li==NULL)
        return 0;
    if((*li)==NULL)
        return 0;

    Elem *no=*li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li==NULL)
        return 0;
    if((*li)==NULL)//lista vazia
        return 0;

    Elem *anterior,*no = *li;
    while(no->prox!=NULL){
        anterior=no;
        no=no->prox;
    }

    if(no==(*li)){
        *li=no->prox;
    }else{
        anterior->prox = no->prox;
    }
    free(no);
    return 1;
}

int remove_lista(Lista *li,int mat){
    if(li==NULL)
        return 0;
    if((*li)==NULL)//lista vazia
        return 0;

     Elem *anterior,*no = *li;
    while(no->prox!=NULL && no->dados.matricula!=mat){
        anterior=no;
        no=no->prox;
    }

    if(no==NULL)
        return 0;
    if(no==*li)
        *li=no->prox;
    free(no);
    return 1;
}

int busca_lista_pos(Lista* li,int pos,struct aluno* al){
    if(li==NULL || pos <=0)
    //se a posição for menor que 0 ou maior doq o tamanho da lista
        return 0;
    Elem *no= *li;
    int i=1;
    while(no!=NULL && i<pos){
        no=no->prox;
        i++;
    }
    if(no==NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int busca_lista_pos(Lista* li,int mat,struct aluno* al){
    if(li==NULL)
        return 0;
    Elem *no= *li;
    while(no !=NULL && no->dados.matricula!=mat){
        no=no->prox;
    }
    if(no==NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}