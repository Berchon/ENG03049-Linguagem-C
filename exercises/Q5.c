#include<stdio.h>

int valor=10;

void main(){
    //declaracao de variaveis
    int i1=20, i2=30, i3=40, i4=50, i5=60;
    char c1='c', c2='o', c3='e', c4='l', c5='h', c6='a';

    printf("A variavel global inteira possui o valor %d\n", valor);
    printf("As variaveis locais inteiras possuem o valor %d, %d, %d, %d, %d\n", i1, i2, i3, i4, i5);
    printf("As variaveis locais caracteres possuem o valor %c, %c, %c, %c, %c, %c\n", c1, c2, c3, c4, c5, c6);
    printf("%c%c%c%c%c%c\n\n", c1, c2, c3, c4, c5, c6);
}
