#include <stdio.h>
#include <stdlib.h>


#define RED 1
#define BLACK 0

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
    int cor;
};

typedef struct NO* ArvLLRB;
// ABB RUBRO NEGRO 2-3
ArvLLRB* cria_ArvLLRB();
void libera_ArvLLRB(ArvLLRB* raiz);
int insere_ArvLLRB(ArvLLRB* raiz,int valor);
int remove_ArvLLRB(ArvLLRB *raiz, int valor);
int estaVazia_ArvLLRB(ArvLLRB *raiz);
int totalNO_ArvLLRB(ArvLLRB *raiz);
int altura_ArvLLRB(ArvLLRB *raiz);
int consulta_ArvLLRB(ArvLLRB *raiz, int valor);
void preOrdem_ArvLLRB(ArvLLRB *raiz, int H);
void emOrdem_ArvLLRB(ArvLLRB *raiz, int H);
void posOrdem_ArvLLRB(ArvLLRB *raiz, int H);



// =================================
// CRIA��O DA ARVORE
// =================================
ArvLLRB* cria_ArvLLRB(){
    ArvLLRB* raiz = (ArvLLRB*) malloc(sizeof(ArvLLRB));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}
// =================================
// LIBERAR
// =================================
void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvLLRB(ArvLLRB* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada n�
    free(raiz);//libera a raiz
}
// =================================
// CONSULTA �RVORE
// =================================
int consulta_ArvLLRB(ArvLLRB *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}
// =================================
// ROTA��O
// =================================
struct NO* rotacionaEsquerda(struct NO* A){
    struct NO* B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct NO* rotacionaDireita(struct NO* A){
    struct NO* B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}
// =================================
// PROPRIEDADES
// =================================
int cor(struct NO* H){
    if(H == NULL)
        return BLACK;
    else
        return H->cor;
}

void trocaCor(struct NO* H){
    H->cor = !H->cor;
    if(H->esq != NULL)
        H->esq->cor = !H->esq->cor;
    if(H->dir != NULL)
        H->dir->cor = !H->dir->cor;
}

// =================================
// INSERCAO
// =================================
struct NO* insereNO(struct NO* H, int valor, int *resp){
    if(H == NULL){
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL){
            *resp = 0;
            return NULL;
        }

        novo->info = valor;
        novo->cor = RED;
        novo->dir = NULL;
        novo->esq = NULL;
        *resp = 1;
        return novo;
    }

    if(valor == H->info)
        *resp = 0;// Valor duplicado
    else{
        if(valor < H->info)
            H->esq = insereNO(H->esq,valor,resp);
        else
            H->dir = insereNO(H->dir,valor,resp);
    }

    //n� Vermelho � sempre filho � esquerda
    if(cor(H->dir) == RED && cor(H->esq) == BLACK)
        H = rotacionaEsquerda(H);

    //Filho e Neto s�o vermelhos
    //Filho vira pai de 2 n�s vermelhos
    if(cor(H->esq) == RED && cor(H->esq->esq) == RED)
        H = rotacionaDireita(H);

    //2 filhos Vermelhos: troca cor!
    if(cor(H->esq) == RED && cor(H->dir) == RED)
        trocaCor(H);

    return H;
}

int insere_ArvLLRB(ArvLLRB* raiz, int valor){
    int resp;

    *raiz = insereNO(*raiz,valor,&resp);
    if((*raiz) != NULL)
        (*raiz)->cor = BLACK;

    return resp;
}
// =================================
// REMO��O
// =================================
struct NO* balancear(struct NO* H){
    //n� Vermelho � sempre filho � esquerda
    if(cor(H->dir) == RED)
        H = rotacionaEsquerda(H);

    //Filho da direita e neto da esquerda s�o vermelhos
    //if(H->esq != NULL && cor(H->dir) == RED && cor(H->esq->esq) == RED)

    //Filho da esquerda e neto da esquerda s�o vermelhos
    if(H->esq != NULL && cor(H->esq) == RED && cor(H->esq->esq) == RED)
        H = rotacionaDireita(H);

    //2 filhos Vermelhos: troca cor!
    if(cor(H->esq) == RED && cor(H->dir) == RED)
        trocaCor(H);

    return H;
}

struct NO* move2EsqRED(struct NO* H){
    trocaCor(H);
    if(cor(H->dir->esq) == RED){
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaEsquerda(H);
        trocaCor(H);
    }
    return H;
}

struct NO* move2DirRED(struct NO* H){
    trocaCor(H);
    if(cor(H->esq->esq) == RED){
        H = rotacionaDireita(H);
        trocaCor(H);
    }
    return H;
}

struct NO* removerMenor(struct NO* H){
    if(H->esq == NULL){
        free(H);
        return NULL;
    }
    if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
        H = move2EsqRED(H);

    H->esq = removerMenor(H->esq);
    return balancear(H);
}

