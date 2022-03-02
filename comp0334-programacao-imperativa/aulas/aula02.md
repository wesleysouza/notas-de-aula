# Aula 2

## 2.1 Comando if

O comando if permite executar ou não um conjunto de comandos de acordo com uma condição.

Forma geral:

```cpp
if(condição){
	conjunto de comandos
}
```

Obs.: Essa **condição** é uma expressão relacional ou logica.

É interessante observar que antes de utilizar o comando **if** todos os comandos eram excutados. Agora podemos executar um conjunto de comandos considerando uma condição.

Exemplo 1:

```cpp
#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    if(num == 0){
        printf("O numero eh igual a 0\n");
    }else{
        printf("O numero eh menor que 0\n");
    }else{ // ERRO!
        printf("O numero eh maior que 0\n");
    }

    printf("Fim do programa \n");
    return 0;
}
```

Exemplo 2:

```cpp
#include <stdio.h>
#include <stdlib.h>

int main(){
    int x;
    printf("Digite um valor inteiro:");
    scanf("%d", &x);
    if((x%2 == 0) || (x < 0)){
        printf("O valor é par ou negativo\n");
    }

    printf("Fim do programa \n");
    return 0;
}
```

Atenção:
- Os comandos que tem "influência" do **if** estão dentro do par de chaves. 
- No caso de existir **apenas um comando**, pode-se fazer o if sem o par de chaves (não recomendado).

Exemplo 3:

```cpp
#include <stdio.h>
#include <stdlib.h>

int main(){
    int x;
    printf("Digite um valor inteiro:");
    scanf("%d", &x);
    if((x%2 == 0) || (x < 0)){
        printf("O valor é par ou negativo\n");
    }

    //Sem usar o par de chaves
    if((x%2 == 0) || (x < 0))
        printf("O valor é par ou negativo\n");

    printf("Fim do programa \n");
    return 0;
}
```

Exemplo 4: Cuidado quando não utilizar as chaves

```cpp
#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, y = -1;
    printf("Digite um valor inteiro:");
    scanf("%d", &x);
    if(x > 0)//sem as chaves
        y = x % 3; 
        //a partir daqui os comandos não pertencem ao o if acima 
        printf("O valor é positivo\n");

    printf("Fim do programa \n");
    return 0;
}
```

## 2.2 Comando else

O comando **else** permite executar um segundo conjunto de comandos se a condição do comando **if** for falsa.

Forma geral:

```cpp
if(condição){
    Primeiro conjunto de comandos
}else{
    Segundo conjunto de comandos
}
```

O comando **else** pode ser visto como um complemento do comando **if**.

Exemplo 1:

```cpp
#include <stdio.h>
#include <stdlib.h>

int main(){
    int x;
    printf("Digite um valor inteiro:");
    scanf("%d", &x);
    if(x%2 == 0){
        printf("O valor é PAR\n");
    }else{
        printf("O valor é ÍMPAR\n");
    }

    printf("Fim do programa \n");
    return 0;
}
```

Obs.: Um erro comum é colocar uma condição no comando **else**. Esse comando é o inverso do **if**, logo não precisa de condição.

## 2.3 Aninhamento if-else

Esse aninhamento trata-se do uso de outro comando **if**, ou **if-else** dentro de um comando **if**, ou **else**.

Exemplo 1:

```cpp
if(condição){
    if(condição2){
        Primeiro conjunto de comandos
    }else{
        Segundo conjunto de comandos
    }
}else{
    Terceiro conjunto de comandos
}
```

Obs.: Não há um limites de **if** e **else** que podemos colocar dentro de um comando **if**.

Exemplo 2:

```cpp
#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    printf("Digite um numero: ");
    scanf("%d", &x);
    if(num == 0){
        printf("O numero e igual a 0.\n");
    }else{
        if(num > 0){
            printf("O numero e maior do que 0\n");
        }else{
            printf("O numero e menor do que 0\n");
        }
    }

    printf("Fim do programa \n");
    return 0;
}
```

