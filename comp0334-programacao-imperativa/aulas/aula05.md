# Aula 05

## STRUCT - Parte 1

Tipos de variáveis que podemos declarar:
- Tipos básicos: 
    - char, int, float, double;

```cpp
int f;
double x;
//Tipos compostos homogêneos: array
int v[5];
char nome[50];
```

A linguagem C nos permite também criar nossos pŕoprios tipos de variáveis. Um deles é o "struct" que vamos chamar de **ESTRUTURA**.

```cpp
//Forma geral:
struct nome_struct{
	tipo1 nome1; //declarações das variáveis
	tipo1 nome1; //campos da estrutura
	...
	tipoN nomeN;
};//ponto e vírgula obrigatória!
```

Obs.: É recomendado definir a ESTRUTURA antes do main, na verdade, o objetivo é que ela tenha escopo global e seja "acessada" por todo o código.

### Declaração de variáveis X Estrutura

Vantagem da estrutura: "Empacotamento" dos dados e mais organização:

```cpp
//declarando variável
char nome[50], rua[50];
int idade, numero;

//declaração de uma variável struct
struct pessoa p; 
//empacotamento das variáveis acima...
// gerenciamento de apenas uma variável...
```

Exemplo mais geral:

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

//ESTRUTURA do exemplo 1
struct pessoa{
	char nome[50], rua[50];
	int idade, numero;
};


//ESTRUTURAS do exemplo 2
struct ponto2D{
	int x, y;
};

struct ponto3D{
	int x, y, z;
};

int main(){

	/*
	Acessando os valores dentro da ESTRUTURA
	Cada campo (variável) da struct pode ser acessada usando o operador "." (ponto)
	*/

	p.idade = 31; //comando de atribuição
	scanf("%d", &p.numero); // comando de leitura
	scanf("%d", &p.nome);
	p.numero = p.numero + p.idade - 100; //expressão

	// COM ESTRUTURA VS SEM ESTRUTURA
	
	//Guardando os dados de 4 pessoas
	
	//sem ESTRUTURA
	char nome1[50], nome2[50], nome3[50], nome4[50];
	char rua1[50], rua2[50], rua3[50], rua4[50];
	int idade1, idade2, idade3, idade4, 
	int numero1, numero2, numero3, numero4;
	
	//com ESTRUTURA
	struct pessoa p1, p2, p3, p4; //essas variáveis possuem todos os campos acima

	//É possível definir várias estruturas no programa

	//Obs.: ESTRUTURAS diferentes podem ter campos com o mesmo nome.
	struct ponto2D p2;
	struct ponto3D p3;

	p2.x = 10;
	p3.x = 12;

	printf("%d  %d \n", p2.x, p3.x);

	return 0;
}
```

## - Trabalhando com STRUCT

No exemplo abaixo será demostrado como inicializar e manipular dados de estruturas:

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ESTRUTURA do exemplo 1
struct pessoa{
	char nome[50], rua[50];
	int idade, numero;
};

//ESTRUTURAS do exemplo 2
struct ponto
{
	int x, y;
};

struct novo_ponto
{
	int x, y;
};

int main(){
	//Inicialização da ESTRUTURA
	struct pessoa p;

	//ATRIBUINDO DADOS A ESTRUTURA

	//Boa opção de atribuir valores string a estrutura
	strcpy(p.nome, "Ricardo"); //copia o nome Ricardo para a variável
	strcpy(p.rua, "Rua 1");
	p.idade = 31;
	p.numero;

	//Atribuir dados dessa forma é trabalhoso, há formas melhores...

	/*
	Opção de inicialização semelhante a arrays
	Podemos definir uma lista de valores para colocar na estrutura (como nos arrays)
	*/

	struct pessoa p2 = {"Ricardo", "Rua 1", 31, 101};

	// Obs.1: Campos não definidos são inicializados com zero ou com uma string vazia ("").
	// Obs.2: A atribuição de valores tem que seguir a mesma ordem que foram definidos na estrutura.

	struct pessoa p2 = {"Ricardo", "Rua 1", 31};

	//Atribuição entre estruturas

	struct pessoa p3 = {"Jean", "Rua 1", 31, 101};
	struct pessoa p4;

	//Copiando os dados de p3 em p4
	strcpy(p4.nome, p3.nome);
	strcpy(p4.rua, p3.rua);
	p4.idade = p3.idade;
	p4.numero = p3.numero;

	//Estruturas que são do mesmo tipo suportam o tipo de atribuição abaixo:

	struct pessoa p5 = {"Jean", "Rua 1", 31, 101};
	struct pessoa p6;

	p6 = p5;

	// IMPORTANTE: Ser do mesmo tipo é derivar da mesma estrutura, e não possuir os mesmos campos, observe as funções ponto e novo_ponto, elas possuem os mesmos campos, mas são tipos diferentes!

	struct ponto x1, x2 = {1, 2};
	struct novo_ponto x1, x2 = {1, 2};

	x1 = x2; //CORRETO, MESMA ESTRUTURA = MESMO TIPO
	//x1 = x3 //ERRADO, ESTRUTURAS DIFERENTES (mesmo possuindo os mesmos campos), TIPOS DIFERENTES
}
```

