#include <stdio.h>
 
int max(long long int a, long long int b);
int knapSack(long long int N, long long int taxa[],long long int bytes[],long long int n);

int main() {
    long long int N, C, i, size;

    scanf("%lld %lld", &N,&C);

    long long int taxa[N];
    long long int bytes[N];
    long long int a=0, b=0;

    size = N * 2;

    for (i=0; i<size; i++) {
        if (i % 2 == 0) {
            scanf("%lld", &taxa[a]);
            a++;
        } else {
            scanf("%lld", &bytes[b]);
            b++;
        }
    }

    int n = sizeof(taxa) / sizeof(taxa[0]);
    
    printf("%lld", knapSack(C, bytes, taxa, n));
    return 0;
}

int max(long long int a, long long int b) { return (a > b) ? a : b; }
 

int knapSack(long long int N, long long int taxa[], long long int bytes[], long long int n) {
    if (n == 0 || N == 0) {
        return 0;
    }
 

    if (taxa[n - 1] > N) {
        return knapSack(N, taxa, bytes, n - 1);
    } else {
        return max(bytes[n - 1]  + knapSack(N - taxa[n - 1], taxa, bytes, n - 1),  knapSack(N, taxa, bytes, n - 1));
    }

}
 