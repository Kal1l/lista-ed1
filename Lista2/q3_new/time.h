#ifndef TIME_H
#define TIME_H
#include <stdio.h>
#include "jogador.h"

typedef struct{
    char nome[50];
    Jogador jogadores[11];
    int vitorias;
    int empates;
    int derrotas;
}Time;

void atribuir_time(Time* time, char nome[], Jogador jogadores[], int vit, int emp, int der);
void imprimir_time(Time time);
int pontuacao(Time time);

#endif