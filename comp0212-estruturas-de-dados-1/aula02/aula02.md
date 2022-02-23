# Estruturas de Dados 

## Resolução do Exercício

### 1. Implemente um sistema simplificado para a gestão de funcionários de uma empresa. O sistema deve armazenar dados dos funcionários cadastrados utilizando um vetor de structs (a quantidade n de funcionários da empresa deve ser definida pelo programador, 10 <= n < 20). Desse modo, deve-se criar structs para armazenar os dados dos funcionários. Esses dados são compostos por:

- Id (identificador do funcionário);
- Nome (primeiro nome do funcionário);
- Salário.


```cpp
//Definição do Struct para armazenar os dados
struct func{
	int id;
	char nome[25];
	float salario;
};

typedef struct func funcionario;

//Variavel global para geracao dos ids 
int gerId = 1;
```

### 2. O sistema deve ter as funcionalidades descritas abaixo. Cada funcionalidade deve ser implementada criando pelo menos uma função, ou seja, as funcionalidades não podem ser implementadas na função principal (main).

#### 2.2 Cadastrar funcionário:
Funcionalidade para cadastro de um ÚNICO FUNCIONÁRIO POR VEZ;
Um funcionário só pode ser cadastrado em uma posição vazia do vetor, ou seja, se já existir um funcionário cadastrado na posição x, deve-se procurar outra posição do vetor que não esteja ocupada. Sendo assim, não é permitido sobrescrever os dados de um funcionário já cadastrado;
Alertas de erro devem ser gerados, exemplo: o número de funcionários maior que o tamanho do vetor;

```cpp
/*
Função que zera os ids de todos os scrutcs criados com valores lixo no vetor.
*/
void inicializaVetorDinamico(funcionario *vetor, int tam){
	int i;
	for(i = 0; i < tam; i++){
		vetor[i].id = 0;
	}
}

/*
Função para verificar se existe pelo menos uma posição vazia no vetor.
Possíveis retornos:
1 - Primeira posição vazia do vetor;
2 - -1 no caso de não existir posição vazia.
*/
int verificaPosVazia(funcionario *vetor, int tam){
	int i;
	for(i = 0; i < tam; i++){
		if(vetor[i].id < 1){
			return i;
		}
	}
	return -1;
}

void cadastraFuncionario(funcionario *vetor, int tam){
	int pos = verificaPosVazia(vetor, tam);
	vetor[pos].id = gerId;
	gerId = gerId + 1; //incremento a cada adição de usuário
	printf("Digite o nome do funcionario:\n");
	scanf("%s", &vetor[pos].nome);
	printf("Digite o salario do funcionario:\n");
	scanf("%f", &vetor[pos].salario);
}
```

#### 2.3 Listar funcionários:
Funcionalidade para imprimir todos os dados (id, nome, cargo, setor e salário) de todos os funcionários de maneira organizada;
Na impressão dos dados no console, posições vazias do vetor devem ser ignoradas;

```cpp
void printFuncionario(funcionario f){
	printf("id: %d - Nome: %s - Salario: %f \n", f.id, f.nome, f.salario);
}

void listarFuncionarios(funcionario *vetor, int tam){
	int i;
	printf("LISTA DE FUNCIONARIOS:\n");
	for(i = 0; i < tam; i++){
		if(vetor[i].id > 0){
			printFuncionario(vetor[i]);
		}
	}
}
```

#### 2.4 Buscar funcionário:
Essa funcionalidade tem como objetivo buscar e imprimir os dados de um determinado funcionário, a busca deve ser realizada por meio do id (identificador) único do funcionário;

```cpp
int buscarFuncionario(funcionario *vetor, int tam, int id){
	int i;
	for(i = 0; i < tam; i++){
		if(vetor[i].id == id){
			return i;
		}
	}
	return -1;
}

void buscaFuncionarioPrint(funcionario *vetor, int tam, int id){
	int pos = buscarFuncionario(vetor, tam, id);
	//imprimindo o funcionario
	printf("BUSCA\n");
	if(pos >= 0){
		printFuncionario(vetor[pos]);
	}else{
		printf("ERRO: Nao existe funcionario com o id=%d.\n", id);
	}
}
```