## Arrays de Structs

A STRUCT é um tipo de dado, e portanto a linguagem C suporta a declaração de um array de estrutura. Esse caso é muito útil quando precisamos armazenar dados do mesmo tipo (do novo tipo que criamos), caso contrário teríamos o problema abaixo:

```cpp
//Definindo 4 pessoas, se fosse 100?
struct pessoa p1, p2, p3, p4;

//STRUCT COM ARRAY;

struct pessoa p[4];
```

No exemplo abaixo é apresentado como podemos trabalhar com arrays de ESTRUTURAS, observe: 

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
	char nome[50], rua[50];
	int idade, numero;
};

int main(){
	
	/*
	Acesso aos campos do array de struct
	Em um array de estruturas, o operador de ponto (.) vem depois dos colchetes [] do índice do array
	*/

	struct pessoa p1[4];
	// mudando o campo IDADE da estrutura armazenada no vetor na posição 0
	p[0].idade = = 31; 
	// mudando o campo NOME da estrutura armazenada no vetor na posição 0
	strcpy(p[1].nome, "Ricardo"); 
	// mudando o campo NUMERO da estrutura armazenada no vetor na posição 2, pelo valor do campo NÚMERO da posição 0, subtraindo 1. 

	p[2].numero = p[0].numero - 1; 
	return 0;

	/*
	Arrays e estruturas
	A combinação de arrays e estruturas permite que se manipule de modo muito mais prático várias variáveis de uma estrutura.
	*/

	//Lendo dados de 4 pessoas com um loop.

	struct pessoa vetorPessoas[4];
	int i;
	for (i = 0; i < 4; i++){
		//ler o conteúdo digitado em uma linha (uma string)
		gets(p[i].nome); 
		scanf("%d", &p[i].idade);
		gets(p[i].rua);
		scanf("%d", &p[i].numero);
	}
}
```


## Aninhamento de Structs

Uma ESTRUTURA também é um tipo de dado. Logo, uma estrutura pode possuir uma variável do tipo de outra estrutura previamente definida.

**A isso chamamos de ESTRUTURAS ANINHANDAS!**

Forma Geral:

```CPP
struct nome_struct1{
	...
};
struct nome_struct2{
	...
	struct nome_struct1 nome{
	...
	};
};
```

No exemplo abaixo, observe as estruturas endereço e pessoa2 acima da função main:

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Rua e numero poderiam fazer parte da ESTRUTURA endereço
struct pessoa{
	char nome[50], rua[50];
	int idade, numero;
};

//EXEMPLO 2 DE ESTRUTURAS

struct endereco{
	char rua[50];
	int numero;
};

struct pessoa2{
	char nome[50];
	int idade;
	struct endereco ender; // utilização da estrutura endereço como uma estrutura interna (aninhamento)
};

//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	//Declaração e uso

	struct pessoa p_end;
	p_end.idade = 31;
	//São necessários dois pontos para acessar a estrutura interna
	//Estrutura interna é acessada por meio da variavel que foi definida na ESTRUTURA
	p_end.ender.numero = 101;

	//Obs.: É possível criar vários níveis de aninhamento.

	//Lendo valores para uma estrutura aninhada 

	gets(p_end.nome);
	scanf("%d", &p.idade);
	gets(p.ender.rua);
	scanf("%d", &pp.ender.numero);

	//Tudo isso é tem como objetivo organizar os dados!

	return 0;
}
```

## Demostração

Resolvendo o armazenamento de dados do Trabalho Prático 1 utilizando array de ESTRUTURAS.

# Referências
- [Linguagem C Descomplicada](https://youtube.com/playlist?list=PL8iN9FQ7_jt4DJbeQqv--jpTy-2gTA3Cp)
- [Programação em C](https://youtube.com/playlist?list=PL0Z-gyL9saMeqFxaevIhHx6vCkaaPwO5t)