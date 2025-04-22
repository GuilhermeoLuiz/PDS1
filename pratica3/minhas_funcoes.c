//bibliotecas
#include "minhas_funcoes.h"
#include <stdio.h>
#include <math.h>

//funcao para somar 1 a um inteiro qualquer
void soma1(int* p){
    (*p)++;
}

//funcao para troca valores de float
void troca(float* end_valor_1, float* end_valor_2){
    float a = *end_valor_1;
    *end_valor_1 = *end_valor_2;
    *end_valor_2 = a;
    printf("a:%f\nb:%f\n", *end_valor_1, *end_valor_2);
}

//retorna o dd de um numero de 11 digitos
int ddd(long long int num){
    return num / pow(10,9);
}