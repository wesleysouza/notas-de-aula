# Aula 07

## Árvores AVL

A gente viu que a ordem de inserção determina o formato de uma árvore de Busca Binária:

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl1.png "")

Essa é a diferença entre a estrutura de comportar como numa busca binária ou sequencial.

**O balanceamento é importante. Contudo, um balanceamento perfeito é algo computacionalmente caro!**

O que podemos fazer?
- Nada... você está com sorte?
- Aplicamos um bom balanceamento:
    - Permite um pouco de desbalanceamento;
    - Algoritmo de **A**delson-**V**elskii e **L**andis (as Árvores AVL).

AVL é uma **árvore de busca binária** balanceada com relação à altura de suas subárvores.

Uma árvore AVL verifica a altura das subárvores da esquerda e direta, garantindo que essa diferença não seja menor que +1 ou -1:
- Essa diferença é seu **Fator de Balanceamento**:
    - $ f_b = h_esq - h_dir $

O fator de balanceamento é calculado a cada nó:
- E, para daca nó, a diferença de altura entre a subárvore da esquerda e direita não pode passar de +1 ou -1.
- Lembrando que a altura de uma árvore vazia é -1, o fator de balanceamento, ou alternativamente a altura do nó, é armazenada no próprio nó.

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl2.png "")


![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl3.png "")

**Note que, nesse caso, a inserção de um único elemento foi o suficiente para fazer com que uma árvore deixasse de ser AVL.**

Uma inserção pode fazer com que o fator de balanceamento de um nó vire +2 ou -2:

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl4.png "")

Contudo, somente nós no caminho o ponto de inserção até a raiz **podem ter mudado** sua altura. 

Então após a inserção, voltamos até a raiz, nó por nó, atualizando as alturas:
- Se um novo fator de balanceamento para um determinado nó for 2 ou -2, ajustamos a árvore rotacionando em torno desse nó.

### Rotações

- Objetivo: corrigir o **fator de balancemento (fb)** de cada nó:
    - Operação b´sica para balancear a árvore AVL.
- Ao todo, existem dois tipos de rotação:
    - Rotação simples;
    - Rotação dupla.
- As rotações diferem entre sí pelo sentido da inclinação entre o nó pai e filho:
    - **Rotação simples**: O nó desbalanceado (pai), seu filho e o seu neto estão todos no mesmo sentido de inclinação;
    - **Rotação dupla**: O nó desbalanceado (pai) e seu filho estão inclinados no sentido inverso ao neto:
         - **Equivale a duas rotações simples**.

Resumo das possíveis rotações:
- Rotação simples a direita ou Rotação LL;
- Rotação simples a esquerda ou Rotação RR;
- Rotação dupla a direita ou Rotação LR;
- Rotação dupla a esquerda ou Rotação RL.

### Rotação LL

- Rotação LL ou rotação simples à direita
    - Um novo nó é inserido na sub-árvore da esquerda do filho esquerdo de A:
        - A é o nó desbalanceado
        - Dois movimentos para a esquerda: **LEFT** **LEFT**
    - É necessário fazer uma rotação à direita, de modo que o nó intermediário **B** ocupe o lugar de **A**, e **A** se torne a sub-árvore direita de **B**.


![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl5.png "")

Passo a passo:

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl6.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl7.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl8.png "")

### Rotação RR

- Rotação RR ou rotação simples à esquerda
    - Um novo nó é inserido na **sub-árvore da direita do filho direito** de **A**:
        - A é o nó desbalanceado;
        - Dois movimentos para a direita: **RIGHT RIGHT**;
    - É necessário fazer uma rotação à esquerda, de modo que o nó intermediário **B** ocupe o lugar de **A**, e **A** se torne a sub-árvore esquerda de **B**.

Passo a passo:

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl9.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl10.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl11.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl12.png "")

### Rotação LR

- Rotação LR ou rotação dupla à direita
    - Um novo nó é inserido na sub-árvore da direita do filho esquerdo de A:
        - A é o nó desbalanceado;
        - Um movimento para a esquerda e outro para a direita: **LEFT RIGHT**
