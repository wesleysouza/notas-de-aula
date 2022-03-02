# Aula 03

## 3.1 Comandos de Repetição

### 3.1.1 Comando for

Permite executar, repetidamente, um conjunto de comandos de acordo com uma condição.

Forma geral:

```cpp
for(inicializãção; condição; incremento) {
		conjunto de comandos
	}
```

Exemplo:

```cpp
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, c;
	printf("Digite dois inteiros: ");
	scanf("%d %d", &a, &b);
	for (c = a; c <= b; c++){ //Cuidado: sujeito a loop infinito
		printf("%d\n", c);
	}
	printf("Fim do programa");
	//system("pause");
	return 0;
}
```

## 3.1.2 Aninhamento de Repetições

O aninhamento de repetições é o uso dos comandos de repetição (while, for ou do-while) um dentro do outro.

Exemplo:

```cpp
repeticao (condicao1){
	conjunto de comandos;
	repeticao(condicao2){
		conjunto de comandos;
		repeticao... Não há limites...
	}
}
```

Exemplo: Imprimindo uma matriz identidade 5 x 5 com o for

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, j;
	
	for (i = 1; i <= 5; i++){
		for(j = 1; j <= 5; j++){
			if(i == j){
				printf("1 ");
			}
			else{
				printf("0 ");
			}
		}
		printf("\n");
	}
    return 0;
}
```

Exemplo: Imprimindo uma matriz identidade 5 x 5 com o while

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, j;

	printf("------\n");

	i = 1;
	while(i <= 5){
		j = 1;
		while(j <= 5){
			if(i == j){
				printf("1 ");
			}
			else{
				printf("0 ");
			}
			j++;
		}
		printf("\n");
		i++;
	}
    return 0;
}
```

Obs.: Nada impede de você combinar os diferentes comandos de repetição.

# 3.2 - Comando Break

A função do comando **break** é interromper a repetição de qualquer comando de laço (for, while ou do-while).

Forma geral:

```cpp
repeticao(condição1){
	if(condição 2){
		break; //Se a condição for verdadeira, para o loop.
	}
}
```

Exemplo:

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//Exemplo
	int a, b;
	printf("Digite o valor de a:"); 
	scanf("%d", &a);
	printf("Digite o valor de b:"); 
	scanf("%d", &b);
	while(a <= b){
		a = a + 1;
		if(a == 5){
            // O break deve ser colocado dentro de uma condição pois, caso contrário ele sempre vai quebrar o loop.
			break;
		}
		printf("%d\n", a);
	}

	return 0;
}
```


## 3.3 Comando Continue

A função do comando **continue** é interromper a repetição atual de qualquer comando de loop (for, whle ou do-while), e passar para a próxima repetição.

Forma geral:

```cpp
repetição (condição1){
	if(condição2){
		continue; //Pula para o inicio do laço, ignorando tudo que está depois dele dentro da repetição.
		}
	}
```

**Obs.: O continue ignora apenas a iteração atual do laço e não o laço inteiro**.

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main(){

	int a, b;
	printf("Digite o valor de a:"); 
	scanf("%d", &a);
	printf("Digite o valor de b:"); 
	scanf("%d", &b);

	while(a <= b){
		a = a + 1;
		if(a == 5){ //Sem a condiçãoooo, todo o cídigo abaixo do comando continue será sempre ignorado!
			continue;
		}
		printf("%d\n", a);
	}
	return 0;
}
```

## 3.4 Arrays / Vetores

Um Array é um conjunto de variáveis do mesmo tipo usando o mesmo nome.

Forma geral:

```cpp
tipo nome_array[tamanho];
```

Porque usar vetores ou arrays?

- Problema: Leia a nota de 5 estudantes e imprima as notas maiores que a média da turma;

Resolvendo com o que aprendemos até agora:

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

//OBS.: ESSES TRECHOS DE CÓDIGO NÃO SÃO PROGRAMAS COMPLETOS E ESTÃO SENDO UTILIZADOS APENAS PARA FINS DIDÁTICOS.

int main(){
    float n1, n2, n3, n4, n5;
    ...
    return 0;
}
```

Nesse caso teriamos que manipular 5 variáveis (e se fosse 100 notas?), com vetores podemos manipular todos esses dados por meio de um único identificador.

Resolvendo com um array: 

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

//OBS.: ESSES TRECHOS DE CÓDIGO NÃO SÃO PROGRAMAS COMPLETOS E ESTÃO SENDO UTILIZADOS APENAS PARA FINS DIDÁTICOS.

int main(){
    float notas[5];
    ...
    return 0;
}
```

Obs.: O tamanho do array deve ser uma constante inteira!

Criando arrays:


```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main(){
	
    //OBS.: ESSES TRECHOS DE CÓDIGO NÃO SÃO PROGRAMAS COMPLETOS E ESTÃO SENDO UTILIZADOS APENAS PARA FINS DIDÁTICOS.

	//guardando a nota de 100 alunos
	float notas[100];
	
	#define N 100

    scanf("%d", n); //CUIDADO!
	
	int n = 5;
	float F[N+1]; // CORRETO
	char texto[30]; //CORRETO
	int vetor[n]; //ERRADO 
	int V[4.5]; //ERRADO -> não podemos usar valores reais

    return 0;
}
```

O acesso aos elementos do array é por meio do índice, veja o exemplo abaixo:

```cpp
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main(){
	
    //OBS.: ESSES TRECHOS DE CÓDIGO NÃO SÃO PROGRAMAS COMPLETOS E ESTÃO SENDO UTILIZADOS APENAS PARA FINS DIDÁTICOS.

	//Acesso aos elementos: indice
	float notas[100];
	notas[0] = 81; // Primeiro indice
	notas[1] = 55; // Segundo indice
	notas[99] = 72; // Terceiro indice
	
	//Obs.: É o programador que define o tamanho e controla o valor do índice!
	
	//Cada posição do array é uma variável
	
	float notas[100], vetor[100];
	scanf("%d", &notas[5]); // Comando de leitura
	notas[0] = 10; //Comanod de atribuição
	notas[1] = notas[5] + notas[0] // expressão
	notas = vetor; //Errado -> você tem que copiar posição por posição
	
	return 0;
}
```

Agora vamos resolver um problema: Lendo e imprimindo as notas dos alunos.

# Referências
- [Linguagem C Descomplicada](https://youtube.com/playlist?list=PL8iN9FQ7_jt4DJbeQqv--jpTy-2gTA3Cp)

- [Programação em C](https://youtube.com/playlist?list=PL0Z-gyL9saMeqFxaevIhHx6vCkaaPwO5t)