#include <stdlib.h>
#include <stdio.h>
#include "questao3.h"

struct no {
    int valor;
    No* prox;
};

struct lista {
    No* cabeca;
};

Lista* cria_lista() {
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->cabeca = NULL;
    return l;
}

void insere_lista(Lista* l, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = l->cabeca;
    l->cabeca = novo;
}

void remove_lista(Lista* l, int valor) {
    No* ant = NULL;
    No* p = l->cabeca;
    while (p != NULL && p->valor != valor) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) {
        return;
    }
    if (ant == NULL) {
        l->cabeca = p->prox;
    } else {
        ant->prox = p->prox;
    }
    free(p);
}

void imprime_lista(Lista* l) {
    No* p = l->cabeca;
    while (p != NULL) {
        printf("%d ", p->valor);
        p = p->prox;
    }
    printf("\n");
}

void destroi_lista(Lista* l) {
    No* p = l->cabeca;
    while (p != NULL) {
        No* t = p->prox;
        free(p);
        p = t;
    }
    free(l);
}

void remove_nos(Lista* l1, Lista* l2, Lista* l3) {
    No* p1 = l1->cabeca;
    No* p2 = l2->cabeca;
    No* p3 = l3->cabeca;
    while (p1 != NULL && p2 != NULL && p3 != NULL) {
        if (p1->valor == p2->valor) {
            No* t = p1;
            p1 = p1->prox;
            remove_lista(l1, t->valor);
            free(t);
            p2 = p2->prox;
        } else if (p1->valor == p3->valor) {
            No* t = p1;
            p1 = p1->prox;
            remove_lista(l1, t->valor);
            free(t);
            p3 = p3->prox;
        } else if (p1->valor < p2->valor || p1->valor < p3->valor) {
            p1 = p1->prox;
        }
    }
    while (p1 != NULL && p2 != NULL) {
        if (p1->valor == p2->valor) {
            No* t = p1;
            p1 = p1->prox;
            remove_lista(l1, t->valor);
            free(t);
        } else if (p1->valor < p2->valor) {
        p1 = p1->prox;
    } else {
        p2 = p2->prox;
    }
}
while (p1 != NULL && p3 != NULL) {
    if (p1->valor == p3->valor) {
        No* t = p1;
        p1 = p1->prox;
        remove_lista(l1, t->valor);
        free(t);
        p3 = p3->prox;
    } else if (p1->valor < p3->valor) {
        p1 = p1->prox;
    } else {
        p3 = p3->prox;
    }
}
}