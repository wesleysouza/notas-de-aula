# Estruturas de Dados

## Salvando dados mais complexos utilizando structs

Podemos utilizar o aninhamento de structs para salvar dados mais complexos em nossas estruturas:

```cpp
//Estrutura Pessoa 
struct pessoa{
    int idade;
    char nome[30];
};

typedef struct pessoa Pessoa;

//Funcao para imprimir os dados da estrutura Pessoa
imprimePessoa(Pessoa p){
    printf("Idade: %d - Nome: %s \n", p.idade, p.nome);
}

//Nova definicao de no com a estrutura pessoa no campo do dado
struct no{
    Pessoa p;
    struct no *prox;
};

typedef struct no Lista;
```

## Resolução do Exercício

1 - Implemente uma função que tenha como valor de retorno o comprimento de uma lista encadeada, isto é, que calcule o número de nós de uma lista. Esta função deve obedecer ao seguinte protótipo:

```cpp
int calcularComprimento(Lista *l){
    Lista* aux = l;
    int i = 0;
    if(l == NULL){
        return 0;
    }
    while(aux != NULL){
        i++;
        aux = aux->prox;
    }
    return i;
}
```

2 - Implemente uma função que retorno o último valor de uma lista encadeada de inteiros. Essa função deve ter o protótipo:

```cpp
Lista* retornarUltimo(Lista *l){
    Lista* aux = l;
    if(l == NULL){
        return NULL;
    }
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    return aux;
}
```

3 - Implemente uma função que receba duas listas encadeadas de valores reais e transfira para o final da primeira os elementos da segunda lista. No final, a primeira lista representará a
concatenação das duas listas e a segunda lista estará vazia. Esta função deve obedecer ao protótipo:

```cpp
Lista* concatenarListas(Lista *l, Lista* outra){
    Lista *aux = l;
    if(l == NULL){
        return outra;
    }
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = outra; // atribuicao da cabeca da outra lista.
    return l;
}
```

**PERGUNTA:** Existe algum problema no método concatenar lista? 

## Lista Circular

Na lista circular o último elemento apontará para o primeiro. 

Para implementar de forma adequada, precisamos utilizar um nó para controlar a cabela da lista, esse elemento deve ser criado junto da lista.

![Lista](/comp0212-estruturas-de-dados-1/aula03/img/lista-circular01.png "Pilha Estática")

A implementação é bem semelhante a lista normal, mas obviamente é necessário adicionar a característica adicional.

## Lista Duplamente Encadeada

Uma lista encadeada tem algumas desvantagens:
- O acesso aos elementos da lista é apenas em uma direção. Desta forma, não temos como percorrer eficientemente os elementos em ordem inversa.
- Dificulta a retirada de um elemento da lista.

Para solucionar esses problemas, podemos formar o que chamamos de listas  duplamente encadeadas. 

Cada elemento tem um ponteiro para o próximo elemento e um ponteiro para o elemento anterior. Desta forma, dado um elemento, podemos acessar ambos os elementos adjacentes: o próximo e o anterior.

![Lista](/comp0212-estruturas-de-dados-1/aula03/img/lista-dupla01.png "Pilha Estática")

Se tivermos um ponteiro para o último elemento da lista, podemos percorrer a lista em ordem inversa, bastando acessar continuamente o elemento anterior, até alcançar o primeiro elemento da lista, que não tem elemento anterior (o ponteiro do elemento anterior vale NULL).

Exemplo da modelagem:

```cpp
struct lista2 {
    int info;
    struct lista2* ant;
    struct lista2* prox;
};
typedef struct lista2 Lista2;
```

A estrutura acima representa um elemento de uma lista duplamente encadeada. Observe que a estrutura possui os dois ponteiros, para o próximo elemento e para o elemento anterior.

As funções são basicamente as mesmas funções utilizadas para uma lista simplesmente encadeada: 
- Inserção de elementos na lista;
- Retirar elemento da lista;
- Impressão da lista;
- Busca de elementos na lista;
- Verificar se a lista está vazia;

## Pilha

A pilha é uma estrutura linear na qual:
- As inserções ocorrem no topo da pilha;
- as exclusõs ocorrem no topo da pilha;
- Utiliza a mesma lógica de uma pilha de papéis.

Ex.: Pilha de papéis

