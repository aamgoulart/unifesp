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
        meuNo = malloc(sizeof(Vertice));
        meuNo->number = f;
        meuNo->esq = meuNo->dir = NULL;
    } else if (f <= meuNo->number){
        meuNo->esq = insertNumberABB(meuNo->esq, f);
    }  else {
        meuNo->dir = insertNumberABB(meuNo->dir, f);
    }

    return meuNo;
}
 
void abb_insereOrdemnumber (tipoArv *minhaArvore, int f) {
    minhaArvore->raiz = insertNumberABB(minhaArvore->raiz, f);
    minhaArvore->elementos++;
}


static Vertice* buscaABB (Vertice*meuNo, int f){

    if (meuNo == NULL) {
        return NULL;
    } else if (meuNo->number > f) {
        return buscaABB(meuNo->esq, f);
    } else if (meuNo->number < f) {
        return buscaABB(meuNo->dir, f);
    } else {
        return meuNo;
    } 
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
    minhaArvore->elementos--;
}

int max2(int a, int b){
    return (a > b) ? a : b;
}

int Altura(Vertice * r)
{
   int AlturaE , AlturaD;

   if( r != NULL )
   {
       AlturaE = Altura(r->esq);
       AlturaD = Altura(r->dir);
       if( AlturaE > AlturaD ) return( AlturaE + 1);
       else return(AlturaD + 1);
   }
   else return 0;
} 

 
int alturaArv(Vertice *meuNo) {
    if (meuNo == NULL){
        return 0;
    } else {
        return max2(alturaArv(meuNo->esq), alturaArv(meuNo->dir));
    }
}

int main () {
    int array[] = {4,10,12,5,8};
    int i;
    int number, key;
    Vertice *busca;

    tipoArv abb;
    inicializaArv(&abb);

    scanf("%d", &number);
    while(number != -1){
        abb_insereOrdemnumber(&abb, number);
        scanf("%d", &number);
    }

    scanf("%d", &key);

    printf("%d %d\n",abb.elementos, Altura(abb.raiz));

    busca = buscaABB(abb.raiz, key);

    if (busca == NULL) {
        abb_insereOrdemnumber(&abb,key);
    } else if (busca->number == key) {
        abb_remover(&abb,key);
    }

    printf("%d %d",abb.elementos, Altura(abb.raiz));

}