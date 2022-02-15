# 1 Introdução

Estruturas de dados são basicamente as formas de como organizar os dados. Cada uma dessas formas tem impacto direto na maneira que os dados são armazenados e recuperados. Além disso, o armazenamento, busca e recuperação do dado vai ter um custo computacional diferente a depender da estrura selecionada.

Esse conhecimento é fundamental para qualquer um que deseja trabalhar com implementação, testes e manutençõa de projetos de software.

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

Esses tipos são muito úteis, no entanto eles são limitados, por exemplo, não faz sentido utilizar uma variável para cada nome de aluno que precisamos armazenar. Para fazer isso, podemos combinar variáveis do mesmo tipo utilizando um único identificador.

## 1.3 Arrays 

Arrays ou vetores são **tipos compostos homogênios**, ou seja, um conjunto de variáveis do mesmo tipo que utilizam um único identificador (nome).

IMPORTANTE: Arrays são armazenados na memória de forma sequencial.

### 1.3.1 Declarando Arrays

Segue a forma geral de declaração de arrays na linguagem C:

```cpp
//Forma geral:
tipo nome_array[tamanho];
```

Declaração de um array que pode ser utilizado para guardar a nota de 100 alunos:

```cpp
//Forma geral:
float notas[100];
```

Obs.1: O tamanho do array deve ser uma constante inteira. 

Exemplos de definição de arrays:

```cpp
#define N 100
	
int n = 5;
float F[N+1]; // CORRETO
char texto[30]; //CORRETO
int vetor[n]; //ERRADO
int V[4.5]; //ERRADO -> não podemos usar valores reais
```

Obs.2: O tamanho de um array não pode ser definido em tempo de exercução! 

Nunca faça isso:

```cpp
int main(){
    int tamanho;
    scanf("Digite o tamanho do vetor %d", &tamanho);
    int vetor[tamanho]; //Vai dar erro!
}
```
### 1.3.2 Acessando os elementos

O acesso aos elementos do vetor é por meio do índice:

```cpp
float notas[100];
notas[0] = 81; // Primeiro indice
notas[1] = 55; // Segundo indice
notas[99] = 72; // Terceiro indice
	
//É o programador que define o tamanho e controla o valor do índice!
```

Cada posição do array funciona como uma "variável" ou espaço na memória.

```cpp	
float notas[100], vetor[100];
scanf("%d", &notas[5]); // Comando de leitura
notas[0] = 10; //Comanod de atribuição
notas[1] = notas[5] + notas[0] // expressão
notas = vetor; //Errado -> você tem que copiar posição por posição
```

Como deu pra perceber, os arrays de tipos homogênios dão mais possibilidade. No entanto, eles não oferecem a flexibilidade para lidar com problemas mais complexos, como armazenar nome, e notas de alunos em um mesmo array.

## 1.4 Structs

Com o objetivo de possibilitar uma maior flexibilidade, a linguagem C nos permite também criar nossos pŕoprios tipos de variáveis. Um deles é o **"struct"** que vamos chamar de ESTRUTURA.

Essa tal ESTRUTURA permite um "empacotamento dos dados" e gerenciamento dos dados empacotados por meio de apenas uma única variável. Segue a forma geral de criar uma ESTRUTURAS:

```cpp
struct nome_struct{
	tipo1 nome1; //declarações das variáveis
	tipo1 nome1; //campos da ESTRUTURAS
	...
	tipoN nomeN;
};//ponto e vírgula obrigatória!
```

### 1.4.1 Declarando as estruturas

Defina as estruturas antes da função main e após as declarações de bilbiotecas:

```cpp
#include <stdio.h>

//Declaração do struct entre a declaração das bilbiotecas e a função main.

struct pessoa{
    char nome[50], rua[50];
	int idade, numero;
};//Esse ponto e vírgula ";" é obrigatório!

int main(){
    //declaração de uma variável struct
	struct pessoa p; 
	//empacotamento das variáveis acima...
	// gerenciamento de apenas uma variável...
}
```

### 1.4.2 Acessando os valores dentro das ESTRUTURAS

```cpp
//Cada campo (variável) da struct pode ser acessada usando o operador "." (ponto)

p.idade = 31; //comando de atribuição
scanf("%d", &p.numero); // comando de leitura
scanf("%d", &p.nome);
p.numero = p.numero + p.idade - 100; //expressão
```

