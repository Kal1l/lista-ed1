#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES 
#include <math.h>
#include "esfera.h"

esfera_t* nova_esfera(float raio){
    esfera_t* esfera=(esfera_t*) malloc(sizeof(esfera_t));
    esfera->raio=raio;
    return esfera;
};

void deleta_esfera(esfera_t* esfera){
    free(esfera);
}
float raio(esfera_t* esfera){
    return esfera->raio;
}
float area(esfera_t* esfera){
    return 4 * M_PI *pow(esfera->raio,2);
}
float volume(esfera_t* esfera){
    return (4/3) * M_PI * pow(esfera->raio,3);
}