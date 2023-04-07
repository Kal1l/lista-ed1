#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

ponto_t* cria(float x,float y){
    ponto_t*p =(ponto_t*)malloc(sizeof(ponto_t));
    if(p==NULL){
        printf("Memória insuficiente!\n");
        exit(1);
    }
    p->x=x;
    p->y=y;
    return p;
}

void libera(ponto_t* p){
    free(p);
}

void acessa(ponto_t* p,float*x,float*y){
    *x = p->x;
    *y = p->y;
}

void atribui(ponto_t* p,float x,float y){
    p->x=x;
    p->y=y;
}

float distancia(ponto_t* p1,ponto_t* p2){
    float dx= p2->x - p1->x;
    float dy= p2->y - p2->y;
    return sqrt(dx*dx+dy*dy);
}

ponto_t* soma_ponto(ponto_t* p1,ponto_t* p2){
    ponto_t* soma=cria((p1->x+p2->x),(p1->y+p2->y));
    return soma;
}

ponto_t* sub_ponto(ponto_t* p1,ponto_t* p2){
    ponto_t* sub=cria ((p1->x-p2->x),(p1->y-p2->y));
    return sub;
}

void imprime_ponto(ponto_t* p){
    printf("X: %.2f\n",p->x);
    printf("Y: %.2f\n",p->y);
    printf("-----------------\n");
}