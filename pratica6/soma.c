//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para somar n inteiros
int soma(int n){
   int soma = 0;
   for(int i = 1; i <= n; i++){
      soma += i;
   }

   return soma;
}

//funcao main
int main(int argc, char const *argv[])
{

	printf("%d\n", soma(10));

	//encerra programa
	return SUCESSO;
}