    #include <bits/stdc++.h>
    using namespace std;
    int knapSack(int W, int taxa[], int bytes[], int n)
    {
        int dp[W + 1];
        memset(dp, 0, sizeof(dp));
     
        for (int i = 1; i < n + 1; i++) {
            for (int w = W; w >= 0; w--) {
                if (taxa[i - 1] <= w) {
                    dp[w] = max(dp[w],dp[w - taxa[i - 1]] + bytes[i - 1]);
                }
            }
        }
        return dp[W]; 
    }
    int main()
    {
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