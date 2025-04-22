#define SUCESSO 0
#include <stdio.h>
#include <math.h>

int ddd(long long int num){
	return num / pow(10,9);
}

int main(int argc, char const *argv[])
{	
	long long int num = 31984406210;
	printf("%d\n", ddd(num));

	return SUCESSO;
}