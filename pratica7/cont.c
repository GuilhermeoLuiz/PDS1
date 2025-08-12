//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <string.h>

//funcao para contar os caracteres validos de uma string
int contacarateresalfa(char* str, int tam){
   
   int num = 0;
   for(int i = 0; i < tam; i++){
      if(((str[i] >= 65) && (str[i] <= 90)) || ((str[i] >= 97) && (str[i] <= 122)) || ((str[i] >= 48) && (str[i] <= 57)))
      {  
         num++;
      }
   }

   return num;
}

//funcao main
int main(int argc, char const *argv[])
{
	char str[19] = "Ola, mundo! 123 :)";
   int tam = strlen(str);
   printf("%d\n", contacarateresalfa(str, tam));
   // printf("%d\n", str[1]);

	//encerra programa
	return SUCESSO;
}