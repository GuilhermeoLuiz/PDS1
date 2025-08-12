//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para verificar se n e primo
int primo(int n){
   int primo = 0;

   if(n > 1){
      primo = 1;
      for(int i = 2; i <= n/2; i++){
         if((n % i) == 0){
            primo = 0;
            break;
         }
      }
   }

   return primo;
}

//funcao main
int main(int argc, char const *argv[])
{

	printf("%d\n", primo(2));

	//encerra programa
	return SUCESSO;
}