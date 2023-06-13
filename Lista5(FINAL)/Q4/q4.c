#include <stdlib.h>
#include <string.h>
#include "q4.h"

No* criarNo(int id, const char* data) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->id = id;
    novoNo->data = strdup(data);
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->alt = 1;
    return novoNo;
}
int retorna_altura(No* no) {
    if (no == NULL)
        return 0;
    return no->alt;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
void atualiza_altura(No* no) {
    no->alt = 1 + max(retorna_altura(no->esq), retorna_altura(no->dir));
}
No* rotaçãoDireita(No* y) {
    No* x = y->esq;
    No* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    atualiza_altura(y);
    atualiza_altura(x);

    return x;
}
No* rotaçãoEsquerda(No* x) {
    No* y = x->dir;
    No* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    atualiza_altura(x);
    atualiza_altura(y);

    return y;
}
int retorna_fb(No* no) {
    if (no == NULL)
        return 0;
    return retorna_altura(no->esq) - retorna_altura(no->dir);
}
No* insere_no(No* no, int id, const char* data) {
    if (no == NULL)
        return criarNo(id, data);

    if (id < no->id)
        no->esq = insere_no(no->esq, id, data);
    else if (id > no->id)
        no->dir = insere_no(no->dir, id, data);
    else
        return no;

    atualiza_altura(no);

    int balanceamento = balanceamento(no);

    // Caso esquerda-esquerda
    if (balanceamento > 1 && id < no->esq->id)
        return rotaçãoDireita(no);

    // Caso direita-direita
    if (balanceamento < -1 && id > no->dir->id)
        return rotaçãoEsquerda(no);

    // Caso esquerda-direita
    if (balanceamento > 1 && id > no->esq->id) {
        no->esq = rotaçãoEsquerda(no->esq);
        return rotaçãoDireita(no);
    }

    // Caso direita-esquerda
    if (balanceamento < -1 && id < no->dir->id) {
        no->dir = rotaçãoDireita(no->dir);
        return rotaçãoEsquerda(no);
    }

    return no;
}
void libera_no(No* no) {
    if (no == NULL)
        return;

    libera_no(no->esq);
    libera_no(no->dir);
    free(no->data);
    free(no);
}
AVLTree* criar(){
    AVLTree* arv = (AVLTree*)malloc(sizeof(AVLTree));
    arv->raiz = NULL;
    return arv;
}
void libera(AVLTree* arv){
    if (arv == NULL)
        return;
    libera_no(arv->raiz);
    free(arv);
}
void insere(AVLTree* arv, int id, const char* data) {
    if (arv == NULL)
        return;
    arv->raiz = insere_no(arv->raiz, id, data);
}
int no_mais_esquerda(No* no){
    if (no == NULL || no->esq == NULL)
        return no;
    return no_mais_esquerda(no->esq);
}
no_mais_direita(No* no){
    if (no == NULL || no->dir == NULL)
        return no;
    return no_mais_direita(no->dir);
}
int mais novo(AVLTree* arv){
    if (arv == NULL || arv->raiz == NULL)
        return -1;
    No* no_mais_direita = no_mais_direita(arv->raiz);
    return no_mais_direita->id;
}
int mais_velho(AVLTree* arv){
        if (arv == NULL || arv->raiz == NULL)
        return -1;
    No* no_mais_esquerda = no_mais_esquerda(arv->raiz);
    return no_mais_esquerda->id;
}
