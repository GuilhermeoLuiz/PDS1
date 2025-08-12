//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para obter maior e menor numero
void alturas(){

   int maior, menor, altura, i = 1, n = 15;

   printf("Digite a altura %d: ",i);
   scanf("%d", &altura);
   maior = altura;
   menor = altura;
      
   while (i < n)
   {  
      i++;
      printf("Digite a altura %d: ",i);
      scanf("%d", &altura);
      if(altura > maior) maior = altura;
      if (altura < menor) menor = altura;
   }
   printf("Maior: %d\nMenor: %d\n",maior, menor);
  
}

//funcao main
int main(int argc, char const *argv[])
{
	alturas();

	//encerra programa
	return SUCESSO;
}