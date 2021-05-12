#include<stdio.h>
#include<stdlib.h>

//************************************************************************************
//***  Testes que nao funcionaram
//***  Nao consigo determinar o tamanhodo array passado por ponteiro para uma funcao
//************************************************************************************
#define ARRAYSIZE(ar) (sizeof(ar) / sizeof(ar[0]))
#define SIZEOF(Var) ((char*)(&Var + 1) -(char*)&Var)

void tamanhoVetor(int *D){
    //Nao funcionou
    int iTotalElement;
    iTotalElement = *(&D + 1) - D;

    printf("Number of element = %d %d\n",*(&D + 1), D);

 return 0;
}

void teste(float **A, float **B, float **C){

    int row = sizeof(*A) / sizeof(**A);
int column = sizeof(A[0])/row;

printf("Sizeof(A): %d\n", (int) sizeof(**A));
printf("Sizeof(A[0]): %d\n", sizeof(*A[0]));
printf("Number of rows: %d\n", SIZEOF(A)/SIZEOF(A[0]));
printf("Number of columns: %d\n", ARRAYSIZE(A));
    return(C);
}
//************************************************************************************


int dimensao(int a){
    int valor;
    do{
        printf("Informe o numero de linhas da Matriz %d: ", a);
        fflush(stdin);
        scanf("%d", &valor);
        if (valor<1){
            printf("Atencao! Voce deve informar um numero inteiro maior que zero.\n");
        }
    } while(valor<1);
    return(valor);
}

float preenche(int i, int j){
    float valor;

    printf("Informe o valor do elemento [%d][%d]: ", i,j);
    fflush(stdin);
    scanf("%f", &valor);

    return(valor);
}

void imprime(float ** Matriz, int a, int i1, int j1){
    printf("\nMatriz %d\n", a);
    for (int i=0; i<i1; i++){
        for (int j=0; j<j1; j++){
            printf("%9.2f ", Matriz[i][j]);
        }
        printf("\n");
    }
    return;
}

void multiplica(float **A, float **B, float **C, int lin, int col, int dim_comum){

    for (int i=0; i<lin; i++){
        for (int j=0; j<col; j++){
            for (int k=0; k<dim_comum; k++){
                C[i][j] = C[i][j] + A[i][k]*B[k][j];
            }
        }
    }
}

void main(){
    int i1, j1, i2, j2;
    float **A, **B, **C;
    int iTotalElement;

    printf("          MULTIPICACAO DE MATRIZES\n");
    printf("==============================================\n");

    i1 = dimensao(1);
    j1 = dimensao(1);
    do{
        i2 = dimensao(2);
        if (i2 != j1){
            printf("Atencao! O numero de colunas da Matriz 1 deve ser igual ao numero de linhas da Matriz 2.\n");
        }
    } while(i2 != j1);
    j2 = dimensao(2);

    A = (float **)malloc(i1 * sizeof(float*));
    if (!A){
        printf("** Erro: Memoria Insuficiente **");
        exit;
    }
    for (int i=0; i<i1; i++){
        A[i] = (float *)malloc(j1 * sizeof(float));
        if (!A[i]){
            printf("** Erro: Memoria Insuficiente **");
            exit;
        }
    }

    B = (float **)malloc(i2 * sizeof(float*));
    if (!B){
        printf("** Erro: Memoria Insuficiente **");
        exit;
    }
    for (int i=0; i<i2; i++){
        B[i] = (float *)malloc(j2 * sizeof(float));
        if (!B[i]){
            printf("** Erro: Memoria Insuficiente **");
            exit;
        }
    }


    C = (float **)malloc(i1 * sizeof(float*));
    if (!C){
        printf("** Erro: Memoria Insuficiente **");
        exit;
    }
    for (int i=0; i<i1; i++){
        C[i] = (float *)malloc(j2 * sizeof(float));
        if (!C[i]){
            printf("** Erro: Memoria Insuficiente **");
            exit;
        }
    }

    printf("\nInforme os elementos da Matriz 1\n");
    for (int i=0; i<i1; i++){
        for (int j=0; j<j1; j++){
            A[i][j] = preenche(i,j);
        }
    }

     printf("\nInforme os elementos da Matriz 2\n");
    for (int i=0; i<i2; i++){
        for (int j=0; j<j2; j++){
            B[i][j] = preenche(i,j);
        }
    }

    multiplica(A, B, C, i1, j2, j1);

    imprime(A, 1, i1, j1);
    imprime(B, 2, i2, j2);
    imprime(C, 3, i1, j2);


}
