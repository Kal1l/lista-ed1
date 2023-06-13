#ifndef Q1_H
#define Q1_H

typedef struct {
    char cidade[50];
} Registro;

typedef struct {
    int tamanho;
    Registro* registros;
} Hash;

Hash* criarHash(int tamanho);
void inserirRegistro(Hash* hash, char cidade[]);
Registro* buscarRegistro(Hash* hash, char cidade[]);
void liberarHash(Hash* hash);

#endif