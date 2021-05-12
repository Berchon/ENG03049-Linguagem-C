#define max(A,B) ((A>B) ? (A):(B))
#define min(A,B) ((A<B) ? (A):(B))
#define sqr(x) x*x                  // deve-se colocar parenteses para evitar o erro da linha 13. #define sqr(x) (x)*(x)
int main() {
    int a = 10 ,b = 50, minimo, maximo, quad;
    int z = 5;
    printf("%d %d\n", a, b);
    minimo = min(a,b);              // tudo certo. minimo = 10
    printf("%d\n", minimo);
    maximo = max(a++,b++);          // a eh incrementado uma vez, entretanto b eh incrementado duas vezes. Uma vez na comparacao e outra no resultado do teste
    printf("%d %d\n", a, b);
    printf("%d\n", maximo);         //
    quad = sqr(z+1);                // quad = z+1*z+1 e deveria ser (z+1) * (z+1)

    return 0;
}
