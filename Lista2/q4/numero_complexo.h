#include <stdio.h>
#include <stdlib.h>
/*
z=x+iy
x-> REAL 
y->IMAGINÁRIO
i=-1
*/

typedef struct numero_complexo{
float x;
float y;
}numero_complexo;

numero_complexo *criar_complexo(float real,float imaginario);
void deletar_complexo(numero_complexo* n);
numero_complexo* add_complexo(numero_complexo* n1,numero_complexo* n2);
numero_complexo* mult_complexo(numero_complexo* n1,numero_complexo* n2);
