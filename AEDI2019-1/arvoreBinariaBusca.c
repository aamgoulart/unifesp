#include <stdlib.h>
#include <stdio.h>

typedef struct tipoVertice{
  int freq;
  char letra;
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

Vertice* insereFrequencia (Vertice*meuNo, char c, int f){

    if (meuNo == NULL){
        meuNo = malloc(sizeof(Vertice));
        meuNo->letra = c;
        meuNo->freq = f;
        meuNo->esq = meuNo->dir = NULL;
    } else if (f <= meuNo->freq){
        meuNo->esq = insereFrequencia(meuNo->esq, c, f);
    }  else {
        meuNo->dir = insereFrequencia(meuNo->dir, c, f);
    

    return meuNo;
}
 
void abb_insereOrdemFreq (tipoArv *minhaArvore,  char c, int f){
    minhaArvore->raiz = insereFrequencia(minhaArvore->raiz, c, f);
}

static void imprime (Vertice *meuNo){
    if (meuNo != NULL){
        imprime(meuNo->esq);
        printf("%c", meuNo->letra);
        imprime(meuNo->dir);
    
}
 
void abb_imprime (tipoArv *minhaArvore){
    return imprime(minhaArvore->raiz);
}

void insereArv(Lista *L, tipoArv *minhaArvore){
    No *P = L->primeiro;
    while (P != NULL){
        abb_insereOrdemFreq(minhaArvore,P->letra,P->freq);
        P=P->prox;
    
}

void  abb_remover (tipoArv *minhaArvore, char letra){
    minhaArvore->raiz = remover(minhaArvore->raiz, letra);
}
 
static Vertice* remover (Vertice *meuNo, char letra){
    if (meuNo == NULL){
        return NULL;
    } else if (meuNo->letra > letra){
        meuNo->esq = remover (meuNo->esq, letra);
    } else if (meuNo->letra < letra){
        meuNo->dir = remover (meuNo->dir, letra);
    } else if (meuNo->letra == letra) {
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
            
            meuNo->letra = aux->letra;
            meuNo->freq = aux->freq;
            aux->letra = letra;
            meuNo->esq = remover(meuNo->esq,letra);
        
    
    return meuNo;
}
