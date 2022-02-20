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

![Lista](/aula02/img/02-pessoa-lista.jpg "Lista de pessoas")

![Lista](/aula02/img/03-lista-ligada.png "Exemplo de lista encadeada")