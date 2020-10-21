#include <stdio.h>

int pow(int n){
    if (n == 0){
        return 1;
    } else {
        return pow(n-1)*2;
    }
}

int main(){
    int value;

    scanf("%d", &value);

    printf("%d", pow(value));
}
