#include <stdio.h>
#define LEFT(i) (2*i)
#define RIGHT(i) (LEFT(i)+1)
#define TAM 11

void maxHeapify(int array[], int number);
void buildMaxHeap(int array[]);
void swap(int array[], int number,int max);
void output(int array[]);

// int debug = 0;
int main() {
    int array[TAM] = {4,6,3,0,8,3,3,5,8,7,8};

    buildMaxHeap(array);
    output(array);

}


void maxHeapify(int array[], int number){ 
    int left = LEFT(number);
    int right = RIGHT(number);
    int max;

    max = left < TAM && array[left]> array[number] ? left : number;

    if (right < TAM && array[right] > array[max]) max = right;
    if ( max!= number) {
        swap(array, number, max);

        maxHeapify(array, max);
    }
}

void buildMaxHeap(int array[]) {
    int i;
    // printf("%d", debug++);
    for (i= TAM/2; i>0; i--){
        maxHeapify(array,i);
    }
}

void swap(int array[], int number,int max){
    int x;
    // printf("%d", debug++);

    x = array[max];
    array[max] = array[number];
    array[number] = x;
}

void output(int array[]) {
    int i;
    // printf("%d", debug++);

    for (i = 0; i <TAM; i++){
        printf("%d ", array[i]);
    }
}

int heapExtractMax(int array[]){
    int max, last;
    if (TAM < 1){
        error("error in extract max");
    }

    max = array[0];
    last = TAM;
    array[0] = array[last];


}