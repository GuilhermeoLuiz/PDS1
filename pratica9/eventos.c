//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <string.h>
#define MAX_NOME 50+1

//estrutura para data
typedef struct{
	int dia;
	int mes;
	int ano;
} date;

//estrutura para eventos
typedef struct{
	char nome[MAX_NOME];
	char local[MAX_NOME];
	date data;
} event;

//imprime os eventos por data
void confereData(event *eventos, int numEventos)
{
	int eventosEncontrados = 0;
	date dataTeste;
	printf("Digite a data a ser conferida\n");
	scanf("%d %d %d", &dataTeste.dia, &dataTeste.mes, &dataTeste.ano);

	for (int i = 0; i < numEventos; ++i)
	{
		if(eventos[i].data.ano == dataTeste.ano)
		{
			if(eventos[i].data.mes == dataTeste.mes)
			{
				if(eventos[i].data.dia == dataTeste.dia)
				{
					printf("%s\n", eventos[i].nome);
					printf("%s\n", eventos[i].local);
					eventosEncontrados = 1;
				}
			}
		}
	}
	
	if(eventosEncontrados == 0)
	{
		printf("Nenhum evento encontrado!\n");
	}
}

//funcao main
int main(int argc, char* argv[])
{
	int numEventos;
	printf("Digite o numero de eventos: ");
	scanf("%d", &numEventos);
	getchar();

	event eventos[numEventos];

	//obtem dados dos eventos
	for (int i = 0; i < numEventos; ++i)
	{
		fgets(eventos[i].nome, MAX_NOME, stdin);
		eventos[i].nome[strcspn(eventos[i].nome, "\n")] = '\0';
		fgets(eventos[i].local, MAX_NOME, stdin);
		eventos[i].local[strcspn(eventos[i].local, "\n")] = '\0';
		scanf("%d %d %d", &eventos[i].data.dia, &eventos[i].data.mes, &eventos[i].data.ano);
		getchar();
	}

	//chama funcao para verificar data
	confereData(eventos, numEventos);

    //encerra codigo
	return SUCESSO;
}//guilhermeoluiz