#include <stdio.h>
#define TAM 100

int bubbleSort(int array[], int number);
void verifyWinner(int array[], int number);

int main (){
    int array[TAM], numberMax;
    int i;

    scanf("%d", &numberMax);
    
    for (i=0; i<numberMax; i++){
        scanf("%d", &array[i]);
    }

    verifyWinner(array,numberMax);

}

int bubbleSort(int array[], int number){
    int i, j;
    int aux =0;
    int play=0;

    for (i=0; i<number; i++){
        for (j=i+1; j<number; j++){
            if (array[i] > array[j]){
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
                play++;
            }
        }
    }

    return play;
}

void verifyWinner(int array[], int number){
    if (bubbleSort(array,number) % 2 ==0){
        printf("Ciclano");
    } else {
        printf("Fulano");
    }
}