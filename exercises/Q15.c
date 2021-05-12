#include<stdio.h>
#include<string.h>

#define N 30
void main(){
    char str1[N], str2[N], str3[N], str4[N];
    printf("Informe a palavra 1: ");
    scanf(" %s", &str1);

    printf("Informe a palavra 2: ");
    scanf(" %s", &str2);

    printf("Informe a palavra 3: ");
    scanf(" %s", &str3);

    printf("Informe a palavra 4: ");
    scanf(" %s", &str4);

    int tamanho = strlen(str1) + strlen(str2) + strlen(str3) + strlen(str4);
    char concatenados[tamanho];

    strcpy(concatenados, str1);
    strcat(concatenados, str2);
    strcat(concatenados, str3);
    strcat(concatenados, str4);
    printf("\n\n O resultado das quatro palavra concatenadas eh:\n");
    printf("%s\n\n", concatenados);
}
