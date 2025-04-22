#define SUCESSO 0
#include <stdio.h>

//funcao para retornar apenas a parte fracionaria de um numero
float parteFracionaria(float x){
	return x - (int)x;
}

int main(int argc, char const *argv[])
{
	printf("%f\n",parteFracionaria(-3.141592));
	return SUCESSO;
}