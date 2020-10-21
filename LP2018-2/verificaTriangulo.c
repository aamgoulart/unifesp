#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z;
    printf("Insira três números para saber se é um triângulo.\n");
    printf("Insira o primeiro número.\n ");
    scanf("%d", &x);
    printf("Insira o segundo número.\n ");
    scanf("%d", &y);
    printf("Insira o terceiro número.\n ");
    scanf("%d", &z);

    printf((x < y + z) && (y < x + z) && (z < x + y) ? "é um triângulo" : "Não é um triângulo");
}
