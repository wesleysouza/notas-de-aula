# Estruturas de Dados

## Fila (Implementação Estática)

Uma fila é uma estrutura linear na qual:
- As inserções ocorrem no final da fila;
- As exclusões ocorrem no início da fila;
- Mesma lógica da fila do RESUN.

![Lista](/comp0212-estruturas-de-dados-1/aula04/img/fila02.jpg "Pilha Estática")

**REGRA GERAL: Primeiro que entra é o primeiro a ser atendido.**

![Lista](/comp0212-estruturas-de-dados-1/aula04/img/fila01.jpg "Pilha Estática")

Implementação: Utilizaremos um array de elementos de tamanho predefinido;

### Ideia Geral

- Temos um **array** de elementos, um campo indicando a **posição do primeiro** e um indicando o **número de elementos**.
- O sucessor de cada elemento está na **próxima posição do array** (exceto o sucessor do último que estará na posição 0).

![Lista](/comp0212-estruturas-de-dados-1/aula04/img/fila03.png "Pilha Estática")

### Como inserimos o elemento 8?

-Devemos inserir no final da fila;
-Vamos inserir depois do último elemento;

![Lista](/comp0212-estruturas-de-dados-1/aula04/img/fila04.png "Pilha Estática")

### Como excluir um elemento?

- Excluimos quem ta no inicio da fila;
- Aumentamos em 1 o campo que guarda o inicio da fila;
- Diminuímos em 1 o número total de elementos;

![Lista](/comp0212-estruturas-de-dados-1/aula04/img/fila05.png "Pilha Estática")

### Modelagem

```cpp
#include <stdio.h>

#define MAX 50

struct fila{
    int a[MAX];
    int inicio;
    int fim
};

typedef struct fila Fila;
```

### Funções de gerenciamento

- Inicialização da estrutura;
- Retornar a quantidade de elementos válidos;
- Exibir os elementos da estrutura;
- Inserir elementos na estrutura (**no fim**);
- Excluir elementos da estrutura (**no inicio**);
- Reinicializar a estrutura.

#### **Inicialização da estrutura**

Para inicializar precisamos:
- Ajustar o valor do campo **nroElem** (para indicar que não existe nenhum elemento válido);
- Acertar o valor do campo **inicio** (índice do primeiro elemento válido).

```cpp
void inicializarFile(Fila *f){
    f->inicio = 0;
    f->nroElem = 0;
}
```

Antes da inicialização:

![Lista](/comp0212-estruturas-de-dados-1/aula04/img/fila06.png "Pilha Estática")

Após inicialização:

![Lista](/comp0212-estruturas-de-dados-1/aula04/img/fila07.png "Pilha Estática")

#### **Retornar a quantidade de elementos válidos**

Para retornar a quantidade basta retornar o valor do campo **nroElem**:

```cpp
int tamanhoFila(Fila *f){
    return f->nroElem;
}
```

#### **Exibir os elementos da estrutura**

Para exibir os elementos da estrutura precisaremos iterar pelos **elementos** válidos.

Observações:
- Há elementos válidos e o primeiro está na posição inicio do array;
- Após o elemento da última posição do array (posição MAX-1) está o elemento da posição 0 (trataremos o array como se fosse **circular**);

```cpp
void exibirFila(Fila *f){
    printf("Fila: ");
    int i = f->inicio;
    int temp;
    for(temp = 0; temp < f->nroElem; temp++){
        printf("%i ", f->A[i].chave);
        i = (i + i) % MAX; //Evita tentar acessar uma posição inexistente do array
    }
    printf("Fila: ");
}
```

Exemplo:

![Lista](/comp0212-estruturas-de-dados-1/aula04/img/fila07.png "Pilha Estática")

Imprime: 5 7 2 e 8.

#### **Inserir elementos na estrutura**

Requisito: o usuário passa como parâmetro um registro a ser inserido no dinal da fila:
- Se a fila não estiver **cheia**, precisamos:
    - Identificar a **posição** no array no qual o registro será inserido e inseri-lo lá;
    - Alterar o valor no campo **nroElem**:
        - nroElem++;

Exemplo:

![Lista](/comp0212-estruturas-de-dados-1/aula04/img/fila09.png "Pilha Estática")

Cálculando posição:

Posição = 2 + 3 % 5 (tamanho da fila) = 0

![Lista](/comp0212-estruturas-de-dados-1/aula04/img/fila10.png "Pilha Estática")

Inserção:

![Lista](/comp0212-estruturas-de-dados-1/aula04/img/fila11.png "Pilha Estática")

Implementação:

```cpp
int inerirElementoFila(Fila* f, int dado){
    if(f->nroElem >= MAX){
        return 0;
    }
    int posicao = (f->inicio + f->nroElem) % MAX;
    f->a[posicao] = dado;
    f->nroElem++;
    return 1;
}
```

#### **Excluir elementos da estrutura**

A exclusão do elemento é no início da fila. Se a fila **não estiver vazia**:
- Copiamos esse elemento para um local indicado pelo usuário;
    - Acertamos o valor do campo **nroElem**;
    - Acertar o valor do campo **inicio**;

```cpp
int excluirElementoFila(Fila* f){
    if(f->nroElem == 0){
        return 0;
    }
    int dado = f->a[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->nroElem--;
    return 1;
}
```

#### **Reinicializar a estrutura**

Para reinicializar esta estrutura basta chamarmos a **função de inicialização**. 

```cpp
void reinicializarFila(Fila* f){
    inicializarFila(f);
}
```