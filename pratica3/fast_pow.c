//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//eleva 2 ao expoente dado
unsigned long long int fast_pow_2(int expoente){
	return 1ULL << expoente;;
}

//funcao main
int main(int argc, char const *argv[])
{	
	//define expoente e chama funcao
	int expoente = 4096;
	printf("%llu\n", fast_pow_2(expoente));

	//encerra programa
	return SUCESSO;
}