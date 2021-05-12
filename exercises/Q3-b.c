#include<stdio.h>

#define TAMANHO 10
int main(){
    //Declaracao de variaveis
    char palavra1[TAMANHO + 1];
    char palavra2[TAMANHO + 1];

    //solicita ao usuario para entrar com 2 palavras
    printf("Informe uma palavra com ate 10 caracteres: ");
    gets(palavra1);
    printf("Informe outra palavra com ate 10 caracteres: ");
    gets(palavra2);

    //imprime na tela as duas entradas via teclado
    printf("\nA primeira palavra digitada foi: %s\n", palavra1);
    printf("A segunda palavra digitada foi: %s\n", palavra2);

    //imprime na tela a segunda letra de cada palavra
    printf("A segunda letra de cada palavra digitada foi: %c e %c\n\n", palavra1[1],palavra2[1]);
    return(0);
}
