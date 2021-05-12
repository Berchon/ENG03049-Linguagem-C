
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void telainicial(){
    system("CLS");
    printf("\n\n< Conversao de base >\n");
    printf("=====================\n\n");
    printf("*** ATENCAO! Numeros com mais de 10 digitos podem extrapolar a capacidade de armazenamento das \n*** variaveis utilizadas. Nesse caso os calculos nao estarao corretos.\n\n");
    printf("1: decimal para hexadecimal\n\n");
    printf("2: hexadecimal para decimal\n\n");
    printf("3: decimal para octal\n\n");
    printf("4: octal para decimal\n\n");
    printf("5: encerra\n\n");
    printf("Informe sua opcao: ");
}

void DecToHexOrOct(char dec[], int base){
    int i,j;
    long long int quociente;
    quociente = atoi(dec);
    //esse for eh soh para determinar quantos digitos tera o nro Hex ou Oct
    //Assim j+1 sera o tamanho dos vetores
    for(j=0; quociente>base; j++){
        quociente = quociente/base;
    }
    j++;

    int resto[j];
    quociente = atoi(dec);
    //determina o coeficiente de serie
    for(i=0; i<j; i++){
        resto[i] = quociente%base;
        quociente = quociente/base;
    }

    char hex[j];
    //converte cada coeficiente de inteiro para char
    for(i=0; i<j; i++){

        switch (resto[j-1-i]){
            case 1:
                hex[i] = '1';
                break;
            case 2:
                hex[i] = '2';
                break;
            case 3:
                hex[i] = '3';
                break;
            case 4:
                hex[i] = '4';
                break;
            case 5:
                hex[i] = '5';
                break;
            case 6:
                hex[i] = '6';
                break;
            case 7:
                hex[i] = '7';
                break;
            case 8:
                hex[i] = '8';
                break;
            case 9:
                hex[i] = '9';
                break;
            case 0:
                hex[i] = '0';
                break;
            case 10:
                hex[i] = 'A';
                break;
            case 11:
                hex[i] = 'B';
                break;
            case 12:
                hex[i] = 'C';
                break;
            case 13:
                hex[i] = 'D';
                break;
            case 14:
                hex[i] = 'E';
                break;
            case 15:
                hex[i] = 'F';
        }
    }
    hex[i]='\0';
    printf("\n\n%s \n\n", hex);
    return(0);
}

void HexOrOctToDec(char hex[], int base){
    int numero, expoente, soma=0;

    for(int i=0; i<strlen(hex); i++){
        expoente = strlen(hex)-i-1;
        //converte os coeficientes da serie de char para int
        switch (hex[i]){
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
                numero = hex[i]-'0';
                break;
            case 'A':
            case 'a':
                numero = 10;
                break;
            case 'B':
            case 'b':
                numero = 11;
                break;
            case 'C':
            case 'c':
                numero = 12;
                break;
            case 'D':
            case 'd':
                numero = 13;
                break;
            case 'E':
            case 'e':
                numero = 14;
                break;
            case 'F':
            case 'f':
                numero = 15;
                break;
            default:
                printf("\n\nO numero informado nao eh Hexadecimal.\n\n");
                system("pause");
                return(0);
        }
        //faz o somatorio da serie
        soma=soma + numero * pow(base,expoente);
    }
    printf("\n\n%d \n\n", soma);
    return(0);
}

void main(){
    int continua = 1;
    char numero[20];
    do{
        telainicial();
        char opcao;
        scanf(" %c", &opcao);
        switch (opcao){
            case '1':
                printf("\n\nDigite um numero na base decimal ");
                scanf(" %s", numero);
                DecToHexOrOct(numero, 16);
                while(1){
                    printf("Deseja retornar ao menu principal [R] ou finalizar [F]? ");
                    scanf(" %c", &opcao);
                    if (opcao=='R' || opcao=='r'){
                        break;
                    }
                    else if (opcao=='F' || opcao=='f'){
                        return(0);
                    }
                }
                break;
            case '2':
                printf("\n\nDigite um numero na base hexadecimal ");
                scanf(" %s", numero);
                HexOrOctToDec(numero, 16);
                while(1){
                    printf("Deseja retornar ao menu principal [R] ou finalizar [F]? ");
                    scanf(" %c", &opcao);
                    if (opcao=='R' || opcao=='r'){
                        break;
                    }
                    else if (opcao=='F' || opcao=='f'){
                        return(0);
                    }
                }
                break;
            case '3':
                printf("\n\nDigite um numero na base decimal ");
                scanf(" %s", numero);
                DecToHexOrOct(numero, 8);
                while(1){
                    printf("Deseja retornar ao menu principal [R] ou finalizar [F]? ");
                    scanf(" %c", &opcao);
                    if (opcao=='R' || opcao=='r'){
                        break;
                    }
                    else if (opcao=='F' || opcao=='f'){
                        return(0);
                    }
                }
                break;
            case '4':
                printf("\n\nDigite um numero na base octal ");
                scanf(" %s", numero);
                HexOrOctToDec(numero, 8);
                while(1){
                    printf("Deseja retornar ao menu principal [R] ou finalizar [F]? ");
                    scanf(" %c", &opcao);
                    if (opcao=='R' || opcao=='r'){
                        break;
                    }
                    else if (opcao=='F' || opcao=='f'){
                        return(0);
                    }
                }
                break;
            case '5':
                continua = 0;
                break;
            default:
                printf("\n\nOpcao invalida. Informe um numero entre 1 e 5.\n\n");
                system("pause");

        }
    } while(continua);
    //printf("%s", numero);
    //system("pause");
}
