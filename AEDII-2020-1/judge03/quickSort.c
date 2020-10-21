#include <stdio.h>
#include <string.h>
#define N 105000
typedef struct People {
    char name[15];
    int age;
} People;

void swap(People people[], int i, int j);
int partition(People A[], int init, int end);
void quicksortMedian(People people[], int init, int end);
void output(People people[], int sizePeopleOutput, int positionFirstName);

int main() {
    People people[N];
    int positionFirstName, qtdPeople, sizePeopleOutput;
    int i;

    scanf("%d", &qtdPeople);

    for (i=0; i<qtdPeople; i++){
        scanf("%s", people[i].name);
        scanf("%d", &people[i].age);
    }

    scanf("%d", &positionFirstName);
    scanf("%d", &sizePeopleOutput);

   quicksortMedian(people, 0, qtdPeople);   

   output(people, sizePeopleOutput, positionFirstName); 

}

void swap(People people[], int i, int j) {
   char temp[15];
   strcpy(temp, people[i].name); 
   strcpy (people[i].name ,people[j].name);
   strcpy (people[j].name, temp);
   int temporary;

   temporary = people[i].age;
   people[i].age = people[j].age;
   people[j].age = temporary;

}

int partition(People A[], int init, int end) {
    //procura a mediana entre init, middle e end
    int middle = (init + end) / 2;
    int a = A[init].age;
    int b = A[middle].age;
    int c = A[end].age;
    int median; //índice da mediana
    //A sequência de if...else a seguir verifica qual é a mediana
    if (a < b) {
        if (b < c) {
            //a < b && b < c
            median = middle;
        } else {
            if (a < c) {
                //a < c && c <= b
                median = end;
            } else {
                //c <= a && a < b
                median = init;
            }
        }
    } else {
        if (c < b) {
            //c < b && b <= a
            median = middle;
        } else {
            if (c < a) {
                //b <= c && c < a
                median = end;
            } else {
                //b <= a && a <= c
                median = init;
            }
        }
    }
    //coloca o elemento da mediana no end para poder usar o Quicksort de Cormen
    swap(A, median, end);
        
    //*******************ALGORITMO DE PARTIÇÃO DE CORMEN*********************
    //o pivo é o elemento final
    int pivo = A[end].age;
    int i = init - 1;
    int j;
    /*
     * Este laço irá varrer os vetores da esquerda para direira
     * procurando os elementos que são menores ou iguais ao pivô.
     * Esses elementos são colocados na partição esquerda.         
     */
    for (j = init; j <= end - 1; j++) {
        if (A[j].age <= pivo) {
            i = i + 1;
            swap(A, i, j);
        }
    }
    //coloca o pivô na posição de ordenação
    swap(A, i + 1, end);
    return i + 1; //retorna a posição do pivô
}

void quicksortMedian(People people[], int init, int end) {
    if (init < end) {
        //realiza a partição
        int q = partition(people, init, end);
        //ordena a partição esquerda
        quicksortMedian(people, init, q - 1);
        //ordena a partição direita
        quicksortMedian(people, q + 1, end);
    }
}

void output(People people[], int sizePeopleOutput, int positionFirstName){
   int i;
   printf("no\n");
   for (i = positionFirstName; i < sizePeopleOutput + positionFirstName; i++) {
      printf("%s %d\n", people[i].name, people[i].age);
   }
}