#include<stdio.h>
#include<string.h>

// este codigo nao preve linhas em branco e nem preve que o arquivo esteja vazio.
// este problema esta implementado no exercicio 40 (Q40.c)

int main(){
    FILE *fp;
    fp=fopen ("Q39.txt","r");

    if (!fp){
        printf("Erro na abertura do arquivo. Fim de programa.\n\n");
        exit (1);
    }


    char nome[50]={}, c;
    char idade[3]={};
    do{
        //c = getc(fp);
        //    printf("%c\n", c);

        do{
            c = getc(fp);
            //printf("%s\n", nome);
            if (c != ';'){
                sprintf(nome,"%s%c",nome, c);
            }
        } while(c != ';');

        printf("Nome: %s", nome);
        for (int i = strlen(nome); i<=50; i++){
            printf(" "); // somente para alinhar a tabulacao
        }

        do{
            c = getc(fp);
            //printf("%d\n", c);
            if (c != '\n'){
                sprintf(idade,"%s%c",idade, c);
            }
        } while(c != '\n' && !feof(fp));

        printf("\t\tIdade: %s\n", idade);

        strcpy(nome, "\0");
        strcpy(idade, "\0");
        //printf("\n\n%s111\n", nome);

    }while (!feof(fp));
    return(0);
}
