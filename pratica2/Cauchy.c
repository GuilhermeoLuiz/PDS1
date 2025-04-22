#define SUCESSO 0
#include <stdio.h>
#include <math.h>

//funcao para realizar o calculo de Cauchy
float cauchy(float x){
    float funcao;
    funcao = (1/(M_PI*(1+(pow(x,2.0)))));
    return funcao;
}

//funcao main
int main(int argc, char const *argv[])
{
    //chama funcao e imprime valor
    printf("%f\n", cauchy(1));
    return SUCESSO;
}