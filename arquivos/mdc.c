//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <stdlib.h>

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

    //le dados do arquivo
    int num[4];
    if(fscanf(arq, "%d\n%d\n%d\n%d", &num[0], &num[1], &num[2], &num[3]) != 4)
    {
        printf("Erro na leitura dos numeros\n");
        fclose(arq);
        return SUCESSO;
    }
    fclose(arq);
    
    //calcula mdc de 4 numeros com o teorema de Euclides
    int mdc, maior, menor;
    for (int i = 0; i < 3; ++i)
    {
        if(num[i] >= num[i+1])
        {
            maior = num[i];
            menor = num[i+1];
        }
        else
        {
            maior = num[i+1];
            menor = num[i];
        }

        int r;
        while(menor != 0)
        {
            r = maior % menor;
            maior = menor;
            menor = r;
        }
        mdc = maior;
        num[i+1] = maior;
    }

    //imprime mdc
    printf("%d\n", mdc);

    //encerra programa
    return SUCESSO;
}