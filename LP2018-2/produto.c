#include <stdio.h>
#include <stdlib.h>

int main(){
int x, y, produto, i;
printf("Programa que calcula a multiplicaçao de dois numeros\n");
printf("Entre com o primeiro número\n");
scanf("%d", &x);
printf("Entre com o segundo numero\n");
scanf("%d", &y);
produto =0;
for ( i = 0; i < y; i++){
    produto+=x; //a porra nao ta multiplicando
}
printf("%d",produto);
return(0);
}
