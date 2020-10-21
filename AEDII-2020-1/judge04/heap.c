// C implementation of Heap Sort
#include <stdio.h>
#include <stdlib.h>

// A heap has current size and array of elements
struct MaxHeap
{
    int size;
    int* array;
};

void printArray(int* arr, int size);

// A utility function to swap to integers
void swap(int* a, int* b) { int t = *a; *a = *b;  *b = t; }

// The main function to heapify a Max Heap. The function
// assumes that everything under given root (element at
// index index) is already heapified
void maxHeapify(struct MaxHeap* maxHeap, int index)
{
    int largest = index;  // Initialize largest as root
    int left = (index << 1) + 1;  // left = 2*index + 1
    int right = (index + 1) << 1; // right = 2*index + 2

    // See if left child of root exists and is greater than
    // root
    if (left < maxHeap->size &&
        maxHeap->array[left] > maxHeap->array[largest]){
        largest = left;
        printf("Como o filho esquerdo é maior que a raiz o maior se torna o da direita %d %d\n", largest,left);
        }


    // See if right child of root exists and is greater than
    // the largest so far
    if (right < maxHeap->size &&
        maxHeap->array[right] > maxHeap->array[largest]){
            printf("Como o filho direita é maior que a raiz o maior se torna o da esquerda %d %d\n", largest,right);
            largest = right;
        }

    // Change root, if needed
    if (largest != index)
    {
        printf("Fazendo o swap do maior \n");
        swap(&maxHeap->array[largest], &maxHeap->array[index]);
        maxHeapify(maxHeap, largest);
    }
}

// A utility function to create a max heap of given capacity
struct MaxHeap* createAndBuildHeap(int *array, int size)
{
    int i;
    struct MaxHeap* maxHeap =
              (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = size;   // initialize size of heap
    maxHeap->array = array; // Assign address of first element of array

    // Start from bottommost and rightmost internal mode and heapify all
    // internal modes in bottom up way
    printf("Criando o max heapify\n");
    for (i = (maxHeap->size - 2) / 2; i >= 0; --i){
         printf("Fazendo max heapify\n");
        maxHeapify(maxHeap, i);
        printArray(array,size);

    }
    return maxHeap;
}

// The main function to sort an array of given size
void heapSort(int* array, int size)
{
    // Build a heap from the input data.
    struct MaxHeap* maxHeap = createAndBuildHeap(array, size);

    // Repeat following steps while heap size is greater than 1.
    // The last element in max heap will be the minimum element
    while (maxHeap->size > 1)
    {
        // The largest item in Heap is stored at the root. Replace
        // it with the last item of the heap followed by reducing the
        // size of heap by 1.
        printf("fazendo a troca do primeiro com o ultimo\n");
        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
        printf("Diminuindo o tamanho do maxHeap\n");
        --maxHeap->size;  // Reduce heap size

        // Finally, heapify the root of tree.
        maxHeapify(maxHeap, 0);
        printArray(array,size);
    }

}

// A utility function to print a given array of given size
void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);

    printf("\n");
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {4,6,3,0,8,3,3,5,8,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, size);

    printf("\nSorted array is \n");
    printArray(arr, size);
    return 0;
}

