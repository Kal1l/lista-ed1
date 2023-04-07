#include <stdio.h>
#include <stdlib.h>
#include "numero_complexo.c"

int main(){
    numero_complexo* z1=criar_complexo(1.0,3.0);
    numero_complexo* z2=criar_complexo(-3.0,5.0);

    numero_complexo* z3=add_complexo(z1,z2);
    numero_complexo* z4=mult_complexo(z3,z1);

    printf("z1 = %.2f + %.2f\n",z1->x,z1->y);
    printf("z2 = %.2f + %.2f\n",z2->x,z2->y);
    printf("z3(z1+z2) = %.2f + %.2f\n",z3->x,z3->y);
    printf("z4(z3*z1) = %.2f + %.2f\n",z4->x,z4->y);

    deletar_complexo(z1);
    deletar_complexo(z2);
    deletar_complexo(z3);
    deletar_complexo(z4);

}

