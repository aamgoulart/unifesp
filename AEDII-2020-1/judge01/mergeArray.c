#include <stdlib.h>
#include <stdio.h>
#define MAX 100

void bubbleSort(int array[], int number);
void concat(int firstArray[], int secondArray[],int totalArray[], int totalSize, int firstSize);
void output(int totalArray[], int totalSize);
void clearMemoryArray(int totalArray[], int totalSize);

int main(){
    int sizeA, sizeB, VETA[MAX], VETB[MAX], i, totalSize, totalArray[MAX];

    scanf("%d", &sizeA);

    if (sizeA < MAX){
        for (i=0; i<sizeA; i++) {
            scanf("%d", &VETA[i]);
        }
    }

    scanf("%d", &sizeB);

    if (sizeB < MAX){
        for (i=0; i<sizeB; i++) {
            scanf("%d", &VETB[i]);
        }
    }
    totalSize = sizeB + sizeA;

    concat(VETA, VETB, totalArray, totalSize, sizeA);
    bubbleSort(totalArray, totalSize);

    output(totalArray, totalSize);
    
}

void bubbleSort(int array[], int number){
    int i, j;
    int aux =0;

    for (i=0; i<number; i++){
        for (j=i+1; j<number; j++){
            if (array[i] > array[j]){
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}

void concat(int firstArray[], int secondArray[],int totalArray[], int totalSize, int firstSize){
    int i,j;
    for (i=0; i<firstSize; i++){
        totalArray[i] = firstArray[i];
    }

    for (i=firstSize, j=0; i<totalSize, j<totalSize-firstSize; i++, j++){
        totalArray[i] = secondArray[j];
    }
}

void output(int totalArray[], int totalSize){
    int i;
    for (i=0; i<totalSize; i++){
        printf("%d ", totalArray[i]);
    }
}
