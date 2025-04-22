#define SUCESSO 0
#include <stdio.h>

//funcao para troca valores de float
void troca(float* end_valor_1, float* end_valor_2){
    float a = *end_valor_1;
    *end_valor_1 = *end_valor_2;
    *end_valor_2 = a;
    printf("a:%f\nb:%f\n", *end_valor_1, *end_valor_2);
}

//funcao main
int main(int argc, char* argv[]){

    //declara variaveis e atribui valor
    float x = 1.77, y = 2.75;
    float* v1 = &x;
    float* v2 = &y;

    //chama funcao
    troca(v1, v2);

    //encerra programa
    return SUCESSO;
}