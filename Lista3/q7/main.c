#include <stdio.h>
#include "questao7.h"

int main(){
    int base,valor;
    Pilha *pi;

    printf("Base do numero a ser converitdo: ");
    scanf("%d",&base);
    pi=cria_Pilha();

    printf("Digitos do numero (-1 para encerrar):");
    scanf("%d",&valor);

    while (valor != -1) {
        pilha_empilha(pi, valor);
        scanf("%d", &valor);
    }

    int decimal=converte_para_decimal(base,pi);
    printf("Numero em base decimal: %d\n",decimal);
    libera_Pilha(pi);

    return 0;
}