//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <string.h>

void frequencia_str(const char* dados_brutos)
{
    int freq[256] = {0};  // Tabela ASCII

    int tam = strlen(dados_brutos);

    //Conta frequência de cada caractere
    for (int i = 0; i < tam; i++)
    {
        unsigned char ch = dados_brutos[i];
        freq[ch]++;
    }

    //Imprime os caracteres em ordem de código ASCII
    for (int i = 1; i < 256; i++)
    {
        if (freq[i] > 0)
        {
            printf("%c aparece %d vezes\n", i, freq[i]);
        }
    }

    printf("\n");
}

//funcao principal
int main(int argc, char const *argv[])
{

	printf("--- Teste 1 ---\n");
	frequencia_str("PDS1PDS1PDS1 ");

	//encerra codigo
	return SUCESSO;
}