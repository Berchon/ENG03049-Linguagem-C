#include <stdio.h>

int fibonacci(int a, int b){
    return (a+b);
}

int main(){
    int a, b, n, resultado;
    printf("Informe um numero inteiro válido (Primeiro elemento da serie de Fibonacci): ");
    scanf(" %d", &a);
    printf("Informe um numero inteiro válido (Segundo elemento da serie de Fibonacci): ");
    scanf(" %d", &b);

    printf("Informe o numero de termos que deseja calcular: ");
    scanf(" %d", &n);
    //n-=2;
    for (int i=0; i<n-2; i++){
        resultado = fibonacci(a, b);
        a=b;
        b=resultado;
    }
    printf("\n\nO %d-esimo termo da serie de Fibonacci eh %d", n, b);

    return(0);
}
