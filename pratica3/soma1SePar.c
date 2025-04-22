//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para somar 1 ao numero par
unsigned int soma1SePar(unsigned int number){
	return number+= ((number % 2) ^ 1);
}

//funcao main
int main(int argc, char const *argv[])
{	
	//declara variavel e chama funcao
	unsigned int number = 8;
	printf("%u\n", soma1SePar(number));

	//encerra programa
	return SUCESSO;
}