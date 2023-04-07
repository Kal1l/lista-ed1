#include <stdio.h>
#include <stdlib.h>
#include "numero_complexo.h"

numero_complexo *criar_complexo(float real,float imaginario){
    numero_complexo* n=(numero_complexo*) malloc(sizeof(numero_complexo));
    n->x=real;
    n->y=imaginario;
    return n;
}

void deletar_complexo(numero_complexo* n){
    free(n);
}

numero_complexo* add_complexo(numero_complexo* n1,numero_complexo* n2){
    return (criar_complexo(n1->x + n2->x,(n1->y+ n2->y)*-1));
}

numero_complexo* mult_complexo(numero_complexo* n1,numero_complexo* n2){
    return (criar_complexo(n1->x * n2->x - (n1->y * n2->y)*-1,(n1->x * n2->y)*-1 + (n1->y + n2->x)*-1));
}