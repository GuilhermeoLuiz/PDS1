//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para verificar se e par ou impar
void par_ou_impar(int num){
	if (num > 0){
		if((num % 2) == 0){
			printf("%d e par.\n", num);
		}
		else if((num % 2) != 0){
			printf("%d e impar.\n", num);
		}
	}
	else if (num <= 0){
		printf("ERRO: numero invalido.\n");
	}
}

//funcao main
int main(int argc, char* argv[]){

    //declara variavel e chama funcao par_ou_impar
    float num = 0;
    par_ou_impar(num);

    //encerra programa
    return SUCESSO;
}