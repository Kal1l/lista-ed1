#include <stdio.h>
#include "questao3.c"

int main() {
Lista* l1 = cria_lista();
Lista* l2 = cria_lista();
Lista* l3 = cria_lista();
insere_lista(l1, 1);
insere_lista(l1, 2);
insere_lista(l1, 3);
insere_lista(l1, 4);
insere_lista(l1, 5);

insere_lista(l2, 2);
insere_lista(l2, 4);
insere_lista(l2, 5);

insere_lista(l3, 1);
insere_lista(l3, 3);

printf("Lista 1 antes: ");
imprime_lista(l1);

remove_nos(l1, l2, l3);

printf("Lista 1 depois: ");
imprime_lista(l1);

destroi_lista(l1);
destroi_lista(l2);
destroi_lista(l3);

return 0;
}