#include <stdio.h>


// O valor de y sera: 4
int main() {
    int y, *p, x; y = 0;            //declara as variaveis e inicializa y=0. Note que &y>&x

    p = &y;                         // atribui ao ponteiro p o endereco de y
    x = *p;                         // pega o valor armazenado no endereco apontado por p e atribui para x. x=0

    x = 4;                          // atribui 4 para x

    (*p)++;                         // pega o valor armazenado no endereco apontado por p e incrementa 1. y=1
    x--;                            // decrementa x em 1. x=3

    (*p) += x;                      // pega o valor armazenado no endereco apontado por p e soma com x armazenando o resultado no endereco de p. y = 1 + 3 = 4

    printf("y = %d\n", y);
    return(0);
}

