#include <stdio.h>
#include "biblio.h"

void imprime(int x, int y, int valor){
    gotoxy(x+19+1, y+1);
    switch (valor){
        case 0:
            setTextColor(BLACK, WHITE, stdout);
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
    return;
}
