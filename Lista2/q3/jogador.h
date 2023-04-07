#ifndef JOGADOR_H
#define JOGADOR_H
typedef struct{
    char nome[50];
    int jogos;
    int gols;
    int assistencias;
}jogador_t;

jogador_t novo_jogador(char nome[],int jogos,int gols,int assistencias);
void listar_jogador(jogador_t jogador);
void bom_jogador(jogador_t jogador);

#endif