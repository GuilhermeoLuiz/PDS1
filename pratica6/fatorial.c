//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para obter fatorial de n
unsigned long long fatorial(int n){

   unsigned long long fat;
   if (n >= 0){
      fat = 1;
      for(int i = 1; i <= n; i++){
         fat *= i;
      }
   }else return -1;

   return fat;
}

//funcao main
int main(int argc, char const *argv[])
{
	printf("%llu\n", fatorial(5));

	//encerra programa
	return SUCESSO;
}