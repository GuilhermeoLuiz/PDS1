#define SUCESSO 0
#include <stdio.h>

//funcao para retornar apenas a parte inteira de um numero
float parteInteira(float x){
	return (float)(int)x;
}

int main(int argc, char const *argv[])
{
	printf("%.1f\n",parteInteira(-3.141592));
	return SUCESSO;
}