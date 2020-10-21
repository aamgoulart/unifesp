# Representação de Dados e Códigos Digitais

Em um byte ou palavra, o bit da extrema direita é denominado *bit menos significativo* e o *bit da extrema esquerda* é chamado de bit mais significativo.

## Código de Gray e BCD

Dado um código de Gray com n dígitos, podemos derivar o código com n+1 dígitos por:
1. Criar uma cópia em ordem decrescente (invertida. da sequência de códigos com n dígitos.
2. Acrescentar um bit 0 à esquerda da sequência original.
3. Acrescentar um bit 1 à esquerda da sequência invertida.
4. Concatenar a sequência original acrescida de 0 à esquerda da sequência invertida acrescida de 1.

## Múmeros inteiros

Uma alternativa para representar números inteiros é denominada sinal-magnitude. Essa
representação consiste simplesmente em utilizar o bit mais significativo como o sinal. Assim, se este bit tiver valor 0, o número é positivo e se for 1, o valor é negativo.

## Complemento de um

Essa representação consiste em inverter todos os bits de um número positivo para gerar um negativo de mesma magnitude. Nesse caso, o bit mais significativo também será o sinal. Portanto, se o bit mais significativo tiver valor 0, o número é positivo e se for 1, o valor é negativo.

## Complemento de dois

Nessa notação, um número com o bit mais significativo igual a 1 é estritamente negativo. Se o bit tiver valor 0, então o número pode ser nulo ou positivo.

## Números reais

1. Transformar o número em binário e utilizar inicialmente a notação com vírgula e sinal de '-'
para separar parte inteira e fracionária, como fazemos normalmente para números na representação
decimal.

1.a. Converte-se primeiramente a parte inteira do número, isto é, os dígitos que aparecem
à esquerda da vírgula, utilizando o método das divisões sucessivas por dois.

1.b. Converte-se então a parte fracionária, isto é, os dígitos que aparecem depois da
vírgula pelo método das multiplicações sucessivas. (Esse método será explicado no
Exemplo 3..

2. Converter o número para notação científica na base 2. Para isso, deve-se multiplicar ou dividir
o número por potências de 2, de modo que apenas um dígito '1' fique antes da vírgula. A
quantidade de multiplicações ou divisões será o valor do expoente, sendo positivo para
multiplicações e negativo para divisões.

3. Calcula-se o expoente, normalizando o valor encontrado no passo anterior. No caso de
representações com 32 bits, deve-se somar o valor de 127d, ou seja, 01111111b. Essa
normalização equivala à seguinte transformação: E=e+127 e equivale a dizer que 'E' é um
expoente não negativo, para que o valor 'e', utilizado na representação, esteja entre -126 e 127 em
complemento de 1.

4. Calcula-se a mantissa, fazendo arredondamentos se necessário. A mantissa só é representada
pela parte que vem depois da vírgula. O primeiro dígito '1' que representa a parte inteira e que
aparece antes da vírgula fica implícito, ou seja, não é representado. O arredondamento pode ser
conseguido das seguintes maneiras:

a. Despresando-se os dígitos excedentes, fora da precisão possível. (Truncamento..

b. Arredondando o número para cima, na direção de +∞.

c. Arredondando o número para baixo, na direção de -∞.

d. Arredondando o número para o mais próximo possível do valor real.

5. Escreve-se o número dada a quantidade de dígitos para cada parte: sinal, expoente, mantissa.
No caso de números de 32 bits temos 1 bit de sinal, 8 bits de expoente e 23 bits de mantissa.
