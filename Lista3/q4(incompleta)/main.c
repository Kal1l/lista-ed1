#include <stdio.h>
#include <stdlib.h>
#include "inverte_fila.c"

int main(){
    Fila* fila=cria_Fila();

    insere_Fila(fila,1);
    insere_Fila(fila,2);
    insere_Fila(fila,3);
    printf("Fila:\n");
    while (fila->qtd!=0) {
        int valor=remove_Fila(fila);
        printf("%d ", valor);
    }
    insere_Fila(fila,1);
    insere_Fila(fila,2);
    insere_Fila(fila,3);
    inverte_fila(fila);
    printf("Fila invertida:\n");
    while (fila->qtd!=0) {
        int valor=remove_Fila(fila);
        printf("%d ", valor);
    }

    libera_Fila(fila);
    return 0;
}