### 1.4.3 Vantagens de se trabalhar com ESTRUTURAS

Trabalhar sem o recurso das ESTRUTURAS seria um problema, imagine que queremos guardar os seguintes dados de 4 pessoas, sem ESTRUTURAS uma forma de resolver isso seria assim:

```cpp
//sem ESTRUTURA
char nome1[50], nome2[50], nome3[50], nome4[50];
char rua1[50], rua2[50], rua3[50], rua4[50];
int idade1, idade2, idade3, idade4, 
int numero1, numero2, numero3, numero4;
```

Agora vamos utilizar os recursos das estruras:

```cpp
struct pessoa p1, p2, p3, p4; //essas variáveis possuem todos os campos acima
```

Obs.: É possível definir várias ESTRUTURAS no programa!

Por fim, vale mencionar que ESTRUTURAS diferentes podem ter campos com o mesmo nome. Exemplo:

```cpp
#include <stdio.h>

struct ponto2D{
	int x, y;
};

struct ponto3D{
	int x, y, z;
};

int main(){
    struct ponto2D p2;
    struct ponto3D p3;

    p2.x = 10;
    p3.x = 12;

    printf("%d  %d \n", p2.x, p3.x);
}
```

### 1.4.4 Extras

Uma forma interessante de atribuir dados como cadeias de caracteres (string) a campos de uma estrutura é utilizando a função **strcpy**. Veja o exemplo abaixo:

```cpp
//Inicialização da ESTRUTURA
	struct pessoa p;

	//ATRIBUINDO DADOS A ESTRUTURA

	//Boa opção de atribuir valores string a estrutura
	strcpy(p.nome, "Ricardo"); //copia o nome Ricardo para a variável
	strcpy(p.rua, "Rua 1");
	p.idade = 31;
	p.numero;
```

Obs.: Para utilizar essa função é necessário incluir a biblioteca _string.h_ no seu código.

## 1.5 Arrays de ESTRUTUTURAS

É possível definir arrays de estruturas, dessa forma teremos **tipos compostos heterogênios**. Veja o exemplo abaixo:

```cpp
//STRUCT COM ARRAY;

struct pessoa p[4];

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
```

### 1.5.1 Manipulando os arrays de estrturas com comandos de repetição. 

A combinação de arrays e estruturas permite que se manipule de modo muito mais prático várias variáveis de uma estrutura.

Um exemplo disso é a leitura de dados de 4 pessoas com um loop como demostrando no fragmento de código abaixo:

```cpp
struct pessoa vetorPessoas[4];
int i;
for (i = 0; i < 4; i++){
	//ler o conteúdo digitado em uma linha (uma string)
	gets(p[i].nome); 
	scanf("%d", &p[i].idade);
	gets(p[i].rua);
	scanf("%d", &p[i].numero);
}
```

# 1.6 Ponteiros

Variáveis armazenam dados:
- int, float, double, char;
- struct (ESTRUTURA);
- e etc.

Por sua vez, os **ponteiros** são um tipo especial de variável que armazena endereços de memória.

Forma geral de declaração:

```cpp
//Ponteiro
tipo_ponteiro *nome_ponteiro
int *x;
```

É possível declarar ponteiros e variváveis na mesma linha de declaração:

```cpp
int x, *y;
//x é uma variável 
//y é um ponteiro
```

## 1.6.1 Inicializando ponteiros

Ponteiros não inicializados apontam para um lugar indefinido.

Lembre-se: Quando declaramos uma variável e não a inicializamos o seu conteúdo será um **valor lixo**.

Um ponteiro pode ter um valor especial **NULL**, que é o endereço de nenhum lugar.

```cpp
int *p = NULL;
```

Nesse caso, o ponteiro aponta para um endereço de memória que não existe!

Podemos também apontar o ponteiro para uma variável que já exista no nosso programa:

```cpp
int main(){
    int x = 10; //variável
    int *p; //ponteiro
    //ponteiro p aponta para a variável x
    p = &x;
    printf("x = %d\n", x);
    //imprimindo o endereço de memória de x
    printf("x = %d\n", &x);
    printf("p = %d\n", p);
}
```

## 1.6.2 Acessando o conteúdo de um ponteiro

