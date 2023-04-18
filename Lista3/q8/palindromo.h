#ifndef PALINDROMO_H
#define PALINDROMO_H
#define MAX 100

typedef struct No No;
struct No{
    char letra;
    No *prox;
};

void insere(No **topo, char letra);
char remover(No **topo);
int palindromo(char *str);

#endif