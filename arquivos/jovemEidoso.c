//bibliotecas e definicoes
#define SUCESSO 0
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

    //le dados do arquivo e obtem mais novo e mais velho
    char nome[33+1];
    if((fgets(nome, sizeof(nome), arq) != NULL))
    {
        nome[strcspn(nome, "\n")] = '\0';  // remove o \n
        int idade;
        if(fscanf(arq, "%d", &idade) != EOF)
        {
            char nomeIdoso[33+1], nomeJovem[33+1]; //nome da maior pessoa no Brasil tem 32 letras
            int maior = idade, menor = idade;
            strcpy(nomeIdoso, nome);
            strcpy(nomeJovem, nome);
            while(fgets(nome, sizeof(nome), arq) != NULL)
            {
                nome[strcspn(nome, "\n")] = '\0';  // remove o \n
                if(fscanf(arq, "%d", &idade) != EOF)
                {
                    if(idade > maior)
                    {
                        maior = idade;
                        strcpy(nomeIdoso, nome);
                    }
                    if(idade < menor)
                    {
                        menor = idade;
                        strcpy(nomeJovem, nome);
                    }
                }
            }

        //imprime nome do mais nome e mais velho
        printf("%s\n%s\n", nomeJovem, nomeIdoso);
        }
    }

    //encerra programa
    return SUCESSO;
}