#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q3.h"

Time* criarTime(const char* nome, int score) {
    Time* novoTime = (Time*)malloc(sizeof(Time));
    if (novoTime == NULL) {
        printf("Erro ao alocar memória para um novo time.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(novoTime->nome, nome);
    novoTime->score = score;
    novoTime->esq = NULL;
    novoTime->dir = NULL;
    return novoTime;
}
void insere(Time** raiz, const char* nome, int score) {
    if (*raiz == NULL) {
        *raiz = criarTime(nome, score);
    } else {
        if (score < (*raiz)->score) {
            insere(&(*raiz)->esq, nome, score);
        } else {
            insere(&(*raiz)->dir, nome, score);
        }
    }
}
Time* busca(Time* raiz, const char* nome) {
    if (raiz == NULL || strcmp(raiz->nome, nome) == 0) {
        return raiz;
    }
    if (strcmp(raiz->nome, nome) > 0) {
        return busca(raiz->esq, nome);
    } else {
        return busca(raiz->dir, nome);
    }
}
void atualizarScore(Time* raiz, const char* nome, int novo_score){
    Time* time = busca(raiz, nome);
    if (time != NULL) {
        time->score = novo_score;
    } else {
        printf("Time não encontrado.\n");
    }
}
void ranking_aux(Time* raiz) {
    if (raiz != NULL) {
        displayRankingHelper(raiz->dir);
        printf("Time: %s, Pontuação: %d\n", raiz->nome, raiz->score);
        ranking_aux(raiz->esq);
    }
}
void ranking(Time* raiz) {
    if (raiz == NULL) {
        printf("Nenhum time cadastrado.\n");
    } else {
        printf("Classificação dos times:\n");
        ranking_aux(raiz);
    }
}
void libera(Time* raiz) {
    if (raiz != NULL) {
        freeTree(raiz->esq);
        freeTree(raiz->dir);
        free(raiz);
    }
}

