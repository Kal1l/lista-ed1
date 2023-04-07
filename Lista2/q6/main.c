#include <stdio.h>
#include "ponto.c"

int main(){
    ponto_t* ponto1=cria(3,4);
    ponto_t* ponto2=cria(2,3);
    printf("Ponto 1:\n");
    imprime_ponto(ponto1);
    printf("Ponto 2:\n");
    imprime_ponto(ponto2);
    float dist=distancia(ponto1,ponto2);
    printf("A distancia entre os dois pontos eh: %.2f\n",dist);
    atribui(ponto2,1,4);
    printf("Modificando o ponto 2:\n");
    imprime_ponto(ponto2);
    float dist2=distancia(ponto1,ponto2);
    printf("Depois de mudar o ponto 2, a distancia entre os dois pontos eh: %.2f\n",dist2);

    ponto_t* soma=soma_ponto(ponto1,ponto2);
    printf("Soma dos pontos:\n");
    imprime_ponto(soma);
    ponto_t* sub=sub_ponto(ponto1,ponto2);
    printf("Subtracao dos pontos:\n");
    imprime_ponto(sub);

    libera(ponto1);
    libera(ponto2);
    libera(soma);
    libera(sub);
    return 0;
}