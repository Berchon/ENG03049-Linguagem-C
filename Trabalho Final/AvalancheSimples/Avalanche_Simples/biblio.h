typedef enum TextColor{
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
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

extern enum TextColor;

void imprime(int x, int y, int valor);
//tamX = tamanho do dominio em X
//tamY = tamanho do dominio em Y
//matrix = dominio computacional

int semear(int Y, int X, int **matrix);//Y][X]);
//tamX = tamanho do dominio em X
//tamY = tamanho do dominio em Y
//matrix = dominio computacional

int sorteio(int MAX);
//MAX = maximo valor sorteado

int avalanche(int Y, int X, int **matrix, int posicao_y, int posicao_x, int recursividade);
//X = tamanho do dominio em X
//Y = tamanho do dominio em Y
//matrix = dominio computacional
//posicao_x = posicao atual sorteada, no eixo x
//posicao_y = posicao atual sorteada, no eixo y
//recursividade: Eh 1 quando a propria funcao avalanche se chama
//               Eh 0 quando a funcao avalanche eh chamada pela funcao semear

#ifdef _WIN32
    void gotoxy( int coluna, int linha );
#else

    #define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#endif

#ifdef _WIN32

    void setTextColor(TextColor CorLetra, TextColor CorFundo, FILE *stream);

#else

    void setTextColor(TextColor CorLetra, TextColor CorFundo, FILE *stream);
#endif

void box(int x1,int y1,int x2,int y2,int Linha);

void Sombra(int x1, int y1, int x2, int y2, int Caracter);

int menu(int incremento, int opcao);

void mensagem(char mens[80]);

void imprimeTodoTerreno(int tamY, int tamX, int **matrix);//[tamY][tamX]);

void entradaDados(int dimens[2]);
