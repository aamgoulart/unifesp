    #include <stdio.h>
    #include <stdlib.h>
     
    typedef struct {
        int *vector;
        int size;
        int start;
        int mainlocalization;
    }node;
     
    typedef struct {
        node *node;
        int size;
    }type;
     
    void deleteMinor (type *matrix, int smaller);
    int sum (type *matrix);
    int findMinor (type *matrix);
     
     
    int main () {
        int I, K, counter, vetsize, result;
        type matrix;
     
        scanf("%d %d", &K, &I);
     
        matrix.node = malloc(K * sizeof(node));
        matrix.size = K;
     
        for (counter = 0; counter < K; counter++){
            scanf("%d", &vetsize);
            if (vetsize == 0) {
                counter--;
                K--;
                matrix.size--;
            } else {
                matrix.node[counter].vector = malloc(vetsize * sizeof(int));
                matrix.node[counter].size = vetsize;
                matrix.node[counter].start = 0;
                matrix.node[counter].mainlocalization = counter;
     
                for (int index = 0; index < vetsize; index++){
                    scanf("%d", &matrix.node[counter].vector[index]);
                }
            }
        }
     
     
     
        for (int j = 0; j < I-1; ++j) {
            int smaller = findMinor(&matrix);
            deleteMinor(&matrix, smaller);
        }
     
        result = sum(&matrix);
     
        printf("%d\n", result);
     
        return 0;
    }
     
    int findMinor (type *matrix) {
        int smaller = matrix->node[0].vector[matrix->node[0].start];
     
        for (int i = 0; i < matrix->size; ++i) {
            if(matrix->node[i].size > 0) {
            if (matrix->node[i].vector[matrix->node[i].start] < smaller)
                smaller = matrix->node[i].vector[matrix->node[i].start];
            }
        }
        return smaller;
    }
     
     
    void deleteMinor (type *matrix, int smaller) {
        int smallerposition = matrix->node[0].mainlocalization, newindex = 0;
     
     
        for (int i = 0; i < matrix->size; ++i) {
            if (matrix->node[i].vector[matrix->node[i].start] == smaller){
                matrix->node[i].start++;
                matrix->node[i].size--;
            }
        }
     
    }
     
    int sum (type *matrix) {
        int sum = 0;
        for (int i = 0; i < matrix->size; ++i) {
            if (matrix->node[i].size > 0)
                sum += matrix->node[i].vector[matrix->node[i].start];
        }
        return sum;
    }