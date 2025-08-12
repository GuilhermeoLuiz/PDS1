//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct address {
    char *line;
    int number;
    int zipcode;
};

//funcao para alocar memorias para uma struct addres
struct address *create_address(const char *input)
{
	//aloca memoria de uma struct
	struct address *endereco = (struct address*) malloc(sizeof(struct address));

	//copia o ponteiro de char, devido a input ser um const
	char *input_copy = (char*) malloc(strlen(input)+1);
	strcpy(input_copy, input);

	//comeca a separar por tokens o ponteiro de char e guardar nas respectivas variaveis
	char* token = strtok(input_copy, "|");
	endereco->line = (char*) malloc(strlen(token)+1);
	strcpy(endereco->line, token);
	endereco->number = atoi(strtok(NULL, "|"));
	endereco->zipcode = atoi(strtok(NULL, "\n "));

	free(input_copy);
	return endereco;
}

//funcao para desalocar memoria de uma struct addres
void free_address(struct address *addr)
{
	free(addr->line);
	free(addr);
}

//funcao principal
int main(int argc, char const *argv[])
{	



	//encerra programa com sucesso
	return SUCESSO;
}