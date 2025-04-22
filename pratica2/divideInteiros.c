#define SUCESSO 0
#include <stdio.h>

//funcao para retornar apenas a parte fracionaria de um numero
float divInts(int x, int y){
	return (float)x/y;
}

int main(int argc, char const *argv[])
{
	printf("%f\n",divInts(5,4));
	return SUCESSO;
}