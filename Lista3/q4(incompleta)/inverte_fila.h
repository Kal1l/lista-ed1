#ifndef INVERTE_FILA_H
#define INVERTE_FILA_H
#define MAX 100

typedef struct fila Fila;
typedef struct pilha Pilha;

Fila* cria_Fila();
void libera_Fila(Fila*fi);
void insere_Fila(Fila *fi,int valor);
int remove_Fila(Fila*fi);
int Fila_vazia(Fila* fi);

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
void insere_Pilha(Pilha*pi,int valor);
int remove_Pilha(Pilha*pi);
int Pilha_vazia(Pilha* pi);

void inverte_fila(Fila *fi);

#endif