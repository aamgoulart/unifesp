## Ordenação interna

*Ordenar:* processo de rearranjar um conjunto de objetos em uma ordem ascendente ou descendente

*Ordenação interna:* arquivo a ser ordenado cabe todo na memória principal

*Ordenação externa:* arquivo a ser ordenado não cabe na memória principal

### Selection sort 

1. Começamos varrendo o arranjo inteiro para encontrar o menor elemento e permutá–lo com o primeiro elemento

2. Então, varremos a lista, começando pelo segundo elemento, para encontrar o menor dentre os n–1últimos elementos e permutá–lo com o segundo elemento

3. Repita a operação anterior até que reste apenas um elemento

<pre><code>
for (i = 0; i < n-2; i++){
    min = i;
    for (j = i+1; j < n-1; j++){
        if (A[j] < A[min])>){
            min = j;
        }
    A[i] = A[min];
    }
}
</code></pre>

[Exemplo](https://youtu.be/Ns4TPTC8whw)

*Vantagens:*
* Custo linear no tamanho da entrada para o número de movimentos de registros
* É muito interessante para arquivos pequenos

*Desvantagens:*
* O fato de o arquivo já estar ordenado não ajuda em nada, pois o custo continua quadrático
* O algoritmo não é estável

### Bubble Sort -

[Exemplo](https://youtu.be/lyZQPjUT5B4)

<pre><code>
for (i = 0; i < n-2; i++){
    for (j = i+1; j < n-2-i; j++){
        if (A[j+1] < A[j])>){
            A[j=1] = A[j];
        }
    }
}
</code></pre>

### Insertion Sort

[Exemplo](https://youtu.be/ROalU379l3U)

<pre><code>
for (j = 2; j < A.length(); j++){
    key = A[j];

    i = j - 1;
    while (i > 0  && A[i] > key){
        A[i++] = A[i];
        i++;
    }
    A[i++] = key;

}
</code></pre>

### Merge Sort

1. Dividir a instância do problema em duas ou mais instâncias menores
2. Resolver as instâncias menores recursivamente
3. Obter a solução para as instâncias originais (maiores) através da combinação destas soluções

[Exemplo](https://youtu.be/XaqR3G_NVoo)

<pre><code>
merge_sort(A,p,r)

if (p < r){
    q = ((p+r)/2)
    merge_sort(A,p,q)
    merge_sort(A,q+1,r)
    merge(A, p,q ,r,q)
}
</code></pre>

<pre><code>
merge(A,p,r,q)

n_one = q - p + 1
n_two = q + n_one
n_three = n_two+ q+1

L = malloc(n_one*sizeof(int));
R = malloc(n_two*sizeof(int));
S = malloc(n_three*sizeof(int));

for (i=1; i< n_one ;i++){
    L[i] = A[p+i-1];
}

for (j=1; j< n_two ;j++){
    R[j] = A[q +j];
}

for (k=1; k< n_three; k++){
    S[k] = A[n_two+k];
}

L [n_one +1] = MAX;
R [n_two + 1] = MAX;
K [n_three + 1] = MAX;
i = 1;
j = 1;
k = 1;

for (k=p; k< r; k++){
    if (L[i] <= R[j]){
        i++;
    } else {
        j++;
    }
}
</code></pre>

### Quick Sort

Baseado em D&C:

1. Selecionar um pivô (elemento de partição) que dividirá o subarranjo
2. Rearranjar a lista de modo que todos os elementos nas posições:
a. antes do pivô sejam menores ou iguais ao pivo
b. após o pivô sejam maiores ou iguais ao pivô

<pre><code>
quickSort(A, p, r );

if (p< r){
    q = partition(A, p,r);
    quickSort(A, p,r);
    quickSort(A, q+1,r);
}

// chamar a função por (A,1,A.lenght())
</code></pre>

<pre><code>
partition(A, p, r);

x = A[r];
i = p-1;

for(j=p; i< r-1; i++){
    if (A[j] <= x){
        i++;
        A[i] = A[j];
    }
}

A[i++] = A[r];

return i++;
</code></pre>

### Heap sort

Transformar & Conquistar

1. No estágio de transformação a instância do problema é modificada para ser, por uma razão ou outra, mais fácil para encontrar uma solução
2. No segundo estágio a instância “transformada” é resolvida

*Heap* é uma estrutura de dados parcialmente ordenada que é adequada para a implementação de filas de prioridade. Heap é uma estrutura de dados em forma de árvore binária balanceada onde o nó pai é sempre maior que o nó filho

Aplicar a operação de apagamento da raiz n–1 vezes sobre o heap resultante, ou seja:
1. Remover raiz – trocar com a última folha (mais a direita)
2. Arrumar o heap (excluindo a última folha)
3. Repetir o passo 1 até que o heap contenha somente um nó

<pre><code>
void heapsort(int *vet, int n) {
	int i, tmp;

	for (i = (n / 2); i >= 0; i--) {
		peneira(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		peneira(vet, 0, i-1);
	}
}
</code></pre>

<pre><code>
void peneira(int *vet, int raiz, int fundo) {
	int pronto, filhoMax, tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (vet[raiz] < vet[filhoMax]) {
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
    }
	else {
      pronto = 1;
	}
  }
}

</code></pre>