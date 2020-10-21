#include <stdio.h>
#include <string.h>
#define ALF 26

void vetor_letras_maiusculas(char maiusculas[]);
void vetor_letras_minusculas(char minusculas[]);
void limpa_lixo(int vetor_cont[]);
void conta (int cont_letras[], char str[], int tam_str, char letras[]);
void total(int cont_mai[], int cont_min[], int cont_total[]);
void saida (int cont_total[]);

int main(){
    char maiusculas[26], minusculas[26], str[100];
    int cont_mai[26], cont_min[26], tam_str, cont_total[26];

    scanf("%s", str);
    tam_str= strlen(str);
    letras_maiusculas(maiusculas);
    letras_minusculas(minusculas);
    limpa_lixo(cont_mai);
    limpa_lixo(cont_min);
    limpa_lixo(cont_total);
    conta(cont_mai, str, tam_str, maiusculas);
    conta(cont_min, str, tam_str, minusculas);
    total(cont_mai, cont_min, cont_total);
    saida(cont_total);
    
}
// vetor para inserir letras maiusculas
void letras_maiusculas(char maiusculas[]){
    char a=65;
    for (int i=0; i<ALF; i++){
        maiusculas[i]=a;
        a++;
    }
}

// vetor para inserir letras minusculas
void letras_minusculas(char minusculas[]){
    char a=97;
    for (int i=0; i<ALF; i++){
        minusculas[i]=a;
        a++;
    }
}
// limpar o lixo de memoria  dos vetores de contagem
void limpa_lixo(int vetor_cont[]){
    for (int i=0; i<ALF; i++){
       vetor_cont[i]=0;
    }
}
// contagem da comparação da String com os caracteres
void conta (int cont_letras[], char str[], int tam_str, char letras[]){
    for (int i=0; i< tam_str; i++){
        for (int j=0; j<ALF; j++){
            if (str[i] == letras[j]){
                cont_letras[j]++;
            }
        }
    }
}

// soma da contagem de maiusculas e minusculas
void total(int cont_mai[], int cont_min[], int cont_total[]){
    for (int i=0; i<ALF; i++){
        cont_total[i] = cont_mai[i]+ cont_min[i];
    }
}

// saida com as letras que estão na String 
void saida (int cont_total[]){
    char a=65;
    for (int i=0; i<ALF; i++){
        if (cont_total[i] > 0){
        printf("%c: %d \n" , a, cont_total[i]);
        }
        a++;
    }
}
