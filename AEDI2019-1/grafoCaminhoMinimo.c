void relaxa (Grafo *G, int X, int Y, float c){
    if (G->v[Y].custo > G->v[X].custo + c){
        G->v[Y].custo = G->v[X].custo + c;
        G->v[Y].Vant = X;
    
}

void grafo_BellmanFord (Grafo *G, int S){
    int i, k;
    
    G->v[S].custo = 0;

    for (i=1; i<G->tam; ++i){
        for (k=0; k<G->tam; ++k){
            Aresta *A = G->v[i].lista->primeiro;
            while (A != NULL){
                int j = A->v;
                relaxa(G, i, j, A->custo);
                A = A->prox;
            
        
    
}
