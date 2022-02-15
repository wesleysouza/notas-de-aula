# Variáveis, Apontadores e Alocação Dinâmica

## Variáveis

Uma variável é um local reservado na memória para armazenar algum dado. Toda variável deve ter um identificador (nome) e um tipo. Esse tipo é muito importante pois, ele determina o que a variável pode armazenar. 

### Tipos de Dados

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
