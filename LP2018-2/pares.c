#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, soma;
    soma = 0;
    i = 0;
    for (i = 0; i < 100; i++){
        if (i%1 == 0)
        printf("%d\n", i);
        soma = soma + i;

    }

    printf("%d", soma);
}
