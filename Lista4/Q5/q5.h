#ifndef Q5_H
#define Q5_H
#define SIZE 7
typedef struct{
    int codigo,qtd;
    char* nome;
    float preco;
}Produto;

typedef struct No{
    Produto produto;
    struct No* prox;
}No;

typedef struct{
    No** elemento;
    int tam;
}Tabela;

Tabela* criarTabela();
void inserir(Tabela* tabela,int codigo,char* nome,float preco,int qtd);
No* procurar(Tabela*tabela, int codigo);
void remover(Tabela* tabela,int codigo);
void atualizarpreco(Tabela* tabela,int codigo,float preconovo);
No* precomax(Tabela* tabela);
#endif