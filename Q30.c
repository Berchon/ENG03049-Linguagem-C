#include <stdio.h>

int impar(int n){
    if (n%2){
        return(1);
    }
    else{
        return(0);
    }
}

int main(){
    if(impar(24)){
        printf("O numero eh impar");
    }
    else{
        printf("O numero eh par");
    }

    return(0);
}
