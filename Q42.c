#include<stdio.h>
#include <math.h>

struct Ponto{
    int x;
    int y;
};

void main(){
    struct Ponto p1, p2;
    float d;

    printf("   Calculo da distancia entre dois pontos\n");
    printf("============================================\n");
    printf("\nPONTO 1\n");
    printf("     Informe o valor da coordenada x: ");
    fflush(stdin);
    scanf("%d", &p1.x);
    printf("     Informe o valor da coordenada y: ");
    fflush(stdin);
    scanf("%d", &p1.y);

    printf("\nPONTO 2\n");
    printf("     Informe o valor da coordenada x: ");
    fflush(stdin);
    scanf("%d", &p2.x);
    printf("     Informe o valor da coordenada y: ");
    fflush(stdin);
    scanf("%d", &p2.y);

    d = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

    printf("\n============================================\n");
    printf("A distancia entre os dois pontos eh %f\n\n\n", d);

    return;
}
