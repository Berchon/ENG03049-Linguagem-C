#include <stdio.h>
#include <stdlib.h>


void main(){
    int a[2][3]={};
    int **b, lin=20, col=20;


    b = (int **)calloc(lin, sizeof(int*));
    for (int i=0; i<lin; i++){
        b[i] = (int *)calloc(col, sizeof(int));
    }

    for (int i=0; i<lin; i++){
        for (int j=0;j<col;j++){
            b[i][j] = i+j;
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    //b[2][8]=3;

    for (int j=0;j<lin;j++){
        for (int i=0; i<col; i++){
            b[j][i]=0;
            printf("%2d  ", b[j][i]);
        }
        printf("\n");
    }
    printf("\naaaaaaaaaaaaaaa");
}

