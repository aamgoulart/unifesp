#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
typedef struct tipoNo{
    char letra;
    int freq;
    struct tipoNo *prox;
} No;
 
typedef struct tipoLista{
    No *primeiro, *ultimo;    
} Lista;
 
typedef struct tipoVertice{
  int freq;
  char letra;
  struct tipoNo *dir;
  struct tipoNo *esq;
} Vertice;
 
typedef struct tipoArv{
  struct tipoArv *raiz;
  int elementos;
} tipoArv;
 
static Vertice* remover (Vertice *meuNo, char letra);
 
void inicializaArv(tipoArv *arvore){
  arvore->raiz = NULL;
  arvore->elementos = 0;
}
void inicializaLista(Lista *L){
    L->primeiro = L->ultimo = NULL;
}
 
No* verifica (Lista *L, char letra){
    No *busca = L->primeiro;
    while (busca != NULL){
        if (busca->letra == letra){
            return busca;
        }
        busca = busca->prox;
    }
    return NULL;
}
 
void insereOrdLista(Lista *L, char letra, char X,char Y){
    if (letra != X && letra != Y) {
        if (verifica(L,letra) == NULL) {
            No *novo = malloc(sizeof(No));
            novo->letra = letra;
            if (L->primeiro == NULL){
                L->primeiro = novo;
                novo->prox = NULL;
                novo->freq=1;
            } else {
                No *busca = L->primeiro;
                No *anterior;
                novo->freq=1;
                while (busca != NULL && letra > busca->letra) {
                    anterior = busca;
                    busca = busca->prox;
                }
                if (busca == L->primeiro){
                novo->prox = busca;
                L->primeiro = novo;
                } else if(busca == NULL){
                    anterior->prox = novo;
                    novo->prox = NULL; 
                } else {
                    novo->prox = anterior->prox;
                    anterior->prox = novo;
                }
            }
        } else{
            No *igual = verifica(L, letra);
            igual->freq++;
        }
    }
}
 
void saidaLista(Lista *L){
    No *aux;
    while (aux != NULL){
        printf("%d%c", aux->freq,aux->letra);
        aux = aux->prox;
    }
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
    }
 
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
}
/* 
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
            }
            meuNo->letra = aux->letra;
            meuNo->freq = aux->freq;
            aux->letra = letra;
            meuNo->esq = remover(meuNo->esq,letra);
        }
    }
    return meuNo;
}
*/
int main(){
    char X, Y, N[1024];
    Lista L;
    tipoArv minhaArvore;
    int i;
    inicializaLista(&L);
    inicializaArv(&minhaArvore);
    scanf("%c %c", &X, &Y);
    scanf("%s", N);
 
    for (i=0; i<strlen(N); i++){
        insereOrdLista(&L,N[i], X,Y);
    }
    insereArv(&L, &minhaArvore);
    abb_imprime(&minhaArvore);
}
