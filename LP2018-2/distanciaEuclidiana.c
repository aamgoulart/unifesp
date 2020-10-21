#include <stdio.h>
 
int distancia (int coordenadas[30][30],int tam_cidade, int linha[], int tam_trajeto) {
    register int i,j,k;
    int soma, x, y;

        for (k=0; k< tam_trajeto-1; k++) { // percorro o vetor das coordenadas
            x = linha[k]; // acho x e Y
            y = linha [k+1];
            printf ("XXX %d\n", x);
            printf ("YYY %d\n", y);
            for (i=0; i < tam_cidade; i++) { 
                for (j=0; j< tam_cidade; j++){       // percorro a matriz do plano
                } 
            }  
            soma= soma + coordenadas[x][y];  // soma o role
            printf ("soma %d\n", soma);
        }
 
    return soma;    
 
}
 
 
 
int main () {
    int matriz[30][30],valor_matriz, vetor[30], valor_trajeto, trajeto; 
    register int i,j;

    // leituras 
 
    scanf ("%d", &valor_matriz);
 
    for (i=0; i < valor_matriz; i++) {
        for (j=0; j< valor_matriz; j++){
            scanf ("%d", &matriz[i][j]);
        }
    }
 
    scanf ("%d", &valor_trajeto);
 
    for (i=0; i < valor_trajeto; i++) {
        scanf ("%d", &vetor[i]);
    }

    // saidas
 
    printf ("%d", distancia (matriz, valor_matriz, vetor, valor_trajeto));
 
 
}
