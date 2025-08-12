//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para obter tempo da igualdade de populacao
int populacao(unsigned long popA, double taxaA, unsigned long popB, double taxaB){

   int tempo = 0;
   while(popA < popB){
      popA *= (1 + (taxaA/100));
      popB *= (1 + (taxaB/100));
      tempo++;
   }
   
   return tempo;
}


//funcao main
int main(int argc, char const *argv[])
{

   printf("%d\n", populacao(1,100,6,50));
	//encerra programa
	return SUCESSO;
}