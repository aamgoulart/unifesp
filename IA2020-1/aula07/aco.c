#include <stdio.h>
#define ALPHA 1
#define BETA 1
#define RHO 0.5
#define TAU 2
#define TAM 5 

void probabilityEdge(float probabilityWay[][TAM], float pheromone[][TAM], float qualityEdges[][TAM]);
void outputArray(float array[][TAM]);
void updatePheromone(float pheromone[][TAM]);
int findBigger(float qualityEdges[][TAM], int visitedCurrent, int visited[], int tamanhoVisited);
void findRouter(float qualityEdges[][TAM], int visited[], int init);
void outputVisited(int visited[]);


int main(){
    float probabilityWay[TAM][TAM] = {{0.0,0.0,0.0,0.0,0.0}, {0.0,0.0,0.0,0.0, 0.0}, {0.0,0.0,0.0,0.0, 0.0}, {0.0,0.0,0.0,0.0, 0.0}, {0.0,0.0,0.0,0.0, 0.0}};
    float qualityEdges[TAM][TAM] = {{0,2,10,8,3}, {1,0,2,5,7}, {9,1,0,3,6}, {10,4,3,0,2}, {2,7,5,1,0}};
    float pheromone[TAM][TAM] = {{0,2,2,2,2}, {2,0,2,2,2}, {2,2,0,2,2}, {2,2,2,0,2}, {2,2,2,2,0}};
    int visited[5], i;


    for (i=0; i<5; i++) {
        probabilityEdge(probabilityWay, pheromone, qualityEdges);
        printf("Saindo de 0\n");
        findRouter(qualityEdges, visited, i);
        printf("Probabilidade\n");
        outputArray(probabilityWay);
        updatePheromone(pheromone);
        printf("Atualização do feromônio\n");
        outputArray(pheromone);
        printf("Caminho\n");
        outputVisited(visited);
    }

}

void probabilityEdge(float probabilityWay[][TAM], float pheromone[][TAM], float qualityEdges[][TAM]) {
    int i, j;

    for (i=0; i<TAM; i++) {
        for (j=0; j<TAM; j++) {
            if (qualityEdges[i][j] != 0) {
                probabilityWay[i][j] = ((ALPHA* pheromone[i][j])*(BETA*1/qualityEdges[i][j]))/46;
            }
        }
    }
}

void outputArray(float array[][TAM]){
    int i,j;
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            printf("%f ", array[i][j]);
        }
        printf("\n");
    }
}

void updatePheromone(float pheromone[][TAM]){
    int i,j;
    for (i=0;i<TAM;i++){
        for (j=0; j<TAM; j++){
            if (pheromone[i][j] != 0){
                pheromone[i][j] = (ALPHA*RHO)*TAU*(RHO*1/pheromone[i][j]);
            }
        }
    }
}

void findRouter(float qualityEdges[][TAM], int visited[], int init){
    int i =0;
    int visitedCurrent;

    visited[i] = init;
    i++;
    visitedCurrent = findBigger(qualityEdges, init, visited, i);
    visited[i] = visitedCurrent;
    i++;


    while (i < 5) {
        visitedCurrent = findBigger(qualityEdges, visitedCurrent, visited, i);
        visited[i] = visitedCurrent;
        i++;
    }


}

int findBigger(float qualityEdges[][TAM], int visitedCurrent, int visited[], int tamanhoVisited){
    int j,i;
    float bigger = -100000000000000000000;
    int biggerIndex = 3;

    for (j=0;j<TAM;j++){
        for (i=0; i<tamanhoVisited; i++){
            if (0 != j){
                if (qualityEdges[visitedCurrent][j] > bigger){
                    bigger = qualityEdges[visitedCurrent][j];
                    biggerIndex = j;
                }
            }
        }
    }
    return biggerIndex;

}

void outputVisited(int visited[]){
    int i;
    for (i = 0; i<TAM; i++){
        if (visited[i] == 0) {
            printf("A");
        } else if (visited[i] == 1) {
            printf("B");
        } else if (visited[i] == 2) {
            printf("C");
        } else if (visited[i] == 3) {
            printf("D");
        } else if (visited[i] == 4) {
            printf("E");
        } else {
            printf("%d", visited[i]);
        }
    }
    printf("\n");
}