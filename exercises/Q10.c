#include<stdio.h>

void main(){
    int dia;
    printf("Informe um numero equivalente ao um dia da semana [1-7] ");
    scanf(" %d", &dia);

    switch(dia){
    case 1:
        printf("Domingo");
        break;
    case 2:
        printf("Segunda");
        break;
    case 3:
        printf("Terca");
        break;
    case 4:
        printf("Quarta");
        break;
    case 5:
        printf("Quinta");
        break;
    case 6:
        printf("Sexta");
        break;
    case 7:
        printf("Sabado");
        break;
    default:
        printf("Deve ser informado um numero inteiro entre 1 e 7");
    }
    printf("\n\n");
}
