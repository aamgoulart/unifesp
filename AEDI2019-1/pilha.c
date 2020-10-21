#include <stdlib.h>
#include <stdio.h>

//ESTRUTURA DE INFORMAÇÕES
typedef struct TipoItem{
	int n;
	struct TipoItem *prox;
}TipoItem;

typedef struct{
	TipoItem *topo;
}TipoPilha;

void inicializaPilha(TipoPilha *minhaPilha){
	minhaPilha->topo= NULL;
}

void push (TipoPilha *minhaPilha, int n){
  TipoItem *novo = malloc (sizeof(TipoPilha));
  novo->n = n;
  novo->prox = minhaPilha->topo;
 minhaPilha->topo = novo;
}

void imprimePilha(TipoPilha *minhaPilha){
  TipoItem *aux = minhaPilha->topo;
  printf("entrou\n");

  while(aux != NULL){
	printf("%d ", aux->n);
	aux = aux->prox;
  
  printf("\n");
}

int  remover(TipoFila *minhaFila){
	TipoItem *R = minhaLista->topo;
	int remove = R->n;
	minhaFila->topo = R->prox;	
free(R);
	return remove;
}

int main(){
  TipoPilha minhaPilha;
  int n, valor, i;

  scanf("%d", &n);

  for(i=0; i<n; i++){
	scanf("%d", &valor);
	insereElem(&minhaPilha, valor);
  

  imprimePilha(&minhaPilha);
}
