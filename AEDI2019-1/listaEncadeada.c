#include <stdio.h>
#include <stdlib.h>

//ESTRUTURA DE INFORMAÇÕES
typedef struct TipoItem{
   int n;
   struct TipoItem *prox;
}TipoItem;

//ESTRUTURA DA LISTA
typedef struct{
   TipoItem *primeiro;
   int tamanho;
}ListaLinear;

void inicializaLista(ListaLinear *lista); //INICIALIZA A LISTA
void imprimeLista(ListaLinear *lista); //IMPRIME TODOS OS ELEMENTOS DA LISTA
void insereOrdenado(ListaLinear *lista, int n); //INSERE EM ORDEM CRESCENTE  NA LISTA
void removeElem (ListaLinear *lista, int remove); //REMOVE O ELEMENTO PEDIDO

int main (){
   ListaLinear minhaLista;
   int n, valor, i, remove;
   inicializaLista(&minhaLista);
   scanf("%d", & n); //PEDE A QUANTIDADE DE ELEMENTOS PARA SEREM INSERIDOS NA LISTA

   for (i=0; i<n; i++){ //PERCORRE E INSERE
       scanf("%d", &valor);
       insereOrdenado(&minhaLista, valor);
   
   imprimeLista(&minhaLista); //IMPRIME A LISTA SEM REMOÇÃO

   scanf("%d", &remove); // PEDE O NUMERO PARA SER REMOVIDO
   // REMOVE E IMPRIME A LISTA
   removeElem(&minhaLista, remove);
   imprimeLista(&minhaLista);
}

void inicializaLista(ListaLinear *lista){
   lista->tamanho = 0;
   lista->primeiro = NULL;
}
void imprimeLista(ListaLinear *lista){
   TipoItem *aux = lista->primeiro; // COLOCA O PONTEIRO NA CABEÇA DA LISTA
   while(aux != NULL){ // PERCORRER TODA A LISTA
       printf("%d ",aux->n);
       aux = aux->prox;
   
   printf("\n");
}

void insereOrdenado(ListaLinear *lista, int n){

   TipoItem *novo = malloc(sizeof(TipoItem));
   novo->n = n;

   if(lista->tamanho == 0){ // CASO SEJA O PRIMEIRO DA LISTA
       lista->primeiro = novo; //CABEÇA DA LISTA SE TORNA NOVO ELEMENTO
       novo->prox = NULL; // O PROXIMO DO NOVO TEM QUE APONTAR NULL
   
   else{ // CASO JÁ TENHA ELEMENTO NA LISTA
       TipoItem *aux = lista->primeiro; // CRIA PONTEIRO PARA PERCORRER
       TipoItem *anterior; // CRIA PONTEIRO PARA GUARDAR O ANTERIOR
       while(aux != NULL && n > aux->n){ // PERCORRE A LISTA ATE O FINAL E ATE ACHAR O MAIOR ELEMENTO
           anterior = aux;
           aux = aux->prox;
       
       if(aux == NULL){ // INSERÇÃO NO ULTIMO DA LISTA
           anterior->prox = novo; // ANTERIOR PROXIMO APONTA PARA O NOVO
           novo->prox = NULL; // O NOVO PROXIMO0 APONTA PARA NULL
       } else if (aux == lista->primeiro){ // INSERÇÃO NO COMEÇO DA LISTA
           novo->prox = aux; // O PROXIMO DO NOVO APONTA PARA O QUE ACHAMOS
           lista->primeiro = novo; // A CABEÇA DA LISTA SE TORNA O NOVO
       } else{ // INSERÇÃO NO MEIO DA LISTA
           novo->prox = anterior->prox; //O PROXIMO DO NOVO APONTA PARA O ANTERIOR PROXIMO
           anterior->prox = novo; //
       
   
   lista->tamanho++;
}

void removeElem (ListaLinear *minhaLista, int remove){
 TipoItem *aux = minhaLista->primeiro;
 TipoItem *anterior;
 while(aux != NULL){ // PERCORRE TODA A LISTA
   if (aux->n == remove){ // VERIFICA SE TEM ALGUMM NA LISTA
     anterior->prox = aux->prox; // FAZ O ANTERIOR APONTAR PRO PROXIMO DO ENCONTRADO
     free(aux); //LIBERA A MEMORIA
   
   //ATUALIZA OS PONTEIROS
   anterior = aux;
   aux = aux->prox;
 
}
