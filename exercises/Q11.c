#include<stdio.h>
#include<string.h>


void main(){
    char palavra[20+1], invertida[20+1];
    int j;

    printf("Informe uma expressao a ser invertida: ");
    gets(palavra);

    j = (strlen(palavra)-1);

    if (j < 20){
        for(int i=j; i>=0; i--){

            invertida[strlen(palavra) - i-1] = palavra[i];
        }
        invertida[strlen(palavra)] = '\0';

        printf("%s\n", palavra);
        printf("%s\n", invertida);
    }
    else{
        printf("Deve ser informado uma expressao de ate 20 caracteres\n\n");
    }
}
