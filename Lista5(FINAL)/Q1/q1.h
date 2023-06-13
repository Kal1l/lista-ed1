#ifndef Q1_H
#define Q1_H

typedef struct No {
    int chave;
    struct No* esq;
    struct No* dir;
} No;

void insere(No** raiz, int chave);
void preOrdem(No* raiz);
void emOrdem(No* raiz);
void posOrdem(No* raiz);
int busca(No* raiz, int chave);
int min(No* raiz);
int max(No* raiz);
double media(No* raiz);
int qtdNosNull(No* raiz);
int somaChaves(No* raiz);
int multiplosDe3(No* raiz);
int qtdNos(No* raiz);
int qtdNosFolha(No* raiz);
int altura(No* raiz);
int estritamenteBinaria(No* raiz);

#endif