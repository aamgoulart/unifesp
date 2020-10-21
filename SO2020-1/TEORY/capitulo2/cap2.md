# Processos e Threads

## Processos

 Um processo é simplesmente um programa em execução, incluindo os valores correntes do contador de programa, dos registradores e das variáveis. Ele tem um programa, entrada, saída e um estado

 Rigorosamente falando, a qualquer momento, enquanto a CPU está executando apenas um programa, durante 1 segundo ela pode trabalhar em vários programas, dando aos usuários a ilusão de paralelismo. Às vezes, as pessoas falam de pseudoparalelis-mo nesse contexto, para contrastar com o verdadeiro paralelismo de hardware dos sistemas multiprocessadores (que têm duas ou mais CPUs compartilhando a mesma memória física)

Os processos não devem ser programados com suposições sobre temporização estabelecida.

### Criação de processos

1.  Inicialização do sistema.
2.  Realização de uma chamada de sistema por um processo em execução para criação de processo.
3.  Um pedido de usuário para criar um novo processo.
4.  Início de uma tarefa em lote.

Os processos que fi cam em segundo plano para executar alguma atividade, como buscar páginas web, impressão etc., são chamados de *daemons*. 

No MINIX 3, existe apenas uma chamada de sistema para criar um novo processo: fork. Essa chamada cria um clone exato do processo que fez a chamada. Após a chamada de fork, os dois processos, o pai e o fi lho, têm a mesma imagem da memória, as mesmas strings de ambiente e os mesmos arquivos abertos. 

No MINIX 3 e no UNIX, depois que um processo é criado, tanto o pai quanto o fi lho têm seus próprios espaços de endereçamento distintos. 

### Término de processos

1.  Término normal (voluntário)
2.  Término por erro (voluntário)
3.  Erro fatal (involuntário)
4.  Eliminado por outro processo (involuntário)

### Hierarquia de processos

Em alguns sistemas, quando um processo cria outro, o pai e o fi lho continuam associados de certas maneiras. O próprio fi lho pode criar mais processos, formando uma hierarquia de processos. Ao contrário das plantas e dos animais, que usam reprodução sexual, um processo tem apenas um pai (mas zero, um, dois ou mais filhos)

### Estados de um processo

1.  Executando (realmente utilizando a CPU nesse instante)
2.  Pronto (executável; temporariamente parado para permitir que outro processo seja executado)
3.  Bloqueado (incapaz de executar até que algum evento externo aconteça)

Quando um processo é bloqueado, isso acontece porque logicamente ele não pode con-tinuar, normalmente, porque está esperando uma entrada que ainda não está disponível. 
Também é possível que um processo que esteja conceitualmente pronto e capaz de executar, seja interrompido porque o sistema operacional decidiu alocar a CPU temporariamente para outro processo

### Implementação de processos 

Para implementar o modelo de processos, o sistema operacional mantém uma tabela (um array de estruturas), chamada tabela de processos, com uma entrada por processo. (Alguns autores chamam essas entradas de bloco de controle de processo.) 

![](fig1.png)

### Threads

As vezes é desejável ter vários fluxos de controle no mesmo espaço de endereçamento, executando quase em paralelo, como se fossem processos separados (exceto quanto ao espaço de endereçamento compartilhado). Normalmente, esses fl uxos de controle são chamados de threads, embora algumas pessoas os chamem de pro-cessos leves.

 Uma thread tem um contador de programa que controla qual instrução vai ser executada. Ela possui registradores, os quais contêm suas variáveis de tra-balho correntes. Possui uma pilha, que contém o histórico de execução, com um bloco para cada função chamada, mas das quais ainda não houve retorno.

 *O que as threads acrescentam no modelo de processo é o fato de permitir que várias execuções ocorram no mesmo ambiente de processo de forma bastante independente umas da outras.*

 Assim como os processos, as threads podem estar no estado em execução, pronto ou bloqueado.

 ## Comunicação entre Processos (IPC)

Existem três problemas aqui. O primeiro foi mencionado anteriormente: como um processo pode passar informações para outro. O segundo tem a ver com como garantir que dois ou mais processos não interfi ram um com outro quando envolvidos em atividades crí-ticas (suponha dois processos tentando alocar os últimos 1 MB de memória). O terceiro diz respeito ao seqüenciamento adequado quando estão presentes dependências: se o processo Aproduz dados e o processo B os imprime, B tem de esperar até que A tenha produzido alguns dados, antes de começar a imprimir. 

### Condições de corrida

 Situaçõe em que dois ou mais processos lêem e escrevem dados compartilhados e o resultado final depende da ordem de quem precisamente executa, e quando, são chamadas de condições de corrida (race conditions). 

 ### Seções críticas

*Exclusão mútua:* uma maneira de garantirmos que, se um processo estiver utilizando um arquivo compartilhado, ou uma variável compartilhada, outros processos sejam impedidos de fazer a mesma coisa. 

