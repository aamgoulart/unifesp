#define <stdio.h>
#define <stdlib.h>
typedef struct tipoNo {
    char letra;
    struct tipoNo *prox;
    struct tipoNO *ant;
} No;

typedef struct tipoListaDupla{
    No *prim;
    No *ult;
    int tam;
} Lista;


Lista* inicializaLista(){
    Lista *L = malloc (sizeof(Lista));
    L->prim = L->ult = NULL;
    L->tam = 0;

    return L;
}

void insere(Lista *L, char letra){
        No *novo = malloc(sizeof(No));
        
        novo->letra = letra;
        L->tam++;
        if (L->prim == NULL){ 
            novo->prox = L->prim;
            novo->ant = NULL;
            L->ult = novo;
            L->prim = novo;
        } else {
            No *busca = L->prim;
            No *anterior;
            while (busca != NULL &&  busca->letra > letra){
              anterior = busca;
              busca = busca->prox;
            
          if (busca == NULL){ 
            novo->ant = L->ult;
            novo->prox = NULL;
            No *aux = L->ult;        
            aux->prox = novo;
            L->ult = novo;
          } else if (busca == L->prim){
            novo->prox = L->prim;
            novo->ant = NULL;
            L->ult = novo;
            L->prim = novo;  
          }else {
            busca->ant = novo;
            novo->prox = busca;
            anterior->prox = novo;
            novo->ant = anterior;
          
        
    } 

void imprime(Lista *L){
    No *aux = L->prim;
    while (aux != NULL){
        printf(“%c", aux->letra);
        aux = aux->prox;
    
    printf("\n");
}

void remover (Lista *L, char letra){
    No *busca = buscar(L,letra);

    if (busca == L->prim){
        L->prim = busca->prox;
    } else {
        No *aux = busca->ant;
        aux->prox = busca->prox;
    

    if (busca == L->ult){
        L->ult = busca->ant;
    } else {
        No *aux = busca->prox;
        aux->ant = busca->ant;
    
    L->tam--;
    free(busca);
}
