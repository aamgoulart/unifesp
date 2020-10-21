#include <stdio.h>

#define MAX 2000

void clearTable(int hash[][MAX]);
void insertion(int hash[][MAX], int value, int sizeHash);
int find(int hash[][MAX],int value, int sizeHash);
void remotion(int hash[][MAX],int value,int sizeHash);
void output(int hash[][MAX], int sizeHash);

int main () {
    int sizeHash, hash[MAX][MAX], value, findValue, sizeInput,i;


    scanf("%d", &sizeHash);

    scanf("%d", &sizeInput);

    clearTable(hash);

    for (i=0; i<sizeInput; i++) {
        scanf("%d", &value);
        insertion(hash, value, sizeHash);
    }

    scanf("%d", &findValue);

    if (find(hash,findValue, sizeHash)){
        remotion(hash, findValue, sizeHash);
    } else if (find(hash,findValue, sizeHash) == 0){
        insertion(hash, findValue, sizeHash);
    }
    
    output(hash, sizeHash);
}

void clearTable(int hash[][MAX]) {
    int i,j;

    for (i=0; i<MAX; i++){
        for (j=0; j<MAX; j++){
            hash[i][j] = 0;
        }
    }
}

void insertion(int hash[][MAX], int value, int sizeHash) {
    int key = value%sizeHash;
    // printf("key - %d value %d\n", key, value);
    int i;

    for(i=0; i<MAX; i++) {
        if (hash[key][i] == 0) {
            hash[key][i] = value;
            break;
        }
    }
}

int find(int hash[][MAX],int value, int sizeHash){
    int i,j, exist =0;

    for(i=0; i<sizeHash; i++) {
        for (j=0; j<MAX; j++) {
            if (hash[i][j] == value) {
                exist = 1;

            }
        }
    }

    return exist;
}

void remotion(int hash[][MAX],int value, int sizeHash) {
    int i,j;

    for(i=0; i<sizeHash; i++) {
        for (j=0; j<MAX; j++) {
            if (hash[i][j] == value) {
                hash[i][j] = 0;
                break;
            }
        }
    }
}

void output(int hash[][MAX],int sizeHash){
    int i,j;

    for(i=0; i<sizeHash; i++) {
        printf("[%d]", i);
        for (j=0; j<MAX; j++) {
            if (hash[i][j] != 0) {
                printf(" %d ", hash[i][j]);

            }
        }
        printf("\n");
    }
}
