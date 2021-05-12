#include<stdio.h>

int main(){
    float f;
    printf("Celsius\t\t| Fahrenheit\n");
    printf("===============================\n");
    for(int i=-100; i<=100; i=i+10){
        f = 9/5*i + 32;
        printf("\t%3d\t|\t%.2f\n", i, f);
    }
}
