//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para verificar se e par ou impar
int parOuImpar(unsigned int number){
	return ((number % 2) ^ 1);
}

//funcao main
int main(int argc, char const *argv[])
{	
	//declara variavel e chama funcao
	unsigned int number = 2;
	printf("%u\n", parOuImpar(number));

	//encerra programa
	return SUCESSO;
}