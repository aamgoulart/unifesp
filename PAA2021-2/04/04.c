#include <stdio.h>
 
int max(int a, int b);
int knapSack(int N, int taxa[], int bytes[], int n);

int main() {
    int N, C, i, size;

    scanf("%d %d", &N,&C);

    int taxa[N];
    int bytes[N];
    int a=0, b=0;

    size = N * 2;

    for (i=0; i<size; i++) {
        if (i % 2 == 0) {
            scanf("%d", &taxa[a]);
            a++;
        } else {
            scanf("%d", &bytes[b]);
            b++;
        }
    }

    int n = sizeof(taxa) / sizeof(taxa[0]);
    
    printf("%d", knapSack(C, bytes, taxa, n));
    return 0;
}

int max(int a, int b) { return (a > b) ? a : b; }
 

int knapSack(int N, int taxa[], int bytes[], int n) {
    if (n == 0 || N == 0) {
        return 0;
    }
 

    if (taxa[n - 1] > N) {
        return knapSack(N, taxa, bytes, n - 1);
    } else {
        return max(bytes[n - 1]  + knapSack(N - taxa[n - 1], taxa, bytes, n - 1),  knapSack(N, taxa, bytes, n - 1));
    }

}
 