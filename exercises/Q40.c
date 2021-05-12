#include<stdio.h>
#include<string.h>

//*********************************************************************************************************
//*** Este codigo apresenta uma falha se a ultima linha do arquivo de texto esta em branco              ***
//*********************************************************************************************************


int get_size(const char* file_name)
{
    FILE *file = fopen(file_name, "r");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}

int main(){
    if(get_size("Q40.txt") == 0){
        printf("Arquivo vazio!!!\n\n");
        exit(1);
    }


    FILE *fp;
    fp=fopen ("Q40.txt","r");

    if (!fp){
        printf("Erro na abertura do arquivo. Fim de programa.\n\n");
        exit (1);
    }


    char nome[30]={}, c;
    char endereco[50]={};
    char telefone[18]={};
    int linhaNula = 0;
    do{
        //c = getc(fp);
        //    printf("%c\n", c);

        do{
            c = getc(fp);

            if (c == '\n'){
                linhaNula = 1;
                break;
            }
            if (c != ';'){
                sprintf(nome,"%s%c",nome, c);
            }
        } while(c != ';');

        if (linhaNula==1){
            linhaNula = 0;
            printf("\n");
            continue;
        }

        printf("Nome: %-30s", nome);

        do{
            c = getc(fp);
            if (c != ';'){
                sprintf(telefone,"%s%c",telefone, c);
            }
        } while(c != ';');

        printf("\tTelefone: %-18s", telefone);


        do{
            c = getc(fp);
            //printf("%d\n", c);
            if (c != '\n'){
                sprintf(endereco,"%s%c",endereco, c);
            }
        } while(c != '\n' && !feof(fp));

        printf("\tEndereco: %s\n", endereco);

        strcpy(nome, "\0");
        strcpy(telefone, "\0");
        strcpy(endereco, "\0");

    }while (!feof(fp));
    return(0);
}