#### 2.5 Remover funcionário:
- Nessa funcionalidade deve-se remover um funcionário do vetor através do seu  id (identificador) único;
- Deve-se, após a remoção, disponibilizar no vetor um novo espaço para o aluno, ou seja, a posição do array de structs onde esse usuário estava pode ser liberada para a adição de um novo usuário;
- Alertas de erro devem ser gerados, por exemplo, o id 6 não foi encontrado (não existe no vetor um funcionário com esse id);

```cpp
int buscarFuncionario(funcionario *vetor, int tam, int id){
	int i;
	for(i = 0; i < tam; i++){
		if(vetor[i].id == id){
			return i;
		}
	}
	return -1;
}

void removeFuncionario(funcionario *vetor, int tam, int id){
	//utilizacao da funcao de busca para encontrar a posicao onde o funcionario foi armazenado
	int pos = buscarFuncionario(vetor, tam, id);
	if(pos >= 0){
		vetor[pos].id = 0;
		strcpy(vetor[pos].nome, "");
		vetor[pos].salario = 0;
		printf("FUNCIONARIO DELETADO COM SUCESSO!\n");
	}else{
		printf("ERRO: O usuario com o id=%d nao existe!\n", id);
	}
}
```

Código da função main:

```cpp
int main(){
	funcionario *vetor = malloc(5 * sizeof(funcionario));
	inicializaVetorDinamico(vetor, 5);
	cadastraFuncionario(vetor, 5);
	cadastraFuncionario(vetor, 5);
	listarFuncionarios(vetor, 5);
	buscaFuncionarioPrint(vetor, 5, 2);
	buscaFuncionarioPrint(vetor, 5, 85);
	removeFuncionario(vetor, 5, 2);
	listarFuncionarios(vetor, 5);
}
```

O código na integra pode ser acessado pelo link (exercicio01.c)[link].

## Listas Ligadas (ou Listas Encadeadas)

Até o momento, trabalhamos com vetores e matrizes. Na Figura abaixo temos o exemplo de um vetor e uma matriz:

![Lista](/aula02/img/01-vetor-matriz.png "Lista de pessoas")

Matrizes e vetores são estruturas de dados muito úteis fornecidas pelas linguagens de programação. No entanto, elas tem algunas limitações, como:
- (1) O seu tamanho tem que ser conhecido no momento da compilação;
- (2) Os dados estão separados na memória do computador pela mesma distância, o que significa que para adicionar um item exige-se que se movam outros dados da estrutura.

Essas limitações podem ser superadas empregando listas ligadas.

## Estrutura

Nesse tipo de estrutura, para cada novo elemento inserido na lista,  alocamos um espaço de memória para armazená-lo. Dessa forma, o espaço total de memória gasto pela estrutura é proporcional ao número de elementos armazenados na lista.

No entanto, não podemos garantir que os elementos armazenados na lista **ocuparão um espaço de memória contíguo**, pois a alocação é feita dinamicamente; portanto, não temos acesso direto aos elementos da lista, somente através do endereço de cada elemento.

Para percorrer todos os elementos da lista, devemos explicitamente **guardar o endereço de cada elemento da ista**, o que é feito armazenando-se, junto com a informação de cada elemento, um ponteiro com o endereço para o próximo elemento da lista.

![Lista](/aula02/img/02-pessoa-lista.jpg "Lista de pessoas")

Por isso, os elementos da lista estão ligados uns aos outros, encadeados e por conta desta característica a lista é também conhecida como lista encadeada.

A Figura abaixo ilustra o arranjo da memória de uma estrutura de dados lista.

![Lista](/aula02/img/03-lista-ligada.png "Exemplo de lista encadeada")

**Em suma: A estrutura de dados Lista consiste de uma sequência encadeada de elementos, em geral chamados de nós da lista. Um nó da lista é representado por uma estrutura que contém, conceitualmente, dois campos: a informação armazenada e o ponteiro para o próximo elemento da lista.**

