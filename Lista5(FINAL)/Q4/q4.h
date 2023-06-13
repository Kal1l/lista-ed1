#ifndef Q4_H
#define Q4_H
typedef struct No {
    int id;
    char* data;
    struct No* esq;
    struct No* dir;
    int alt;
} No;
typedef struct AVLTree {
    No* raiz;
} AVLTree;

AVLTree* criar();
void libera(AVLTree* arv);
void insere(AVLTree* arv, int id, const char* data);
int mais_novo(AVLTree* arv);
int mais_velho(AVLTree* arv);

#endif