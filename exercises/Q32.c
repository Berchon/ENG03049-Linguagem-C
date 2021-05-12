#include <stdio.h>

int main(int argc, char *argv[]){
    int num1, num2;
    if (argc !=3){
        printf("Voce deve informar 2 argumentos de entrada!!!\n\n");
    }
    else{
        num1 = atoi(argv[1]);
        num2 = atoi(argv[2]);
        printf("A soma dos argumentos da chamada de entrada eh: %d", num1 + num2);
    }

    return(0);
}
