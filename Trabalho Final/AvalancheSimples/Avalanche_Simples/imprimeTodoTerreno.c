#include <stdio.h>
#include "biblio.h"

void imprimeTodoTerreno(int tamY, int tamX, int **matrix){//tamY][tamX]){
    //setTextColor(LIGHTRED, WHITE , stdout);
    setTextColor(LIGHTBLUE,WHITE, stdout);
    box(19,0,19+tamX+1,0+tamY+1,1);
    for (int i=0; i<tamY; i++){
        gotoxy(20, i+1);
        for (int j=0; j<tamX; j++){
            //printf("%d", matrix[i][j]);
            switch (matrix[i][j]){
                case 0:
                    setTextColor(BLACK, BLACK, stdout);
                    break;
                case 1:
                    setTextColor(GREEN, BLACK, stdout);
                    break;
                case 2:
                    setTextColor(YELLOW, BLACK, stdout);
                    break;
                case 3:
                    setTextColor(LIGHTRED, BLACK, stdout);
                    break;
                case 4:
                    setTextColor(RED, WHITE, stdout);
            }
            printf("%c", 219);
        }
    }

    return;
}
