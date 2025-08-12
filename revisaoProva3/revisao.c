//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

int procura_letras(char *str, int achou_e, int achou_l, int achou_f)
{
	if(str[0] == '\0')
	{
		return achou_e + achou_l + achou_f;
	}

	if((achou_e == 0) && (str[0] == 'e'))
	{
		achou_e = 1;
	}
	else if((achou_l == 0) && (str[0] == 'l'))
	{
		achou_l = 1;
	}
	else if((achou_f == 0) && (str[0] == 'f'))
	{
		achou_f = 1;
	}

	return procura_letras(str+1, achou_e, achou_l, achou_f);
}

int ehElfica(char *str){
	if((procura_letras(str, 0,0,0)) == 3)
	{
		return 1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", ehElfica("elf"));
	return 0;
}