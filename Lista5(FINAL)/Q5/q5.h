#ifndef Q5_H
#define Q5_H

typedef struct NoAVL {
    int id;
    int votos;
    int altura;
    struct NoAVL* esquerda;
    struct NoAVL* direita;
} NoAVL;

typedef struct ArvoreAVL {
    NoAVL* raiz;
} ArvoreAVL;

ArvoreAVL* criarArvoreAVL();
NoAVL* criarNoAVL(int id, int votos);
int obterAltura(NoAVL* no);
int obterFatorBalanceamento(NoAVL* no);
NoAVL* rotacionarDireita(NoAVL* no);
NoAVL* rotacionarEsquerda(NoAVL* no);
NoAVL* balancearNo(NoAVL* no);
NoAVL* inserirNo(NoAVL* no, int id, int votos);
void inserirCandidato(ArvoreAVL* arvore, int id, int votos);
NoAVL* encontrarNoMinimo(NoAVL* no);
NoAVL* removerNo(NoAVL* no, int id);
void removerCandidato(ArvoreAVL* arvore, int id);
void destruirArvoreAVL(NoAVL* no);

#endif
