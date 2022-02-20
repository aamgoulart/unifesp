#include <stdio.h>
#define MAX 100

int troco(int vetor[], int tam, int valor) ;
int main () {
    int valor, D[4] = {25,10,5,1};

    scanf("%d", &valor);

    printf("%d", troco(D,3,valor));

}

int troco(int vetor[], int tam, int valor) {
    int T =0, t[MAX], i;

    for(i=0; i<tam; i++) {
        t[i] = valor/vetor[i];
        valor = valor - t[i]* vetor[i];
        T = T + t[i];
    }
    return T;
}