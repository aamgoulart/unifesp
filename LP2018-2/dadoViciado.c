#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, vet[6]={0,0,0,0,0,0}, n, face;
    printf("Insira o valor para a testagem do dado\n");
    scanf("%d",&n);
    srand(time(NULL));
    for (i = 0; i < n; i++){
    face=rand()%6;
    vet[face]++;
    }
    printf("Numero de repetições da mesma face\n");
    for (i=0; i<6; i++){
    printf("\t%d:%d", i+1, vet[i]);
    }
    return 0;
}
