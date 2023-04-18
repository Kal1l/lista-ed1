#include "questao7.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Pilha* cria_Pilha(){
    Pilha *pi = (Pilha*) malloc(sizeof(Pilha));
    pi->topo = -1;
    pi->dados = (int*) malloc(MAX * sizeof(int));
    return pi;
}

void libera_Pilha(Pilha *pi) {
free(pi->dados);
free(pi);
}

void insere_Pilha(Pilha *pi, int valor) {
    if (pi->topo == MAX - 1) {
        printf("Erro: pilha cheia!\n");
        exit(1);
    }

    pi->topo++;
    pi->dados[pi->topo] = valor;
}

int remove_Pilha(Pilha *p, int *valor) {
    if (pilha_vazia(p)) {
        printf("Erro: pilha vazia!\n");
        exit(1);
    }

    *valor = p->dados[p->topo];
    p->topo--;

    return 1;
}

int Pilha_vazia(Pilha *pi) {
return (pi->topo == -1);
}

int converte_para_decimal(int base, Pilha *pi) {
    int decimal = 0;
    int potencia = 0;
    int valor;

    while (!pilha_vazia(pi)) {
        pilha_desempilha(pi, &valor);
        decimal += valor * pow(base, potencia);
        potencia++;
    }

    return decimal;
}