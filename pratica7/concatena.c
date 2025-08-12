//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <string.h>

//funcao para contar strings
void concatena(char* a, int tamA, char* b, int tamB, char* s){
   s = strcat(a,b);   
   printf("%s\n",s );
}

//funcao main
int main(int argc, char const *argv[])
{
	char a[] = "pay", b[] = "day";
   int tamA = strlen(a), tamB = strlen(b);
   char s[tamA + tamB -1];
   concatena(a, tamA, b, tamB, s);

	//encerra programa
	return SUCESSO;
}