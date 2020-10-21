# Metodos de pesquisa em arvores AVL

Árvore AVL é uma árvore binária de busca balanceada, ou seja, uma árvore balanceada (árvore completa) são as árvores que minimizam o número de comparações efetuadas no pior caso para uma busca com chaves de probabilidades de ocorrências idênticas. 

<pre><code>
typedef int TChave; 
typedefstruct {   
    TChave Chave; /* outros compomentes */ 
} TItem;  

typedefstruct SNo *TArvBin; 

typedefstruct SNo {   
    TItem Item;   
    TArvBin Esq, 
    Dir; 
} TNo;
</code></pre>

Para manter uma árvore balanceada é necessária Aplicar uma transformação na árvore, tal que:

* O percurso em-ordem na árvore transformada seja igual ao da árvore original, isto é,  a ávore transformada continua sendo uma arvore binária de pesquisa

* A árvore transformada fique balanceada

*Rotação* A transformação que mantém a árvore balanceada.

### Rotação LL

<pre><code>
pB = pA->Esq; 
pA->Esq = pB->Dir; 
pB->Dir = pA; 
pA = pB;
</code></pre>

### Rotação RR

<pre><code>
pB = pA->Dir; 
pA->Dir = pB->Esq; 
pB->Esq = pA; 
pA = pB; 
</code></pre>

### Rotação LR

<pre><code>
pB = pA->Esq; 
pC = pB->Dir; 
pB->Dir = pC->Esq;
pC->Esq = pB; 
pA->Esq = pC->Dir; 
pC->Dir = pA; 
pA = pC; 
</code></pre>

### Rotação RL

<pre><code>
pB = pA->Dir; 
pC = pB->Esq; 
pB->Esq = pC->Dir; 
pC->Dir = pB; 
pA->Dir = pC->Esq; 
pC->Esq = pA; 
pA = pC; 
</code></pre>

