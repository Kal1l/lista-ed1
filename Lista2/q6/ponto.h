#include <stdio.h>

typedef struct{
    float x;
    float y;
}ponto_t;

ponto_t* cria(float x,float y);
void libera(ponto_t* ponto);
void acessa(ponto_t* ponto,float*x,float*y);
void atribui(ponto_t* ponto,float x,float y);
float distancia(ponto_t* p1,ponto_t* p2);
ponto_t* soma_ponto(ponto_t* p1,ponto_t* p2);
ponto_t* sub_ponto(ponto_t* p1,ponto_t* p2);
void imprime_ponto(ponto_t* p);