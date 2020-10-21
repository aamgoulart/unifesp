#include  <stdio.h>
#include <stdlib.h>
//DEFINE O JEITO DA LISTA
typedef struct{
    int coeficiente;
    int expoente;
}tipoItem;
//DEFINE A ESTRUTURA DA LISTA
typedef struct{
    tipoItem *lista;
    int ultimo;
    int tamanho;
}ListaLinearSD;
 
int inicializa(int n, ListaLinearSD *polinomio); //INICIALIZA A LISTA
void saida(ListaLinearSD *polinomio); //SAIDA DA LISTA
void preenche(ListaLinearSD *polinomio); //INSERE OS VALORES NA LISTA
void tiraElem(int posicao, ListaLinearSD *polinomio); //RETIRA ELEMENTOS VAZIOS
int buscaElem(int e, ListaLinearSD *polinomio); //BUSCA O LOCAL PARA INSERIR 
int buscaElemMenor(int e, ListaLinearSD *polinomio); //BUSCA O LOCAL PARA INSERIR
void deslocaElem(int j, ListaLinearSD *polinomio); //MOVE OS ELEMNTOS 
 
 
int main(){
    int tam;
    ListaLinearSD polinomio;
    scanf("%d\n",&tam);
    if(tam>=1 && tam<=1023){
        inicializa(tam,&polinomio);
        preenche(&polinomio);
        saida(&polinomio);
    }
}
 
int inicializa(int tam, ListaLinearSD *polinomio){
    polinomio->ultimo = 0;
    polinomio->tamanho = tam;
    polinomio->lista = malloc(tam *sizeof(polinomio));
}
 
void saida(ListaLinearSD *polinomio){
    int i = 0;
    if(polinomio->ultimo == 0){ //VERIFICA SE A LISTA ESTA VAZIA
        printf("nulo");
    }
    else{
        for(i=0; i < polinomio->ultimo; i++){ //PERCORRE A LISTA
            if(polinomio->lista[i].coeficiente<0){
                printf("%dx^%d ",polinomio->lista[i].coeficiente,polinomio->lista[i].expoente);
            }
            else{
                printf("+%dx^%d ",polinomio->lista[i].coeficiente,polinomio->lista[i].expoente);
            }
 
        }
    }
    printf("\n%d",polinomio->ultimo);
}
 
void preenche(ListaLinearSD *polinomio){
    int i, j, c, e;
    for(i=0;i < polinomio->tamanho;i++){
        scanf("%d %d\n",&c,&e);
        if(c>=-10000 && c<=10000 && e>=0 && e<=1023){ //LIMITA O EXPOENTE E COEFICIENTE
            if(polinomio->ultimo == 0){ //INSERE CASO A LISTA ESTEJA VAZIA 
                polinomio->lista[0].coeficiente = c;
                polinomio->lista[0].expoente = e;
                polinomio->ultimo++;
            }
            else{ //CASO NÃO ESTEJA VAZIA
                j = buscaElem(e, polinomio);
                if(j < polinomio->ultimo || polinomio->lista[polinomio->ultimo].expoente == e){ //INSERE E SOMA O ELEMENTO SE ELE FOR IGUAL
                    polinomio->lista[j].coeficiente += c;
                    if(polinomio->lista[j].coeficiente == 0){
                        tiraElem(j,polinomio);
                    }
                }
                else{ //SE O ELEMENTO FOR DIFERENTE 
                    j = buscaElemMenor(e, polinomio);
                    if(j == polinomio->ultimo){ //
                        polinomio->lista[j].expoente = e;
                        polinomio->lista[j].coeficiente = c;
                        polinomio->ultimo++;
                    }
                    else{
                        deslocaElem(j, polinomio);
                        polinomio->lista[j].expoente = e;
                        polinomio->lista[j].coeficiente = c;
                        polinomio->ultimo++;
                    }
                }
            }
        }
    }
}
 
 
 
int buscaElem(int e, ListaLinearSD *polinomio){
    int j;
    for(j=0; j < polinomio->ultimo && polinomio->lista[j].expoente != e ; j++){}
    return j;
}
 
void deslocaElem(int j, ListaLinearSD *polinomio){
    int k;
    for(k=polinomio->ultimo; k>j ;k--){
        polinomio->lista[k].expoente = polinomio->lista[k-1].expoente;
        polinomio->lista[k].coeficiente = polinomio->lista[k-1].coeficiente;
    }
 
}
 
int buscaElemMenor(int e, ListaLinearSD *polinomio){
    int j;
    for(j=0; j < polinomio->ultimo && polinomio->lista[j].expoente > e ; j++){}
    return j;
}
 
 
void tiraElem(int posicao, ListaLinearSD *polinomio){
    int i;
    if( posicao != polinomio->ultimo){
        for(i=posicao; i < polinomio->ultimo ;i++){
            polinomio->lista[i].expoente = polinomio->lista[i+1].expoente;
            polinomio->lista[i].coeficiente = polinomio->lista[i+1].coeficiente;
        }
    }
    polinomio->ultimo--;
}
