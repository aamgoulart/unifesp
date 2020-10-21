# Busca em Memoria Principal

Estudo de como recuperar informação a partir de uma grande massa de informação previamente armazenada

1. Inicializar a estrutura de dados
2. Pesquisar um ou mais registros com determinada chave
3. Inserir um novo registro
4. Retirar um registro específico
5. Ordenar um arquivo para obter todos os registros em ordem de acordo com a chave
6. Ajuntar dois arquivos para formar um arquivo maior

*Dicionario*: Nome comumente utilizado para descrever uma estrutura de dados para pesquisa

## Pesquisa sequncial

<pre><code>
SequentialSearch(V, value)
for i ← 1 to lenght[V]
    if (v[i]==value)
     return i
     
    return -1
</code></pre>

## Busca Binária

<pre><code>
binarySearch(V, value){
    ini = 1;
    end = V.lenght();

    while(ini < end){
        mid = (ini + end) / 2;
        if ( V[mid] == value){
            return mid;
        }

        if (V[mid] < value){
            ini = mid + 1;
        } else {
            end = mid - 1;
        }
    }
}
</code></pre>

<pre><code>
binarySearchRecursive(V, value, ini,end){
    if (ini > end) return -1;
    mid = (ini+ end)/2;
    if(V[mid]== value){
        return mid;
    }

    if (V[mid] < value){
        return binarySearchRecursive(V,value, mid+1,end);
    } else {
        reuturn binarySearchRecursive(V, value,ini, mid-1,end);
    }
}
</code></pre>

## Arvore de pesquisa

*representação hierárquica:* o topo se constitui por um nó raiz, que liga zero ou mais subárvores;
nós que não tem filhos são chamados de folhas;
binárias só podem ter no máximo 2 filhinhos;
*SAD:* subárvore da direita;
*SAE:* subárvore da esquerda;
*Vértices:* Nó da árvore; objeto que pode ter informações associadas 
 Aresta: conexão entre dois vértices
*Altura de um nó :* Quantidade de nós no caminho mais longo a partir deste nó até algum de seus nós folhas 
*Altura da árvore :* Altura do nó raiz

<pre><code>
Vertice* insereFrequencia (Vertice*meuNo, char c, int f){

    if (meuNo == NULL){
        meuNo = malloc(sizeof(Vertice));
        meuNo->letra = c;
        meuNo->freq = f;
        meuNo->esq = meuNo->dir = NULL;
    } else if (f <= meuNo->freq){
        meuNo->esq = insereFrequencia(meuNo->esq, c, f);
    }  else {
        meuNo->dir = insereFrequencia(meuNo->dir, c, f);
    }

    return meuNo;
}
 
void  abb_remover (tipoArv *minhaArvore, char letra){
    minhaArvore->raiz = remover(minhaArvore->raiz, letra);
}
 
static Vertice* remover (Vertice *meuNo, char letra){
    if (meuNo == NULL){
        return NULL;
    } else if (meuNo->letra > letra){
        meuNo->esq = remover (meuNo->esq, letra);
    } else if (meuNo->letra < letra){
        meuNo->dir = remover (meuNo->dir, letra);
    } else if (meuNo->letra == letra) {
        if (meuNo->esq == NULL && meuNo->dir == NULL){
            free(meuNo);
            meuNo=NULL;
        } else if (meuNo->esq == NULL){
            Vertice *aux = meuNo;
            meuNo =meuNo->dir;
            free(aux);
        } else if (meuNo->dir == NULL){
            Vertice *aux = meuNo;
            meuNo = meuNo->esq;
            free(aux);
        } else {
            Vertice *aux = meuNo->esq;
            while (aux->dir != NULL){
                aux = aux->dir;
            }
            meuNo->letra = aux->letra;
            meuNo->freq = aux->freq;
            aux->letra = letra;
            meuNo->esq = remover(meuNo->esq,letra);
        }
    }
    return meuNo;
}

</code></pre>