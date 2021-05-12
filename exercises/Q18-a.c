/*
O que quer dizer *(p+15);?

significa que o endereco de p sera incrementado em 15 * sizeof(tipo de p). Considerando p um ponteiro inteiro o incremento sera 15*4 = 60 bytes
*/


/*
Explique o que vc entendeu da comparacao entre ponteiros?

A comparacao feita para variaveis normais tambem serve para ponteiros. Com isso podemos comparar (==) dois ponteiros de determinar se eles sao iguais. Ainda podemos determinar se um ponteiro aponta para
uma regiao mais alta ou mais baixa na memoria que outro ponteiro usando <, <=, >=, >
*/
#include <stdio.h>

int main() {
    int *p1, *p2, *p3, num1=10, num2=20, valor;
    p1 = &num1;             // atribuicao dos enderecos das variaveis num1 num2 e valor aos ponteiros p1, p2 p3.
    p2 = &num2;
    p3 = &valor;

    printf("%p\n", p1);     // Ao fazer esses 3 printf`s observo que a alocacao na memoria depende da ordem em que as variaveis sao declaradas
    printf("%p\n", p2);     // e o C faz a alocacao das variaveis (linha 4) da direita para a esquerda pois o endereco de valor eh menor que o
    printf("%p\n", p3);     // endereco de num2 que eh menor que o endereco de num1. Eu esperaria o contrario (aprendi algo hj heheh).

    p1++;                   // Incrementa p em 4 bytes (que eh o tamanho do tipo int).

    printf("%p\n", p1);
    printf("%d\n", num1);

    p1--;                   // Para voltar a apontar para num1

    (*p1)++;                // pEGA O VALOR ARMAZENADO EM P1 E SOMA 1
    printf("%d\n", num1);

    printf("%d\n", *(p1--));    // decrementa p1 em 4 bytes e retorna o valor armazenado no novo endereco (endereco de num2). OBS. Coloquei -- justamente para apontar
                                // para num2 uma vez que o endereco de num1 eh o maior do meu programa (colocando ++ incrementaria 4 bytes e retornaria um valor de fora desse programa

    return 0;
}

