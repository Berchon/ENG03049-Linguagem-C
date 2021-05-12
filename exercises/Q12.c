#include<stdio.h>
#include<string.h>


void main(){
    char palavra[20+1], invertida[20+1];
    int i;

    printf("Informe uma expressao a ser invertida: ");
    gets(palavra);

    i=strlen(palavra)-1;

    if (i<20){
        while (i>=0){
            invertida[strlen(palavra) - i-1] = palavra[i];
            i--;
        }
        invertida[strlen(palavra)] = '\0';

        printf("%s\n", palavra);
        printf("%s\n", invertida);
    }
    else{
        printf("Deve ser informado uma expressao de ate 20 caracteres\n\n");
    }
}
