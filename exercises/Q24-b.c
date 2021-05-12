#include <stdio.h>

int main() {
    int x, *p;
    x = 10;

    //Faltou o & para atribuir para p o endereco de x
    p = &x;
    printf("%d", *p);
}
