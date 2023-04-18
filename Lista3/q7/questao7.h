#ifndef QUESTAO7_H
#define QUESTAO7_H
#define MAX 100

struct pilha {
    int topo;
    int *dados;
};

typedef struct pilha Pilha;

Pilha* cria_Pilha();
void libera_Pilha(Pilha *pi);
void insere_Pilha(Pilha *pi, int valor);
int remove_Pilha(Pilha *pi, int *valor);
int Pilha_vazia(Pilha *pi);
int converte_para_decimal(int base, Pilha *pi);

#endif