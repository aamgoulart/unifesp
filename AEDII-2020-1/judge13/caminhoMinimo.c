#include <stdio.h> 
#include <limits.h>
#include <stdlib.h>
#define INF INT_MAX
#define MAX 1024
 
typedef struct Item {
    int valor;
    struct Item *prox;
} Item;
 
typedef struct {
    Item *topo;
} Lista;
 
void inicializaPilha(Lista *pilha) {
    pilha->topo = NULL;
}
 
int pilhaVazia(Lista *pilha) {
    if (pilha->topo == NULL)
        return 1;
    return 0;
}
 
void push(Lista *pilha, int ch) {
  Item *novo = (Item*)malloc(sizeof(Item));
  if (!novo) {
    exit(-1);
  }
  novo->valor = ch;
  novo->prox = pilha->topo;
  pilha->topo = novo;
}
 
int pop(Lista *pilha) {
  int c;
 
  if (pilhaVazia(pilha)) {
    return -1;
  }
 
  Item *P;
  P = pilha->topo;
  pilha->topo = P->prox;
  c = P->valor;
  free(P);
  
  return c;
}
 
typedef struct Vertice {
  int vertice; 
  int peso; 
  struct Vertice *prox;
} Vertice;
 
typedef struct Grafo {
  unsigned int tam; 
  Vertice **adj;
  int *info; 
} Grafo;
 
Grafo *inicializaGrafo(unsigned int V) {
  Grafo *G;
  int i;
  G = (Grafo *)malloc(sizeof(Grafo));
  G->adj = (Vertice **)malloc(V * sizeof(Vertice*));
  for (i = 0; i < V;i++) G->adj[i] = NULL;
  G->info = (int *)malloc(V * sizeof(int));
  G->tam = V;
  return G;
}
 
void inicializaVertice(Grafo *G, unsigned int i, int data) {
  G->info[i] = data;
}
 
void GrafoAddEdge(Grafo* G, int v, int w, int peso) {
  Vertice *L;
  L = (Vertice*)malloc(sizeof(struct Vertice));
  L->vertice = w;
  L->peso = peso;
  if (G->adj[v] == NULL) {
    L->prox = G->adj[v];
    G->adj[v] = L;  }
  else {
    Vertice *N;
    N = G->adj[v];
    if (L->vertice < N->vertice) {
      L->prox = G->adj[v];
      G->adj[v] = L;
    } else {
      while (N->prox) {
    if (L->vertice < N->prox->vertice) {
      break;
    }
    N = N->prox;
      }
      L->prox = N->prox;
      N->prox = L;
    }
  }
}
 
void percorre(Grafo* G, int v, int visitou[], Lista *pilha) {
 
  visitou[v] = 1;
 
  Vertice *L = G->adj[v];
  while (L) {
    if (!visitou[L->vertice])
      percorre(G, L->vertice, visitou, pilha);
    L = L->prox;
  }
 
 
  push(pilha, v);
}
 
 
void relax(int u, int v, int pesoEdge, int *dist) {
  if (dist[v] > dist[u] + pesoEdge)
    dist[v] = dist[u] + pesoEdge;
}
 
 
 
void caminhoMinimo(Grafo* G, int s) {
  Lista pilha;
  int dist[MAX];
  
  inicializaPilha(&pilha);
 
  int visitou[MAX];
  int i;
  for (i = 0; i < G->tam; i++)
    visitou[i] = 0;
  
 
  for (i = s; i < G->tam; i++)
    if (visitou[i] == 0)
      percorre(G, i, visitou, &pilha);
 
  for (i = 0; i < G->tam; i++)
    dist[i] = INF;
  dist[s] = 0;
  
  Vertice *L;
  
 
  while (pilhaVazia(&pilha) == 0) {
    
    int u = pop(&pilha);
    L = G->adj[u];
      
 
    if (dist[u] != INF) {
      while (L) {
    
    relax(u, L->vertice, L->peso, dist);
    L = L->prox; 
      }
    }
  }
  
  for (i = 0; i < G->tam; i++)
    if (dist[i]==INF)/*  printf("INF ")*/;
    else printf("%d ", dist[i]);
  printf("\n");
}
 
 
 
int main()
{
  int B, R, V, A, X, Y, i, P;
  /*
  B: verticeice de busca
  R: Restrição
  V: Qtd verticeices
  A: Qtd arestas
  X: aresta 1
  Y: areta 2
  P: peso das arestas */
 
  scanf("%d %d %d %d", &B, &R, &V, &A);
  Grafo* g = inicializaGrafo(V);
 
  for (i=0;i<A; i++){
     scanf("%d %d %d", &X, &Y, &P);
    GrafoAddEdge(g, X, Y, P);
  }
  caminhoMinimo(g, B);
  
  return 0;
}