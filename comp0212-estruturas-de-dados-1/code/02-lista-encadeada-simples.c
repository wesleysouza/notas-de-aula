#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;       // Valor inteiro
    struct no* prox; // Ponteiro para o proximo elemento
};

typedef struct no lista;

lista* cria(void) {
    return NULL;
}

lista* insere(lista* l, int i)
{
    lista* novo = (lista*) malloc(sizeof(lista)); //alocação dinâmica do novo nó
    novo->valor = i;
    novo->prox = l;
    return novo;
}

/* função vazia: retorno 1 se vazia ou 0 se não vazia*/
int lista_vazia(lista* l) {
   if(l == NULL)
      return 1;  // Retorna 1 que significa verdadeiro, a lista está vazia
    else
      return 0; // Retorna 0 que significa falso, a lista não está vazia
}


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
}

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

int main()
{
    lista *l = cria();
    l = insere(l, 1);
    l = insere(l, 2);
    l = insere(l, 3);
    l = insere(l, 4);
    l = insere(l, 5);

    imprime(l);

    lista *aux = busca(l, 4)
    printf("Valor: %d\n", aux->valor);

    retira(l, 4);

    imprime(l);
    return 0;
}
