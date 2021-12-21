#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *vector;
    int size;
    int init;
} node;

typedef struct {
    node *node;
    int size;
} type;

void output(type data);

int main () {
    int I, K, i, j, size;
    type data;


    scanf("%d %d", &K, &I);

    data.node = malloc(K * sizeof(type));
    data.size = K;

    for (i=0; i<K; i++) {
        scanf("%d", &size);
        data.node[i].vector = malloc(size* sizeof(int));
        for (j=0; j<size; j++) {
            scanf("%d", &data.node[i].vector[j]);
        }
        data.node[i].size = size;
        data.node[i].init = 0;
    }

    output(data);
}


void output(type data) {
    int i,j;
    for (i=0; i<data.size; i++) {
        for(j=data.node[i].init; j<data.node[i].size; j++) {
            printf("%d ", data.node[i].vector[j]);
        }

        printf("\n");
    }
}

void deleteLess() {

}

void findLess(type *data) {
    int i, menor = 99999999;
    for (i=0; i<data->size; i++) {

    }
}