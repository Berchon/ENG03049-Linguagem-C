#include<stdio.h>
#include <string.h>

struct Produto{
    char nome[30];
    int codigo;
    float preco;
};

void main(){
    struct Produto produtos[10];
    strcpy(produtos[0].nome, "Pe de Moleque");
    produtos[0].codigo = 13205;
    produtos[0].preco = 0.20;

    strcpy(produtos[1].nome, "Cocada Baiana");
    produtos[1].codigo = 15202;
    produtos[1].preco = 0.50;

    for (int i=0; i<2; i++){
        printf("Produto %d\n", i+1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Codigo: %d\n", produtos[i].codigo);
        printf("Preco: %.2f\n\n", produtos[i].preco);
    }

    return;
}
