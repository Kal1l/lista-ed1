#include <stdio.h>
#include <stdlib.h>
#include "q1.h"

No* criaNo(int chave) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        exit(EXIT_FAILURE);
    }
    novoNo->chave = chave;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}
void insere(No** raiz, int chave) {
    if (*raiz == NULL) {
        *raiz = criaNo(chave);
    } else {
        if (chave < *raiz->chave) {
            insert(&(*raiz)->esq, chave);
        } else if (chave > (*raiz)->chave) {
            insert(&(*raiz)->dir, chave);
        }
    }
}
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        emOrdem(raiz->dir);
    }
}
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->chave);
    }
}
int busca(No* raiz, int chave) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->chave == chave) {
        return 1;
    }
    if (chave < raiz->chave) {
        return busca(raiz->esq, chave);
    } else {
        return busca(raiz->dir, chave);
    }
}
int min(No* raiz) {
    if (raiz == NULL) {
        printf("A árvore está vazia.\n");
        exit(EXIT_FAILURE);
    }
    while (raiz->esq != NULL) {
        raiz = raiz->esq;
    }
    return raiz->chave;
}
int max(No* raiz) {
    if (raiz == NULL) {
        printf("A árvore está vazia.\n");
        exit(EXIT_FAILURE);
    }
    while (raiz->dir != NULL) {
        raiz = raiz->dir;
    }
    return raiz->chave;
}
double media(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int soma = somaChaves(raiz);
    int qtd = qtdNos(raiz);
    return (double)soma / qtd;
}
int qtdNosNull(No* raiz) {
    if (raiz == NULL) {
        return 1;
    }
    return qtdNosNull(raiz->esq) + qtdNosNull(raiz->dir);
}
int somaChaves(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return raiz->chave + somaChaves(raiz->esq) + somaChaves(raiz->dir);
}
int multiplosDe3(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int qtd = multiplosDe3(raiz->esq) + multiplosDe3(raiz->dir);
    if (raiz->chave % 3 == 0) {
        qtd++;
    }
    return qtd;
}
int qtdNos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return qtdNos(raiz->esq) + qtdNos(raiz->dir) + 1;
}
int qtdNosFolha(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->esq == NULL && raiz->dir == NULL) {
        return 1;
    }
    return qtdNosFolha(raiz->esq) + qtdNosFolha(raiz->dir);
}
int altura(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int esqalt = altura(raiz->esq);
    int diralt = altura(raiz->dir);
    return (esqalt > diralt) ? (esqalt + 1) : (diralt + 1);
}
int estritamenteBinaria(No* raiz) {
    if (raiz == NULL) {
        return 1;
    }
    if ((raiz->esq == NULL && raiz->dir != NULL) || (raiz->esq != NULL && raiz->dir == NULL)) {
        return 0;
    }
    return estritamenteBinaria(raiz->esq) && estritamenteBinaria(raiz->dir);
}