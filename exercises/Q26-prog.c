#include <stdio.h>
#include "Q26-func.h"

int main(){

    int a=7, b=2;
    int boolean;
    boolean = EDivisivel(a,b);
    if (boolean){
        printf("a eh divisivel por b");
    }
    else{
        printf("%d nao eh divisivel por %d", a, b);
    }
    return(0);
}
