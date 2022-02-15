# Introdução a Linguagem C

## 1.1 Estrutura geral de um programa na linguagem C

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Outras funções podem ser declaradas aqui

//Declaração da função principal
int main() {

	//Comando
	printf("Hello world! \n");

	//O programa aguarda um entre no teclado pra finalizar.
	system("pause");

	//Avisando para o sistema operacional que não houve erros na execução do programa.
	return 0;
}
```

## 1.2 Variáveis

Uma variável é um local reservado na memória para armazenar algum dado. Toda variável deve ter um identificador (nome) e um tipo. Esse tipo é muito importante pois, ele determina o que a variável pode armazenar. 

### 1.2.1 Tipos de Dados Básicos

Existem vários tipos de dados na linguagem C, esses tipos podem ser classificados como númerico e caracter. Os tipos númericos podem ser divididos em:
- Inteiro: armazena números inteiros (ex.: 1, 6, 6565 e etc);
- Real: armazenamento de números com casas decimais, ou seja, ponto flutuante (ex.: 6.54, 3.14 e etc);

O tipo caracter é capaz de representar um conjunto de caracteres (letras, dígitos e símbolos). 

Tipos de dados mais comuns na linguagem C:
- **int**: armazenamento de números inteiros;
- **char**: armazenamento de caracteres;
- **float**: armazenamento de números reais (ponto flutuante) com precisão simples;
- **double**: armazenamento de números reais (ponto flutuante) com precisão simples;

### 1.2.2 Declaração de variáveis

A declaração segue a seguinte forma geral:

```cpp
//Declarando variáveis
tipo nome
```

Regras:
- identificadores (nomes) (pode usar):
	- a, b, c, d, ...
	- 1, 2, 3, 4, ...
	- _ (underscore)
- Não pode usar palavras reservadas. Ex.: int, while, for e etc.
- Não pode iniciar com número.
- A linguagem C é case sensitive, ou seja, maiúsculas são diferentes de minúsculas.

Exemplo de declaração de variáveis:

```cpp
//Exemplos:
char letra = 'a';
float n = 5.25;
double d = 5.0e3;

//Também é possível
int nro1 = 10, nro2, nro3;
```

Cada uma dessas variáveis ocupam uma quantidade definida de bytes na memória e é possível saber a quantidade desses bytes utilizando a função _sizeof()_:

```cpp
int main(){
    //Declaração de variáveis
    // = é o operador de atribuição
	int numero = 1;
    char caractere = 'a';
    float psimples = 1.1;
	double pdupla = 6.5;
	printf("Tipo inteiro em bytes %d \n", sizeof(int));
    printf("Tipo caractere em bytes %d \n", sizeof(char));
    printf("Tipo float em bytes %d \n", sizeof(float));
	printf("Tipo float em bytes %d \n", sizeof(double));
	return 0;
}
```

## 1.3 Printf

O printf é uma função da bilbioteca **stdio.h** que possibilita escrever na tela do console. Veja o exemplo abaixo: 

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//Escrever na tela do console
	printf("Meu programa em C\n");

	// \n -> pular de linha
	
	//Escrevendo valores das variáveis[
	char letra = 'a';
	int nro = 10;
	float n = 5.25;

	//Use o código %c para escrever caracteres
	printf("%c \n", letra); 
	//Use o código %d para escrever números inteiros
	printf("%d \n", nro); 
	//Use o código %f para escrever os números reais
	printf("%f \n", n);

	//Nesse caso, você pode usar o %d para escrever o valor numerico do caractere dentro da tabela ASCII.
	printf("%d \n", letra);

	//Escrevendo mais de um valor em uma única linha.
	printf("Letra %c, inteiro %d \n", letra, nro);

	//Também é possível adicionar expressões matemáticas.
	printf("Letra %c, inteiro %d \n", letra, nro + 5);

	system("pause");
	return 0;
}
```

# Referências
- [Aula 03 Printf](https://youtu.be/07YPObbEpU8)



