#include <stdio.h>

void insertionSort(int *v, int n){
	int i, j, aux;
	for(i = 0; i < n; i++){
		aux = v[i];
		//Move os números maiores pra frente e insere na posição vaga
		for(j = i; (j > 0) && (aux < v[j - 1]); j--){
			v[j] = v[j - 1];
		}
		v[j] = aux;
	}
}

//Retorna a posição do elemento;
int buscaBinaria(int *vetor, int tamVetor, int elem){
    int fim = tamVetor;
    int ini = 0;
    int meio;
    while (ini <= fim){
        meio = (fim + ini)/2;
        if(vetor[meio] < elem){
            ini = meio + 1;
        }else{
            if(vetor[meio] > elem){
                fim = meio - 1;
            }else{
                return meio;
            }
        }
    }
    return -1;
}

void imprimeVetor(int *v, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main(){

	int v[10] = {52, 125, -4, 32, 55, 69, -78, 200, 0, 63};

	imprimeVetor(v, 10);
	insertionSort(v, 10);
	printf("#InsertionSort\n");
	imprimeVetor(v, 10);

    int r = buscaBinaria(v, 10, 32);

    printf("Busca binaria (indide) %d", r);
}