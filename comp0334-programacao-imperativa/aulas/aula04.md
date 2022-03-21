# Aula 04

## Arrays e Matrizes

Um array ou vetor é uma estrutura de dado com uma dimenssão; Já uma matriz é uma estrutura de dados com duas dimensões.

Forma geral:

```cpp
tipo nome_array[nro_linhas][nro_colunas];

// Exemplo de declaração de matriz

int mat[3][2]; //Parece uma planilha
```

Exemplo:

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	//Declaração de matrizes: Sempre use uma constante inteira!
	
	define N 100
	
	int n = 5;
	float F[N+1][N]; // CORRETO
	char frases[30][50]; //CORRETO
	int mat[n][n]; //ERRADO
	int V[4.5][5]; //ERRADO -> não podemos usar valores reais
		
	//Acesso aos elementos: índice
	
	int mat[3][2]
	mat[0][0] = 5; //primeira posição
	mat[0][1] = 23;
	mat[2][1] = -1;
	
	Lendo dados e etc.
	int mat[3][2], M[3][2];
	scanf("%d", &mat[2][0]); //Comando de leitura
	mat[0][0] = 10; // Comando de atribuição
	mat[1][1] = mat[0][0] + mat[2][0] //Expressão
	mat = M // ERRADO! -> O C não sabe copiar tudo de uma vez!
	
	int mat[100][50];
	int i, j;
	for (i = 0; i < 100; i++){
		for (j = 0; j < 50; j++){
			printf("Digite mat[%d][%d]: ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
	
	return 0;
}
```

CODIFICANDO: LENDO E IMPRIMINDO UMA MATRIX 2 X 2.

## Array Multidimensional

Até o momento discutimos sobre arrays com uma e duas dimenssões (matriz):

```cpp
//vetor = uma dimensão
//Exemplo:
float notas[100];
//Matriz = duas dimensões
//Exemplo:
int mat[100][50];
```

A linguagem C permite vc criar quantas dimenssões vc quiser, a quantidade de dimensões vai depender da aplicação!

Exemplo com código:

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main(){

	
	//Declaração de array de int com 1 dimensão
	int vet[5];
	//Declaração de array de float com 2 dimensão
	float mat[5][5];
	//Declaração de array de double com 3 dimensão
	double cub[5][5][5];
	//Declaração de array de int com 4 dimensão
	int X[5][5][5][5];

	int cub[5][5][5]; //125 variáveis
	//Cuidado com o consumo de memória
	int i,j,k;
	//Preenchendo o array de 3 dimensões com zeros
	//Para cada dimenssão utilizamos um comando de repetição
	for (i = 0;i < 5; i++){
		for (j = 0; j <5; j++){
			for (k = 0; k <5; k++){
				cub[i][j][k] = 0;			
			}
		}
	}
	return 0;
}
```

CODIFICANDO: LENDO E IMPRIMINDO UMA MATRIX 2 X 2 X 2.

##  Inicialização de Arrays

É possível inicializar arrays com valores pré-definidos no meio do código.

Até o momento, para incializar um vetor utilizamos laços de repetição e outras estratégias, por exemplo:

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// Inicializando um array com zeros
	int vetor[5], i;
	for (i = 0; i < 5; i++)
	{
		vetor = 0;
	}
	return 0;
}
```

E se for necessário por um valor diferente em cada posição?

Exemplo:

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int vetor[5];
	
	vetor[0] = 15;
	vetor[1] = 12;
	vetor[2] = 8;
	vetor[3] = 7;
	vetor[4] = 1;
	return 0;
}
```

Não é muito prático fazer desse modo, podemos podemos definir uma lista de valores para colocar no array:

Exemplo:

```cpp
tipo nome_array[tam1]...[tamN] = {valores}
```

Agora vamos ver um exemplo com código:

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main()
{

	//Só é possível fazer isso na inicialização do vetor
	int vet[5] = {15, 12, 8, 7, 1}

	/*
	INICIALIZANDO UMA MATRIZ
	Opção 1
	*/
	int matriz1[2][3] = {1, 2, 3, 4, 5, 6};
	//Opção 2 (atribuindo linha por linha)
	int matriz1[2][3] = {{1, 2, 3}, {4, 5, 6}};

	/*
	INICIALIZANDO SEM TAMANHO
	Não é necessário definir o tamanho do array no caso de ele ser inicializado com valores.
	Exemplo:
	*/

	int vetorNL[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

	/*
	No caso da matriz é obrigatória a definição do número de colunas.
	Exemplo:
	*/

	int matrizNL[][2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} 

	//Evitem usar essas declarações sem tamanho!

	return 0;
}
```

## Demostrações:
- Somando os valores de um array;
- Maior valor de um array;

