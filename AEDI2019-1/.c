#include <stdlib.h>
#include <stdio.h>

//FIFO (FIRST IN, FIRST OUT)

//ESTRUTURA DE INFORMAÇÕES
typedef struct TipoItem{
	int n;
	struct TipoItem *prox;
}TipoItem;

typedef struct{
	TipoItem *primeiro , *ultimo;
}TipoFila;

void inicializaFila(TipoFila *minhaFila){
	minhaFila->primeiro= minhaFila->ultimo = NULL;

}

void insereElem (TipoFila *minhaFila, int n){
  TipoItem *novo = malloc (sizeof(TipoFila));
  novo->n = n;
  if (minhaFila->primeiro == minhaFila->ultimo){
	minhaFila->primeiro = novo;
	novo->prox = minhaFila->ultimo;
  } else {
	minhaFila->ultimo  = novo; 
	novo->prox = NULL; 
  }  
  
}

void imprimeFila(TipoFila *minhaFila){
  TipoItem *aux = minhaFila->primeiro;
  printf("entrou\n");

  while(aux != NULL){
	printf("%d ", aux->n);
	aux = aux->prox;
  
  printf("\n");
}

int  remover(TipoFila *minhaFila){
	TipoItem *R = minhaLista->primeiro;;
	int remove = R->n;
	minhaLista->prim = R->prox;
if (minhaFila->primeiro == NULL){
minhaFila->ultimo = NULL;
}
	free(R);
	return remove;
}

int main(){
  TipoFila minhaFila;
  int n, valor, i;

  scanf("%d", &n);

  for(i=0; i<n; i++){
	scanf("%d", &valor);
	insereElem(&minhaFila, valor);
  

  imprimeFila(&minhaFila);
}
