#ifndef Q3_H
#define Q3_H
#define TABLE_SIZE 7

typedef struct{
int chave,valor,ativa;
}Elemento;

typedef struct{
Elemento* tabela;
int tam;
}Tabela;

Tabela* criarTabela();
int hash(int chave,int tam);
int sondagem(int pos,int tam);
void inserir(Tabela* tabela,int chave,int valor);
int buscar(Tabela* tabela,int chave);
#endif