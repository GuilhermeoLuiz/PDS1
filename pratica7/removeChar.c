//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <string.h>

//funcao para remover a primeira ocorrencia de um caracter
void removechar(char* str, size_t tam, char caracter){

   if(str != NULL)
   {
      for(size_t i = 0; i < tam; i++){
         if(str[i] == caracter){
            for(size_t j = i; j < tam; j++){
               str[j] = str[j+1];
            }
            break;
         }
      }
   }
}

//funcao main
int main(int argc, char const *argv[])
{
	char s[50+1];
   printf("Digite uma frase com ate 50 caracteres.\n");
   fgets(s, 50+1, stdin);
   size_t tam = strlen(s);
   char caracter;
   printf("Digite o caracter a ser removido da string.\n");
   scanf(" %c", &caracter);
   
   removechar(s, tam, caracter);

	//encerra programa
	return SUCESSO;
}