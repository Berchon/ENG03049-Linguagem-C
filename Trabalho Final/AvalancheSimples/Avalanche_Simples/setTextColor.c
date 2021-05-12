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

    void setTextColor(TextColor CorLetra, TextColor CorFundo, FILE *stream){
        /*
        0 - Preto       8  - Cinza
        1 - Azul        9  - Azul Claro
        2 - Verde       10 - Verde Claro
        3 - Ciano       11 - Ciano Claro
        4 - Vermelho    12 - Vermelho Claro
        5 - Rosa        13 - Rosa Claro
        6 - Amarelo     14 - Amarelo Claro
        7 - Branco      15 - Branco
        */
        int Cor;
        Cor = CorLetra + 16 * CorFundo;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cor);
    }

#else
    static const char *ansiColorSequences[] =
    {
        "\x1B[0;30m", //preto
        "\x1B[0;34m", //azul
        "\x1B[0;32m", //verde
        "\x1B[0;36m", //ciano
        "\x1B[0;31m", //vermelho
        "\x1B[0;35m", //magenta
        "\x1B[0;33m", //amarelo
        "\x1B[0;37m", //branco
        "\x1B[1;30m", //preto claro
        "\x1B[1;34m", //azul claro
        "\x1B[1;32m", //verde claro
        "\x1B[1;36m", //ciano claro
        "\x1B[1;31m", //vermelho claro
        "\x1B[1;35m", //magenta claro
        "\x1B[1;33m", //amarelo claro
        "\x1B[1;37m"  //branco claro
    };

    static const char *ansiColorTerms[] =
    {
        "xterm",
        "rxvt",
        "vt100",
        "linux",
        "screen",
        0
        // there are probably missing a few others
    };

    // get current terminal and check whether it's in our list of terminals
    // supporting ANSI colors:
    static int isAnsiColorTerm(void)
    {
        char *term = getenv("TERM");
        for (const char **ansiTerm = &ansiColorTerms[0]; *ansiTerm; ++ansiTerm)
        {
            int match = 1;
            const char *t = term;
            const char *a = *ansiTerm;
            while (*a && *t)
            {
                if (*a++ != *t++)
                {
                    match = 0;
                    break;
                }
            }
            if (match) return 1;
        }
        return 0;
    }

    void setTextColor(TextColor CorLetra, TextColor CorFundo, FILE *stream)
    {
        int Cor;
        Cor = CorLetra + 16 * CorFundo;

        int outfd = fileno(stream);
        if (isatty(outfd) && isAnsiColorTerm())
        {
            // we're directly outputting to a terminal supporting ANSI colors,
            // so send the apppropriate sequence:
            fputs(ansiColorSequences[color], stream);
        }
    }
#endif

