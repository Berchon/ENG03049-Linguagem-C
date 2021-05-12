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


typedef struct{
    char textoMenu[16];
    char mensagemMenu[120];
} Menu;

int menu(int incremento, int opcao){
    static int indice=-1;
    static char opcoes[4][16]={"  Comecar      ", "  Salvar       ", "  Carregar     ", "  Sair         "};
    static char mens[4][120]={
                            "Pressione <ENTER> para comecar/continuar a simulacao.",
                            "Pressione <ENTER> para salvar os dados ja obtidos.",
                            "Pressione <ENTER> para carregar a simulacao ja salva.",
                            "Pressione <ENTER> para sair d programa."};
    if (opcao ==13){
        switch (indice){
            case 1:
            case 0:
                //opcoes[4][16]={"  Comecar      "
                if (strcmp(opcoes[0], "  Comecar      ") == 0){
                    strcpy(opcoes[0], "  Parar        ");
                    strcpy(mens[0], "Pressione <ENTER> para Parar a simulacao.");
                }
                else{
                    strcpy(opcoes[0], "  Comecar      ");
                    strcpy(mens[0], "Pressione <ENTER> para comecar/continuar a simulacao.");
                }
                setTextColor(LIGHTBLUE,WHITE, stdout);
                gotoxy(1,20);
                printf("%s\n", opcoes[0]);
        }
     }

    //printf("%d %d", sizeof(*opcoes), sizeof(opcoes)/sizeof(*opcoes));
    if (indice == -1){
        setTextColor(LIGHTGRAY,BLACK, stdout);
        Sombra(0,19,16,24,177);
        setTextColor(LIGHTBLUE,WHITE, stdout);
        box(0,19,16,24,2);
        gotoxy(1,20);
        for (int i=0; i<4; i++){
            gotoxy(1,20+i);
            printf("%s\n", opcoes[i]);
        }
        setTextColor(WHITE,LIGHTBLUE, stdout);
        gotoxy(1,20);
        printf("%s\n", opcoes[0]);
        indice = 0;
    }
    else{
            setTextColor(LIGHTBLUE,WHITE, stdout);
            gotoxy(1,20+indice);
            printf("%s\n", opcoes[indice]);
            indice+=incremento;
            if (indice ==-1){
                indice = sizeof(opcoes)/sizeof(*opcoes)-1;
            }
            else if (indice == sizeof(opcoes)/sizeof(*opcoes)){
                indice = 0;
            }

            setTextColor(WHITE,LIGHTBLUE, stdout);
            gotoxy(1,20+indice);
            printf("%s\n", opcoes[indice]);
     }
    mensagem(mens[indice]);
    return indice;
}

void mensagem(char mens[80]){
    char espaco[121] = {"                                                                                                                        "};
    setTextColor(BLACK,CYAN , stdout);
    gotoxy(0,29);
    //printf("%s", espaco);
    printf("%s", espaco);
    gotoxy(0,0);
    gotoxy(0,29);
    printf(" Mensagem | %s", mens);
}
