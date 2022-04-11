# Estruturas de Dados

## Busca Sequencial e Binária

**Busca em um Array**

Suponha que temos um vetor de inteiros, como fazemos para verificar se um determinado número está lá?

Resolução: Busca!

**Busca Sequencial**: Percorrer o vetor da esquerda para a direita até encontrarmos o número procurado, então ele está no vetor.

Se chegarmos ao final do voetor e não acharmos, ele não está.

Exemplo: Buscando o número 55.

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-01.png "")

Percoremos o vetor da esquerda para a direita e retornamos o número encontrado.

Retorno: 55 no índice 4.

Obs.: Em caso do número está presente em mais de uma posição, retornamos o primeiro elemento.

E se estivessemos trabalhando com structs?

O que podemos fazer para melhorar a busca?

### Busca Sequencial em vetor ordenado

O que podemos fazer para melhorar a busca por 63?

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-01.png "")

E se ele estivesse **ordenado**?

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-02.png "")

Vantagem: Poderíamos **parar a busca** assim que encontrássemos um número maior que ele.

[Comparação de métodos de ordenação](http://thanos.icmc.usp.br:4005/)

**Busca Sequencial em arranjo ordenado:** Potencialmente executamos **menos comparações** no caso do elemento não estar no arranjo.

Estar ordenado também **torna fácil** algumas tarefas:
- Busca pelo menor elemento: v[0]
- Busca pelo maior elemento: v[tam-1]

A busca com o vetor ordenado ficam **mais rápidas**:
- Paramos a busca assim que uma das condições for satisfeita:
    - Encontramos o elemento buscado;
    - Chegamos ao final do arranjo;
    - (Diferencial!) **Encontramos um elemento maior que o buscado**

Obs.: No **pior caso**, termos que olhar o vetor inteiro quando:
- O elemento buscado for o último;
- O elemento buscado não estiver no arranjo, mas for maior que o último.

Não teria um método melhor?

## Busca Binária

O algoritmo de busca binária é mais eficiente que o de busca sequencial, mas ele só pode ser aplicado em um **vetor ordenado**.

Algoritmo:
- Verifique se o elemento buscado é o do **meio do vetor**.
- Se não for verifique se é o maior:
    - Se for, repita a busca na metade direita do arranjo;
    - Se não for, repita a busca na metade esquerda do vetor;

Exemplo: Buscando 52

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-03.png "")

### Análise

Sabemos que fazemos no **máximo n comparações** com **busca sequencial**:
- Onde **n** é o número de elementos do arranjo.

E quantas fazemos com a **busca binária**?

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-09.png "")


Iteração 3:

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-10.png "")

No final teremos apenas um elemento, que será o elemento que estamos procurando ou não:

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-11.png "")

Desse modo, temos **$i + 1$** comparações, sendo a última feita com o arranjo de tamanho 1.

A relação entre **$n$** e **$i$** é tal que, após **$i$** comparações, o arranjo terá **n/$2^i$** elementos.

Como no último nível há 1 elemento, então **$n/2^i = 1 -> n = 2^1 -> log_2(n) = i$**.

Assim temos $log_2(n) + 1$ comparações.

### Busca Sequencial X Binária

**Sequencial**:
- **Melhor caso**: O elemento é o primeiro:
    - 1 comparação (vetor ordenado ou não);
- **Pior Caso**:
    - O elemento não está no vetor;
    - O elemento é o maior de todos:
        - n comparações (arranjo ordenado).

**Binária**:
- **Melhor caso:** O elemento é o do meio:
    - 1 comparação.
- **Pior Caso**: O elemento não está no vetor:
    - $log_2(n) + 1$ comparações.

Observação:

$log_2(n) + 1$ para $n >= 3 (para 1 e 2 log_2(n) + 1 = n)$

No pior caso, a **busca binária** é pelo menos tão boa quanto a **sequencial**, mas apenas para arranjos de tamanho mínimo. Para os demaisn ela é melhor!

### Complexidade computacional

Exemplo: Lista telefônica de SP: 18 milhões de entradas.

Se cada comparação (a um elemento do vetor) gasta 10 milionésimos de segundo como ficam os piores casos?
- Busca sequencial: $10/1000000 * 18000000 = 180s = 3 minutos$.
- Busca binária: $10/1000000 * log_2 18000000 = 0.000241s = 0,24 milisegundos$.

## Busca Interpolada

Como buscamos a letra **s** no dicionário?

### Definição

- A busca interpolada é uma variante da busca binária;
- Requisitos: dados ordenados e uniformemente distribuídos;

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-12.png "")

Na busca binária a chave é comparada sempre com o elemento do **meio**.

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-13.png "")

Mas e se tivéssemos uma estimativa melhor da localização da chave(In)

Exemplo da lista telefônica.

### Implementação

