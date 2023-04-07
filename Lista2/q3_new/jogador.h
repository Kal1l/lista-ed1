#include <stdio.h>

typedef struct{
    char nome[50];
    int jogos;
    int gols;
    int assistencias;
}Jogador;

void atribuir_jogador(Jogador* jogador, char nome[], int jogos, int gols, int assistencias);
void imprimir_jogador(Jogador jogador);
int bomJogador(Jogador jogador);