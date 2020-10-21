#include <stdio.h>
#include <stdlib.h>

int sizeStr(char *string);  //TAMANHO DA STRING
void concatenate(char *str1, char *str2, char *strco); // CONCATENA DUAS STRINGS
void reverse(char *str, int size); //INVERTE A STRING
int frequency(char *Z, char C); //BUSCA A FREQUENCIA DE UM CHAR NA STRING
int main() {
  int sizeX, sizeY, sizeStrX, sizeStrY, sizeStrZ,count;
  char C, *X, *Y, *Z;

  //PRIMEIRA ENTRADA
  scanf("%d %d %c", &sizeX, &sizeY, &C);

  //CRIAÇÃO DINAMICA
  X = malloc (sizeX+1 *sizeof(char));
  Y = malloc(sizeY+1 *sizeof(char));
  Z = malloc(sizeX+sizeY+1 *sizeof(char));

  //SEGUNDA ENTRADA
  scanf("%s %s", X, Y);

  sizeStrX=sizeStr(X);
  sizeStrY=sizeStr(Y);
  reverse(X,sizeStrX);
  reverse(Y,sizeStrY);
  concatenate(X, Y,Z);
  count = frequency(Z,C);
  sizeStrZ= sizeStr(Z);

  //SAIDA
  printf("%s\n%d\n%d\n",Z,sizeStrZ,count);
  
  //DESALOCA A MEMORIA
  free(Z);
  free(Y);
  free(X);
}

int sizeStr(char *string){
    int size;

    for(size=0; string[size] ; size++);

    return size;
} 

void reverse(char *str, int size){
    int i, j;
    char aux;
    for(i=0, j=(size-1); i<j; i++, j--) {
        aux = str[i];
        str[i] = str[j];
        str[j] = aux;
    }
}

void concatenate(char *str1, char *str2, char *Z){
    int i,j,k;
    for(i=0; str1[i]; i++){
        Z[i]=str1[i];
    }

    for(j=i, k=0; str2[k]; j++, k++){
        Z[j]=str2[k];
    }

}

int frequency(char *Z, char C){
    int i, freq=0;

    for (i=0; Z[i]; i++){
        if (Z[i] == C){
            freq++;
        }
    }
    return freq;
}
