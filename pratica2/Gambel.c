#define SUCESSO 0
#include <stdio.h>
#include <math.h>

//funcao para realizar o calculo de Gumbel
float gumbel(float x, float y, float z){
    float resultado = (1/z) * (exp(-(((x-y)/z) + exp((-((x-y)/z))))));
    return resultado;
}

//funcao main
int main(int argc, char const *argv[])
{
    //chama funcao e imprime valor
    printf("%f\n", gumbel(1,1,1));
    return SUCESSO;
}