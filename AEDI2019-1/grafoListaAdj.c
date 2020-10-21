#include <stdio.h>
#include <stdlib.h>

typedef struct tipoAresta {
  int v;
  int peso;
  float custo;
  struct tipoAresta *prox;
  struct tipoAresta *primeiro;
} Aresta;

typedef struct tipoVertice {
  Aresta *lista;
  Aresta *prim;
  int num;
  struct tipoVertice *prox;
  float custo;
  int Vant;
} Vertice;

typedef struct  tipoGrafo {
  int tam;
  Vertice *v;
  Vertice *prim;
} Grafo;

void inicializaGrafo(int N, Grafo *G){
  G->v = NULL;
  G->tam = N;
  G->prim = NULL;
}

void criaVertice (Grafo *G){
  int i;

  for (i=0; i<G->tam;i++){
    Vertice *novoV = malloc (sizeof(Vertice));
    Vertice *anterior;
    Vertice *aux = G->prim;

    novoV->lista = NULL;
    novoV->num = i;
    novoV->prox = NULL;
    novoV->custo = 0; //inifnito
    novoV->Vant = NULL;
    if (G->prim == NULL){
      G->prim = novoV;
    } else {
      while (aux != NULL){
        anterior = aux;
        aux = aux->prox;
      
      anterior->prox = novoV;
    

  
}

void criaAresta(Grafo *G, int X, int Y, int peso){
  Vertice *auxV = G->prim;
  Vertice *anteriorV;
  while (auxV != NULL && auxV->num != X){
    anteriorV = auxV;
    auxV = auxV->prox;
  

  Aresta *novoA = malloc (sizeof(Aresta));
  novoA->v = Y;
  novoA->peso = peso;
  
  if (auxV->prim == NULL){
    auxV->prim = novoA;
    novoA->primeiro = novoA;
    novoA->prox = NULL;
  } else {
    Aresta *auxA = auxV->prim;
    Aresta *anteriorA;
    while (auxA != NULL && Y > auxA->v){
      anteriorA = auxA;
      auxA = auxA->prox;
    
    if (auxA == NULL){
      anteriorA->prox = novoA;
      novoA->prox = NULL;
    } else if (auxA == auxV->prim){
      novoA->prox = auxA;
      auxV->prim = novoA;
    } else {
      novoA->prox = anteriorA->prox;
      anteriorA->prox = novoA;
    
  
}

void imprimeAresta(Grafo *G){
  Vertice *auxV = G->prim;

  while (auxV != NULL){
    printf ("%d: ", auxV->num);
    Aresta *auxA = auxV->prim;
    while (auxA != NULL){
      printf("(%d,%d)\t", auxA->v, auxA->peso);
      auxA = auxA->prox;
    
    auxV = auxV->prox;
    printf("\n");
  
}
