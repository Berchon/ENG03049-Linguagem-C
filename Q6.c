#include<stdio.h>


void main(){
    //declaracao de variaveis
    int x,y,z;
    x=y=10;
    z=++x;//incrementa 1 em x e grava em z.                           z=11  x=11
    x=-x;//muda o sinal de x.                                         x=-11
    y++;//incrementa 1 em y.                                          y=11
    x=x+y-(z--);//faz x+y-z e grava em x e depois decrementa 1 em z.  x=-11 y=11 z=10
}