Nas outras estruturas o usuário decidia o local onde seria inserido o elemento.

### Implementação Estática

Utilizaremos um **array** (estático) de elementos de tamanho predefinido;
Controlaremos a posição do elemento que está no topo da pilha.

#### Idéia de implemetação:

Podemos implementar a pilha usando um **array** e um campo extra como na figura abaixo:

![Lista](/comp0212-estruturas-de-dados-1/aula03/img/pilha01.png "Pilha Estática")

Observações:
- Tamanho de **array** pré-definido;
- Campo para indicar a posição do elemento que está no topo.

Exemplo: inserindo o elemento 8:

- Como inserimos o elemento 8?
    - Incrementamos a variável que guarda a posição do topo (**top**);
    - Adicionamos o 8 na posição armazenada na variável **top**.

Exemplo:


![Lista](/comp0212-estruturas-de-dados-1/aula03/img/pilha02.png "Pilha Estática")


- Como removemos?
    - O usuário não diz o qual posição ele quer remover pois o padrão é excluir no topo;
    - Decrementamos a variável **top**.

#### Modelagem

```cpp
#include <stdio.h>

#define MAX 50

struct pilha{
    int a[MAX];
    int topo;
};

typedef struct pilha Pilha;
```

Funções para implementar:
- Inicialização da estrutura;
- Retornar a quantidade de elementos válidos;
- Exibir os elementos da estrutura;
- Inserir elementos na estrutura (**push**);
- Excluir elementos da estrutura (**pop**);
- Reinicializar a estrutura.

#### Implementação das funções:

**Inicialização**

Para inicializar precisamos apenas setar o topo da pilha com o valor **-1**:

```cpp
void inicializarPilha(Pilha *p){
    p->topo = -1;
}
```

Exemplo:

![Lista](/comp0212-estruturas-de-dados-1/aula03/img/pilha03.png "Pilha Estática")

**Retornar o número de elementos**

Fácil: Valor do topo + 1

```cpp
int tamanhoPilha(Pilha *p){
    return p->topo + 1;
}
```

**Exibir os elementos da estrutura**

Para exibir os elementos da estrutura vamos precisar percorrer o vetor apenas considerando os **elementos válidos** e imprimir os dados.

```cpp
void exibirPilha(PILHA* p){
    printf("Dados: ");
    int i;
    for(i=p->topo; i > 0; i--){
        printf("%d ", p->a[i]);
    }
    printf("\n");
}
```

**PERGUNTA:** Considerando a pilha apresentada na figura abaixo, qual será a saída?

![Lista](/comp0212-estruturas-de-dados-1/comp0212-estruturas-de-dados-1/aula03/img/pilha01.png "Pilha Estática")

**Inserir elementos na estrutura (push)**

O usuário passa por parâmetro um dado para ser armazenado na Pilha, nesse caso um inteiro:
- O elemento só será inserido se a Pilha não estiver cheia;
- O elemento será inserido "acima" do elemento que está no topo da Pilha.

```cpp
int inserirElemento(Pilha *p, int dado){
    if(p->topo >= MAX-1){
        return 0;
    }
    p->topo = p->topo + 1;
    p->a[p->topo] = dado;
    return 1;
}
```

Antes da inserção:

![Lista](/comp0212-estruturas-de-dados-1/aula03/img/pilha04.png "Pilha Estática")

Depois da inserção:

![Lista](/comp0212-estruturas-de-dados-1/aula03/img/pilha05.png "Pilha Estática")

**Exclusão de um elemento (pop)**

O usuário solicita a exclusão do elemento to **topo da pilha**:
- Se a pilha **não estiver vazia**, além de excluir esse elemento da pilha iremos copiá-lo para um local indicado pelo usuário.

Obs.: O dado deve ser retornado para o usuário!

```cpp
int excuirElemento(Pilha *p){
    if(p->topo == -1){
        return -1;
    }
    dado = p->[p->topo];
    p->topo = p->topo-1;
    return dado;
}
```

**Reinicializar a Pilha**

Para reinicializar basta apenas atribuir -1 ao campo topo.

```cpp
void reinicializaPilha(Pilha *p){
    p->topo = -1;
}
```

## Pilha Implementação Dinâmica

Na pilha dinâmica alocamos e desalocamos memória para os elementos **sob demanda**.

