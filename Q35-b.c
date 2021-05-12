#define max(A,B) ((A>B) ? (A):(B))
#define min(A,B) ((A<B) ? (A):(B))
#define sqr(x) x*x                  // deve-se colocar parenteses para evitar o erro da linha 13. #define sqr(x) (x)*(x)
int main() {
    float a = 10 ,b = 50, minimo, maximo, quad;
    int z = 5;
    printf("%f %f\n", a, b);
    minimo = min(a,b);              // tudo certo. minimo = 10
    printf("%f\n", minimo);
    maximo = max(a++,b++);          // a eh incrementado uma vez, entretanto b eh incrementado duas vezes. Uma vez na comparacao e outra no resultado do teste
    printf("%f %f\n", a, b);
    printf("%f\n", maximo);
    printf("%f\n", quad);
    quad = sqr(z+1);                // quad = z+1*z+1 e deveria ser (z+1) * (z+1)
    printf("%f\n", quad);

    return 0;
}
