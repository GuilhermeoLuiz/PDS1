//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para obter quociente e resto
void divisao(int* end_var1, int* end_var2) {

    int temp = *end_var1;
    *end_var1 = *end_var1 / *end_var2;
    *end_var2 = (temp % *end_var2);
}

//funcao main
int main(int argc, char const *argv[])
{
	int x = 7, y = 2;

	divisao(&x,&y);
	printf("%d %d\n", x, y);

	//encerra programa
	return SUCESSO;
}