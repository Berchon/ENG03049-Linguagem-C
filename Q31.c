#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanho(char *p){
    int i;
    for(i=0; *p; i++){
        p++;
    }
    return(i);
}

void StrCpy(char *destino,char *origem){
    //printf("\n\n%sorig %sdest\n\n", origem, destino);
    while (*origem)
    {
        *destino = *origem;
        origem++;
        destino++;
    }
    *destino = '\0';
}

void troca(char *str1, char *str2){
    int t1 = tamanho(str1), t2 = tamanho(str2);

    char temp1[t1], temp2[t2];
    strcpy(temp1, str1);
    strcpy(temp2, str2);

    *str1 = (char *)malloc((t2+1) * sizeof(char));

    *str2 = (char *)malloc(t1 * sizeof(char));

    int t3 = tamanho(str1), t4 = tamanho(str2);
    StrCpy(str1, temp2);
    StrCpy(str2, temp1);
    return;
}

int main(){
    char str1[10]="abcdefg";
    char str2[10]="123";
    printf("%s  %s\n\n", str1, str2);
    troca(str1, str2);
    printf("\n%s  %s\n\n", str1, str2);

    return(0);
}
