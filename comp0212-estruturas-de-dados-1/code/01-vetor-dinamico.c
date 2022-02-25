#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct func{
	int id;
	char nome[25];
	float salario;
};

typedef struct func funcionario;

//Variavel global para geracao dos ids 
int gerId = 1;

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