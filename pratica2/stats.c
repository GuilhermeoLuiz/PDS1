#include "stats.h"
#include <stdio.h>
#include <math.h>

//funcao para calcular a distribuicao de Laplace
float laplace(float x, float y, float b){
	float resultado = (1/(2*b)) * exp(-fabs(x-y)/b);
	return resultado;
}

//funcao para realizar o calculo de Gumbel
float gumbel(float x, float y, float z){
    float resultado = (1/z) * (exp(-(((x-y)/z) + exp((-((x-y)/z))))));
    return resultado;
}

//funcao para realizar o calculo de Cauchy
float cauchy(float x){
    float funcao;
    funcao = (1/(M_PI*(1+(pow(x,2.0)))));
    return funcao;
}