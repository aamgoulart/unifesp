#include <stdio.h>
#define MAX 100
int count(int S[], int n, int N);

int main () {

    int array[MAX], size, coin;

    scanf("%d", &coin);

    scanf("%d", &size);

    for (int i=0; i<size; i++) {
        scanf("%d", &array[i]);
    }

    printf("%d", count(array, coin, size));

}


int count(int S[], int n, int N)
{
    // if the total is 0, return 1
    if (N == 0) {
        return 1;
    }
 
    // return 0 if total becomes negative
    if (N < 0) {
        return 0;
    }
 
    // initialize the total number of ways to 0
    int result = 0;
 
    // do for each coin
    for (int i = 0; i < n; i++)
    {
        // recur to see if total can be reached by including
        // current coin `S[i]`
        result += count(S, n, N - S[i]);
    }
 
    // return the total number of ways
    return result;
}