// tirei a recurs�o, assim fica igual a usada na AVL
struct NO* procuraMenor(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

struct NO* remove_NO(struct NO* H, int valor){
    if(valor < H->info){
        if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
            H = move2EsqRED(H);

        H->esq = remove_NO(H->esq, valor);
    }else{
        if(cor(H->esq) == RED)
            H = rotacionaDireita(H);

        if(valor == H->info && (H->dir == NULL)){
            free(H);
            return NULL;
        }

        if(cor(H->dir) == BLACK && cor(H->dir->esq) == BLACK)
            H = move2DirRED(H);

        if(valor == H->info){
            struct NO* x = procuraMenor(H->dir);
            H->info = x->info;
            H->dir = removerMenor(H->dir);
        }else
            H->dir = remove_NO(H->dir, valor);
    }
    return balancear(H);
}

int remove_ArvLLRB(ArvLLRB *raiz, int valor){
    if(consulta_ArvLLRB(raiz,valor)){
        struct NO* h = *raiz;
        *raiz = remove_NO(h,valor);
        if(*raiz != NULL)
            (*raiz)->cor = BLACK;
        return 1;
    }else
        return 0;
}
// =================================
// PROPRIEDADES �RVORE
// =================================
int estaVazia_ArvLLRB(ArvLLRB *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvLLRB(ArvLLRB *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;

    int alt_esq = totalNO_ArvLLRB(&((*raiz)->esq));
    int alt_dir = totalNO_ArvLLRB(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1);
}

int altura_ArvLLRB(ArvLLRB *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvLLRB(&((*raiz)->esq));
    int alt_dir = altura_ArvLLRB(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}
// =================================
// PERCURSO
// =================================
void  posOrdem_ArvLLRB(ArvLLRB *raiz, int H){
    if(raiz == NULL)
        return;

    if(*raiz != NULL){
        posOrdem_ArvLLRB(&((*raiz)->esq),H+1);
        posOrdem_ArvLLRB(&((*raiz)->dir),H+1);

        if((*raiz)->cor == RED)
            printf("%d  Vermelho: H(%d) \n",(*raiz)->info,H);
        else
            printf("%d  Preto: H(%d) \n",(*raiz)->info,H);

    }
}

void emOrdem_ArvLLRB(ArvLLRB *raiz, int H){
    if(raiz == NULL)
        return;

    if(*raiz != NULL){
        emOrdem_ArvLLRB(&((*raiz)->esq),H+1);

        if((*raiz)->cor == RED)
            printf("%dR: H(%d) \n",(*raiz)->info,H);
        else
            printf("%dB: H(%d) \n",(*raiz)->info,H);

        emOrdem_ArvLLRB(&((*raiz)->dir),H+1);
    }
}

// void preOrdem_ArvLLRB(ArvLLRB *raiz,int H){
//     if(raiz == NULL)
//         return;

//     if(*raiz != NULL){
//         if((*raiz)->cor == RED)
//             printf("%d  Vermelho: H(%d) \n",(*raiz)->info,H);
//         else
//             printf("%d  Preto: H(%d) \n",(*raiz)->info,H);

//         preOrdem_ArvLLRB(&((*raiz)->esq),H+1);
//         preOrdem_ArvLLRB(&((*raiz)->dir),H+1);
//     }
// }

void preOrdem_ArvLLRB(ArvLLRB *raiz, int H){

    if (raiz == NULL) {
        printf("()");
        return;
    }
	if (*raiz != NULL) {
        if((*raiz)->cor == RED)
            printf("(R%d",(*raiz)->info,H);
        else
            printf("(N%d",(*raiz)->info,H);
		preOrdem_ArvLLRB(&((*raiz)->esq),H+1);
		preOrdem_ArvLLRB(&((*raiz)->dir),H+1);
		printf(")");
	} 
}


int main(){
    ArvLLRB * raiz = cria_ArvLLRB();
    //system ("color C");
    //https://www.youtube.com/watch?v=rcDF8IqTnyI

    int i, N = 7, val[7] ={3,4,9,2,5,1};
    // int i, N = 1, val[1] = {4};
    //int i, N = 10, val[10] ={10,15,10,20,30,70,70,85,50,50};

    for(i=0; i< N; i++){
        /*
        if(insere_ArvLLRB(raiz,val[i]))
            printf("Insercao: %d -> OK\n",val[i]);
        else
            printf("Insercao: %d -> ERRO\n",val[i]);
        */
        //printf("Insercao: %d -> OK\n",val[i]);
        insere_ArvLLRB(raiz,val[i]);
        //emOrdem_ArvLLRB(raiz,0);
        //printf("\n\n==========================\n\n");
    }

    printf("Tamanho: %d \n",altura_ArvLLRB(raiz));
    preOrdem_ArvLLRB(raiz,0);


    printf("\n\n==========================\n\n");

    // remove_ArvLLRB(raiz,4);
    // emOrdem_ArvLLRB(raiz,0);
    printf("\n\n==========================\n\n");
    remove_ArvLLRB(raiz,1);
    preOrdem_ArvLLRB(raiz,0);

    return 0;
}

