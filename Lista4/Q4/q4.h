#ifndef Q4_H
#define Q4_H
#define SIZE 7

typedef struct{
    int matricula;
    char* nome;
}Aluno;

typedef struct No{
    Aluno aluno;
    struct No* prox;
}No;

typedef struct{
    No** elemento;
    int tam;
}Tabela;

Tabela* criarTabela();
void inserir(Tabela* tabela,int mat,char* nome);
void remover(Tabela* tabela,int mat);
No* procura(Tabela*tabela, int mat);
float media(Tabela* tabela);
#endif