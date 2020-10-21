void bfs(Grafo *G, int Vinicial){
  Fila *F;
  inicializaFila(&F);
  insereF(&F, Vinicial);
  
  G->v[Vinicial].cor = CINZA;
  
  while (filaVazia(&F) == 0){
    int remove = retiraF(&F);
    Vertice *buscaV = G->prim;
    
    while (buscaV != NULL && buscaV->num == remove){
      buscaV = buscaV->prox;
    
    
    Aresta *buscaA = buscaV->prim;
    
    while (buscaA != NULL){
      int visitei = buscaA->v;
      if (visitei == BRANCO){
        buscaA->cor = BRANCO;
        insereF(&G, visitei);
      buscaA = buscaA->prox;
      
    
  
