#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>    // for win32 API functions
    #include <io.h>         // for _get_osfhandle()
#else
    #define _POSIX_SOURCE   // enable POSIX extensions in standard library headers
    #include <unistd.h>     // for isatty()
#endif

#include "biblio.h"


#define X 20
#define Y 20



int main(){
    //inicializa a semente
    srand(time(NULL));

    FILE *arqDominio;
    FILE *arqPotencia;

    int DOMINIO_X, DOMINIO_Y;

    int dimens[2]; /////////////////////////////////, X, Y;
    entradaDados(dimens);
    DOMINIO_X = dimens[0];
    DOMINIO_Y = dimens[1];
    setTextColor(LIGHTGRAY,BLACK,stdout);
    system("CLS");



    //Criando e inicializando eros a matriz de discretização do terreno
    int **terreno;

    terreno = (int **)calloc(DOMINIO_Y, sizeof(int*));
    if (!terreno){
        printf("** Erro: Memoria Insuficiente **");
        exit;
    }
    for (int i=0; i<DOMINIO_Y; i++){
        terreno[i] = (int *)calloc(DOMINIO_X, sizeof(int));
        if (!terreno[i]){
            printf("** Erro: Memoria Insuficiente **");
            exit;
        }
    }

    for (int m=0; m<DOMINIO_Y; m++){
        for (int n=0; n<DOMINIO_X; n++){
            terreno[m][n] = 0;
        }
    }

    int ocorrencias=0;

    int indice=0;
    //int posicao[2];

    indice = menu(1, 0);
    char ch;
    int flag = 1, comecarSimulacao = 0, DadosPrevios = 0;
    while (flag) {
        //Controle para o menu
        if(kbhit()){
            ch = getch();
            if (ch == -32){
                ch = getch();
            }
            switch (ch){
            case 77:
            case 80:
                indice = menu(1, 0);
                break;
            case 75:
            case 72:
                indice = menu(-1, 0);
                break;
            case 13:
                switch (indice){
                    case 1:
                        for (int i=0; i<DOMINIO_Y; i++){
                            for (int j=0;j<DOMINIO_X; j++){
                                fprintf(arqDominio, "%d", terreno[i][j]);
                            }
                            fprintf(arqDominio, "\n");
                        }

                        fclose(arqDominio);
                        fclose(arqPotencia);

                        mensagem("Dados salvos. Pressione qualquer tecla para continuar.");
                        getch();

                        if (comecarSimulacao ==0){
                            //comecarSimulacao = 0;
                            break;
                        }
                    case 0:
                        if (comecarSimulacao){
                            //fclose(arqDominio);
                            //fclose(arqPotencia);

                            comecarSimulacao = 0;
                        }
                        else{
                            comecarSimulacao = 1;
                            imprimeTodoTerreno(DOMINIO_Y,DOMINIO_X,terreno);
                            if (DadosPrevios){
                                //DadosPrevios = 1;
                                arqPotencia = fopen("ArqPotencia.txt", "a");

                                if (arqPotencia == NULL){
                                    system("CLS");
                                    printf("\nProblemas na CRIACAO do arquivo\n");
                                    return(0);
                                }
                            }
                            else{
                                DadosPrevios = 1;
                                arqPotencia = fopen("ArqPotencia.txt", "w");

                                if (arqPotencia == NULL){
                                    system("CLS");
                                    printf("\nProblemas na CRIACAO do arquivo\n");
                                    return(0);
                                }
                            }
                            arqDominio = fopen("ArqDominio.txt", "w");

                            if (arqDominio == NULL){
                                system("CLS");
                                printf("\nProblemas na CRIACAO do arquivo\n");
                                return(0);
                            }

                        }
                        menu(0, 13);
                        break;
                    case 2:

                        arqDominio = fopen("ArqDominio.txt", "r");

                        if (arqDominio == NULL){
                            system("CLS");
                            printf("\nProblemas na CRIACAO do arquivo\n");
                            return(0);
                        }

                        //contando o nro de caracteres do arquivo
                        int contador = 0, nro_linhas=0, nro_colunas=0;
                        char c;
                        do{
                            c = fgetc(arqDominio);
                            if (c != '\n'){
                                contador++;
                            }
                            if (c == '\n' && nro_colunas == 0){
                                nro_colunas = contador;
                            }
                        } while(!feof(arqDominio));
                        contador --;
                        if (contador == 0){
                            mensagem("O arquivo esta vazio. Nada foi carregado para a memoria.");
                            break;
                        }

                        nro_linhas = contador / nro_colunas;

                        rewind(arqDominio);

                        setTextColor(WHITE, BLACK, stdout);
                        gotoxy(0,0);

                        if (nro_colunas == DOMINIO_X && nro_linhas == DOMINIO_Y){
                            DadosPrevios = 1;
                            for (int m=0; m<DOMINIO_Y; m++){
                                for (int n=0; n<DOMINIO_X; n++){
                                    c = fgetc(arqDominio);
                                    if (c == '\n'){
                                        n--;
                                    }
                                    else{
                                        terreno[m][n] = (c - '0');
                                        //printf("%d ", terreno[m][n]);
                                    }
                                }
                            }
                            mensagem("Dados carregados para a memoria.");
                        }
                        else{
                            mensagem("O nro de linhas e colunas do arquivo eh diferente do especificado no inicio do programa");
                        }
                        break;
                    case 3:
                        //exit(1);
                        flag = 0;
                }
            }
        }

        if (comecarSimulacao){

            //Parte responsavel pela simulacao da Avalanche
             ocorrencias = semear(DOMINIO_Y, DOMINIO_X, terreno);

            if (ocorrencias){
                fprintf(arqPotencia, "%d\n", ocorrencias);
            }
        }

    }
    if (DadosPrevios){
        fclose(arqPotencia);
    }
    if (DadosPrevios){
        fclose(arqDominio);
    }
    setTextColor(LIGHTGRAY,BLACK,stdout);
    system("CLS");

    setTextColor(LIGHTBLUE, WHITE,stdout);
    box(1,1,118,7,2);
    gotoxy(3,2);
    printf("UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL");
    gotoxy(3,3);
    printf("ESCOLA DE ENGENHARIA");
    gotoxy(3,4);
    printf("ENG03049 - Linguagem C");
    gotoxy(3,6);
    printf("PROGRAMADOR: ");//dimens
    setTextColor(BLACK, WHITE, stdout);
    printf("Luciano da Silva Berchon");

    setTextColor(LIGHTBLUE, WHITE,stdout);
    gotoxy(109,2);
    printf("%s", __TIME__);
    gotoxy(88,6);
    printf("Simulador de Avalanche v(3.0)");

    gotoxy(0,12);
    setTextColor(LIGHTGRAY,BLACK, stdout);
    return 0;
}
