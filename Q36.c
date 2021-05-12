#include<stdio.h>

int main(){
    char nome[20];

    for (int i=0; i<3; i++){
        puts("Informe um nome: ");
        gets(nome);
        puts("\nO nome digitado foi: ");
        puts(nome);
        puts("\n\n");

    }
}
