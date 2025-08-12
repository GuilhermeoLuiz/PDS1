//bibliotecas e definicoes
#define SUCESSO 0
#define TAM_PALAVRA 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcao principal
int main(int argc, char* argv[])
{
    //abre arquivo
    FILE *arq;
    arq = fopen("texto.txt", "r");
    if(arq == NULL){
        printf("O seu arquivo nao foi aberto com sucesso\n");
        return SUCESSO;
    }

    //le arquivo e imprime palavras maiores/igual n
    int n;
    scanf("%d", &n);
    char nome[TAM_PALAVRA];
    while(fscanf(arq, "%s", nome) != EOF)
    {
        if(strlen(nome) >= n)
        {
            printf("%s\n", nome);
        }
    }
    fclose(arq);

    //encerra programa
    return SUCESSO;
}