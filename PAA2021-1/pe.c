#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void longestPalindrome(char s[]) {
    int len_S = strlen(s);
    
    int maxLen = 0;
    char maxSub[] = "";
    char w[100];

    char dp[len_S][len_S];
    
    for(int i = len_S-2 ; i>=0 ;--i){
        int maxJ = i;
        for (int j = i+1; j < len_S; j++) { 
            if(w[j] == w[i] && (j < i+3 || dp[i+1][j-1])){
                dp[i][j] = 1;
                maxJ = j;
            }
            else{
                dp[i][j] = 0;
            }
        }

        int len_maxSub = strlen(maxSub);
        
        if(maxJ - i+1 > maxLen){
            maxLen = maxJ - i+1;
            
            int c = 0;
   
            while (c < len_maxSub-1) {
                maxSub[c] = s[c-1];
                c++;
            }
            maxSub[c] = '\0';
        }
    }

    
    
    printf("%s", maxSub);
}

int main(){
    char s[] = "character";

    longestPalindrome(s);
    return 0;
}