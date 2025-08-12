//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <math.h>

//funcao para calcular o mdc de dois inteiros
int mdc(int a, int b){
   //cria variavel e obtem modulo dos numeros
   int mdc;
   a = fabs(a);
   b = fabs(b);

   //identifica maior em a e menor em b
   if(a < b){
      int menor = b;
      b = a;
      a = menor;
   }

   //verifica se ha algum numero invalido
   if(a == 0 || b == 0){
      return -1;
   }
   //verifica sem o menor e divisor do maior
   else if ((a % b) == 0){
      mdc = b;
   }
   //obtem mdc dos outros casos possiveis 
   else if((a % b) != 0){
      for (int i = b/2; i > 0; i--)
      {
         if(((a%i) == 0) && ((b%i) == 0)) {
            mdc = i;
            break;
         }
      }
   }
   //trata erro
   else return -1;

   //finaliza funcao
   return mdc;
}

//funcao main
int main(int argc, char const *argv[])
{
   //chama funcao e imprime retorno
   printf("%d\n", mdc(14,24));
	//encerra programa
	return SUCESSO;
}