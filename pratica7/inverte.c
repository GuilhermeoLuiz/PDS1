//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <string.h>

//funcao para inverter uma string
void inverte(char* s){

   int i, tam;
   char temp[50+1];
   s[strcspn(s, "\n")] = '\0';
   tam = strlen(s);  
   strcpy(temp, s);

   for(i = 0; i < tam; i++){
      s[i] = temp[tam -(i+1)];
   }
   s[i] = '\0';
}

//funcao main
int main(int argc, char const *argv[])
{
	char s[50+1];

   // printf("Digite uma frase com ate 50 caracteres.\n");
   fgets(s, 50+1, stdin);
   // printf("%u\n", contaPalavras(s));
   inverte(s);
   printf("%s\n", s);

	//encerra programa
	return SUCESSO;
}