- É necessário fazer uma rotação dupla, de modo que o nó **C** se torne o pai dos nós **A** (filho da direita) e **B** (filho da esquerda):
    - Rotação RR em **B**;
    - Rotação LL em **A**.

Primeira rotação:

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl13.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl14.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl15.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl16.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl17.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl18.png "")

### Rotação RL

- Rotação RL ou rotação dupla à esquerda
     - um novo nó é inserido na sub-árvore da esquerda do filho direito de A
        - A é o nó desbalanceado;
        - Um movimento para a direita e outro para a esquerda: **RIGHT LEFT**.
    - É necessário fazer uma rotação dupla, de modo que o nó C se torne o pai dos nós A (filho da esquerda) e B (filho da direita):
        - Rotação LL em B;
        - Rotação RR em A.

Passo a passo:

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl19.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl20.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl21.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl22.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl23.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl24.png "")

### Quando usar cada rotação?

Sinais iguais: rotação simples:
- Sinal positivo: rotação à direita (LL);
- Sinal negativo: rotação à esquerda (RR).

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl25.png "")

Sinais diferentes: rotação dupla:
- **A** positivo: rotação dupla a direita (LR).
- **A** negativo: rotação dupla a esquerda (RL).

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl25.png "")

### Inserção na árvore AVL

Para inserir um valor V na árvore
 Se a raiz é igual a NULL, insira o nó
 Se V é menor do que a raiz: vá para a subárvore esquerda
 Se V é maior do que a raiz: vá para a sub-árvore
direita
 Aplique o método recursivamente
 Dessa forma, percorremos um conjunto de
nós da árvore até chegar ao nó folha que irá
se tornar o pai do novo nó



Uma vez inserido o novo nó
 Devemos voltar pelo caminho percorrido e
calcular o fator de balanceamento de cada um
dos nós visitados
 Aplicar a rotação necessária para restabelecer o
balanceamento da árvore se o fator de
balanceamento for +2 ou -2

Passo a passo:

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl26.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl27.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl28.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl29.png "")


![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl30.png "")

### Remoção na Árvore AVL

- Como na inserção, temos que percorremos
um conjunto de nós da árvore até chegar ao
nó que será removido:
    - Existem 3 tipos de remoção
        - Nó folha (sem filhos);
        - Nó com 1 filho;
        - Nó com 2 filhos;


- Uma vez removido o nó
    - Devemos voltar pelo caminho percorrido e calcular o fator de balanceamento de cada um dos nós visitados;
    - Aplicar a rotação necessária para restabelecer o balanceamento da árvore se o fator de balanceamento for **+2** ou **-2**.
        - **Remover** um nó da sub-árvore direita equivale a **inserir** um nó na sub-árvore **esquerda**.

**Remoção**:
- Trabalha com 2 funções:
    - Busca pelo nó;
    - Remoção do nó com 2 filhos.

Passo a passo:

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl31.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula07/img/avl32.png "")

**"Se desse pra aprender olhando cachorro era açougueiro"**

## Trabalho

1 - Implemente uma árvore AVL com as funções básicas de adição e remoção de nós com o balanceamento ativado.

## Referências

[Estrutura de Dados - Aula 21 - Árvores AVL](https://youtu.be/YkF76cOgtMQ)

[Aula 78 – Árvores Balanceadas](https://youtu.be/Au-6c55J90c)

[Aula 79: Árvore AVL: Defin](https://youtu.be/4eO3UbTiRyo)

[Aula 80: Árvore AVL: Implementação](https://youtu.be/I5cl39jdnow)

[Aula 81: Árvore AVL: Tipos de Rotação](https://youtu.be/1HkWqH7L2rU)

[Aula 82: Árvore AVL: Implementando as Rotações](https://youtu.be/6OJ8stXwdq0)

[Aula 83: Árvore AVL: Inserção](https://youtu.be/lQsVUxa3Auk)

[Aula 84: Árvore AVL: Remoção](https://youtu.be/F7_Daymw-WM)
