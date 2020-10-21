## Analise assintótica

Tempo de computação e espaço de armazenagem são recursos limitados que devem ser usados de forma otimizada!


### Função de complexidade

f(n) é denominada Função de Complexidade de Tempo, e representa a medida de custo necessária para executar um algoritmo para um problema de tamanho n

*Melhor caso:* menor tempo de execução sobre todas as entradas de tamanho n
*Pior caso:* maior tempo de execução sobre todas as entradas de tamanho n
*Caso médio (ou caso esperado):* média dos tempos de execução de todas as entradas de tamanho n

### Notação assintótica para Algoritmos●

Permite classificar classes de algoritmos conforme sua complexidade computacional:
* Θ(f(n)) -  ”Teta”
* O(f(n))  - ”Ozão
* o(f(n))  - Ozinho”
* Ω(f(n)) - ”Omega"
* ω(f(n)) - "Omegazinho"

#### f(n) = O(1)

Algoritmos de complexidade O(1) são ditos de complexidade constante

#### f(n) = O(log n)

Típico em algoritmos que transformam um problema em outros menores

#### f(n) = O(n)

Em geral, um pequeno trabalho é realizado sobre cada elemento de entrada

#### f(n) = O(n log n)

Típico em algoritmos que quebram um problema em outros menores, resolvem cada um deles independentemente e ajuntando as soluções depois

#### f(n) = O(n2)

Ocorrem quando os itens de dados são processados aos pares, muitas vezes em um laço aninhado dentro de outro

#### f(n) = O(n3)

Sempre que n dobra, o tempo de execução fica multiplicado por 8

#### f(n) = O(2n)

Comum na solução de problemas quando se usa força bruta para resolvê-los

#### (n) = O(n!)

Um algoritmo de complexidade O(n!) é dito ter complexidade exponencial, apesar de O(n!) ter comportamento muito pior do que O(2