#include<stdio.h>
#include<string.h>


void main(){
    int dia, mes, ano;

    do{
        printf("Informe o numero de um ano [valores entre 1900 e 2100]: ");
        scanf(" %d", &ano);
    }while(ano<1900 || ano>2100);

    int bissexto=0;
    if ((ano%4 == 0 && ano%100 !=0) || ano%400 ==0){
        bissexto = 1;
    }

    do{
        printf("Informe o numero de um mes [valores entre 1 e 12]: ");
        scanf(" %d", &mes);
    }while(mes<1 || mes>12);

    char texto[60];
    int diaMax;
    switch (mes){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            diaMax = 31;
            strcpy(texto, "Informe o numero de um dia do mes[valores entre 1 e 31]: ");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            diaMax = 30;
            strcpy(texto, "Informe o numero de um dia do mes[valores entre 1 e 30]: ");
            break;
        case 2:
            if (bissexto){
                    diaMax = 29;
                strcpy(texto, "Informe o numero de um dia do mes[valores entre 1 e 29]: ");
            }
            else{
                diaMax = 28;
                strcpy(texto, "Informe o numero de um dia do mes[valores entre 1 e 28]: ");
            }
    }
    do{
        printf(texto);
        scanf(" %d", &dia);
    }while(dia<1 || dia>diaMax);

    int numDias=0;
    for(int i = 1; i<mes; i++){
        numDias = numDias + 30;
    }
    switch (mes){
        case 2:
            numDias++;
            break;
        case 3:
            numDias--;
            break;
        case 6:
        case 7:
            numDias++;
            break;
        case 8:
            numDias=numDias+2;
            break;
        case 9:
        case 10:
            numDias=numDias+3;
            break;
        case 11:
        case 12:
            numDias=numDias+4;
            break;
    }
    if (mes>2){
        numDias = numDias + bissexto;
    }
    numDias=numDias+dia;


    printf("O numero de dias decorridos do inicio do ano ate a data informada eh %d\n", numDias);
}
