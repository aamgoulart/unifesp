#include <stdio.h>
#include <stdlib.h>
 
 
int converter (char letra){
    if (letra >= 97 && letra <= 122){
        letra = letra -97;
    } else if (letra >= 65 && letra <= 90) {
        letra = letra - 65;
    }
 
    return letra;
}
 
int buscaLetra(int grafo[1024][1024], int coord, int A){
    int i, cont=0;
 
    for (i=0; i<A; i++){
        if (grafo[coord][i] == 0){
            cont++;
        }
    }
    
    cont--;
 
    return cont;
}
 
int main (){
    int grafo[1024][1024];
    int V, A, i, busca, aux,j;
    char S;
    int  X, Y;
    char M, N;
    /*S: busca
    V: qtd vertice
    A: qtd aresta */
    scanf("%c %d %d", &S, &V, &A);
    getchar();
    for (i=0; i<A; i++){
        scanf("%c %c", &M, &N);
        getchar();
        X = converter (M);
        Y = converter (N);
        grafo[X][Y] = 1;
        grafo[Y][X] = 1;
    }
    aux = converter (S);
    busca = buscaLetra(grafo, aux, V);
    printf("%d", busca);
}
