#include <stdio.h>
#include<string.h>

void lervetor(int *vet, int dimensao){
    printf("Informe %d numeros inteiros\n", dimensao);
    for (int i=0; i<dimensao; i++){
        printf("Informe o %do. numero: ", i+1);
        scanf(" %d", vet);
        vet++;
    }

    return;
}

int main(){
    int a[5];
    lervetor(a, 5);
    printf("\n\nO vetor digitado eh:\n");

    for (int i=0; i<5; i++){
        printf("%d\n", a[i]);
    }
    return(0);
}
