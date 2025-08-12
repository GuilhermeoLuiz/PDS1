//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <string.h>
#define NUMATLETAS 5
#define MAX_NOME 15+1

//estrutura para atleta
typedef struct{
	char nome[MAX_NOME];
	char esporte[MAX_NOME];
	int idade;
	float altura;
} atleta;

//imprime nome dos atletas por altura decrescente
void maiorAtleta(atleta *players)
{
	for(int i = 0; i < NUMATLETAS; ++i)
	{
		int index = i;
		for (int j = i; j < NUMATLETAS; ++j)
		{
			if(players[j].idade > players[index].idade)
			{
				index = j;
			}
		}
		atleta temp = players[i];
		players[i] = players[index];
		players[index] = temp;
	}

	for (int i = 0; i < NUMATLETAS; ++i)
	{
		printf("%d- %s\n",i+1, players[i].nome);
	}
}

//funcao main
int main(int argc, char* argv[])
{
	atleta players[NUMATLETAS];
	for (int i = 0; i < NUMATLETAS; ++i)
	{
		scanf(" %15s %15s %d %f", players[i].nome, players[i].esporte, &players[i].idade, &players[i].altura);
	}

    //chama funcao para comparar
	maiorAtleta(players);

    //encerra codigo
	return SUCESSO;
}