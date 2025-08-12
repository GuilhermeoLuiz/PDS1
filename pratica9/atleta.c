//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <string.h>
#define NUMATLETAS 5

//estrutura para atleta
typedef struct{
	char nome[16];
	char esporte[16];
	int idade;
	float altura;
} atleta;

//imprime nome do atleta maior atleta
void maiorAtleta(atleta atl1, atleta atl2, atleta atl3, atleta atl4, atleta atl5)
{
	char nomeAtletas[NUMATLETAS][16];
	strcpy(nomeAtletas[0],atl1.nome);
	strcpy(nomeAtletas[1],atl2.nome);
	strcpy(nomeAtletas[2],atl3.nome);
	strcpy(nomeAtletas[3],atl4.nome);
	strcpy(nomeAtletas[4],atl5.nome);
	
	float alturaAtl[NUMATLETAS];
	alturaAtl[0] = atl1.altura;
	alturaAtl[1] = atl2.altura;
	alturaAtl[2] = atl3.altura;
	alturaAtl[3] = atl4.altura;
	alturaAtl[4] = atl5.altura;

	float maiorAlt = alturaAtl[0];
	int index = 0;
	for (int i = 1; i < NUMATLETAS; ++i)
	{
		if(alturaAtl[i] > maiorAlt)
		{
			maiorAlt = alturaAtl[i];
			index = i;
		}
	}
	printf("Mais alto: %s\n",nomeAtletas[index]);

	int idadeAtletas[NUMATLETAS];
	idadeAtletas[0] = atl1.idade;
	idadeAtletas[1] = atl2.idade;
	idadeAtletas[2] = atl3.idade;
	idadeAtletas[3] = atl4.idade;
	idadeAtletas[4] = atl5.idade;

	int maior = idadeAtletas[0];
	index = 0;
	for (int i = 1; i < NUMATLETAS; ++i)
	{
		if(idadeAtletas[i] > maior)
		{
			maior = idadeAtletas[i];
			index = i;
		}
	}
	printf("Mais velho: %s\n",nomeAtletas[index]);
}

//funcao main
int main(int argc, char* argv[])
{
	atleta atl1, atl2, atl3, atl4, atl5;
	scanf(" %15s %15s %d %f", atl1.nome, atl1.esporte, &atl1.idade, &atl1.altura);
	scanf(" %15s %15s %d %f", atl2.nome, atl2.esporte, &atl2.idade, &atl2.altura);
	scanf(" %15s %15s %d %f", atl3.nome, atl3.esporte, &atl3.idade, &atl3.altura);
	scanf(" %15s %15s %d %f", atl4.nome, atl4.esporte, &atl4.idade, &atl4.altura);
	scanf(" %15s %15s %d %f", atl5.nome, atl5.esporte, &atl5.idade, &atl5.altura);

    //chama funcao para comparar
	maiorAtleta(atl1, atl2, atl3, atl4, atl5);

    //encerra codigo
	return SUCESSO;
}