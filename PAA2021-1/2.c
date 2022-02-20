#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX 100

void longestPalindrome(char str[]);

int main()
{
    char str[100];

    scanf("%s", str);

    longestPalindrome(str);
}

void longestPalindrome(char str[])
{

    int len = strlen(str);
    int dp[MAX][MAX];
    char newStr[MAX];
    int start = 0;
    int end = 0;
    int max = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (str[i] == str[j] && (i - j <= 2 || dp[j + 1][i - 1]))
            {
                dp[j][i] = 1;
            }
            if (dp[j][i] && max < i - j + 1)
            {
                max = i - j + 1;
                start = j;
                end = i;
            }
        }
    }

    substring(str, newStr, start, end);
    printf("%s", newStr);
}

void substring(char s[], char sub[], int p, int l) {
   int c = 0;
   
   while (c < l) {
      sub[c] = s[p+c-1];
      c++;
   }
   sub[c] = '\0';
}