//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <math.h>

//imprime todos os numeros naturais em ordem decrescente a partir de N
void imprimeNaturais(int N)
{
	if(N < 0)
	{
		return;
	}
	printf("%d\n", N);
	imprimeNaturais(N-1);

}

//retorna recursivamente a soma dos cubos de n ate 0
int somaCubos(int n)
{
	if(n < 1)
	{
		return 0;
	}

	return(pow(n,3) + somaCubos(n-1));
}

//soma os n valores de um vetor
int somaVetor(int v[], int n)
{
	if(n <= 0)
	{
		return 0;
	}
	return v[0]+somaVetor(v+1, n-1);
}

//calcula media dos valores de um vetor de int
double mediaVetor(int v[], int n)
{
	return ((double)(somaVetor(v, n))/n);
}

//funcao recursiva para retornar x elevado a y
int potencia(int x, int y)
{
	if(y == 0)
	{
		return 1;
	}
	if(y == 1)
	{
		return x;
	}

	return x * potencia(x, y-1);
}

//imprime valor em binario
void imprimeBinario(int n)
{
	if(n <= 0)
	{
		return;
	}
	imprimeBinario(n/2);
	printf("%d", n%2);
}

//funcao recursiva para o menor elemento de um vetor
int menorElemento(int v[], int n)
{
	if(n == 1)
	{
		return v[0];
	}

int menor = menorElemento(v+1, n-1);

	if(v[0] < menor)
	{
		return v[0];
	}

	return menor;
}

//funcao para retornar string invertida
void imprimeInvertida(char str[])
{
	if(str[0] == '\0')
	{
		return;
	}		

	imprimeInvertida(str+1);
	printf("%c", str[0]);
}

//funcao recursiva para retornar numero invertido
int inverteNumero(int x)
{
	if(x == 0)
	{
		return 0; // ou x
	}

	int num = inverteNumero(x/10);
	return x%10 * pow(10,((int)log10(x))) + num;
}


//funcao principal 
int main(int argc, char const *argv[])
{
	// char str[] = {"ALIMO"};
	printf("%d\n", inverteNumero(500));
	//encerra programa
	return SUCESSO;
}