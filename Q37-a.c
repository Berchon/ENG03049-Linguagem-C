#include<stdio.h>

#define I 3
#define J 3
int main(){
    int a[I][J];

    for (int i=0; i<I; i++){
        for (int j=0; j<J; j++){
            printf("a[%d][%d]=", i+1, j+1);
            scanf(" %d", &a[i][j]);
        }
    }
    //imprimindo a matriz de numeros inteiros
    for (int i=0; i<I; i++){
        for (int j=0; j<J; j++){
            printf("%5d\t\t", a[i][j]);
            //printf("\t\t");
        }
        printf("\n");
    }
    //imprimindo os enderecos hexadecimais da matriz
    printf("\n");
    for (int i=0; i<I; i++){
        for (int j=0; j<J; j++){
            printf("%x\t\t", &a[i][j]);
            //printf("\t\t");
        }
        printf("\n");
    }
}
