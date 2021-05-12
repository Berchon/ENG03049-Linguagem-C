#include<stdio.h>
#include<windows.h>
#include<string.h>
//#include<conio.h>

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

int aleatorio(int minimo, int maximo){
    if (maximo<minimo){
        int temp = minimo;
        minimo = maximo;
        maximo=temp;
    }
    return(rand()%(maximo - minimo) + minimo);
}

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

typedef struct{
    char textoMenu[16];
    char mensagemMenu[120];
} Menu;

int menu(int incremento){
    static int indice=-1;
    static char opcoes[4][16]={"  Comecar      ", "  Salvar       ", "  Carregar     ", "  Sair         "};
    static char mens[4][120]={
                            "Pressione <ENTER> para comecar/continuar a simulacao.",
                            "Pressione <ENTER> para salvar os dados ja obtidos.",
                            "Pressione <ENTER> para carregar a simulacao ja salva.",
                            "Pressione <ENTER> para sair d programa."};
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


#define N 25
#define M 80

void sorteio(int *posicao[2]){
    posicao[0] = 7;
    posicao[1] = 20;
    return;
}

void main(){
    //inicializa a semente
    srand(time(NULL));

    //Criando e inicializando eros a matriz de discretização do terreno
    int terreno[N][M]={};

    int a=0, indice;
    int posicao[2];

    indice = menu(1);
    char ch;
    while (1) {
        if(kbhit()){
            ch = getch();
            if (ch == -32){
                ch = getch();
            }
            switch (ch){
            case 77:
            case 80:
                indice = menu(1);
                break;
            case 75:
            case 72:
                indice = menu(-1);
                break;
            case 13:
                switch (indice){
                    case 0:
                        break;
                    case 1:
                    break;
                    case 2:
                        break;
                    case 3:
                        exit(1);
                }
            }
        }
        //sorteia onde sera colocado o grao de areia
        sorteio(posicao);
        //coloca o grao de areia na posicao sorteada
        terreno[posicao[0]][posicao[1]]++;
        avalanche(terreno, posicao[0], posicao[1]);

    }

    return;
}

void avalanche(int *terreno, int x, int y){

}
