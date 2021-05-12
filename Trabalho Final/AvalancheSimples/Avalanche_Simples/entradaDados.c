#include <stdio.h>
#include "biblio.h"

void entradaDados(int dimens[2]){
    int x=3, y=1, dimens_x, dimens_y;
    setTextColor(LIGHTBLUE, WHITE, stdout);
    box(x,y,x+92,y+15,2);
    gotoxy(x+5,y+1);
    setTextColor(RED,WHITE,stdout);
    printf("ATENCAO! ");
    setTextColor(BLACK,WHITE,stdout);
    printf("As  dimensoes/discretizacao  do  terreno (dominio  computacional)  podem  ser");
    gotoxy(x+2,y+2);
    printf("QUALQUER valor inteiro maior que 5.  Entretanto,  recomenda-se utilizar numeros de X < 90");
    gotoxy(x+2,y+3);
    printf("(dimensao horizontal) e Y < 25 (dimensao vertical), pois numeros maiores que os indicados");
    gotoxy(x+2,y+4);
    printf("irao desorganizar o layout do software.");

    setTextColor(LIGHTBLUE, WHITE, stdout);
    do{
        gotoxy(x+2,y+7);
        printf("Informe a largura X do terreno (dimensao horizontal): ");
        fflush(stdin);
        scanf(" %4d", &dimens_x);
    } while (dimens_x<5);
    do{
        gotoxy(x+2,y+8);
        printf("Informe a altura Y do terreno (dimensao vertical): ");
        fflush(stdin);
        scanf(" %4d", &dimens_y);
    } while (dimens_y<5);

    dimens[0] = dimens_x;
    dimens[1] = dimens_y;
    return;

}
