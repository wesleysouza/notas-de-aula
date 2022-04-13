# Aula 06

## Árvores Bínárias

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

## Árvores Binárias de Busca

A nossa árvore é mais que uma árvore binária:

![Lista](/comp0212-estruturas-de-dados-1/aula06/img/busca-1.png "")

Ela é uma **árvore binária de pesquisa/busca**.

**Definição:**

Uma **árvore binária de pesquisa** é uma árvore binária em que, cada nó, todos os registros com chaves **menores** que a deste nó estão na subárvore da **esquerda**, enquanto que os registros com chaves **maiores** estão na subárvore da direita.

ESSA REGRA POSSIBILITA UMA RECUPERAÇÃO MAIS EFICIENTE DOS DADOS!

### Funções ABP

- Inicialização da árvore;
- Inserção de um elemento;
- Busca de um elemento;
- Contagem do número de elementos;
- Leitura da árvore;
- Remoção de um elemento;

### Modelagem

```cpp
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

struct no{
    int dado;
    struct no *esq;
    struct no *dir;
} 

typedef struct no ARVORE;
```

### Implemetações das funções

**ABP - Inicialização da árvore**

Para representar nossa árvore, precisaremos tão somente do endereço do nó raiz. E para inicializarmos a árvore basta tornarmos esse endereço **NULL**:

```cpp
ARVORE* inicializa(){
	return NULL;
}
```

**ABP - Inserção de um elemento**

Decisão de projeto: 
- Não permitir duplicação de chaves.

Obs.: Em caso de permitir essa duplicação, é necessário definir uma política. Por exemplo, chaves <= à um determinado nó são alocados na subárvore a esquerda deste.

Como inserir um elemento na árvore?

Inserindo 10:

![Lista](/comp0212-estruturas-de-dados-1/aula06/img/busca-1.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula06/img/busca-2.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula06/img/busca-3.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula06/img/busca-4.png "")

![Lista](/comp0212-estruturas-de-dados-1/aula06/img/busca-5.png "")

Disposição final, com o 10 sendo adicionado como filho do lado esquerdo do nó 12.

![Lista](/comp0212-estruturas-de-dados-1/aula06/img/busca-6.png "")


Algoritmo:
- **Se** a raiz for **NULL**, inderimos lá.
- **Senão**:
    - **Se** a chave do elemento a ser inserido for menor que a raiz:
        - Insere na subárvore da esquerda;
    - **Senão**:
        - Insere na subárvore da direita.

Obs.: Essa implementação é recursiva:

```cpp
ARVORE* addNo(ARVORE *a, int elem){
	if(a == NULL){
		a = malloc(sizeof(ARVORE));
		a->dado = elem;
		a->dir = NULL;
		a->esq = NULL;
	}else{
		if(a->dado > elem){
			a->esq = addNo(a->esq, elem);
		}else{
			a->dir = addNo(a->dir, elem);
		}
	}
}
```

Chamando na função main:

```cpp
ARVORE *arvore = inicializa();
	arvore = addNo(arvore, 5);
```

Adicionando, por exemplo, 23, 12, 25, 8 e 15, nessa ordem temos:

![Lista](/comp0212-estruturas-de-dados-1/aula06/img/busca-7.png "")

**OBS.: A ORDEM DE INSERÇÃO DETERMINA A FORMA DA ÁRVORE**

Inserindo 25, 23, 15, 12 e 8, nessa ordem, geram a árvore abaixo:

![Lista](/comp0212-estruturas-de-dados-1/aula06/img/busca-8.png "")

Qual é essa estrutura?

**A ordem é essencial!**

**ABP - Busca**

Buscando o 12:

Em uma árvore de Busca Binária podemos agir como na busca binária em um vetor:
- Primeiro olhamos para a raiz:
    - **Se** for 12, achamos
    - **Se** for > 12 olhamos na subárvore da esquerda.
    - **Senão** olhamos na da direita.

![Lista](/comp0212-estruturas-de-dados-1/aula06/img/busca-9.png "")

Sendo assim, temos a implementação da função de busca abaixo:

```cpp
int busca(ARVORE *a, int elem){
	if(a == NULL){
		return -1;
	}
	if(a->dado == elem){
		return a->dado;
	}
	if(a->dado > elem){
		return busca(a->esq, elem);
	}else{
		return busca(a->dir, elem);
	}
}
```

**ABP - Contagem de elementos**

Existem várias maneiras de se percorrer uma árvore binária, em geral envolvendo 3 elementos:

- O nó raiz;
- A subárvore a esquerda de cada nó;
- A subárvore a direita de cada nó.

Algumas possibilidades são:
- Subárvore esquerda - raiz - subárvore direita;
- Subárvore Direita - raiz - subárvore esquerda;
- Raiz - subárvore esquerda - subárvore direita.

Uma ordem bastante útil é **subárvore esquerda - raiz - subárvore direita**:
- Tambem chamada de **inorder traversal, varredura infixa**, ou **varredura central**.
- Nessa varredura, os nós são visistados na ordem crescete das chaves de busca.

Sendo assim, vamos contar os elementos:
- Se não houver raiz, n = 0;
- Conte a subárvore à esquerda;
- Some a raiz;
- Some a subárvore à direita.

![Lista](/comp0212-estruturas-de-dados-1/aula06/img/busca-9.png "")

Implementando:

```cpp
int numeroDeNos(ARVORE *a){
	if (a == NULL){
		return 0;
	}
	return (numeroDeNos(a->esq) + 1 + numeroDeNos(a->dir));
}
```

**ABP - Leitura e Impressão dos Elementos**

Percurso na árvore:
- **Pré-ordem**: raiz, subárvore esquerda, sub-árvore direita;
- **Em ordem**: subárvore esquerda, raiz, sub-árvore direita;
- **Pós-ordem**: subárvore esquerda, sub-árvore direita, raiz.

Implementando a pré ordem:

```cpp
void preOrdem(ARVORE *a) {
    if (a != NULL) {
        printf("%d \n", a->dado);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}
```

Qual é a melhor ordem?

Obs.: Note que, para qualquer procedimento, podemos usar qualquer nó da árvore como raiz:
- Podemos então contar nós ou imprimir qualquer subárvore;
- Só não podemos incluir ou excluir nós sem ter começado da raiz. Do contrário poderemos perder a ordem dos nós.

## Exercício

1 - Implemente uma função que imprime os nós da árvore empregando o percurso:
- a) em-ordem.
- b) pós-ordem.

2 - Implemente a função de remoção da ABP.

## Referências

[Estrutura de Dados - Aula 15 - Árvores - Conceitos básicos](https://youtu.be/eiMMtyRBYCE)

[Estrutura de Dados - Aula 16 - Árvores binárias de pesquisa - Parte 1](https://youtu.be/7IKXYhqipK8)

[Estrutura de Dados - Aula 17 - Árvores binárias de pesquisa - Parte 2](https://youtu.be/O4AqgoO42pc)

[Estrutura de Dados - Aula 18 - Árvores binárias de pesquisa - Parte 3](https://youtu.be/3koM42vL6js)