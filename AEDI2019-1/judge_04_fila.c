#include <stdio.h>
#include <stdlib.h>
 
typedef struct{
    int idCaixa;
    int *atendidos;
    int tempo;
    int quantidade;
    int fim;
} tipoCaixa;
 
typedef struct{
    tipoCaixa *filaCaixa;
    int inicio;
    int fim;
    int tam;
    int qtd;
} tipoFila;
 
void inicializaFila(tipoFila *caixa, int N, int A);
void insereLista(tipoFila *caixa, int T, int ID, int A);
int buscaMenorCaixa(tipoFila *caixa, int A);
void saida(tipoFila *caixa, int A);
void desaloca(tipoFila *caixa, int A);
 
 
int main (){
    tipoFila caixa;
    int N,A, T, i;
 
   // printf("coloca N e A\n");
    scanf("%d %d", &N, &A);
    if (N>=1 && N<=1023 && A>=1 && A<=25){
        inicializaFila(&caixa, N, A);
        //printf("inicializou a lista\n");
 
        for (i=0; i<N; i++){
          //  printf("inserir tempo\n");
            scanf("%d", &T);
            if (T>= 0 && T<= 1000){
            //    printf("antes da função\n");
                insereLista(&caixa, T, i+1, A);
              //  printf("inseriu\n");
            }
        }
 
        
 
        saida(&caixa, A); 
     //   desaloca(&caixa, A);
    }
 
}
 
void inicializaFila(tipoFila *caixa, int N, int A){
    int i, j;
    caixa->inicio=0;
    caixa->fim=0;
    caixa->qtd=0;
    caixa->tam=A-1;
    caixa->filaCaixa = malloc (N * sizeof(int));
    for (i=0; i<A; i++){
        caixa->filaCaixa[i].atendidos = malloc (N * sizeof(int));
        caixa->filaCaixa[i].idCaixa = i+1;
        caixa->filaCaixa[i].quantidade =0;
        caixa->filaCaixa[i].tempo=0;
        caixa->filaCaixa[i].fim=0;
        caixa->fim++;
        caixa->qtd++;
    }
/*
    for (i=0; i<A; i++){
        for (j=0; j<N; j++){
            printf("porra %d %d ____ %d\n", i , j, caixa->filaCaixa[i].atendidos[j]);
        }
    }*/
}
 
 
void insereLista(tipoFila *caixa, int T, int ID, int A){
    int menor, indice;
 
    menor = buscaMenorCaixa(caixa, A);
 
//    printf("MENOR %d", menor);
 
    indice = caixa->filaCaixa[menor].fim;
 
    //printf("AQUI TA O ID %d\n", ID);
    
    caixa->filaCaixa[menor].atendidos[indice] = ID;
    caixa->filaCaixa[menor].tempo += T;
    caixa->filaCaixa[menor].quantidade++;
    caixa->filaCaixa[menor].fim++;
 
   // printf("coloquei o id aqui %d\n", caixa->filaCaixa[menor].atendidos[indice]);
 
}
 
int buscaMenorCaixa(tipoFila *caixa, int A){
    int i, menor, indiceMenor;
    //printf("menor\n");
    
 
    menor = caixa->filaCaixa[0].tempo;
 
        for (i=0; i<A; i++){
         //   printf("aqui aqui %d ---%d jjjjjjj %d\n",i, caixa->filaCaixa[i].tempo, menor);
            if (caixa->filaCaixa[0].tempo == 0){
                indiceMenor=0;
            } else {
                if (caixa->filaCaixa[i].tempo < menor){
              //  printf("entrouuuuuu\n");
                menor = caixa->filaCaixa[i].tempo;
                indiceMenor = i;
                //printf("RECEBEUUUUUU %d\n", indiceMenor);
                } else {
                    indiceMenor = i-1;
                }
            }
        }
        
  //  printf("%d menor\n", indiceMenor);
    return indiceMenor;
}
 
void saida (tipoFila *caixa, int A){
    int i, j;
 
//    printf("teste %d", caixa->tam);
 
    for (i=0; i<A; i++){
        printf("%d: ", caixa->filaCaixa[i].idCaixa);
        for (j=0; j<caixa->filaCaixa[i].quantidade; j++){
        printf("%d ", caixa->filaCaixa[i].atendidos[j]);
        }
        printf("\n");
    }
 
} 
 
void  desaloca(tipoFila *caixa, int A){
    int i;
    for (i=0; i<A; i++){
        free(caixa->filaCaixa[i].atendidos);
    }
    free(caixa);
 
    return caixa;
}
