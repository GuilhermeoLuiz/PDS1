//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para obter o maior int
int maior(int a, int b){

	//guarda um inteiro e verifica se ha outro maior
	int maior = a;
	if (maior < b){
		maior = b;
	}

	//encerra funcao e retorna maior inteiro
	return maior;
}

//funcao main
int main(int argc, char* argv[]){

    //declara variavel e chama funcao maior
    printf("%d\n", maior(-99,-3));

    //encerra programa
    return SUCESSO;
}