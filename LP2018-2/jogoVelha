#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int i, j, l, c, contador;
    char m[3][3];
    bool ganhar;


    for(i=0; i<3;i++){
        for(j=0; j<3;j++){
            m[i][j]='-';
        }
    }
    printf("JOGO DA VELHA\n\n");
    printf("Exemplo de cordenadas pra jogar o jogo:\n");
    printf("1 3 (1 referente a linha 3 referente a coluna)\n");
    printf(" - - X\n ");
    printf("- - -\n ");
    printf("- - -\n\n ");
    printf("Primeiro jogador é X e o segundo é O\n\n");
    while(ganhar==false){
        printf("selecione as cordenadas P1:");
        scanf("%d %d", &l, &c);
        m[l-1][c-1]='X';
        for(i=0; i<3;i++){
            for(j=0; j<3;j++){
                printf("%c\t",m[i][j]);
            }
            printf("\n");
        }
        //X na horizontal
        contador=0;
        for(i=0; i<3;i++){
            for(j=0; j<3;j++){
                if(m[i][j]=='X'){
                    contador++;
                }
            }
            if(contador==3){
            ganhar=true;
            break;
            }
            else{
            ganhar=false;
            }
        }
        if(ganhar==false){
        //X na vertical
        contador=0;
        for(i=0; i<3;i++){
            for(j=0; j<3;j++){
                if(m[j][i]=='X'){
                    contador++;
                }
            }
            if(contador==3){
            ganhar=true;
            break;
            }
            else{
            ganhar=false;
            }
        }
        }
        if(ganhar==false){
        //O na horizontal
        contador=0;
        for(i=0; i<3;i++){
            for(j=0; j<3;j++){
                if(m[i][j]=='O'){
                    contador++;
                }
            }
            if(contador==3){
            ganhar=true;
            break;
            }
            else{
            ganhar=false;
            }
        }
        }
        if(ganhar==false){
        //O na vertical
        contador=0;
        for(i=0; i<3;i++){
            for(j=0; j<3;j++){
                if(m[j][i]=='O'){
                    contador++;
                }
            }
            if(contador==3){
            ganhar=true;
            break;
            }
            else{
            ganhar=false;
            }
        }
        }
        if (ganhar==false){
        printf("selecione as cordenadas P2:");
        scanf("%d %d", &l, &c);
        m[l-1][c-1]='O';
        for(i=0; i<3;i++){
            for(j=0; j<3;j++){
                printf("%c\t",m[i][j]);
            }
            printf("\n");
        }
        }
        else{
        break;
        }
        //X na horizontal
        contador=0;
        for(i=0; i<3;i++){
            for(j=0; j<3;j++){
                if(m[i][j]=='X'){
                    contador++;
                }
            }
            if(contador==3){
            ganhar=true;
            break;
            }
            else{
            ganhar=false;
            }
        }
        if(ganhar==false){
        //X na vertical
        contador=0;
        for(i=0; i<3;i++){
            for(j=0; j<3;j++){
                if(m[j][i]=='X'){
                    contador++;
                }
            }
            if(contador==3){
            ganhar=true;
            break;
            }
            else{
            ganhar=false;
            }
        }
        }
        if(ganhar==false){
        //O na horizontal
        contador=0;
        for(i=0; i<3;i++){
            for(j=0; j<3;j++){
                if(m[i][j]=='O'){
                    contador++;
                }
            }
            if(contador==3){
            ganhar=true;
            break;
            }
            else{
            ganhar=false;
            }
        }
        }
        if(ganhar==false){
        //O na vertical
        contador=0;
        for(i=0; i<3;i++){
            for(j=0; j<3;j++){
                if(m[j][i]=='O'){
                    contador++;
                }
            }
            if(contador==3){
            ganhar=true;
            break;
            }
            else{
            ganhar=false;
            }
        }
        }
    }
    printf("Você ganhou!!!");
    return 0;
}
