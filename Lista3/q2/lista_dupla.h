#ifndef LISTADUPLA_H
#define LISTADUPLA_H

typedef struct no{
    int valor;
    struct no* prox;
    struct no* ant;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int qtd;
}ListaDupla;


ListaDupla* cria_lista_dupla();
void insere_lista_dupla(ListaDupla* lista, int valor);
void remove_lista_dupla(ListaDupla* lista, int valor);

#endif