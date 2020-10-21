#include <stdio.h>
#include <math.h>
int histo_1[255], histo_2[255], matriz_1[50][50], matriz_2[50][50],tamanhoLinha_1, tamanhoLinha_2, tamanhoColuna_1, tamanhoColuna_2;
void preencheMatriz (int matriz[50][50], int tamanhoLinha,int tamanhoColuna, int id_foto);
void histo (int matriz[50][50], int tamanhoLinha,int tamanhoColuna, int id_foto);
void saidaMatriz (int id_foto, int tamanhoLinha, int tamanhoColuna);
int dist ();

void preencheMatriz (int matriz[50][50], int tamanhoLinha,int tamanhoColuna, int id_foto){
    register int i,j;

    scanf ("%d", &tamanhoLinha);
    scanf ("%d", &tamanhoColuna);

    if (id_foto==1){
        tamanhoLinha_1=tamanhoLinha;
        tamanhoColuna_1=tamanhoColuna;
    } else if (id_foto == 2){
        tamanhoLinha_2=tamanhoLinha;
        tamanhoColuna_2=tamanhoColuna;
    }

    if (tamanhoLinha > 2 && tamanhoLinha < 256 || tamanhoColuna > 2 && tamanhoColuna < 256) {
        for (i=0; i<tamanhoLinha; i++){
            for (j=0; j<tamanhoColuna; j++){
                scanf ("%d", &matriz[i][j]);
            }
        }
    } else {
        printf ("Matriz precisa ter dimensoes M e N dentro do intervalo [2,256]!");
    }

    for (i=0; i<tamanhoLinha; i++){
        for (j=0; j<tamanhoColuna; j++){
            if (id_foto==1){
                matriz_1[i][j] = matriz[i][j];
            } else if (id_foto == 2){
                matriz_2[i][j] = matriz[i][j];
            }
        }
    }
}

void histo (int matriz[50][50], int tamanhoLinha,int tamanhoColuna, int id_foto){
    int vetor[255], aux;
    register int i,j, k;

    for (k=0; k<255; k++){
        vetor[i]=0;
    }

    for (k=0; k<255; k++){
        for (i=0; i<tamanhoLinha; i++){
            for (j=0; j<tamanhoColuna; j++){
                if (matriz[i][j]== k){
                    aux= k;
                    vetor[k]++;
                }
            }
        }
    }

    for (k=0; k<255; k++){
        if(id_foto==1){
            histo_1[k]=vetor[k];
        }
        else if (id_foto ==2){
            histo_2[k]=vetor[k];
        }
        printf ("%d", vetor[k]);
    }
   
    
}



void saidaMatriz (int id_foto, int tamanhoLinha, int tamanhoColuna){
    register int i,j;

    for (i=0; i<tamanhoLinha; i++){
        for (j=0; j<tamanhoColuna; j++){
            if (id_foto==1) {
                if (matriz_1[i][j]>0){
                    printf ("I1[%d][%d]: \n %d",tamanhoLinha, tamanhoColuna,matriz_1[i][j]);
                } else {
                    printf ("Pixel nao pode ter valor negativo ou maior que 255!");
                }
            } else if (id_foto==2){
                if (matriz_2[i][j]>0){
                    printf ("I1[%d][%d]: \n %d",tamanhoLinha, tamanhoColuna,matriz_2[i][j]);
                } else {
                    printf ("Pixel nao pode ter valor negativo ou maior que 255!");
                }
            }
        }
    }
}

int dist (){
    int soma, pot, dif;
    float distancia;
    register int i;

    for (i=0; i<255; i++){
        dif = histo_1[i] - histo_2[i];
        pot = dif*dif;
        soma+=pot;
    }

    distancia = sqrt(soma);
    
    return distancia;
}


int main(){
    int maUm[50][50], maDois[50][50],tam_colunaUm, tam_colunaDois, tam_linhaUm, tam_linhaDois;
    
    preencheMatriz (maUm, tam_linhaUm, tam_colunaUm,1);

    preencheMatriz (maDois,tam_linhaDois, tam_colunaDois,2);

    saidaMatriz (maUm, tam_linhaUm, tam_colunaUm);

    saidaMatriz (maDois,tam_linhaDois, tam_colunaDois);

    histo (maUm, tam_linhaUm, tam_colunaUm, 1);

    histo (maDois,tam_linhaDois, tam_colunaDois,2);

}
