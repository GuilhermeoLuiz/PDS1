//bibliotecas e definicoes
#define SUCESSO 0
#define MAX_NOMES 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcao principal
int main(int argc, char* argv[])
{
    //abre arquivo
    FILE *arq;
    arq = fopen("case.txt", "r");
    if(arq == NULL){
        printf("O seu arquivo nao foi aberto com sucesso\n");
        return SUCESSO;
    }

    //le os nomes do arquivo e armazena em uma matriz de char
    char nomes[MAX_NOMES][33+1];
    int i = 0;
    while(fgets(nomes[i], sizeof(nomes[i]), arq) != NULL)
    {
        nomes[i][strcspn(nomes[i], "\n")] = '\0';  // remove o \n
        i++;
    }
    int totalNomes = i;

    //coloca nomes em ordem alfabetica
    for (i = 0; i < totalNomes - 1; ++i)
    {
        for (int j = i+1; j < totalNomes; ++j)
        {
            if (strcmp(nomes[i], nomes[j]) > 0)
            {
                char tmp[33+1];
                strcpy(tmp, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], tmp);
            }
        }
    }
    //fecha arquivo
    fclose(arq);

    //imprime nomes em ordem alfabetica
    for (int i = 0; i < totalNomes; ++i)
    {
        printf("%s\n", nomes[i]);
    }

    //encerra programa
    return SUCESSO;
}