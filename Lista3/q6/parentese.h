#ifndef PARENTESE_H
#define PARENTESE_H

typedef struct 
{
    int qtd;
    char *dados;
}Pilha;

void cria_Pilha(Pilha* pi,int tamanho);
void deleta_Pilha(Pilha* pi);
void insere_Pilha(Pilha* pi,char dado);
char remove_Pilha(Pilha* pi);
int pilha_vazia(Pilha* pi);
int parentese(char* expressao);

#endif