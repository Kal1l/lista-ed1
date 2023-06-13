#ifndef Q3_H
#define Q3_H

// Definição da estrutura do nó da árvore
typedef struct Time {
    char nome[50];
    int score;
    struct Time* esq;
    struct Time* dir;
} Time;

// Funções para manipular a árvore
void insere(Time** root, const char* nome, int score);
Time* busca(Time* root, const char* nome);
void atualizarScore(Time* root, const char* nome, int new_score);
void ranking(Time* root);
void libera(Time* root);

#endif