#include <stdio.h>

#define N 100

int main() {
    int matriz[N][N], *p;
    p=matriz;

    for (int i=0; i<N*N; i++){
        *p = 0;
        p++;
    }

    p=matriz;

    for (int i=0; i<N*N; i++){
        *p = i+1;
        p++;
    }
    /*
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            //printf("%d\t", matriz[i][j]);
            printf("%5d ", matriz[i][j]);
        }
        printf("\n");
    }
    */
}