Observações:
- A lista inteira é representada por um ponteiro para o primeiro elemento (ou nó). 
- Do primeiro elemento, podemos alcançar o segundo, seguindo o encadeamento, e assim por diante. 
- O último elemento da lista armazenada, não possui o ponteiro para o próximo elemento mas sim um ponteiro inválido, com valor NULL, e sinaliza, assim, que não existe próximo elemento na lista.

## Características das Listas

- As listas são implementadas através de variáveis dinâmicas que são criadas em tempo de execução com alocação dinâmica de memória;

- Os nós que compõem a lista devem ser tipos abstratos de dados do tipo struct contendo, pelo menos, dois tipos de informação: um campo ou mais campos de tipo simples ou struct para abrigar as informações de cada elemento armazenado na lista e um outro campo do tipo ponteiro para abrigar o endereço do próximo elemento, ou nó, da lista;

- O acesso aos nós componentes da lista é sempre sequencial (para se acessar o 4o elemento, é necessário passar antes pelo 3o, para se acessar o 3o elemento, é necessário passar antes pelo 2o e assim sucessivamente);

- As estruturas de representação devem obrigatoriamente suportar conceitos como ponteiros e alocação dinâmica;

• As Listas Ligadas podem ser simplesmente encadeadas (um único ponteiro por nó) ou duplamente encadeadas (dois ponteiros por nó).

## Vantagens

- Flexibidade no tamanho, podemos crescer e decrescer conforme a necessidade.
- Maior facilidade nas operações de adição e remoção:
	- Consistem em basicamente o rearranjo de alguns ponteiros.

## Desvantagens

- Maior complexidade inerente à manipulação dos elementos devido a utilização de ponteiros.
- Nem todas as linguagens permitem a construção desse tipo de representação de lista ligada.

## Principais Operações

- Inserção de elementos na lista:
	- Início;
	- Final;
	- No "meio" (posição definida utilizando algum critério).
- Busca;
- Remoção de elemento em qualquer posição;
- Impressão da lista;

## Exemplo de Implementação

Implementando uma lista encadeada para armazenar valores inteiros.

### Representação do nó

Implementando a representação de um nó da lista:

```cpp
struct no {
	int valor;            // Valor inteiro
  struct no* prox;       // Ponteiro para o proximo elemento
};

typedef struct no lista;
```

Observações: 
- Devemos observar que estamos criando uma estrutura **auto-referenciada**.
- O tipo lista representa um nó da lista.

### Função de Criação

A Função de criação apenas retorna o valor NULL, que nesse caso siginifica uma lista vazia:

```cpp
/* função de criação de lista: retorna lista vazia*/
lista* cria(void) {
    return NULL;
}
```

### Função de inserção de nó na lista

Após criar a lista podemos inserir elementos. Observe abaixo um exemplo de função para a adição de elementos na lista.

```cpp
/* função que insere elemento no início da lista*/
lista* insere(lista* l, int i)
{
    lista* novo = (lista*) malloc(sizeof(lista)); //alocação dinâmica do novo nó
    novo->valor = i;
    novo->prox = l;
    return novo;
}
```

A figura abaixo ilusta a inserção do nó na lista:

![Lista](/aula02/img/04-lista-insercao.png "Exemplo de lista encadeada")

### Função que verifica se a lista está vazia

É útil verificar se uma determinada lista está vazia em algumas situções. Como sabemos, uma lista vazia sempre retorna NULL, então podemos implementar essa função da forma apresentada abaixo:

```cpp
/* função vazia: retorno 1 se vazia ou 0 se não vazia*/
int lista_vazia(lista* l) {
   if(l == NULL)
      return 1;  // Retorna 1 que significa verdadeiro, a lista está vazia
    else
      return 0; // Retorna 0 que significa falso, a lista não está vazia
}
```

### Função que imprime os elementos da lista

Observe abaixo uma possível implementação dessa função:

