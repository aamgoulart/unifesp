
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char nome [100], inverso [100];
    int tamanho, a, b;

    printf("Insira a palavra\n");
    fgets(nome, 100, stdin);
    tamanho = strlen (nome);
    nome [tamanho-1]='\0';

    for (a=0; nome[a]!='\0'; a++){
        inverso[b]= nome[a];
        b--;
    }
    if (nome==inverso){
        printf("é um palindromo\n");
    } else {
        printf("não é um palindromo\n");
    }


}
