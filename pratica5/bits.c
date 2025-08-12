//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <math.h>

//funcao para obter o DDD de um telefone
int codigoDeArea(unsigned int number) {
    return (int) (number/pow(10,8));
}

//funcao para retornar impar atual ou sucessor de par
int parEmImpar(unsigned int number) {
    number += (number%2)^1;
    return number;
}

//funcao para identificar numero par
int par(unsigned int number) {
    return ((number%2)^1);
}

//funcao main
int main(int argc, char const *argv[])
{
	printf("%d\n", codigoDeArea(3112345678));
	printf("%d\n", parEmImpar(6));
	printf("%d\n", par(2));

	//encerra programa
	return SUCESSO;
}