//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <string.h>

//funcao para contar as ocorrencias de um char
int contaocorrencias(char* str, size_t tam, char caracter){
   int soma = 0;

   if(str == NULL)
      return - 1;
   else
   {
      for(size_t i = 0; i < tam; i++){
         if(str[i] == caracter){
            soma++;
         }
      }
   }  

   return soma;
}

//funcao main
int main(int argc, char const *argv[])
{
	char s[50+1];
   printf("Digite uma frase com ate 50 caracteres.\n");
   fgets(s, 50+1, stdin);
   size_t tam = strlen(s);
   char caracter;
   printf("Digite o caracter a ser contabilizado na string.\n");
   scanf(" %c", &caracter);
   
   printf("%d\n", contaocorrencias(s, tam, caracter));

	//encerra programa
	return SUCESSO;
}