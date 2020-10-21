#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z;
    printf("Insira três números para saber que tipo de triângulo é .\n");
    printf("Insira o primeiro número.\n ");
    scanf("%d", &x);
    printf("Insira o segundo número.\n ");
    scanf("%d", &y);
    printf("Insira o terceiro número.\n ");
    scanf("%d", &z);

    if (x == y && x == z){
    printf("O triângulo é equilatero\n");
    } else if (x == y|| x == z){
    printf("O triângulo é isosceles\n");
    } else {
    printf ("O triângulo é escaleno\n");
}

}
