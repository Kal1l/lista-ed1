#include <stdio.h>
#include "lista_dupla.c"

int main() {
    ListaDupla* lista = cria_lista_dupla();
    insere_lista_dupla(lista, 1);
    insere_lista_dupla(lista, 2);
    insere_lista_dupla(lista, 3);
    insere_lista_dupla(lista, 4);
    printf("List size: %d\n", lista->qtd);
    remove_lista_dupla(lista, 2);
    printf("List size: %d\n", lista->qtd);
    return 0;
}