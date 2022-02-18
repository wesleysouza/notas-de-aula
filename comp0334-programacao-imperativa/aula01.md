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

## 1.3 Scanf

A função **scanf()** serve para a leitura de dados do teclado e salvar em variáveis. A forma geral da utilização dessa função é exibida abaixo:

```cpp
#include <stdio.h> //biblioteca que contém a função scanf

int main(){
	scanf("Tipos de entrada", variáveis);
}
```

Segue abaixo um exemplo de leitura de entradas para diferentes variáveis:

```cpp
#include <stdio.h>

int main(){
	char letra;
	int nro;
	float n;
	double d;
	scanf("%c", &letra);
	scanf("%d", &nro);
	scanf("%f", &n);
	scanf("%c", &d);
	return 0;
}
```

Obs.: Antes de ler qualquer variável é necessário utilizar o operador **&**.

Agora observe abaixo o exemplo de um programa que utiliza a combinação das funções _scanf()_ e _printf()_:

```cpp
#include <stdio.h>

int main(){

	int nro;
	printf("Digite um numero: ");
	scanf("%d", &nro);
	printf("Numero digitado: %d \n ", nro);
	return 0;
}
```

É possível com a função _scanf()_ ler dois números ao mesmo tempo:

```cpp
#include <stdio.h>

int main(){

	int nro;
	float f;
	printf("Digite dois numeros: ");
	scanf("%d%f", &nro, &f);
	printf("Numeros : %d e %f \n ", nro, f);
	return 0;
}
```

## 1.4 Operador de Atribuição

A utilização do operador de atribuição sempre terá a seguinte forma:

```cpp
//variável = expressão;
```

Exemplo:

```cpp
#include <stdio.h>

int main(){

	int x = 5;
	//O valor do lado direito recebe o valor do lado esquerdo.
	int y;
	y = x;
	y = x + 10; // combinação de variáveis com valores numéricos.

	//5 = x ERRADO!

	//É possível também fazer atribuições curtas:

	x = y = z = 10;

	return 0;
}
```

Importante: A atribuição funciona bem quanto estamos trabalhando com valores do mesmo tipo. Quando estamos trabalhando com tipos diferentes devemos tomar cuidado!

```cpp
#include <stdio.h>

int main(){

	int x = 97;
	char cha1 = x;

	//Um número real pode receber um número inteiro, já no oposto perdemos a parte decimal.

	int x = 80;
	float f1, f2 = 5.25;
	f1 = x;
	printf("f1 = %f \n" , f1);
	x = f2;
	printf("x = %d \n" , x);

	return 0;
}
```

## 1.5 Constantes

É uma variável que o valor jamais será modificado durante a execução do programa.

Primeira forma de declarar uma constante:

```cpp
#include <stdio.h>

int main(){

	//Declarando a nossa primeira constante.
	const int numero = 10;

	numero = 15; // ERRO, não é permitido alterar o valor da constante!
}
```

Segunda maneira:

```cpp
#include <stdio.h>

#define PI 3.1415

int main(){

}
```

A diferença entre as duas é que no caso da declaração com o **const** o compilador vai criar uma variável que não pode ser modificada. Já utilizando o **#define** o compilador apenas vai substituir o identificador da constante pelo valor no momento da compilação.


## 1.6 Operadores Aritiméticos

Na linguagem C podemos utilizar os seguintes operadores aritméticos:
- soma: +
- subtração: -
- multiplicação: *
- divisão: /
- resto da divisão: %

Exemplo:

```cpp
#include <stdio.h>

int main(){
	int a = 10;
	int b = 5;
	//Multiplicação e soma.
	int c = 10 * 5 + 2;
}
```

Obs.: Tome cuidado com os tipos!

Outra coisa que temos que tomar cuidado é com a precedência. Veja o exemplo abaixo:

```cpp
#include <stdio.h>

int main(){
	float f1, f2 = 5.25;
	f1 = f2 + 10 / 2.0;
	printf("f1 = %f \n", f1);
	f1 = (f2 + 10) / 2.0;
	printf("f1 = %f \n", f1);
	return 0;
}
```

## 1.7 Operadores Relacionais

Esse operadores permitem a comparação de valores dentro dos programas. Forma geral:

```cpp
valor1 "operador_relacional" valor2

//Resultado da comparação
0: a comparação é falsa
1: a comparação é verdadeira
```

Os operadores relacionais que podemos utilizar da linguagem C são:
- **>** "Maior do que";
- **>=** "Maior ou igual";
- **<** "Menor do que";
- **<=** "Menor ou igual";
- **==** "Igual a"; 
- **!=** "Diferente de";

Lembre-se: O operador **=** é operador de atribuição!

Exemplo:

```cpp
#include <stdio.h>

int main(){
	int x = 5, y = 3;
	printf("Resultado %d\n", x > 4);
	printf("Resultado %d\n", x >= y + 2);
	printf("Resultado %d\n", x == 4);
	printf("Resultado %d\n", x - 2 != y);
	printf("Resultado %d\n", x = 4); //ERRO, = é operador de atribuição.
	return 0;
}
```

## 1.8 Operadores Lógicos

Esses opradores servem para comparar duas expressões relacionais dentro do programa:

```cpp
//Operadores lógicos
&& Operador "E"
|| Operador "OU"

//Forma geral
expressão "operador lógico" expressão

//Resultado da operação
0: a operação é falsa
1: a operação é verdadeira
```

Exemplo:

```cpp
#include <stdio.h>

int main(){
	/*
	Operador E (&&): o resultado é apenas 1 (verdadeiro) se ambas as expressões também forem 1, do contrário, o resultado é 0 (falso). 
	*/

	int r, x = 5, y = 3;
	r = (x > 2) && (y < x);
	printf("Resultado = %d\n", r);

	r = (x % 2 == 0) && (x > 0);
	printf("Resultado = %d\n", r);

	return 0; 
}
```

## 1.9 Comando if

O comando if permite executar ou não um conjunto de comandos de acordo com uma condição.

Forma geral:

```cpp
if(condição){
	conjunto de comandos
}
```

# Referências
- [Aula 03 Printf](https://youtu.be/07YPObbEpU8)



