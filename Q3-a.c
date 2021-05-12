#include<stdio.h>

int main(){
    //Declaracao de variaveis
    char letra;

    //Entrada de dados pelo usuario
    printf("Informe uma letra: ");
    scanf("%c", &letra); //solicita a entrada de um caracter

    printf("\n\nA letra informada foi: %c\n", letra); //imprime o caracter informado pelo teclado
    printf("O codigo ASCII dessa letra eh: %d\n\n", letra); //imprime o codigo ASCII do caracter informado
    return(0);
}
