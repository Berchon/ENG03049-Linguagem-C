#include<stdio.h>
#include<math.h>

int main(){
    float angulo;
    char key='@';

    do{
        printf("Informe [0] para sair\n\n");
        printf("Informe um angulo em radianos: ");
        scanf(" %f", &angulo);
        printf("\n Sin(%f) = %f", angulo, sin(angulo));

        key=getch();
        system("cls");

    // OBS.: No meu PC testei o codigo e esta saindo com o zero mesmo 'angulo' sendo float
    } while (angulo!=0);

}