Para acessar o valor da variável apontada por um ponteiro, basta usar o operador asterisco (*).

```cpp
int main(){
    int x = 10; //variável
    int *p; //ponteiro
    //ponteiro p aponta para a variável x
    p = &x;
    printf("x = %d\n", x);
    printf("x = %d\n", &x);
    printf("p = %d\n", *p);
```

## Modificando valor através de um ponteiro

O operador (*) permite modificar o conteúdo da posição de memória apontada:

```cpp
int main(){
    int x = 10; //variável
    int *p; //ponteiro
    //ponteiro p aponta para a variável x
    p = &x;
    printf("x = %d\n", x);
    *p = 12; // modificação do valor.
    printf("x = %d\n", &x);
    printf("p = %d\n", *p);
```

## 1.7 Alocação Dinâmica

Até o momento sabemos que uma variável é uma posição de memória que armazena um dado que pode ser utilizado pelo programa.

Problema: Precisamos armazenar em um vetor os valores dos salários dos funcinários de uma empresa.

**Solução simples**: declarar um array muito grade:

```cpp
float salarios[1000];
```

Essa solução é obviamente inadequada!

Vamos considerar o seguinte:
- Arrays são agrupamentos sequenciais de dados de um mesmo tipo na memória.
- Um ponteiro guarda um endereço de um dado na memória.
- O nome do array é um ponteiro para o primeiro elemento do array

Logo, **podemos solicitar um bloco de memória e colocar sua primeira posição em um ponteiro?**

Sim, a linguagem C permite alocar reservar dinÂmicamente (em tempo de execução) blocos de memória utilizando ponteiros. A esse processo dá-se o nome de **ALOCAÇÃO DINÂMICA**.

Para fazer isso podemos utilizar as seguintes funções:
- malloc
- calloc
- realloc
- free

## 1.7.1 Operador sizeof

Para alocar memória precisamos saber a quantidade de bytes que precisamos, para isso utilizamos o operador sizeof. Esse operador retorna o número de bytes necessários para alocar um único elemento de um determinado tipo de dado.

Forma geral:

```cpp
sizeof(nome_dotipo)
```

Exemplo:

```cpp
int x = sizeof(int);
printf("x = %d\n", x);
```
Mais um exemplo:

```cpp
int main(){
    //Declaração de variáveis
    // = é o operador de atribuição
	int numero = 1;
    char caractere = 'a';
    float psimples = 1.1;
	double pdupla = 6.5;
	printf("inteiro em bytes %d \n", sizeof(int));
    printf("char em bytes %d \n", sizeof(char));
    printf("float em bytes %d \n", sizeof(float));
	printf("double em bytes %d \n", sizeof(double));
    printf("struct ponto em bytes %d \n", sizeof(struct ponto));
	return 0;
```

## 1.7.2 Função Malloc

A função malloc server para alocar memória durante a execução do programa. Ela faz o pedido de memória ao computador e retorna um ponteiro com o endereço do inicio do espaço de memória alocado.

Protótipo:

```cpp
void* malloc(unsigned int num);
```
Observações:
- retorna um ponteiro genérico;
- num: quantidade de memória em bytes.

Funcionamento:
- A função malloc() recebe por parâmetro a quantidade de bytes a ser alocada e retorna:
    - NULL: no caso de erro;
    - ponteiro para primeira posição do array.

Exemplo:

```cpp
//Criando um array de 50 inteiros (200 bytes)
int *v malloc(200);
//Criando um array de 200 char (200 bytes)
char *v malloc(200);
```

A quantidade de bytes para um determinado tipo pode mudar, sendo assim use o operador sizeof para saber o tamanho correto de cada tipo:

```cpp
int *v = (int*) malloc(50 * sizeof(int));
int *c = (char*) malloc(50 * sizeof(char));
```

## 1.7.3 Função free

Sempre que alocarmos memória é necessário liberá-la quando ela não for mais necessária. 

Exemplo:

```cpp
int *p;
p = (int *) malloc(5 * sizeof(int));
if(p == NULL){
    printf("ERRO: Sem memória!");
    exit(1); // termina o programa
}
int i;
for(i = 0; i< 5; i++){
    printf("Digite p[%d]: ", i);
    scanf("%d", &p[i]);
}
//liberando a memória
free(p);
```


