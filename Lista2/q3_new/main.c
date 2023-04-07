#include <stdio.h>
#include <string.h>
#include "jogador.c"
#include "time.c"

int main(){
    printf("Time A:");
    printf("------------------------------\n\n");
    jogador_time jogadores[11];
    char nomes[11][50]={"Roberto","Chico","Ronaldo","José","Junior","Gustavo","Diego","Alan","Jeremias","Cleiton","Paulo"};
    int jogos[11]={10,10,10,10,10,10,9,9,9,9,9};
    int gols[11]={3,5,6,7,8,9,0,4,6,9,1};
    int assistencias[11]={10,8,8,7,8,9,10,11,13,7,4};

    for(int i=0;i<11;i++){
        jogadores[i]=novo_jogador(nomes[i],jogos[i],gols[i],assistencias[i]);
    }

    int vitorias=3;int empates=2;int derrotas=1;
    char nome_time[]="Time A";

    time_fut* timea=novo_time(nome_time,jogadores,vitorias,empates,derrotas);
    listar_time(timea);
}