void dfs(Grafo *G, int V){
  int cor[G->tam], i;

  for (i=0; i<G->tam; i++){
    cor[i]= BRANCO;
  

  for (i=V; i<G->tam; i++){
    if (cor[i] == BRANCO){
      visita(G,i,cor);
    
  
}

void visita(Grafo *G, int i, int *cor){
  cor[i] = AMARELO;
  Aresta *busca = G->prim;
  while (busca && busca->v == i){
    busca = busca->prox;
  
  Aresta *aux = busca->primeiro;

  while (aux != NULL){
    printf("%d", aux->v);
    if (cor[aux->v] == BRANCO){
      visita(G,aux->v, cor);
      aux = aux->prox;
    
  
  printf("%d", cor[i]);
  cor[i] = VERMELHO;
}
