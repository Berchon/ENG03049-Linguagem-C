#include<stdio.h>

int main(){
    FILE *fp;
    fp=fopen ("Q38.txt","r");

    if (!fp){
        printf("Erro na abertura do arquivo. Fim de programa.\n\n");
        exit (1);
    }

    printf("O texto contido no arquivo sera descrito abaixo:\n");
    int i;
    for (i=0; ; i++){

        printf("%c", getc(fp));
        if (feof(fp)){
            break;
        }
    }
    printf("\n\nO numero de caracteres presente no arquivo eh: %d\n\n", i);
    return(0);
}
