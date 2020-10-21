#include <stdio.h>
#include <stdlib.h>

int main()
{
    int maior, menor, m, soma, media, t;
    printf("Programa que calcula a soma e media e define os numeros maior e menor\n");
    printf("Insira o valor. Para parar insira -1\n");
    scanf ("%d", &m);
    maior = m;
    menor = m;
    soma = m;
    media = m;
    while (m != -1){
        soma = soma + m;
        media = (media + m)/2;
        if (m > maior)
        maior = m;
        else if (m < menor)
        menor = m;
    scanf("%d", &m);
    }

    if (maior == -1 && menor ==-1){
        printf ("Nenhum valor valido");
    }
    else {
    printf("O maior e menor numero respectivamente e %d e %d\n. E a soma é %d\n. E a media %d\n", maior, menor, soma, media);
    }

}
