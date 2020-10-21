#include <stdlib.h>
#include <stdio.h>

typedef struct tipoVertice{
  int number;
  struct tipoNo *dir;
  struct tipoNo *esq;
} Vertice;
 
typedef struct tipoArv{
  struct tipoArv *raiz;
  int elementos; //tamanho da arv
} tipoArv;

void inicializaArv(tipoArv *arvore){
  arvore->raiz = NULL;
  arvore->elementos = 0;
}

Vertice* insertNumberABB (Vertice*meuNo, int f){

    if (meuNo == NULL){
        printf("Encontrei o nó e aloco\n");
        meuNo = malloc(sizeof(Vertice));
        meuNo->number = f;
        meuNo->esq = meuNo->dir = NULL;
    } else if (f <= meuNo->number){
        printf("%d -- %d\t", f, meuNo->number);
        printf("O valor é menor que o nó, vou para a esquerda\n");
        meuNo->esq = insertNumberABB(meuNo->esq, f);
    }  else {
        printf("%d -- %d\t", f, meuNo->number);
        printf("O valor é maior que o nó, vou para a direita\n");
        meuNo->dir = insertNumberABB(meuNo->dir, f);
    }

    return meuNo;
}
 
void abb_insereOrdemnumber (tipoArv *minhaArvore, int f) {
    minhaArvore->raiz = insertNumberABB(minhaArvore->raiz, f);
}

static void imprime (Vertice *meuNo){
    if (meuNo != NULL){
        imprime(meuNo->esq);
        printf("%d ", meuNo->number);
        imprime(meuNo->dir);
    }
}
 
void abb_imprime (tipoArv *minhaArvore){
    return imprime(minhaArvore->raiz);
}

static Vertice* remover (Vertice *meuNo, int number){
    if (meuNo == NULL){
        return NULL;
    } else if (meuNo->number > number){
        meuNo->esq = remover (meuNo->esq, number);
    } else if (meuNo->number < number){
        meuNo->dir = remover (meuNo->dir, number);
    } else if (meuNo->number == number) {
        if (meuNo->esq == NULL && meuNo->dir == NULL){
            free(meuNo);
            meuNo=NULL;
        } else if (meuNo->esq == NULL){
            Vertice *aux = meuNo;
            meuNo =meuNo->dir;
            free(aux);
        } else if (meuNo->dir == NULL){
            Vertice *aux = meuNo;
            meuNo = meuNo->esq;
            free(aux);
        } else {
            Vertice *aux = meuNo->esq;
            while (aux->dir != NULL){
                aux = aux->dir;
            }
            meuNo->number = aux->number;
            aux->number = number;
            meuNo->esq = remover(meuNo->esq,number);
        }
    }
    
    return meuNo;
}


void  abb_remover (tipoArv *minhaArvore, int  number){
    minhaArvore->raiz = remover(minhaArvore->raiz, number);
}
 



int main () {
    int array[] = {4,5,3,0,8,3,3,5,8,7,8};
    int i;

    tipoArv abb;
    inicializaArv(&abb);

    for (i=0; i<11; i++) {
        abb_insereOrdemnumber(&abb, array[i]);
    }

    printf("Árvore ABB\n");
    abb_imprime(&abb);

    
    printf("\n");
    printf("Removendo a posição 6\n");
    abb_remover(&abb, array[6]);
    abb_imprime(&abb);
    printf("\n");


    printf("Removendo a posição 1\n");
    abb_remover(&abb, array[1]);
    abb_imprime(&abb);
}