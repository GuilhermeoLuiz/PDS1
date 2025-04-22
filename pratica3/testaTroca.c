#define SUCESSO 0
#include <stdio.h>

//funcao para troca valores de float
void troca(float* end_valor_1, float* end_valor_2){
    float a = *end_valor_1;
    *end_valor_1 = *end_valor_2;
    *end_valor_2 = a;
}

void testaTroca(float* x, float* y){
    troca(x,y);
    printf("%.4f\n%.4f\n",*x, *y);
}

//funcao main
int main(int argc, char* argv[]){

    //declara variaveis e atribui valor
    float x = 1.77, y = 2.75;
    float* v1 = &x;
    float* v2 = &y;

    //chama funcao
    testaTroca(v1, v2);

    //encerra programa
    return SUCESSO;
}