#include <stdio.h>

int main() {
    int a[5]={1,2,3,4,5}, *pa;

    /*
    // Item 1
    pa=&a[0];
    printf("%p %p\n", a, pa);

    //RESPOSTA= Verdadeiro. &a[0] retorna o endereco do primeiro elemento do vetor a. O nome da variavel é na verdade um ponteiro para o tipo da variavel da matriz
    */

    /*
    // Item 2
    pa=a;
    printf("%p %p\n", a, pa);

    //RESPOSTA = Verdadeiro. Pela mesma justificativa do item 1
    */

    /*
    // Item 3
    printf("%d %d\n", a[2], *(a+2));

    //RESPOSTA = Verdadeiro. a[i] retorna o valor do (i+1)-esimo elemento de a, que é equivalente a fazer *(a+i). Este ultimo significa ir no endereco apontado por a somar i a esse endereco e retornar o valor armazenado
    */

    /*
    // Item 4
    pa=a;
    printf("%p %p\n", &a[2], a+2);

    //RESPOSTA = Verdadeiro. &a[i] retorna o endereco do (i+1)-esimo elemento de a. Na segunda expressao (a+i)) eh um endereco que eh acrescido de i
    */

    /*
    // Item 5
    pa=a;
    printf("%d\n", *(a+2));

    //RESPOSTA = Sim! Eh o endereco do i-esimo elemento apos a. Ou seja, eh o (i+1)-esimo elemento de todo o vetor.
    */

    /*
    // Item 6
    pa=a;
    printf("%d %d\n", pa[2], *(pa+2));

    //RESPOSTA = Verdadeiro. Por definicao pa[i] eh equivalente a *(pa+i)
    */

    /*
    // Item 7
    pa=a;
    printf("%p %p\n", pa, a);

    //RESPOSTA = Verdadeiro. a eh um endereco de memoria e esta sendo atribuido para um ponteiro (que armazena enderecos de memoria)
    */

    /*
    // Item 8
    pa=a;
    pa++;
    printf("%p %p\n", pa, a);
    //RESPOSTA = Verdadeiro. Essa eh uma operacao de incremento do endereco de memoria.
    */

    /*
    // Item 9
    pa=a;
    pa++;
    a=pa;
    printf("%p %p\n", pa, a);
    //RESPOSTA = Falso. O nome de um vetor n˜ao eh uma variavel. Isto significa, que n˜ao se consegue alterar o endereco que eh apontado pelo nome do vetor
    */

    /*
    // Item 10
    pa=a;
    pa++;
    a++;
    printf("%p %p\n", pa, a);
    //RESPOSTA = Falso. O nome de um vetor n˜ao eh uma variavel. Isto significa, que n˜ao se consegue alterar o endereco que eh apontado pelo nome do vetor
    */

}
