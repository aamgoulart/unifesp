#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
 
//CRIA O MODELO
typedef struct {
  int  digito;
  char element;
} tipoItem ;
 
//CRIA A PILHA
typedef struct {
    tipoItem pilha[MAX];
    int tamanho;
    int topo; 
} tipoPilha;
 
//FUNÇÕES
void iniciaPilha(tipoPilha *pilha); //CRIA A PILHA
int pilhaCheia(tipoPilha *pilha); //VERIFICA SE A PILHA ESTA CHEIA
int pilhaVazia(tipoPilha *pilha); //VERIFICA SE A PILHA ESTA VAZIA
int pop(tipoPilha *pilha); //TIRA ELEMENTO DA PILHA
void push(tipoPilha *pilha, int valor); //INSERE ELEMENTO DA PILHA
int checagem(tipoPilha *pilha, char digitos); //CHECA SE O NUMERO ESTA ENTRE 0 E 9
int operacoes(tipoPilha *pilha, char digito); //REALIZA AS OPERAÇOES
void saida(tipoPilha *pilha); //IMPRIME O RESULTADO
void preparingForRpm(char infix[], char postfix[], tipoPilha *pilhaP);
char pilhaTopo(tipoPilha *pilha);
char popChar (tipoPilha *pilha);
void pushChar(tipoPilha *pilha, char valor);
int main (){
    tipoPilha pilha;
    tipoPilha pilhaP;
    int i;
    char digito= ' ';
    char infix[MAX];
    char poxfix[MAX];
    iniciaPilha(&pilha);
    iniciaPilha(&pilhaP);
 

    // while(digito != '\n'){
    //     scanf("%c", &digito);
    //     if (checagem(&pilha,digito) == 0){
    //         digito = digito - '0';
    //         push(&pilha,digito);
    //     } else {
    //         operacoes(&pilha,digito);
    //         }
    //     }
    scanf("%s", infix);
    preparingForRpm(infix,poxfix, &pilhaP);
    printf("%s\n", poxfix);
    // outputPostfix(poxfix);
    
    // saida(&pilha);
}

void preparingForRpm(char infix[], char postfix[], tipoPilha *pilhaP){
    int i;
    int j=0;

    for (i=0; i<strlen(infix); i++){
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/'){
            printf("operação\n");
            if (pilhaVazia(pilhaP) == 0) {
                push(pilhaP, infix[i]);
            }else if (pilhaTopo(pilhaP) == '+' && infix[i] == '*'){
                push(pilhaP, infix[i]);
            } else if (pilhaTopo(pilhaP) == '+' && infix[i] == '/'){
                push(pilhaP, infix[i]);
            } else if (pilhaTopo(pilhaP) == '-' && infix[i] == '*'){
                push(pilhaP, infix[i]);
            } else if (pilhaTopo(pilhaP) == '-' && infix[i] == '/'){
                push(pilhaP, infix[i]);
            }else {
                postfix[j] = pop(pilhaP);
                j++;
            }
        } else if (infix[i] == '('){
            push(pilhaP, infix[i]);
        } else if(infix[i] == ')') {
            while (pilhaTopo(pilhaP) != '('){
                postfix[j] = pop(pilhaP);
                j++;
            }
        } else {
            postfix[j] = infix[i];
            printf("numero\n");
            j++;
        }
    }

}

// void outputPostfix(char postfix[]){
//     int i;
//     for (i = 0; i <strlen(postfix); i++){
//         printf("%c", postfix[i]);
//     }
// }
 
void iniciaPilha (tipoPilha *pilha){
    pilha->topo = -1;
    pilha->tamanho = MAX;
}
 
int pilhaCheia(tipoPilha *pilha){
    if (pilha->topo == pilha->tamanho-1){
        return -1;
    }
    return 0;
}
 
int pilhaVazia(tipoPilha *pilha){
    if (pilha->topo == -1){
        return -1;
    }
 
    return 0;
}

char pilhaTopo(tipoPilha *pilha){
    return pilha->pilha[pilha->topo].element;
}
 
int pop (tipoPilha *pilha){
    int ultimo;
    if (pilhaVazia(pilha) == -1){
        return -1;
    } else {
 
    ultimo = pilha->pilha[pilha->topo].digito;
    pilha->topo--;
 
    return ultimo;
    }
}

char popChar (tipoPilha *pilha){
    int ultimo;
    if (pilhaVazia(pilha) == -1){
        return -1;
    } else {
 
    ultimo = pilha->pilha[pilha->topo].element;
    pilha->topo--;
 
    return ultimo;
    }
}
 
void push(tipoPilha *pilha, int valor){
    pilha->topo++;
    pilha->pilha[pilha->topo].digito = valor;
}

void pushChar(tipoPilha *pilha, char valor){
    pilha->topo++;
    pilha->pilha[pilha->topo].element = valor;
}
 
int checagem(tipoPilha *pilha, char digito){
    int i;
 
    if ( digito > 47 && digito <58){
            return 0;
    }
    
    return -1;
}
 
int operacoes(tipoPilha *pilha, char digito){
    int valorUm, valorDois, resultado;
    switch (digito){
        case '+':
            valorUm = pop(pilha);
            valorDois = pop(pilha);
            if (valorUm != -1 && valorDois != -1) {
            resultado =  valorUm +  valorDois;
            push(pilha,resultado);
            } else {
                return -1;
            }
            break;
    
        case '-':
            valorUm = pop(pilha);
            valorDois = pop(pilha);
            if (valorUm != -1 && valorDois != -1) {
            resultado = valorDois - valorUm;
            push(pilha,resultado);
            } else {
                return -1;
            }
            break;
 
        case '*':
            valorUm = pop(pilha);
            valorDois = pop(pilha);
            if (valorUm != -1 && valorDois != -1) {
            resultado =  valorUm *  valorDois;
            push(pilha,resultado);
             } else {
                return -1;
            }
            break;
 
        case '/':
            valorUm = pop(pilha);
            valorDois = pop(pilha);
            if (valorUm != -1 && valorDois != -1) {
            resultado =  valorDois / valorUm;
            push(pilha,resultado);
            } else {
                return -1;
            }
            break;
    }
}
 
void saida (tipoPilha *pilha){
    int resultadoFinal;
    resultadoFinal =  pop(pilha);
    if (pilhaVazia (pilha) == -1 && resultadoFinal != -1){
        printf("%d", resultadoFinal);
    } else if (pilhaVazia(pilha) == 0 || resultadoFinal == -1) {
        printf("Invalid Expression\n");
    } 
 
}
