#ifndef QUESTAO3_H
#define QUESTAO3_H

typedef struct no No;
typedef struct lista Lista;

Lista* cria_lista();
void insere_lista(Lista* l, int valor);
void remove_lista(Lista* l, int valor);
void imprime_lista(Lista* l);
void destroi_lista(Lista* l);

#endif