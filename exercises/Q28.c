#include <stdio.h>

void zerar(int *a, int *b){
    *a = 0;
    *b = 0;
    return;
}

int main(){
    int a=5, b=8;
    zerar(&a, &b);

    printf("a=%d b=%d", a, b);
    return(0);
}
