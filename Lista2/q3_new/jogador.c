#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador.h"

void atribuir_jogador(Jogador* jogador, char nome[], int jogos, int gols, int assistencias) {
    strcpy(jogador->nome, nome);
    jogador->jogos = jogos;
    jogador->gols = gols;
    jogador->assistencias = assistencias;
}

void imprimir_jogador(Jogador jogador) {
    printf("Nome: %s\n", jogador.nome);
    printf("Jogos: %d\n", jogador.jogos);
    printf("Gols: %d\n", jogador.gols);
    printf("Assistências: %d\n", jogador.assistencias);
}

int bom_jogador(Jogador jogador){
    return(jogador.gols + jogador.assistencias >= 20 && jogador.jogos <= jogador.gols + jogador.assistencias);
}
