#ifdef _WIN32
    #include <windows.h>    // for win32 API functions
    #include <io.h>         // for _get_osfhandle()
#else
    #define _POSIX_SOURCE   // enable POSIX extensions in standard library headers
    #include <unistd.h>     // for isatty()
#endif

#include <stdlib.h>
#include <stdio.h>

typedef enum TextColor
{
    BLACK = 0,
    BLUE = 1,
    GREEN = 22,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHTGRAY = 7,
    DARKGRAY = 8,
    LIGHTBLUE = 9,
    LIGHTGREEN = 10,
    LIGHTCYAN = 11,
    LIGHTRED = 12,
    LIGHTMAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
} TextColor;

// set output color on the given stream:
//void setTextColor(TextColor CorLetra, TextColor CorFundo, FILE *stream);
//void setTextColor(TextColor CorLetra, TextColor CorFundo, FILE *stream)

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

    /*
    void setTextColor(FILE *stream, TextColor color)
    {
        int outfd = fileno(stream);
        HANDLE out = (HANDLE)_get_osfhandle(outfd);
        DWORD outType = GetFileType(out);
        DWORD mode;
        if (outType == FILE_TYPE_CHAR && GetConsoleMode(out, &mode))
        {
            // we're directly outputting to a win32 console if the file type
            // is FILE_TYPE_CHAR and GetConsoleMode() returns success

            SetConsoleTextAttribute(out, color);
            // the enum constants are defined to the same values
            // SetConsoleTextAttribute() uses, so just pass on.
        }
    }
    */

#else

    #define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

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

    void SetTextColor(TextColor CorLetra, TextColor CorFundo, FILE *stream){
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

#endif



void box(int x1,int y1,int x2,int y2,int Linha){
    //1 = Borda Simples, 2 = Borda Dupla, Outro Valor = Sem Borda

    char Caracter1, Caracter2;
    if (Linha==2){
        Caracter1 = 205;
        Caracter2 = 186;
    }
    else if (Linha==1){
        Caracter1 = 196;
        Caracter2 = 179;
    }
    else{
        Caracter1 = ' ';
        Caracter2 = ' ';
    }
    int xMenor, xMaior, yMenor, yMaior;
    if (x1 > x2){
        xMaior = x1;
        xMenor = x2;
    }
    else{
        xMaior = x2;
        xMenor = x1;
    }
    if (y1>y2) {
        yMaior = y1;
        yMenor = y2;
    }
    else{
        yMaior = y2;
        yMenor = y1;
    }

    gotoxy(xMenor, yMenor);
    for (int i=0; i<(xMaior - xMenor);i++){
        printf("%c",Caracter1);
    }

    gotoxy(xMenor, yMaior);
    for (int i=0; i<(xMaior - xMenor);i++){
        printf("%c",Caracter1);
    }

    gotoxy(xMenor, yMenor+1);
    for (int i=0; i<(yMaior - yMenor-1);i++){
        gotoxy(xMenor, yMenor+1+i);
        printf("%c",Caracter2);
    }

    gotoxy(xMaior, yMenor);
    for (int i=0; i<(yMaior - yMenor-1);i++){
        gotoxy(xMaior, yMenor+1+i);
        printf("%c",Caracter2);
    }

    gotoxy(xMenor,yMenor);
    if (Linha==2){
        printf("%c",201);
    }
    else if (Linha==1){
        printf("%c",218);
    }
    else{
        printf("%c",' ');
    }

    gotoxy(xMaior,yMenor);
    if (Linha==2){
        printf("%c",187);
    }
    else if (Linha==1){
        printf("%c",191);
    }
    else{
        printf("%c",' ');
    }

    gotoxy(xMenor,yMaior);
    if (Linha==2){
        printf("%c",200);
    }
    else if (Linha==1){
        printf("%c",192);
    }
    else{
        printf("%c",' ');
    }

    gotoxy(xMaior,yMaior);
    if (Linha==2){
        printf("%c",188);
    }
    else if (Linha==1){
        printf("%c",217);
    }
    else{
        printf("%c",' ');
    }

    for (int j=yMenor+1; j<yMaior; j++){
        for(int i=xMenor+1; i<xMaior; i++){
            gotoxy(i, j);
            printf(" ");
        }
    }

}

void Sombra(int x1, int y1, int x2, int y2, int Caracter){
    int xMenor, xMaior, yMenor, yMaior;
    if (x1 > x2){
        xMaior = x1;
        xMenor = x2;
    }
    else{
        xMaior = x2;
        xMenor = x1;
    }
    if (y1>y2) {
        yMaior = y1;
        yMenor = y2;
    }
    else{
        yMaior = y2;
        yMenor = y1;
    }
    for (int j=yMenor+1;j<yMaior+1;j++){
        gotoxy(xMaior+1,j);
        printf("%c%c",Caracter,Caracter);
    }
    gotoxy(xMenor+2,yMaior+1);
    for (int i=xMenor+2; i<xMaior+3; i++){
        printf("%c",Caracter);
    }
}

int main(void)
{
    puts("Color test.");
    setTextColor(GREEN, WHITE, stdout);
    puts("This is green!");
    setTextColor(LIGHTGRAY, RED, stdout);
    puts("back to normal.");
    return EXIT_SUCCESS;
}
