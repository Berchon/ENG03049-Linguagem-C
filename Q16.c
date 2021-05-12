# include <stdio.h>

//eSSE PROGRACA CRIA UMA MATRIZ DE 3 LINHAS E 4 COLUNAS
//depois preenche essa matriz com nros de 1 ate 12
//preenchendo primeiro a primeira linha, depois a segunda e depois a terceira.
int main() {
    int t, i, M[3][4];                      //cria os indices de controle da matriz e a matriz com duas dimensoes
    for (t=0; t<3; ++t)                     //percorre as linhas da matriz
        for (i=0; i<4; ++i)                 //percorre as colunas da matriz
            M[t][i] = (t*4)+i+1;            //preenche a matriz com valores, preenchendo primeiro todas as colunas da linha 1, depois todas as colunas da linha 2 e depois todas as colunas da linha 3
    for (t=0; t<3; ++t) {
        for (i=0; i<4; ++i)
            printf("%3d ", M[t][i]);        //imprime os valores dos elementos da matriz utilizando 3 digitod
        printf("\n");
    }
    return 0;
}
