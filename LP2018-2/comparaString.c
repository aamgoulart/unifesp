#include <stdio.h>
#include <string.h>
 
void compara (char str1[], char str2[], char str3[]);
void ordena (int x,int  y, int z, char str1[], char str2[], char str3[]);
 
 
int main () {
 
    char str1[30], str2[30], str3[30];
 
    scanf ("%s",str1);
    scanf ("%s",str2);
    scanf ("%s",str3);
    
    compara (str1, str2, str3);
 
}
 
 
// compara as strings
void compara (char str1[], char str2[], char str3[]) {
    int x, y, z;
    x = strcmp (str1, str2);
    y = strcmp (str1, str3);
    z = strcmp (str2, str3);
 
    ordena (x,y,z, str1, str2, str3);
}
 
    // função para ordenar e imprimir as string
void ordena (int x,int  y, int z, char str1[], char str2[], char str3[]){
    char aux1[30], aux2[30], aux3[30];
 
    
    if (x<=0 && y<=0 && z<=0){
        printf ("%s %s %s", str1, str2, str3); 
    }  else if (x>=0 && y>=0 && z<=0){
        printf ("%s %s %s", str2, str3, str1); 
    } else if (x<=0 && y<=0 && z>=0){
        printf ("%s %s %s", str1, str3, str2); 
    } else if (x>=0 && y>=0 && z>=0){
        printf ("%s %s %s", str3, str2, str1); 
    } else if (x<=0 && y>=0 && z>=0){
        printf ("%s %s %s", str3, str1, str2); 
    } else if (x>=0 && y<=0 && z<=0){
        printf ("%s %s %s", str2, str1, str3); 
    }
 
}
×
