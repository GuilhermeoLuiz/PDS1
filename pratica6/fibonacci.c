//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para calcular fibonacci n
int fibonacci(int n) {
    
   if ((n > 0) && (n <= 30)){
      int soma = 1, temp = 1;

      for(int i = 3; i <= n; i++){
        soma = temp + soma;
        temp = soma - temp;
      }

      return soma;
   }
   else return -1;
}

//funcao main
int main(int argc, char const *argv[])
{

	printf("%d\n", fibonacci(10));

	//encerra programa
	return SUCESSO;
}