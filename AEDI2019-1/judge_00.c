#include <stdlib.h>
#include <stdio.h>
#define TAM 5

//FUNÇÕES UTILIZADAS
void random_array(int **array); //PREENCHE A MATRIZ ALEATORIAMENTE
int** create(int **array); // CRIA A MATRIZ
void out(int **array); // SAIDA DA MATRIZ
void release(int **array); //LIBERA A MEMORIA
void search(int **array, int number); //BUSCA ELEMENTO
void searchChange(int **array, int number); //BUSCA ELEMENTO E TROCA
void element (int **array, int line, int column); //ACESSA DETERMINADA POSIÇÃO

int main(){
    int **array, menu, line, column, number;
   
    array = create(array);
    random_array(array);
    out(array);


    // MENU PARA AS OPÇÕES PARA O ITEM B E C DO EXERCICIO
    printf(" ______MENU_____\n 1- Ler qualquer elemento [i,j] válido da array\n 2- Ler qualquer elemento [i,j] válido da array e trocar\n 3- Acessar uma posição na Matriz\n");
    scanf("%d", &menu);
    switch (menu){
        case 1: // LOCALIZA ELEMENTO 
            printf("Insira o valor da linha\n");
            scanf("%d", &number);
            search(array, number);
        break;

        case 2: //LOCALIZA ELEMENTO E TROCA
                        printf("Insira o valor da linha\n");
            scanf("%d", &number);
            searchChange(array, number);
        break;
    
        case 3: //LOCALIZA ELEMENTO E TROCA
            printf("Insira o valor da linha\n");
            scanf("%d", &line);
            printf("Insira o valor da coluna\n");
            scanf("%d", &column);
            element(array,line,column);
        break;

        default:
            printf("Opção invalida\n");
            break;
    }
     release(array);
}

void random_array(int **array){
    int i,j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            array[i][j] = rand() % 10;
        }
    }
}

void out(int **array){
    int i,j, aux=5;
    printf("Matriz Simetrica\n");
    for(i=0; i<TAM; i++, aux--){
        for(j=0; j<aux; j++){
        printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void release(int **array){
    int i;
    //desalocando a array
    for(i=0; i<5; i++){
      free(array[i]);
    }
    free(array);
}

int** create(int **array){
     int i,j;
    //CRIANDO A array DINAMICAMENTE
    array=(int**)malloc(5*sizeof(int*));

    for(i=0; i<5; i++){
     array[i] = (int*)malloc(5*sizeof(int));
    } 
    return array;
}

void search(int **array, int number){
    int i, j, aux=5, not=0;
   for(i=0; i<TAM; i++, aux--){
        for(j=0; j<aux; j++){
            if (number == array[i][j]){
                printf("Elemento encontrado %d\n", array[i][j]);
            } else{
                not++;
            }
        }
    }
    
    if (not == 15){
        printf("Elemento não encontrado\n");
    }
}

void searchChange(int **array, int number){
    int new;
     int i, j, aux=5, not=0;
   for(i=0; i<TAM; i++, aux--){
        for(j=0; j<aux; j++){
            if (number == array[i][j]){
                printf("Elemento encontrado %d\n", array[i][j]);
                scanf("%d", &new);
                array[i][j] = new;
            } else{
                not++;
            }
        }
    }
    
    if (not == 15){
        printf("Elemento não encontrado\n");
    }
}

void element(int **array, int line, int column){
    if (line == 0 && column < 4 || line == 1 && column <3 || line == 2 && column <2 || line == 3 && column < 1 || line == 4 && column < 0 || line < 5){
        printf("Valor encontrado: %d\n", array[line][column]);
    } else {
        printf("Posição invalida\n");
    }
}
