#include<stdio.h>
#include<string.h>

// este codigo nao preve linhas em branco e nem preve que o arquivo esteja vazio.
// este problema esta implementado no exercicio 40 (Q40.c)

int SubStr_find(char expressao[61], char letra){
    int i;
    for (i = 0; i<strlen(expressao); i++){
        if (expressao[i] == letra){
            break;
        }
    }
    return (i);
}

char SubStr(char expressao[61], int inicio, int fim){
    char exp[61];
    int i;
    for (i=inicio; i<fim; i++){
        exp[i-inicio] = expressao[i];
    }
    //i++;
    exp[i] = '\0';
    strcpy(expressao, exp);
    //expressao[i-1] = '\0';
    return exp;
}

int main(){
    FILE *fp;
    fp=fopen ("Q39.txt","r");

    if (!fp){
        printf("Erro na abertura do arquivo. Fim de programa.\n\n");
        exit (1);
    }

    char linha[61]={}, nome[51]={}, idade[4]={};
    int inicio, fim;

    do {
        fgets(linha, 60, fp);
        inicio = 0;
        fim = SubStr_find(linha, ';');
        //printf("%d", pos);
        strcpy(nome,linha);
        SubStr(nome, inicio, fim);
        printf("%s", nome);
        for (int i = strlen(nome); i<=50; i++){
            printf(" "); // somente para alinhar a tabulacao
        }

        inicio = fim+1;
        fim = SubStr_find(linha, '\0');
        strcpy(idade,linha);
        SubStr(idade, inicio, fim+1);
        printf("\t\t%s", idade);
        //printf("%s\n", linha);
    }while(!feof(fp));

    printf("\n\n");
    return(0);
}
