#include <stdio.h>


typedef struct{
    float raio;
}esfera_t;

esfera_t* nova_esfera(float raio);
void deleta_esfera(esfera_t* esfera);
float raio(esfera_t* esfera);
float area(esfera_t* esfera);
float volume(esfera_t* esfera);

