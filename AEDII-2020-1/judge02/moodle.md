# Atividade Moodle - Semana 01

O algoritmo de MergeSort, originalmente, divide o tamanho do problema em duas partes de tamanho aproximadamente iguais em cada etapa recursiva de execução. Como seria um MergeSort que dividisse o tamanho do problema em 3 partes?

Demonstre o funcionamento dessa proposta utilizando-se de um pseudo-código para explique o funcionamento. Não se esqueça de explicar e demonstrar também o funcionamento de um novo algoritmo Merge, bem como o esquema para divisão do problema.

Se necessário inclua um arquivo anexo na resposta.
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

A ideia é ir dividindo o comprimento do arranj em três partes até caso mínimo, ordena-lo e e mesclar com o outro recursivamente, subindo a árvore.