- A busca interpolada procura um item particular computando uma posição de sondagem, levando em consideração não só a quantidade de itens (binária), mas também a distribuição dos itens.

- Se encontrar o item procurado então retorne o índice.

- Caso contrário divide a lista em duas partes através do método seguinte:

$meio = baixo + ((alto - baixo) / (v[alto] - v[baixo])) * (x - v[baixo])$

- v = vetor;
- baixo = indice mais baixo do vetor;
- alto = índice mais alto do vetor;
- A[n] = valor armazenado no índice **n** da lista;
- x = chave procurada;

Índices:

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-14.png "")

Busca binária X Interpolada

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-15.png "")

Custo:

- Índice de particionamento é calculado em tempo constante, de acordo com a distribuição de probabilidade.
- Utilizando uma entrada com distribuição uniforme, é obtido um tempo de execução Omega(1) com uma quantidade média de log(log(n)) comparações.
- No pior caso é obtida a complexidade O(n) quando uma distribuição uniforme não é aplicada.

## Aplicação

Em geral tem as mesmas aplicações da busca binária. No entanto, os requisitos para rodar esse tipo de busca devem ser levados em consideração.

Essa técnica é geralmente utilizada por pessoas na busca por informações com ordenação, como em agendas, dicionários e etc.

## Árvores (Conceitos Básicos)

Imagine que queremos buscar o elemento 15 no vetor abaixo, como fazer?

```cpp
int vetor[5] = {2, 8, 12, 15, 20, 23, 30};
```

Podemos aplicar uma busca sequencial.

Como o vetor ta ordenado podemos melhorar aplicando as seguintes métodos: 
- Busca binária;
- Busca interpolada;

A busca binária ela é **mais  eficiente**... mas depende de arranjos estáticos.

E se tivessemos uma lista ligada?
- Como definir o elemento do meio? 
    - Não da!


Será que não podemos ter uma estrutura dinâmica que ajude nessa tarefa?

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-16.png "")

Separando o cara do meio:

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-17.png "")

Observe o resultado:

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-18.png "")

Pegando novamente o do meio nos subconjuntos restantes:

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-19.png "")

Resultado:

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-20.png "")

Fazendo assim por diante, observe a estrutura que vamos ter:

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-21.png "")

Qual nome daremos a ela?

**Árvores**

Observação: em computação costumamos representar a árvore de forma invertida...

### Definição

Uma **árvore** é um conjunto de **nós** consistindo de um nó chamado **raiz**, abaixo do qual estão as **subárvores** que compõem essa árvore.

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-22.png "")

O número de subárvores de cada nó é chamado de **grau** desse nó. No exemplo acima, todo nó tem grau 2, exceto os da base (folhas), que tem grau 0.

Nós de grau zero são chamados de **nós externos** ou **folhas**. Os demais são chamados de **nós internos**. 

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-23.png "")

Nós abaixo de um determinado nó são seus **decendentes**:
- Descendentes do 8: 2 e 12;
- Descendentes do 15: todos os demais.

Níveis de uma árvore:
- o nível do nó raiz é 0;

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-24.png "")

**Altura (h)**: a altura de um nó é o comprimento do caminho mais longo entre ele e uma folha. Vale notar que a árvore é percorrida da raiz até as folhas.

**Balanceamento**: Nem sempre a árvore estará perfeitamente balanceada. Ainda assim, as definições de altura e nível continuam valendo.

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-25.jpg "")

**IMPORTANTE**: A alura de uma árvore é a altura do nó raiz. Da mesma forma, o **endereço** de uma árvore na memória seráo endereço do seu nó raiz.

A **profundidade** de um nó é a distância da raiz a esse nó:
- Profunidade de 15: 0; 
- Profunidade de 8: 1; 
- Profunidade de 12: 2; 

![Lista](/comp0212-estruturas-de-dados-1/aula05/img/busca-23.png "")

### Árvores Bínárias

Uma **árvore binária** é uma árvore em que abaixo de cada nó, existem **no máximo duas** subárvores.

Como representar computacionalmente uma árvore binária?

Unindo nós!

E como representamos os nós?

Com dois ponteiros: um para a subárvore da esquerda e um para a subárvore da direita. Além de um campo para a chave e dados.

```cpp
struct aux{
    int chave;
    struct aux *esq;
    struct aux *dir;
} 

typedef struct aux NO;
```

## Referências

[Programação de Computadores - Aula 23 - Busca Sequencial e Binária](https://www.youtube.com/watch?v=8weGr_G3Pqo)

[ICC II - Aula 17 - (1/3) - Busca por Interpolação - Introdução e Implementação](https://youtu.be/fYbBukE0lTk)

[Estrutura de Dados - Aula 15 - Árvores - Conceitos básicos](https://youtu.be/eiMMtyRBYCE)