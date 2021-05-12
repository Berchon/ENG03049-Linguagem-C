#include <stdio.h>

int avalanche(int Y, int X, int **matrix, int posicao_y, int posicao_x, int recursividade){
    static ocorrencias=1;
    if (recursividade==1){
        ocorrencias ++;
    }
    else if (recursividade == 2){
        //não faz nada
    }
    else{
        ocorrencias = 1;
    }
    matrix[posicao_y][posicao_x] = 0;
    imprime(posicao_x,posicao_y, matrix[posicao_y][posicao_x]);

    //Avalanche para cima
    if (posicao_y-1>= 0){
        matrix[posicao_y-1][posicao_x]++;
        imprime(posicao_x,posicao_y-1, matrix[posicao_y-1][posicao_x]);
        if (matrix[posicao_y-1][posicao_x] == 5){
            avalanche(Y, X, matrix, posicao_y-1, posicao_x, 1);
        }
    }
    else{
        //O grão de areia sai do domínio
    }

    //Avalanche para baixo
    if (posicao_y+1< Y){
        matrix[posicao_y+1][posicao_x]++;
        imprime(posicao_x,posicao_y+1, matrix[posicao_y+1][posicao_x]);
        if (matrix[posicao_y+1][posicao_x] == 5){
            avalanche(Y, X, matrix, posicao_y+1, posicao_x, 2);
        }
    }
    else{
        //O grão de areia sai do domínio
    }

    //Avalanche para direita
    if (posicao_x+1< X){
        matrix[posicao_y][posicao_x+1]++;
        imprime(posicao_x+1,posicao_y, matrix[posicao_y][posicao_x+1]);
        if (matrix[posicao_y][posicao_x+1] == 5){
            avalanche(Y, X, matrix, posicao_y, posicao_x+1, 2);
        }
    }
    else{
        //O grão de areia sai do domínio
    }

    //Avalanche para esquerda
    if (posicao_x-1>= 0){
        matrix[posicao_y][posicao_x-1]++;
        imprime(posicao_x-1,posicao_y, matrix[posicao_y][posicao_x-1]);
        if (matrix[posicao_y][posicao_x-1] == 5){
            avalanche(Y, X, matrix, posicao_y, posicao_x-1, 2);
        }
    }
    else{
        //O grão de areia sai do domínio
    }
    return (ocorrencias);
}
