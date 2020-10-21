#include <stdlib.h>
#include <stdio.h>

typedef struct TipoArvG{
 char info;
 struct TipoArvG *filho;
 struct TipoArvG *irmao;
}TipoArvG;

TipoArvG *cria(char c){
 TipoArvG *novo = (TipoArvG *) malloc(sizeof(TipoArvG));
 novo->info = c;
 novo->filho = NULL;
 novo->irmao = NULL;
 return novo;
}

void insere(TipoArvG *arv, TipoArvG *subarv){
 subarv->irmao = arv->filho;
 arv->filho = subarv;
}

void imprimePre(TipoArvG *arv){
   if (arv!=NULL) {
      printf("%c\n",arv­>info);      
      TipoArvG *p = arv­>filho;
      imprimePre(p);
      p = arv­>irmao;
      imprimePre(p);
   
}
