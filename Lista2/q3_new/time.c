#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include "jogador.c"

void atribuir_time(Time* time, char nome[], Jogador jogadores[], int vit, int emp, int der) {
    strcpy(time->nome, nome);
    for(int i=0; i<11; i++) {
        time->jogadores[i] = jogadores[i];
    }
    time->vitorias = vit;
    time->empates = emp;
    time->derrotas = der;
}

void imprimir_time(Time time) {
    printf("Nome: %s\n", time.nome);
    printf("Jogadores:\n");
    for(int i=0; i<11; i++) {
        printf("  %s\n", time.jogadores[i].nome);
    }
    printf("Vitórias: %d\n", time.vitorias);
    printf("Empates: %d\n", time.empates);
    printf("Derrotas: %d\n", time.derrotas);
}

int pontuacao(Time time) {
    return (time.vitorias * 3) + time.empates;
}