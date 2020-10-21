void alocaGrafo(tipoGrafo *meuGrafo, int V, int A){
    int i;
 
    meuGrafo->a = A;
    meuGrafo->v = V;
    meuGrafo->mat = calloc(V, sizeof(int));
    for (i=0; i<meuGrafo->v; i++){
        meuGrafo->mat[i] = calloc(V, sizeof(int));
    
}
 
void aresta(tipoGrafo *meuGrafo, int X, int Y){
    meuGrafo->mat[X][Y] = 1;
    meuGrafo->mat[Y][X] = 1;
}
