#include <stdio.h>

void StrCpy(char *destino,char *origem)
{
    while (*origem)
    {
        *destino = *origem;
        origem++;
        destino++;
    }
    *destino = '\0';
}

int StrLen(char *texto){
    int cont = 0;
    while (*texto){
        cont ++;
        texto++;
    }

    return (cont);
}

void StrCat(char *texto1, char *texto2, int tamanho){
    // tamanho eh a quantidade maxima de caracteres/bytes que cabem no vetor passado em texto1
    // OBS. não encontrei uma forma de usar o sizeof dentro da funcao, para nao precisar passar o parametro tamanho
    int i, tam_texto1 = StrLen(texto1), tam_Texto2=StrLen(texto2);

    texto1 += tam_texto1;

    for (i=tam_texto1; i<tamanho; i++){
        if (*texto2){
            *texto1 = *texto2;
            texto1++;
            texto2++;
        }
        else{
            break;
        }
    }
    if (i==tamanho){
            //A string deve conter o \0
        texto1--;
    }
    *texto1='\0';

    return;
}

int StrEnd(char *texto, char *palavra){
    char *p_texto = texto;
    int tam_texto = StrLen(texto);
    int tam_palavra = StrLen(palavra);
    int flag=0;

    if (tam_texto<tam_palavra){
        return(flag);
    }

    texto+=tam_texto-1;

    for (int i=tam_palavra-1; i>=0; i--){
        //mesclei a forma de usar os ponteiros texto e palavra pra exercitar o uso de ponteiros como variaveis normais e como vetores
        if (texto[0]==palavra[i]){
            flag = 1;
        }
        else{
            flag = 0;
            break;
        }
        if (p_texto != texto){
            texto--;
        }
        else{
            break;
        }
    }

    return(flag);
}
int main(){
    char str1[15]="123456789",str2[15]="23456789";

    printf("%d\n",StrEnd(str1, str2));

    return(0);
}
