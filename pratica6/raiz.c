//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para obter a raiz de um float
float raiz(float num){
   float margem = 0.01, y = 1.0;
   
   while(1){
      float diferenca = y * y - num;

      if(diferenca > margem){
         y *= 0.99;
      }
      else if(diferenca < -margem){
         y *= 1.01;
      }
      else break;
   }
   return y;
 }

//funcao main
int main(int argc, char const *argv[])
{
	printf("%f\n",raiz(9));

	//encerra programa
	return SUCESSO;
}