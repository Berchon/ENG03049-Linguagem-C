#include<stdio.h>

#define I 3
#define J 3
int main(){
    double a[I][J];

    for (int i=0; i<I; i++){
        for (int j=0; j<J; j++){
            printf("a[%d][%d]=", i+1, j+1);
            scanf(" %lf", &a[i][j]);
        }
    }
    //imprimindo a matriz de numeros double
    printf("\n");
    for (int i=0; i<I; i++){
        for (int j=0; j<J; j++){
            printf("%15.3f\t\t\t", a[i][j]);
        }
        printf("\n");
    }
}
