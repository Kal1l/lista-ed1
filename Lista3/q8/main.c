/*Utilizamos a pilha dinamica pela vantagem de não ter
limitação na entrada,além de que com a pilha, a inversão
dos elementos se torna mais fácil, visto que a inserção
é o inverso de uma lista, ou fila, onde o primeiro 
a entra vai ser o último a sair. */

#include <stdio.h>
#include <stdlib.h>
#include "palindromo.c"

int main(){
    char str[MAX];

    printf("Digite uma palavra: ");
    scanf("%s",str);

    if(palindromo(str)){
        printf("%s eh palindromo. \n",str);
    } else{
        printf("%s nao eh um palindromo",str);
    }

    return 0;
}