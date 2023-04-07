#include <stdio.h>
#include "esfera.c"

int main(){
    esfera_t* esfera=nova_esfera(3.0);

    float raio_esfera=raio(esfera);
    
    float area_esfera=area(esfera);

    float volume_esfera=volume(esfera);

    printf("Raio da esfera: %.2f\n",raio_esfera);
    printf("Area da esfera: %.2f\n",area_esfera);
    printf("Volume da esfera: %.2f\n",volume_esfera);

    deleta_esfera(esfera);
    return 0;
}