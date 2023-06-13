#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q3.h"

Tabela* criarTabela(){
    Tabela* tabela=(Tabela*)malloc(sizeof(Tabela));
    tabela->tabela=(Elemento*)malloc(sizeof(Elemento)*TABLE_SIZE);
    tabela->tam=TABLE_SIZE;
    //Inicia todas as entradas da tabela livres
    for(int i=0;i<tabela->tam;i++)
        tabela->tabela[i].ativa=0;

    return tabela;
}
int hash(int chave,int tam){
    return (chave & 0x7FFFFFFF) % tam;
}
int sondagem(int pos,int tam){
    return (pos+1) % tam;
}
void inserir(Tabela* tabela,int chave,int valor){
    int pos=hash(chave,tabela->tam);

    //Usa sondagem linear pra achar próxima posição dispoível
    while (tabela->tabela[pos].ativa){
        pos=sondagem(pos,tabela->tam);
    }
    //Ao encontrar insere elementos
    tabela->tabela[pos].chave=chave;
    tabela->tabela[pos].valor=valor;
    tabela->tabela[pos].ativa=1;
}
int buscar(Tabela* tabela,int chave){
    int pos=hash(chave,tabela->tam);
    //Usa sondagem para encontrar elemento na tabela
    while(tabela->tabela[pos].ativa){
        //Caso encontre o elemento o retorna
        if(tabela->tabela[pos].chave==chave)
            return tabela->tabela[pos].valor;
        pos=sondagem(pos,tabela->tam);
    }
    //caso não encontre
    return -1;
}

