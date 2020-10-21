#include <stdio.h>
#include <stdlib.h>
 
    typedef struct{
        int *prox
    }TipoItem;
 
    typedef struct{
        TipoItem *ultimo;
        int topo, diamantes;
    }TipoPilha;
 
    void inicializarPilha(TipoPilha*pilha);
    void push(TipoPilha *pilha);
    void pop(TipoPilha *pilha);
    void imprimirResultado(TipoPilha *pilha);
 
    int main(){
 
        TipoPilha *aux;
        char C = ' ';
        int i, N;
 
        scanf("%d\n",&N);
        TipoPilha pilha[N];
 
        for(i=0;i<N;i++){
            inicializarPilha(&pilha[i]);
        }
 
        for(i=0;i<N;i++){
            while(C != '\n'){
                scanf("%c", &C);
                if(C == '<'){
                    push(&pilha[i]);
                }
                else if(C == '>'){
                    pop(&pilha[i]);
                }
            }
            C = ' ';
        }
 
        for(i=0;i<N;i++){
            imprimirResultado(&pilha[i]);
        }
        return 0;
    }
 
    void inicializarPilha(TipoPilha*pilha){
        pilha->topo = NULL;
        pilha->diamantes = 0;
        pilha->ultimo = 0;
    }
    void push(TipoPilha *pilha){
        TipoItem *aux = malloc(sizeof(TipoItem));
        if(pilha->topo == 0){
            aux->prox == NULL;
        }
        else{
            aux->prox = pilha->ultimo;
        }
        pilha->ultimo = aux;
        pilha->topo++;
    }
 
    void pop(TipoPilha *pilha){
        if(pilha->topo != 0){
            TipoItem *aux = malloc(sizeof(TipoItem));
            aux = pilha->ultimo;
            pilha->ultimo = aux->prox;
            free(aux);
            pilha->topo--;
            pilha->diamantes++;
        }
    }
 
    void imprimirResultado(TipoPilha *pilha){
        printf("%d\n",pilha->diamantes);
    }
 
    
