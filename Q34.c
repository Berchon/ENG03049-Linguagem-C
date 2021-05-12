#include <stdio.h>

int fibonacci(int a, int b, int n){
    int result;
    for (int i=1; i<=n; i++){
        if (i==n){

        }
        else{
            result = (fibonacci(b, a+b, 1));
            a=b;
            b=result;
        }

    }
    return (b);
}

int main(){
    int a, b, n, resultado;
    printf("Informe um numero inteiro valido (Primeiro elemento da serie de Fibonacci): ");
    scanf(" %d", &a);
    printf("Informe um numero inteiro valido (Segundo elemento da serie de Fibonacci): ");
    scanf(" %d", &b);

    printf("Informe o numero de termos que deseja calcular: ");
    scanf(" %d", &n);

    resultado = fibonacci(a, b, n-1);

    printf("\n\nO %d-esimo termo da serie de Fibonacci eh %d", n, resultado);

    return(0);
}
