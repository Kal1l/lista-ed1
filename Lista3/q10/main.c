#include <stdio.h>
#include "questao10.c"

int main() {
    topo1 = -1;
    topo2 = MAX;

    insere_pilha(1, 10);
    insere_pilha(2, 20);
    insere_pilha(1, 30);
    insere_pilha(2, 40);

    printf("Desempilhando da pilha 1: %d\n", remove_pilha(1));
    printf("Desempilhando da pilha 2: %d\n", remove_pilha(2));
    printf("Desempilhando da pilha 1: %d\n", remove_pilha(1));
    printf("Desempilhando da pilha 2: %d\n", remove_pilha(2));
    printf("Desempilhando da pilha 1: %d\n", remove_pilha(1));

    insere_pilha(1, 50);
    insere_pilha(2, 60);

    printf("Desempilhando da pilha 2: %d\n", remove_pilha(2));
    printf("Desempilhando da pilha 1: %d\n", remove_pilha(1));
    printf("Desempilhando da pilha 2: %d\n", remove_pilha(2));

    return 0;
}