#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q1.h"

Hash* criarHash(int tamanho) {
    Hash* hash = (Hash*)malloc(sizeof(Hash));
    hash->tamanho = tamanho;
    hash->registros = (Registro*)malloc(tamanho * sizeof(Registro));
    for (int i = 0; i < tamanho; i++) {
        strcpy(hash->registros[i].cidade, "");
    }
    return hash;
}
int funcaoHash(char cidade[], int numCaracteres) {
    int hash = 0;
    for (int i = 0; i < numCaracteres; i++) {
        hash += (int)cidade[i];
    }
    return hash;
}
void inserirRegistro(Hash* hash, char cidade[]) {
    int tamanho = hash->tamanho;
    int hashValue = funcaoHash(cidade, strlen(cidade)) % tamanho;
    while (strcmp(hash->registros[hashValue].cidade, "") != 0) {
        hashValue = (hashValue + 1) % tamanho;
    }
    strcpy(hash->registros[hashValue].cidade, cidade);
}
Registro* buscarRegistro(Hash* hash, char cidade[]) {
    int tamanho = hash->tamanho;
    int hashValue = funcaoHash(cidade, strlen(cidade)) % tamanho;
    while (strcmp(hash->registros[hashValue].cidade, "") != 0) {
        if (strcmp(hash->registros[hashValue].cidade, cidade) == 0) {
            return &(hash->registros[hashValue]);
        }
        hashValue = (hashValue + 1) % tamanho;
    }
    return NULL;
}
void liberarHash(Hash* hash) {
    free(hash->registros);
    free(hash);
}