Obs.: O **else** pertence ao último comando **if**, por esse motivo use sempre as chaves para deixar o código mais claro.

Exemplo 3: Não coloque dois **elses** dentro de um único **if**!

```cpp
#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    printf("Digite um numero: ");
    scanf("%d", &x);
    if(num == 0){
        printf("O numero e igual a 0.\n");
    }else{
        if(num > 0){
            printf("O numero e maior do que 0\n");
        }else{
            printf("O numero e menor do que 0\n");
        }
    }

    printf("Fim do programa \n");
    return 0;
}
```

## 2.4 Comando switch

O comnando switch permite fazer seleções multiplas com base no valor de uma variável do tipo **int** ou **char**.

Forma geral:

```cpp
switch(variavel)
	{
		case valor1: conjunto de comandos; break;
		case valor2: conjunto de comandos; break;
		case valor3: conjunto de comandos; break;
		//Não precisamos de chave no switch, para sair do case utilizamos o comando break.
		//O defalut é executado se a variavel não recebe nenhum dos valores acima.		
		default: conjunto de comandos;
	}
```

Exemplo:

```cpp
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch;
	printf("Digite um simbolo de pontuação: ");
	scanf("%c", &ch);

	switch(ch){
		case '.': 
			printf("Ponto.\n"); 
			break;
		case ',': 
			printf("Virgula.\n"); 
			break;
		case ':': 
			printf("Dois pontos.\n"); 
			break;
		case ';': 
			printf("Ponto e virgula.\n"); 
			break;
		default : 
			printf("Nao eh pontuacao.\n"); 
	}

	return 0;
}
```

## 2.5 Comandos de repetição

### 2.5.1 Comando while 

O comando **while** permite executar, repetidamente, um conjunto de comando de acordo com uma condição.

Forma geral:

```cpp
while(condicao){
		conjunto de comandos
}
```

Exemplo:

```cpp
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b;
	printf("Digite dois valores inteiros: ");
	scanf("%d %d", &a, &b);
	while(a < b){ //Cuidado com o loop infinito
		a++; //Altera a condição e evita o loop infinito.
		printf("%d\n", a);
	}
	printf("Fim do programa.\n");
	//system("pause");
	return 0;
}
```

### 2.5.2 Comando for

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

### 2.5.3 Comando do-While

O comando **do-while** permite executar, repedidamente e **AO MENOS UMA VEZ**, um conjunto de comandos de acordo com uma condição.

Forma geral:

```cpp
do{
	conjunto de comandos
}while(condição); 
```

A condição é testada só no final. Esse comando é o ideal quando vc precisa iniciar a execução do loop independente da condição ser verdadeira ou falsa, ou seja, que o bloco de comandos dentro do "do" seja executado pelo menos uma vez.

Exemplo 1:

```cpp
#include <stdio.h>
#include <stdlib.h>

int main(){

	int a, b;
	printf("Digite dois valores inteiros: ");
	scanf("%d %d", &a, &b);
	do{ //Uma vez pelo menos eu vou executar!
		printf("%d\n", a);
		a++;
	}while (a < b); //Também está sujeito ao loop infinito.
	printf("Fim do programa \n");

	return 0;
}
```

Exemplo 2:

```cpp
#include <stdio.h>
#include <stdlib.h>

int main(){

	int opcao;

	do{
		printf("Escolha uma opção \n");
		printf("(1) Opção 1 \n");
		printf("(2) Opção 2 \n");
		printf("(3) Opção 3 \n");
		printf("Digite qualquer outro dígito para sair!");
		scanf("%d", &opcao);
	}while((opcao < 1) || (opcao < 3));
	printf("Você escolheu a opção %d \n", opcao);

	//system("pause");
	return 0;
}
```

# Referências
- [Linguagem C Descomplicada](https://youtube.com/playlist?list=PL8iN9FQ7_jt4DJbeQqv--jpTy-2gTA3Cp)
- [Programação em C](https://youtube.com/playlist?list=PL0Z-gyL9saMeqFxaevIhHx6vCkaaPwO5t)