//bibliotecas e definicoes
#define SUCESSO 0;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//funcao para retornar um int aleatorio em um intervalo dado
int randomInt(int num)
{
	return rand()%num;
}

//funcao para inseririr numeros pseudo-aleatorios em uma matriz
void preencherpseudoaleatoriamente(int seed, int min, int max, int lin, int col, int v[lin][col])
{
	srand(seed);

	for(int i = 0; i < lin; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			v[i][j] = (min+randomInt(max-min));
		}
	}

	for(int i = 0; i < col; ++i)
	{
		for (int j = 0; j < lin; ++j)
		{
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
}

//funcao main
int main(int argc, char const *argv[])
{
	
	int v[5][3];

	preencherpseudoaleatoriamente(9, 0, 100, 5, 3, v);

	return SUCESSO;
}