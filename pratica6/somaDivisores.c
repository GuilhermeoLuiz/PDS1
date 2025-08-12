//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <math.h>

//funcao para somar os divisores de n
unsigned soma_divisores(unsigned n){

   unsigned soma = 0;
   if(n > 1){
      for(int i = 1; i <= n; i++){
         if((n % i) == 0){
            soma += i;
            printf("%u\n", soma);
         }
      }
   }

   return soma + n;
}

//funcao main
int main(int argc, char const *argv[])
{
	printf("%u\n",soma_divisores(10));

	//encerra programa
	return SUCESSO;
}