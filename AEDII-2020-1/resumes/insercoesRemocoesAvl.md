# Inserção e remoções em AVL

## Inserção

* Inicialmmente, inserimos um novo nó na árvore AVL como em uma árvore binária de pesquisa.
* A inserção desse nó pode degenerar a árvore.
* A restauração do balanceamento é feita atráves de rotações na árvore em um nó "pivô"
* Nó "pivô" é aquele que após a inserção possui fator de balanceamento fora do intervalo

<pre><code>
void insere(Arv ** raiz, int chave)
{

    if((*raiz)==NULL)
    {
        Arv * arv=(Arv*)malloc(sizeof(Arv));
        arv->esq=NULL;
        arv->dir=NULL;
        arv->chave=chave;
        *raiz=arv;
    }
    else if(chave<(*raiz)->chave)
        insere(&((*raiz)->esq),chave);
    else if(chave>(*raiz)->chave)
        insere(&((*raiz)->dir),chave);

    (*raiz)->altura=altura(*raiz);
    balanco(raiz);
}
</code></pre>

## Remoção
* Inicialmmente, removemos um novo nó na árvore AVL como em uma árvore binária de pesquisa.
* A inserção desse nó pode degenerar a árvore.
* A restauração do balanceamento é feita atráves de rotações na árvore em um nó "pivô"
* Nó "pivô" é aquele que após a inserção possui fator de balanceamento fora do intervalo

<pre><code>
void exclusao(Arv ** raiz,int chave)
{

    if ((*raiz) == NULL) return;

    //se a chave a ser excluida for menor que a chave da raiz
    //então ele vai ser excluido na subarvore esquerda
    if (chave < (*raiz)->chave)
        exclusao(&((*raiz)->esq), chave);

    //se a chave a ser excluida for maior que a chave da raiz
    //então ele vai ser excluido na subarvore direita
    else if (chave > (*raiz)->chave)
        exclusao(&((*raiz)->dir), chave);

    // se a chave for o mesmo da raiz então será deletado
    else
    {
        // nó com um ou nenhum filho
        if ((*raiz)->esq == NULL)
        {
            Arv *temp = (*raiz)->dir;
            free(*raiz);
            *raiz=temp;
            return;
        }
        else if ((*raiz)->dir == NULL)
        {
            Arv *temp = (*raiz)->esq;
            free(*raiz);
            *raiz=temp;
            return;
        }
        // nó com dois filhos: pega o menor dos maiores
        Arv* temp = menorvalor((*raiz)->dir);
        // copia a chave do menor dos maiores para a raiz
        (*raiz)->chave = temp->chave;

        // exclui o menor dos maiores
        exclusao(&((*raiz)->dir), temp->chave);
    }
    (*raiz)->altura=altura(*raiz);
    balanco(raiz);
}
</code></pre>