//biblioteca e definicao
#define SUCESSO 0
#include <stdio.h>
#include <ctype.h>

//funcao para calcular se esta apto a aposentar
void aposentar(int idade, int tempCtb, char sexo){

	sexo = toupper(sexo);

	if(sexo == 'F'){
		if(((idade >= 55) && (tempCtb >= 30)) || (idade >= 60)) printf("Pode aposentar\n");
		else printf("Nao pode aposentar\n");
	}
	else if(sexo == 'M'){
		if(((idade >= 60) && (tempCtb >= 35)) || (idade >= 65)) printf("Pode aposentar\n");
		else printf("Nao pode aposentar\n");
	}
	else printf("Sexo invalido");
}


//funcao main
int main(int argc, char const *argv[]){

	int idade, tempCtb;
	char sexo;

	printf("Hello usuario, vamos descobrir se esta pronto para aposentar\n");
	printf("Digite sua idade: ");
	scanf("%d", &idade);
	printf("Digite seu tempo de contribuicao: ");
	scanf("%d", &tempCtb);
	printf("(F) Feminino - (M) Masculino \nDigite seu sexo: ");
	scanf(" %c", &sexo);
	aposentar(idade, tempCtb, sexo);


	//encerra programa
	return SUCESSO;
}