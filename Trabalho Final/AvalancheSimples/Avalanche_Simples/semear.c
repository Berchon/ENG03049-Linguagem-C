#include <stdio.h>

int semear(int Y, int X, int **matrix){//[Y][X]){
    int i = sorteio(Y);
    int j = sorteio(X);

    int ocorrencias = 0;

    matrix[i][j]++;
    imprime(j,i, matrix[i][j]);
    if (matrix[i][j] == 5){
        ocorrencias = avalanche(Y, X, matrix, i, j, 0);
    }
    return (ocorrencias);
}
