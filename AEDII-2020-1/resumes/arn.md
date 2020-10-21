# Arvore Rubro Negra

Uma árvore rubro-negra é uma árvore binária de busca em quecada nó é constituído dos seguintes campos:
*cor (1 bit):* pode ser vermelho ou preto.
*key (e.g. inteiro):* indica o valor de uma chave.
*left, right:* ponteiros que apontam para a subárvoreesquerda e direita, resp.
*pai:* ponteiro que aponta para o nó pai. O campo pai do nóraiz aponta para null.


As propriedades da árvore rubro-negra são
1. Todo nó da árvore ou é vermelho ou é preto.
2. A raiz é preta.
3. Toda folha (nil) é preta.
4. Se um nó é vermelho, então ambos os filhos são pretos.
5. Para todo nó, todos os caminhos do nó até as folhasdescendentes contêm o mesmo número de nós pretos.

## Balanceamento da arvore

*Todo nó a ser inserido, por convenção, é rubro*

### Rotação direita

<pre><code>
pB = pA->Esq; 
pA->Esq = pB->Dir; 
pB->Dir = pA; 
pA = pB; 
</code></pre>

### Rotação esquerda

<pre><code>
pB = pA->Dir; 
pA->Dir = pB->Esq; 
pB->Esq = pA; 
pA = pB; 
</code></pre>

