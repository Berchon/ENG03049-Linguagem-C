#include<stdio.h>
#include <string.h>

struct Produto{
    char nome[30];
    int codigo;
    float preco;
};

void main(){
    struct Produto *produtos;
    produtos = (struct Produto*)malloc(10*sizeof(struct Produto));

    strcpy((*produtos).nome, "Pe de Moleque");
    produtos->codigo = 13205;
    produtos->preco = 0.20;

    produtos++;

    strcpy((*produtos).nome, "Cocada Baiana");
    produtos->codigo = 15202;
    produtos->preco = 0.50;

    for (int i=0; i<2; i++){
        printf("Produto %d\n", i+1);
        printf("Nome: %s\n", produtos->nome);
        printf("Codigo: %d\n", produtos->codigo);
        printf("Preco: %.2f\n\n", produtos->preco);
        produtos--;
    }

    return;
}
