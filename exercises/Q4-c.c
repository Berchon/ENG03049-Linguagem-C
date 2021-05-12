#include<stdio.h>

#define TAMANHO 20

void main(){
    //declaracao de variaveis
    char str[TAMANHO+1];
    int cont=0;

    //entrada de dados
    printf("Informe uma string de ate %d caracteres ", TAMANHO);
    gets(str);

    //leitura da string
    for (int i=0;str[i]!= '\0'; i++){
        if (str[i]=='a'){
            str[i]='b';
            cont++;
        }
    }

    //retorno ao usuario
    printf("\n\nO numero de caracteres alterado foi %d", cont);
    printf("\nO a string modificada eh %s\n\n", str);
}
