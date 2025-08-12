//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para obter a soma dos digitos pares de um numero
int soma_digitos_pares(unsigned num){
   //cria variaveis e atribui valores
   int soma = 0, digito;

   //laco para obter os digitos e somar se for par
   while(num > 0){
      digito = num % 10;
      if((digito % 2) == 0){
         soma += digito;
      }
      num /= 10;
   }

   //finaliza funcao
   return soma;
}

//funcao main
int main(int argc, char const *argv[])
{
	printf("%d\n", soma_digitos_pares(8887));

	//encerra programa
	return SUCESSO;
}