Vantagem:
- não desperdiçamos memória;

**Semelhante a Lista**: Cada elemento indicará quem é o seu **sucessor** (quem está "abaixo" dele na pilha);

Controlaremos o endereço do elemento que está no topo da pilha.

**Semelhante a cabeça da lista**: Temos um campo para indicar o endereço do elemento que está no topo.

![Lista](/comp0212-estruturas-de-dados-1/aula03/img/pilha06.png "Pilha Estática")

**Exemplo de Inserção**

Inserindo o elemento 8:

![Lista](/comp0212-estruturas-de-dados-1/aula03/img/pilha07.png "Pilha Estática")

**Exemplo de Exclusão**

Excluímos o primeiro elemento e o seguinte a ele se torna a **cabeça da lista**.

### Modelagem

```cpp
#include <stdio.h>
#include <stdlib.h>

struct no{
    int dado;
    struct no* prox;
};

typedef struct no Pilha;

}
```

### Funções para implementar:
- Inicialização da estrutura;
- Retornar a quantidade de elementos válidos;
- Exibir os elementos da estrutura;
- Verificar se a **Pilha está vazia**;
- Inserir elementos na estrutura (**push**);
- Excluir elementos da estrutura (**pop**);
- Reinicializar a estrutura.

### Inicialização da estrutura

Para inicilizar uma pilha já criada pelo usuário precisamos apenas acertar o valor do campo **topo**.

Como a pilha inicia vazia podemos atribuir a esse campo o valor NULL;

```cpp
Pilha* inicializar(){
    return NULL;
}
```

### Retornar número de elementos

**Semelhante a Lista**: É necessário percorrer todos os elementos da pilha para contabilizar.

```cpp
int tamanhoDaPilha(Pilha *l){
    Pilha* aux = l;
    int i = 0;
    if(l == NULL){
        return 0;
    }
    while(aux != NULL){
        i++;
        aux = aux->prox;
    }
    return i;
}
```

### Verificar se a pilha está vazia

**Pergunta:** podemos utilizar a função tamanho pra isso? Qual o custo disso?

A forma mais fácil de fazer isso é verificar se o topo da pilha == NULL:

```cpp
int estaVazio(Pilha *p){
    if(p == NULL){
        return 1;
    }else{
        return 0;
    }
}
```

### Imprimir dados da pilha

Para exibir os elementos da estrutura precisamos percorrer os **elementos** (inciando pelo topo da pilha) e, por exemplo, **imprimir suas chaves**.


```cpp
void imprimePilha(Pilha *l){
    Pilha *aux;
    printf("DADOS DA PILHA \n");
    for(aux=l; aux != NULL; aux=aux->prox){
        printf("%d \n", aux->dado);
    }
    printf("\n");
}

```

![Lista](/comp0212-estruturas-de-dados-1/aula03/img/pilha08.png "Pilha Estática")

### Inserção de um elemento (push)

O usuário passa como parâmetro um registro a ser inserido na pilha:
- O elemento será inserido no topo da pilha, ou melhor, "acima" do elemento que está no topo da pilha.
- O novo elemento irá **apontar** para o elemento que estava no topo da pilha.

Exemplo:

![Lista](/comp0212-estruturas-de-dados-1/aula03/img/pilha09.png "Pilha Estática")

![Lista](/comp0212-estruturas-de-dados-1/aula03/img/pilha10.png "Pilha Estática")

![Lista](/comp0212-estruturas-de-dados-1/aula03/img/pilha11.png "Pilha Estática")

### Exclusão de um elemento (pop)

O usuário solicita a exclusão do elemento do **topo da pilha**:
- Se a pilha **não estiver vazia**, além de excluir esse elemento da pilha iremos copiá-lo para um local indicado pelo usuário.

### Reinicialização da pilha

Para reinicializar a pilha, precisamos excluir todos os seus elementos e colocar NULL no campo topo.

# Exercício

Implementar os métodos abaixo em uma Pilha:

- Exclusão de elemento:
    - Deve-se:
        - excluir de maneira adequada o elemento que representa o topo da pilha.
        - verificar se a pilha ta vazia;
        - retornar o dado para o usuário.
- Reinicialização da pilha:
    - Deve-se excluir todos os elementos da pilha garantindo que cada um deles libere a memória que estava ocupada.
    - Use a função free();