```cpp
/* função que imprime elementos da lista*/
lista* imprime(lista* l) {
if(!lista_vazia(l)) {
    lista* aux;
    for(aux=l; aux != NULL; aux=aux->prox)
           printf("valor = %d\n",aux->valor);
}
else
   printf("\nTentou imprimir uma lista vazia");
}
```

Observe a instrução **aux=aux->prox**, graças a ela estamos percorrendo a lista.

### Função de busca

Essa função é bem últil e semelhante a função anterior de imprimir os elementos, observe-a abaixo:

```cpp
/* função que busca um elemento na lista*/
lista* busca(lista* l, int busca) {
    lista* aux;
   if(!lista_vazia(l)) {
       for(aux=l;aux!=NULL;aux=aux->prox) {
           if(aux->valor == busca) {
               printf("Valor encontrado.\n");
               return aux;
           }
       }
      return NULL;
  }
  else {
      printf("\nTentou buscar de uma lista vazia");
      return NULL; 
}
```

### Função para remover um elemento da lista

A função de remoção é a mais complexa até o momento porque devemos tomar o cuidado de não "partir a lista" no momento da remoção.

Casos:
- 1 - O nó a ser removido é o primeiro da lista:
	- Temos que garantir que a cabeça da lista será a partir de agora o próximo nó da lista;
- 2 - O nó a ser removido está no meio da lista:
	- devemos salvar (temporariamente) o elemento anterior ao que será removido;
	- apontar o elemento salvo para o seguinte considerando o removido;
	- liberar o espaço deletando o nó.
3 - O nó a ser removido é o último:
	- devemos fazer o anterior a ele apontar para NULL;

Na figura abaixo é possível observar um exemplo da remoção de um nó no meio da lista:

![Lista](/aula02/img/05-lista-remocao.png "Exemplo de lista encadeada")

```cpp
lista* retira(lista* l, int valor) {
    lista* ant = NULL;    /* ponteiro para elemento anterior */
    lista* aux = l;       /* ponteiro para percorrer a lista */
    if(!lista_vazia(l)) {
        /* procura elemento na lista, guardando anterior */
        while(aux!= NULL && aux->valor != valor) {
            ant = aux;
            aux = aux->prox;
        }
        /* CASO 1: aux == NULL, isso significa que chegou ao final da lista e nao encontrou o elemento. Logo retorna a lista inalterada. */

        if(aux == NULL){
            return l;
        }

        /* CASO 2: aux != NULL e contem o elemento a ser excluido da lista. */
        if(ant == NULL){
            /* CASO 2.1: O elemento a ser excluído é o primeiro da lista

            O elemento anterior é null porque o elemento excluido é o primeiro e entao agora o primeiro elemento da lista é o  elemento apontado por aux.
            */
            l = aux->prox;
        }else{
            /* CASO 2.2: O elemento não é o primeiro da lista

            O elemento anterior nao é null porque o elemento aux a ser excluido nao é o primeiro. Portanto o elemento anterior deve apontar para o elemento apontado por aux */
            ant->prox = aux->prox;
        }
        /* libera a memoria utilizada pelo elemento aux que foi excluido */
        free(aux);
        /* Retorna a lista atualizada */
        return l;
    }else{
        printf("\nTentou remover de uma lista vazia");
        /* Retorna a lista inalterada */
        return l;
    }
}
```

# Exercício

1 - Implemente uma função que tenha como valor de retorno o comprimento de uma lista encadeada, isto é, que calcule o número de nós de uma lista. Esta função deve obedecer ao seguinte protótipo:

```cpp
– int calcularComprimento(Lista* l);
```

2 - Implemente uma função que retorno o último valor de uma lista encadeada de inteiros. Essa função deve ter o protótipo:

```cpp
– int retornarUltimo(Lista* l);
```

3 - Implemente uma função que receba duas listas encadeadas de valores reais e transfira para o final da primeira os elementos da segunda lista. No final, a primeira lista representará a
concatenação das duas listas e a segunda lista estará vazia. Esta função deve obedecer ao protótipo:

```cpp
– void concatenarListas(Lista* l1, Lista* l2);
```