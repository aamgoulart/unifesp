#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int cost;
    int mutation;
} cell;


void row(int i, cell m[][1000]);
void column(int i, cell m[][1000]);
int isEqual(char c, char d);
void getSizeReal(char *s, char *t, int *i, int *j);
void init(cell m[][1000]);
int getEditions(char *s, char *t, cell m[][1000]);


int main(){

    cell m[1000][1000];
    char A[1000], B[1000];

    scanf("%s %s", A,B);

    init(m);
    
    printf("%d", getEditions(A, B, m));

}



void row(int i, cell m[][1000]){
    m[0][i].cost = i;
    if(i > 0){
        m[0][i].mutation = 1;
    }
    else{
        m[0][i].mutation = -1;
    }
}


void column(int i, cell m[][1000]){
    m[i][0].cost = i;
    if(i > 0){
        m[i][0].mutation = 2;
    }
    else{
        m[i][0].mutation = -1;
    }
}

int isEqual(char c, char d)
{
  return !(c==d); 
}


void getSizeReal(char *s, char *t, int *i, int *j){
    *i = strlen(s)-1;
    *j = strlen(t)-1;
}

void init(cell m[][1000]) {
    int i;
    for(i=0; i<1000; i++){
        row(i, m);
        column(i,m);
    }
}

int getEditions(char *s, char *t, cell m[][1000]){
    int i, j, k;
    int opt[3];

    int lenS = strlen(s);
    for(i=1; i< lenS; i++){
        int lenT = strlen(t);
        for(j=1; j < lenT; j++){
            opt[0] = m[i-1][j-1].cost + isEqual(s[i], t[j]);
            opt[1] = m[i][j-1].cost + 1;
            opt[2] = m[i-1][j].cost + 1;
            m[i][j].cost = opt[0];
            m[i][j].mutation = 0;

            for(k=1; k<=2;k++){
                if(opt[k] < m[i][j].cost){
                    m[i][j].cost  = opt[k];
                    m[i][j].mutation = k; 
                }
            } 
        }
    }

    getSizeReal(s, t, &i, &j);



    return m[i][j].cost;
}

