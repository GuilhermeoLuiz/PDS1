//biblioteca e definicao
#define SUCESSO 0
#include <stdio.h>

//imprime a classificacao da infracao
void infracao(int velVia, int velAut){
	if(velAut <= velVia){
		printf("Sem infracao\n");
	}
	else if(velAut <= (velVia * 1.2)){
		printf("Infracao media\n");
	}
	else if(velAut <= (velVia * 1.5)){
		printf("Infracao grave\n");
	}
	else if(velAut > (velVia * 1.5)){
		printf("Infracao gravissima\n");
	}
}

//funcao main
int main(int argc, char const *argv[]){

	//obtem valores para o radar e chama funcao da infracao
	int velVia, velAut;
	printf("Digite a velocidade maxima da via: ");
	scanf("%d", &velVia);
	printf("Digite a velocidade do automovel: ");
	scanf("%d", &velAut);
	infracao(velVia, velAut);

	//encerra programa
	return SUCESSO;
}