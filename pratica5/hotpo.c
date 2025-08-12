//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao hotpo
int hotpo(unsigned int n)
 {
    if((n % 2) == 0){
    	n /= 2;
    }
    else if ((n % 2) != 0){
    	n = n * 3 + 1;
    }
    else printf("Erro inesperado!!");

    return n;
}

//funcao main
int main(int argc, char const *argv[])
{
	int unsigned x = 7, y = 2;

	printf("%u %u\n", hotpo(x), hotpo(y));

	//encerra programa
	return SUCESSO;
}