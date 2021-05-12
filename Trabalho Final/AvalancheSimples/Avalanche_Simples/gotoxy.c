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

#ifdef _WIN32
    void gotoxy( int coluna, int linha ){
        COORD coord;
        coord.X = coluna;
        coord.Y = linha;
        SetConsoleCursorPosition(
        GetStdHandle( STD_OUTPUT_HANDLE ),
        coord
        );
    }

#else

    //#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#endif
