#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

struct arquivo{
    FILE *f;
    int pos, MAX;
    int *buffer;
};


//faz a comparações de duas variaveis
int compara(const void *a, const void *b){
    if(*(int*)a == *(int*)b)
        return 0;//iguais
    else
        if(*(int*)a < *(int*)b)
            return -1; //vem antes
        else
            return 1; //vem depois
}


//realiza a abertura do arquivo e fecha o mesmo
void salvaArquivo(char *nome, int *V, int tam, int mudaLinhaFinal){
    int i;
    FILE *f = fopen(nome,"a");
    for(i=0; i < tam-1; i++)
        fprintf(f,"%d\n",V[i]);
    if(mudaLinhaFinal == 0)
        fprintf(f,"%d",V[tam-1]);
    else
        fprintf(f,"%d\n",V[tam-1]);
    fclose(f);
}


//cria o arquivo para a manipulação
void criArquivoTeste(char *nome){
    long int i;
    FILE *f = fopen(nome,"w");
    srand(time(NULL));
    for(i=1; i < 10000000; i++)
        fprintf(f,"%d\n",rand());
    fprintf(f,"%d",rand());
    fclose(f);
}

// gera os arquivos temporarios para a mesclagem posteriormente
int criaArquivosOrdenados(char *nome){
    int V[N];
    char novo[20];
    int cont = 0, total = 0;
    FILE *f = fopen(nome,"r");
    while(!feof(f)){
        fscanf(f,"%d",&V[total]);
        total++;
        if(total == N){
            cont++;
            sprintf(novo,"Temp%d.txt",cont);
            qsort(V,total,sizeof(int),compara);
            salvaArquivo(novo, V, total,0);
            total = 0;
        }
    }

    if(total > 0){
        cont++;
        sprintf(novo,"Temp%d.txt",cont);
        qsort(V,total,sizeof(int),compara);
        salvaArquivo(novo, V, total,0);
    }
    fclose(f);
    return cont;
}


// função que vai preenchendo o arquivo de acordo com a necessidade
void preencheBuffer(struct arquivo* arq, int T){
    int i;
    if(arq->f == NULL)
        return;

    arq->pos = 0;
    arq->MAX = 0;
    for(i=0; i<T; i++){
        if(!feof(arq->f)){
            fscanf(arq->f,"%d",&arq->buffer[arq->MAX]);
            arq->MAX++;
        }else{
            fclose(arq->f);
            arq->f = NULL;
            break;
        }
    }
}

//busca o menor valor para preencher o arquivo
int procuraMenor(struct arquivo* arq,int K,int T,int* menor){
    int i, idx = -1;
    for(i=0; i<K; i++){
        if(arq[i].pos < arq[i].MAX){
            if(idx == -1)
                idx = i;
            else{
                if(arq[i].buffer[arq[i].pos] < arq[idx].buffer[arq[idx].pos])
                    idx = i;
            }
        }
    }
    if(idx != -1){
        *menor = arq[idx].buffer[arq[idx].pos];
        arq[idx].pos++;
        if(arq[idx].pos == arq[idx].MAX)
            preencheBuffer(&arq[idx],T);
        return 1;
    }else
        return 0;

}

// realiza a mesclagem do arquivo
void merge(char *nome, int K, int T){
    char novo[20];
    int i;
    int *buffer = (int*)malloc(T*sizeof(int));

    struct arquivo* arq;
    arq = (struct arquivo*)malloc(K*sizeof(struct arquivo));
    for(i=0; i < K; i++){
        sprintf(novo,"Temp%d.txt",i+1);
        arq[i].f = fopen(novo,"r");
        arq[i].MAX = 0;
        arq[i].pos = 0;
        arq[i].buffer = (int*)malloc(T*sizeof(int));
        preencheBuffer(&arq[i],T);
    }

    //enquanto houver arquivos para processar
    int menor, qtdBuffer = 0;
    while(procuraMenor(arq,K,T,&menor) == 1){
        buffer[qtdBuffer] = menor;
        qtdBuffer++;
        if(qtdBuffer == T){
            salvaArquivo(nome, buffer, T,1);
            qtdBuffer = 0;
        }
    }

    if(qtdBuffer != 0)
        salvaArquivo(nome, buffer, qtdBuffer,1);

    for(i=0; i<K; i++)
        free(arq[i].buffer);
    free(arq);
    free(buffer);

}

//aplicação do argoritmo de merge sort
void mergeSortExterno(char *nome){
    char novo[20];
    int K = criaArquivosOrdenados(nome);
    int i, T = N / (K + 1);
    printf("Nro de arquivos:%d\n",K);
    printf("K:%d\n",T);

    remove(nome);
    merge(nome,K,T);

    for(i=0; i<K; i++){
        sprintf(novo,"Temp%d.txt",i+1);
        remove(novo);
    }
    printf("Fim!\n");

}

//verifica se os arquivos foram realmente ordenados
void verificaArquivoOrdenado(char *nome){
    int v1,v2, erro = 0;
    FILE *f = fopen(nome,"r");
    fscanf(f,"%d",&v1);
    while(!feof(f)){
        fscanf(f,"%d",&v2);
        if (v2 < v1){
            erro = 1;
            break;
        }
    }
    fclose(f);
    if(erro)
        printf("Valores fora de ordem!\n");
    else
        printf("Arquivo corretamente ordenado!\n");
}
int main(){
    clock_t tempoDistribuicao, tempoIntercalacao; 
    char arquivo[N];
    int i;

    scanf("%s", arquivo);
    tempoDistribuicao = clock();
    criArquivoTeste(arquivo);
    tempoDistribuicao= clock() - tempoDistribuicao;
    tempoIntercalacao = clock();
    mergeSortExterno(arquivo);
    tempoIntercalacao= clock() - tempoIntercalacao;
    verificaArquivoOrdenado(arquivo);
    printf("Tempo de distribuicao: %lf ms", ((double)tempoDistribuicao)/((CLOCKS_PER_SEC/1000))); 
    printf("Tempo de Intercalacao: %lf ms", ((double)tempoIntercalacao)/((CLOCKS_PER_SEC/1000))); 




    return 0;
}
