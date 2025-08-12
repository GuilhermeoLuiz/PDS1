//bibliotecas e definicoes
#include <stdio.h>
#define SUCESSO 0
#define TAM_Y 400
#define TAM_X 800
#define LINHAS 1
#define COLUNAS 4
#define NUM_JOGADORES 2


//
typedef struct Tile {
  int investigado;
  int premio;
} Tile;

typedef struct Jogador {
  int vidas;
  int pontuacao;
} Jogador;


//funcao main
int main(int argc, char* argv[])
{
	Tile grid[LINHAS][COLUNAS];
	Jogador players[NUM_JOGADORES];

	//incializa o grid com os premios e nao investigados
	for (int i = 0; i < LINHAS; ++i)
	{
		for (int j = 0; j < COLUNAS; ++j)
		{
			grid[i][j].investigado = 0;
			grid[i][j].premio = 1;
		}
	}

	//inicializa as pontuacoes e vidas dos players
	for (int i = 0; i < NUM_JOGADORES; ++i)
	{
		players[i].vidas = 3;
		players[i].pontuacao = 0;
	}

	//laco de repeticao para o jogo
	int vez = 0, fim = 0;
	do{
		int lin, col;
		printf("Player %d digite a linha e coluna do jogo: ", (vez%NUM_JOGADORES) + 1);
		scanf("%d %d", &lin, &col);
		col --;
		lin --;

		//coenfere se o campo ja foi investigado e tira vida
		if (grid[lin][col].investigado == 1)
		{
			players[vez % NUM_JOGADORES].vidas--;
		}

		//se o campo nao foi investigado, marca como investigado e pontua jogador
		else if(grid[lin][col].investigado == 0)
		{
			grid[lin][col].investigado = 1;
			players[vez % NUM_JOGADORES].pontuacao += grid[lin][col].premio;
		}
		vez++;

		//confere se as vidas do player permitem o jogo continuar
		for (int i = 0; i < NUM_JOGADORES; ++i)
		{
			if(players[i].vidas == 0){
				printf("O player %d morreu!!\n", i+1);
				fim = 1;
			}
		}

		//confere se todos os campos ja foram marcados
		if(vez == (LINHAS * COLUNAS))
		{
			printf("Todos os campos foram concluidos!!\n");
			fim = 1;
		}

	} while(fim == 0);

	//imprime pontuacao dos players
	printf("Pontuacao\n");
	for (int i = 0; i < NUM_JOGADORES; ++i)
	{
		printf("Player %d: %d\n", i+1, players[i].pontuacao);
	}

    //encerra codigo
	return SUCESSO;
}//guilhermeoluiz