#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void testerString(char textInput[], char textOutput[]){
    bool valid = true;
    int length = strlen(textInput);
    int i;

    for (i=0; i<length; i++){
        if (textInput[i] != textOutput[i]){
            valid = false;
            break;
        } 
    }
     
    if (valid){
        printf("Sucesso!\n");
    } else {
        printf("Erro na entrada %d. Entrada ocorrida %c. Saida esperada %c\n", i , textInput[i], textOutput[i]);
    }
}

void testerFloat(float arrayInput[], float arrayOutput[], int length){
    bool valid = true;
    int i;

    for (i=0; i<length; i++){
        if (arrayInput[i] != arrayOutput[i]){
            valid = false;
            break;
        } 
    }
     
    if (valid){
        printf("Sucesso!\n");
    } else {
        printf("Erro na entrada %d. Entrada ocorrida %f. Saida esperada %f\n", i , arrayInput[i], arrayOutput[i]);
    }
}

void testerInt (int arrayInput[], int arrayOutput[], int length){
    bool valid = true;
    int i;

    for (i=0; i<length; i++){
        if (arrayInput[i] != arrayOutput[i]){
            valid = false;
            break;
        } 
    }
     
    if (valid){
        printf("Sucesso!\n");
    } else {
        printf("Erro na entrada %d. Entrada ocorrida %d. Saida esperada %d\n", i , arrayInput[i], arrayOutput[i]);
    }
}

void tester(int value){
    printf("-%d-");
}
