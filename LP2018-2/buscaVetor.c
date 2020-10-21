#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main ()

{
    int vet [50], i, chave;
    bool c;
        //vet [1] = i+1;

    srand(time(NULL));

    for (i = 0; i < 50; i++) {
        vet[i]= rand () % 51;
        }

    for (i = 0; i < 50; i++){
        printf("vet[%d] = %d\n", i, vet [i]);
    }

    printf("Entre com o numero para buscar no vetor:\n");
    scanf("%d", &chave);

    for (i = 0; i < 50; i++) {
        if (vet[i] == chave){
        c = true;
        i = 50;
        }
        else {
        c = false;
        }
        }
    if (c) {
    printf("Este numero consta na matriz\n");
    } else {
    printf("Este numero nao consta na matriz\n");
    }

}
