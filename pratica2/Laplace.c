#define SUCESSO 0
#include <stdio.h>
#include <math.h>

//funcao para calcular a distribuicao de Laplace
float laplace(float x, float y, float b){
	float resultado = (1/(2*b)) * exp(-fabs(x-y)/b);
	return resultado;
}


//funcao main
int main(int argc, char const *argv[])
{
	printf("%f", laplace(-6,-5,-4));
	//0.0974
	return 0;
}