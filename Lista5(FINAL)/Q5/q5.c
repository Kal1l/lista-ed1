#include <stdio.h>
#include <stdlib.h>
#include "q5.h"

ArvoreAVL* criarArvoreAVL() {
    ArvoreAVL* arvore = (ArvoreAVL*)malloc(sizeof(ArvoreAVL));
    arvore->raiz = NULL;
    return arvore;
}

NoAVL* criarNoAVL(int id, int votos) {
    NoAVL* novoNo = (NoAVL*)malloc(sizeof(NoAVL));
    novoNo->id = id;
    novoNo->votos = votos;
    novoNo->altura = 1;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

int obterAltura(NoAVL* no) {
    if (no == NULL)
        return 0;
    return no->altura;
}

int obterFatorBalanceamento(NoAVL* no) {
    if (no == NULL)
        return 0;
    return obterAltura(no->esquerda) - obterAltura(no->direita);
}

NoAVL* rotacionarDireita(NoAVL* no) {
    NoAVL* pivot = no->esquerda;
    NoAVL* temp = pivot->direita;

    pivot->direita = no;
    no->esquerda = temp;

    no->altura = 1 + max(obterAltura(no->esquerda), obterAltura(no->direita));
    pivot->altura = 1 + max(obterAltura(pivot->esquerda), obterAltura(pivot->direita));

    return pivot;
}

NoAVL* rotacionarEsquerda(NoAVL* no) {
    NoAVL* pivot = no->direita;
    NoAVL* temp = pivot->esquerda;

    pivot->esquerda = no;
    no->direita = temp;

    no->altura = 1 + max(obterAltura(no->esquerda), obterAltura(no->direita));
    pivot->altura = 1 + max(obterAltura(pivot->esquerda), obterAltura(pivot->direita));

    return pivot;
}

NoAVL* balancearNo(NoAVL* no) {
    no->altura = 1 + max(obterAltura(no->esquerda), obterAltura(no->direita));

    int fatorBalanceamento = obterFatorBalanceamento(no);

    if (fatorBalanceamento > 1) {
        if (obterFatorBalanceamento(no->esquerda) >= 0)
            return rotacionarDireita(no);
        else {
            no->esquerda = rotacionarEsquerda(no->esquerda);
            return rotacionarDireita(no);
        }
    }
    else if (fatorBalanceamento < -1) {
        if (obterFatorBalanceamento(no->direita) <= 0)
            return rotacionarEsquerda(no);
        else {
            no->direita = rotacionarDireita(no->direita);
            return rotacionarEsquerda(no);
        }
    }

    return no;
}

NoAVL* inserirNo(NoAVL* no, int id, int votos) {
    if (no == NULL)
        return criarNoAVL(id, votos);

    if (id < no->id)
        no->esquerda = inserirNo(no->esquerda, id, votos);
    else if (id > no->id)
        no->direita = inserirNo(no->direita, id, votos);
    else // Candidato com o mesmo ID já existe
        return no;

    return balancearNo(no);
}

void inserirCandidato(ArvoreAVL* arvore, int id, int votos) {
    arvore->raiz = inserirNo(arvore->raiz, id, votos);
}

NoAVL* encontrarNoMinimo(NoAVL* no) {
    NoAVL* atual = no;

    while (atual && atual->esquerda != NULL)
        atual = atual->esquerda;

    return atual;
}

NoAVL* removerNo(NoAVL* no, int id) {
    if (no == NULL)
        return no;

    if (id < no->id)
        no->esquerda = removerNo(no->esquerda, id);
    else if (id > no->id)
        no->direita = removerNo(no->direita, id);
    else {
        if (no->esquerda == NULL || no->direita == NULL) {
            NoAVL* temp = no->esquerda ? no->esquerda : no->direita;

            if (temp == NULL) {
                temp = no;
                no = NULL;
            }
            else
                *no = *temp;

            free(temp);
        }
        else {
            NoAVL* temp = encontrarNoMinimo(no->direita);
            no->id = temp->id;
            no->votos = temp->votos;
            no->direita = removerNo(no->direita, temp->id);
        }
    }

    if (no == NULL)
        return no;

    return balancearNo(no);
}

void removerCandidato(ArvoreAVL* arvore, int id) {
    arvore->raiz = removerNo(arvore->raiz, id);
}

void destruirArvoreAVL(NoAVL* no) {
    if (no == NULL)
        return;

    destruirArvoreAVL(no->esquerda);
    destruirArvoreAVL(no->direita);
    free(no);
}
