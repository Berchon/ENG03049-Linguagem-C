// Este programa tem um resultado de inverter os os elementos de uma string
// fazendo com que essa string seja reescrita de tras para frente

#include <stdio.h>
#include <string.h>

#define TAM 20
/*
int main() {
    char s[TAM] = "Ah! Eu to maluco!";
    int c, i, j;

    for (i=0, j=strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    printf("%s", s);
    return 0;
}
*/

int main() {
    char s[TAM] = "5*4+(3^3)+4*5";
    int c, i, j;

    for (i=0, j=strlen(s)-1; i<j; i++, j--) {       //cria um lacao inicializando i no primeiro elemento da string e j no ultimo. O laco persiste enquanto i<j e a cada volta i incrmenta em 1 e j decrementa em 1
        c = s[i];                                   //variavel temporaria
        s[i] = s[j];                                //coloca o ultimo/penultomo/etc elemento no primeiro/segundo/etc
        s[j] = c;                                   //coloca pprimeiro/segundo/ect elemento no ultimo/penultimo/etc elemento
    }
    printf("%s", s);
    return 0;
}

