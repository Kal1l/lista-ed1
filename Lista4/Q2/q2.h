#ifndef Q2_H
#define Q2_H

typedef struct No{
    char* dado;
    struct No* prox;
}No;

typedef struct Tabela{
    No** elemento;
}Tabela;

Tabela* criaTabela();
unsigned int hash(char* chave);
void insere(Tabela* tabela,char* dado);
void remove(Tabela* tabela,char* dado);
int busca(Tabela* tabela, char* dado);

#endif