#include <stdio.h>

int main() {
    int x, *p;

    //o ponteiro p nao aponta para endereco algum
    int y=5;
    p=&y;

    x = 10;
    *p = x;

    printf("%d", y);
}
