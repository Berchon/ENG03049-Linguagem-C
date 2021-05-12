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
int main(){
    char str1[10]="abcdef",str2[10]="1234567";

    printf("Tamanho inicial da string-1 e da string-2 (respectivamente): %d e %d\n", StrLen(str1), StrLen(str2));

    StrCat(str1, str2, sizeof(str1));

    printf("A uniao das duas Strings resulta em: %s\n", str1);
    printf("Tamanho da nova string: %d\n", StrLen(str1));
    return(0);
}
