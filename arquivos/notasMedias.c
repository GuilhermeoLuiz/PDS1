//bibliotecas e definicoes
#define SUCESSO 0
#define MAX_NOTAS 100
#define MAX_LINHA 100
#define MAX_NOME 33+1
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcao principal
int main(int argc, char* argv[])
{
    //abre arquivo
    FILE *arq;
    arq = fopen("notas.txt", "r");
    if(arq == NULL){
        printf("O seu arquivo nao foi aberto com sucesso\n");
        return 1;
    }

    //estrutura para 
    int numAlunos = 4, index = 0;
    float notas[MAX_NOTAS];
    char linha[MAX_LINHA], nomes[100][MAX_NOME], *nomeTmp;
    while(fgets(linha, MAX_LINHA, arq) != NULL)
    {
        nomeTmp = strtok(linha, " ");
        float soma = 0, media;
        for(int i = 0; i < numAlunos; i++)
        {   
            soma += atof(strtok(NULL, " "));
        }
        if(numAlunos > 0)
        {
            media = soma/numAlunos;
            if(media >= 60)
            {
                strcpy(nomes[index], nomeTmp);
                notas[index] = media;
                index++;
            }
        }
    }
    //fecha arquivo
    fclose(arq);

    //imprime nome e media dos alunos 60++
    for (int i = 0; i < index; ++i)
    {
        printf("Nome: %s - Média: %.2f\n", nomes[i], notas[i]);
    }
    
    //encerra programa
    return SUCESSO;
}