#include "parentese.c"
#include <stdio.h>
int parentese(char* expressao){
    Pilha pi;
    int i,tamanho=0;
    char c;

    tamanho=strlen(expressao);

    cria_Pilha(&pi,tamanho);

    for(i=0;i<tamanho;i++){
        c=expressao[i];
        if(c=='('){
            insere_Pilha(&pi,c);
        }
        else if(c==')'){
            if(pilha_vazia(&pi)){
                deleta_Pilha(&pi);
                return 0;
            }
            else{
                remove_Pilha(&pi);
            }
        }
    }

    if(pilha_vazia(&pi)){
        deleta_Pilha(&pi);
        return 1;
    }
    else{
        deleta_Pilha(&pi);
        return 0;
    }
}

int main(){
    char expressao[10];
    printf("Digite uma expressao: \n");
    scanf("%s",expressao);
    if(parentese(expressao)){
        printf("Correto.\n");
    }
    else{
        printf("Incorreto.\n");
    }
    return 0;
}