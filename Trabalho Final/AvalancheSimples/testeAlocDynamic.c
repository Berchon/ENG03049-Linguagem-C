#include <stdio.h>

void main(){
    int a[2][3]={};
    int **b, n=3;

    b = (int **)calloc(n, sizeof(int*));
    for (int i=0; i<n; i++){
        b[i] = (int )calloc(1, sizeof(int));
    }

    for (int i=0; i<2; i++){
        for (int j=0;j<3;j++){
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    b[2][8]=1;

    for (int j=0;j<3;j++){
        for (int i=0; i<3; i++){
            printf("%d  ", b[j][i]);
        }
        printf("\n");
    }
    printf("\naaaaaaaaaaaaaaa");
}