Essa parte do programa, em que a memória compartilhada é acessada, é chamada de região crítica ou *seção crítica*.

Precisamos que quatro condições sejam válidas para termos uma boa solução:
1.  Dois processos não podem estar simultaneamente dentro de uma região crítica.
2.  Nenhuma suposição pode ser feita sobre as velocidades ou sobre o número de CPUs.
3.  Nenhum processo executando fora de sua região crítica pode bloquear outros pro-cessos.
4.  Nenhum processo deve ter que esperar eternamente para entrar em sua região crítica.

### Exclusão mútua com espera ativa

*Desativando interrupção:* A solução mais simples é fazer cada processo desativar todas as interrupções imediatamente após entrar em sua região crítica e reativá-las imediatamente após sair dela. Com as interrup-ções desativadas, nenhuma interrupção de relógio pode ocorrer. 
Geralmente, essa estratégia é pouco atraente, pois não é aconselhável dar a processos de usuário o poder de desativar interrupções.

*Variáveis tipo trava:* Considere o fato de ter uma única variável (trava*) compartilhada, inicialmente com o valor 0. Quando um processo quer entrar em sua região crítica, ele primeiro testa o valor da variável trava. Se a trava for 0, o processo o confi gurará como 1 e entrará na região crítica. Se a trava já for 1, o processo apenas esperará até que ele se torne 0. Assim, 0 signifi ca que nenhum processo está em sua região crítica e 1 signifi ca que algum processo está em sua região crítica.

*Alternancia estrita:* 
<pre><code>
while (TRUE) {       
    while (turn != 0) ;  /* laço */      
    critical_region();      
    turn   =   1;      
    noncritical_region();}
</code></pre>

<pre><code>
while (TRUE) {       
    while (turn != 1) ;  /* laço */      
    critical_region();      
    turn   =   0;      
    noncritical_region();}
</code></pre>

*A solução de Peterson:* Esse algoritmo consiste em duas rotinas escritas em C ANSI, o que signifi ca que devem ser fornecidos protótipos de função para todas as funções defi nidas e utilizadas. 

<pre><code>
#define FALSE 0
#define TRUE 1
#define N 2               /* número de processos */
int turn;                     /* de quem é a vez? */
int interested[N];        /* todos os valores são inicialmente 0 (FALSE) */

void enter_region(int process) /* o processo é 0 ou 1 */{      
    int other;             /* número do outro processo */      
    other = 1 – process; /* o oposto do processo */      
    interested[process] = TRUE; /* mostra que você está interessado */      
    turn   =   process;   /* confi gura fl ag */      
    while (turn == process && interested[other] == TRUE) /* laço de espera */ ;
    
}

void leave_region(int process) /* process: quem está saindo */{      
    interested[process] = FALSE; /* indica saída da região crítica */
}
</code></pre>

*A instrução TSL:*  ela lê o conteúdo da palavra de memória LOCK no registrador RX e, então, armazena um valor diferente de zero no endereço de memória LOCK. É garantido que as operações de leitura e de armazenamento da palavra são indivisíveis – nenhum outro processador pode acessar a palavra de memória até que a instrução tenha terminado. A CPU que executa a instrução TSL bloqueia o barramento de memória, proibindo outras CPUs de acessar a memória até que ela tenha terminado.

### Sleep e Wakeup

*Sleep* é uma chamada de sistema que causa o bloqueio do processo que fez a chamada; isto é, ele é suspenso até que outro processo o desperte. 
A chamada de *wakeup* tem um parâmetro, o processo a ser despertado. Como alter-nativa, sleep e wakeup têm um parâmetro, um endereço de memória utilizado para fazer as instruções sleep corresponderem às instruções wakeup

### Mutex

Um mutex é uma variável que pode ter dois estados: livre ou ocupado. Conseqüente-mente, apenas 1 bit é exigido para representá-lo, mas, na prática, freqüentemente é usado um valor inteiro, com 0 signifi cando livre e todos os outros valores signifi cando ocupado. 

### Monitores

Um monitor é um conjunto de rotinas, variáveis e estruturas de dados, todas agrupadas em um tipo especial de módu-lo ou pacote. Os processos podem chamar as rotinas presentes em um monitor sempre que quiserem, mas não podem acessar diretamente as estruturas de dados internas do monitor a partir das rotinas declaradas fora dele. 

Os monitores têm uma propriedade importante que os torna úteis para obter exclusão mútua: a qualquer instante, apenas um processo pode estar ativo em um monitor. Os monito-res são uma construção de linguagem de programação, de modo que o compilador sabe que eles são especiais e pode manipular chamadas para as rotinas do monitor de forma diferente de outras chamadas de procedimentos.


## Escalonamento

