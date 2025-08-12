//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao que inverte os digitos de um numero inteiro
unsigned int inverte(unsigned int num){
   unsigned int oposto = 0;

   //obtem digito na ordem inversa e adiciona os a ultima posicao
   while(num > 0){
      oposto = oposto * 10 + (num % 10);
      num = num / 10;
   }

   return oposto;
}

//funcao main
int main(int argc, char const *argv[])
{
   //chama funcao e passa parametro
	printf("%u\n", inverte(1234));
	//encerra programa
	return SUCESSO;
}