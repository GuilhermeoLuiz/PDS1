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

struct user {
    char *name;
    int idade;
    struct address *addr;
};


//funcao para alocar memoria para um usuario
struct user *create_user(const char *input)
{
	struct user *usuario = (struct user*) malloc(sizeof(struct user));

	char* input_copy = (char*) malloc(strlen(input)+1);
	strcpy(input_copy, input);

	//token para receber nome
	char *token;
	token = strtok(input_copy, "#");
	usuario->name = (char*) malloc(strlen(token)+1);
	strcpy(usuario->name, token);

	//token para receber idade
	usuario->idade = atoi(strtok(NULL, "#"));;

	//token para receber endereco
	token = strtok(NULL, "#");
	usuario->addr = create_address(token);

	//libera memoria auxiliar
	free(input_copy);

	return usuario;
}

//funcao para desalocar memoria de um usuario
void free_user(struct user *user)
{
	free_address(user->addr);
	free(user->name);
	free(user);
}

//funcao principal
int main(int argc, char const *argv[])
{	
	//encerra programa com sucesso
	return SUCESSO;
}