Quando mais de um processo está no estado pronto e existe apenas uma CPU disponível, o sistema operacional deve decidir qual deles vai executar primeiro. A parte do sistema operacional que faz essa escolha é chamada de escalonador; o algoritmo que ele utiliza é chamado de algoritmo de escalonamento.

Existe uma variedade de situações nas quais o escalonamento pode ocorrer. Primeiramente, o escalonamento é absolutamente exigido em duas ocasiões:
1.  Quando um processo termina.
2.  Quando um processo é bloqueado em uma operação de E/S ou em um semáforo.
Em cada um desses casos, o processo que estava em execução se torna não apto a conti-nuar, de modo que outro processo deva ser escolhido para executar em seguida.
Existem três outras ocasiões em que o escalonamento é normalmente feito, embora, logicamente falando, não seja absolutamente necessário nesses momentos:
1.  Quando um novo processo é criado.
2.  Quando ocorre uma interrupção de E/S.
3.  Quando ocorre uma interrupção de relógio.

### Categorias de algoritmo de escalonamento
1. Lote            
2. Interativo            
3. Tempo  real

### Objetivos

*Todos os sistemas*
    Imparcialidade – dar a cada processo o mesmo tempo de uso de CPU
    Imposição da política – garantir que a política declarada é executada
    Balanceamento de carga – manter todas as partes do sistema ocupadas
*Sistemas de lote*
    Taxa de saída – maximizar o número de jobs por hora
    Tempo de retorno – minimizar o tempo entre envio e término
    Utilização da CPU – manter a CPU ocupada o máximo de tempo possível
*Sistemas interativos*
    Tempo de resposta – atender rapidamente as requisições
    Proporcionalidade —satisfazer às expectativas dos usuários
*Sistemas de tempo real*
    Cumprir os prazos fi nais – evitar a perda de dados
    Previsibilidade – evitar degradação da qualidade em sistemas multimídia

### Escalonamento em sistema de lote

Provavelmente, o mais simples de todos os algoritmos de escalonamento é o não-preemptivo *primeiro a chegar é o primeiro a ser atendido*. A maior vantagem desse algoritmo é que ele é fácil de ser entendido e igualmente fácil de programar. 

*tarefa mais curta primeiro* É interessante notar que o algoritmo da tarefa mais curta primeiro é ótimo apenas quan-do todos os jobs estão disponíveis simultaneamente

*Menor tempo de execução restante* (Shortest Remaining Time Next – SRT). Nesse algoritmo, o  escalonador  sempre  escolhe  o  processo  (ou  job)  cujo  tempo  de  execução  restante  é  o  mais curto.

O *escalonador de admissão* decide quais jobs ingressarão no sistema. Um algoritmo de controle de admissão típico poderia procurar uma mistura de jobs limitados por processamento e jobs limitados por E/S. Como alternativa, os jobs curtos poderiam ser admitidos rapidamente, enquanto os jobs mais longos teriam de esperar. O es-calonador de admissão está livre para manter alguns jobs na fi la de entrada e admitir jobs que cheguem depois, se optar por isso

### Escalonamento em sistemas interativos

Um dos algoritmos mais antigos, mais simples e mais amplamente utilizados é feito um *rodízio entre os processos* (escalonamento round-robin – RR). A cada processo é atribuído um intervalo de tempo, cha-mado de quantum, durante o qual ele pode ser executado. Se o processo estiver em execução no fi m do quantum, é feita a preempção da CPU e esta é alocada a outro processo.

A necessidade de levar em conta fatores externos conduz ao *escalonamento por prioridade*. A idéia básica é simples: cada processo recebe uma prioridade e o processo pron-to, com a prioridade mais alta, tem permissão para executar.

Como o algoritmo da *tarefa mais curta primeiro* (SJF – Shortest Job First) sempre produz o menor tempo médio de resposta para sistemas de lote, seria interessante se ele também pudesse ser usado para processos interativos

Uma estratégia completamente diferente de escalonamento é fazer *promessas realistas* aos usuários sobre o desempenho e, então, cumpri-las. Uma promessa realista e fácil de cumprir: se houver n usuários conectados enquanto você estiver trabalhando, você receberá cerca de 1/n do poder da CPU.

*Por sorteio* A idéia básica é dar aos processos “bilhetes de loteria” para os vários recursos do sis-tema, como o tempo de CPU. Quando uma decisão de escalonamento tiver de ser tomada, um “bilhete de loteria” é sorteado aleatoriamente e o processo que possui esse bilhete recebe o recurso. Quando aplicado ao escalonamento da CPU, o sistema pode realizar sorteios 50 vezes por segundo, com cada vencedor recebendo como prêmio 20 ms do tempo da CPU.

### Escalonamento de threads

O algoritmo de escalonamento usado pode ser qualquer um dos descritos anteriormen-te. Na prática, o escalonamento round-robin e o escalonamento por prioridade são os mais comuns. A única restrição é a ausência de um relógio para interromper uma thread que preci-sa ser executado por muito tempo.

