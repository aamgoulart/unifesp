#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
typedef struct tipoNo {
    char letra;
    int freq;
    struct tipoNo *prox;
    struct tipoNO *ant;
} No;
 
typedef struct tipoListaDupla{
    No *prim;
    No *ult;
    int tam;
} Lista;
No* buscar(Lista*L, char letra);
Lista* inicilizaLista(){
    Lista *L = malloc (sizeof(Lista));
    L->prim = L->ult = NULL;
    L->tam = 0;
 
    return L;
}
 
void insere(Lista *L, char letra){
        No *novo = malloc(sizeof(No));
        
        novo->letra = letra;
        novo->freq++;
        L->tam++;
        if (L->prim == NULL){
            novo->prox = L->prim;
            novo->ant = NULL;
            L->ult = novo;
            L->prim = novo;
        } else {
            if (L->ult->letra != letra){
            novo->ant = L->ult;
            novo->prox = NULL;
            No *aux = L->ult;        
            aux->prox = novo;
            L->ult = novo;
            } else {
                L->ult->freq++;
            }
        }
    } 
 
void imprime(Lista *L){
    No *aux = L->prim;
    printf("%d\n", tamanhoLista(L));
    while (aux != NULL){
        printf("%d%c", aux->freq,aux->letra);
        aux = aux->prox;
    }
    printf("\n");
}
int tamanhoLista(Lista *L){
    No *aux = L->prim;
    int tam=0;
    while (aux != NULL){
        if (aux->freq >= 10){
            tam+=3;
        } else if (aux->freq <10){
            tam+=2;
        }
        aux=aux->prox;
    }
    return tam;
}
 
No* buscar(Lista*L, char letra){
    No *busca = L->prim;
    while (busca != NULL){
        if (busca->letra == letra){
            return busca;
        }
        busca = busca->prox;
    }
}
 
void remover (Lista *L, char letra){
    No *busca = buscar(L,letra);
 
    if (busca == L->prim){
        L->prim = busca->prox;
    } else {
        No *aux = busca->ant;
        aux->prox = busca->prox;
    }
 
    if (busca == L->ult){
        L->ult = busca->ant;
    } else {
        No *aux = busca->prox;
        aux->ant = busca->ant;
    }
    L->tam--;
    free(busca);
}
 
void buscaRemove(Lista *L){
    No *aux = L->prim;
 
    while (aux != NULL){
        if (aux->freq == 1){        
            if (aux != L->ult && aux != L->prim){ //Caso o ruído encontrado esteja localizado no meio da lista e ambas as substrings vizinhas possuem tamanho maior que 1. 
                No *viziEsq = aux->ant;
                No *viziDir = aux->prox;
                    if (viziDir->freq >1 && viziEsq->freq > 1){
                    remover(L, aux->letra);
                    if (viziEsq->freq >= viziDir->freq){
                        viziEsq->freq++;
                    } else {
                        viziDir->freq++;
                    }
                    }
            } else if (aux == L->prim){ // Caso o ruído seja encontrado na primeira posição da string, deve-se considerar apenas o vizinho da direita
                No *viziDir = aux->prox;
                if (viziDir->freq > 1 && viziDir->letra != 1){
                    remover(L, aux->letra);
                    viziDir->freq++;
                }
            } else if (aux == L->ult){
                No *viziEsq = aux->ant;
                if (viziEsq->freq > 1 && viziEsq == NULL){
                    remover(L, aux->letra);
                    viziEsq->freq++;
                }
            }
        }
        aux = aux->prox;
    }
}
int main(){
    Lista *L;
    char N[1023];
    int i;
    L = inicilizaLista();
 
    scanf("%s", N);
    for (i=0; i<strlen(N); i++){
        insere(L, N[i]);
    }
    imprime(L);
    buscaRemove(L);
    imprime(L);
}
