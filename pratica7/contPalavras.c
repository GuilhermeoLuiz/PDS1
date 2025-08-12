//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <string.h>

//funcao para contar quantidade de palavras em uma string
unsigned  contaPalavras(char* s){
   unsigned soma = 0;
   
   if(strlen(s) != 1){
      soma++;
      for(int i = 0; i < (strlen(s)); i++)
      {
         if(s[i] == ' ')
            {
               soma++;
            }

      }
   }
   //finaliza funcao
   return soma;
}

//funcao main
int main(int argc, char const *argv[])
{
	char s[50+1];

   printf("Digite uma frase com ate 50 caracteres.\n");
   fgets(s, 50+1, stdin);
   printf("%u\n", contaPalavras(s));

	//encerra programa
	return SUCESSO;
}