//biblioteca e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao main
int main(int argc, char* argv[])
{

   //define variaveis e obtem valores
    int linhas;
    scanf("%d", &linhas);
    int colunas;
    scanf("%d", &colunas);
    int mat[linhas][colunas];
    
    //armazena valores na matriz
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            scanf(" %d", &mat[i][j]);
        }
    }
    
    //impressao em espiral
    int colMax = colunas, colMin = 0, linMax = linhas, linMin = 0;
    while((colMin < colMax) && (linMin < linMax))
    {

        //linha superior
        for(int j = colMin; j < colMax; j++)
        {
            printf("%d ", mat[linMin][j]);
        }
        linMin++;

        //coluna direita
        for(int k = linMin; k < linMax; k++)
        {
            printf("%d ", mat[k][colMax-1]);
        }
        colMax--;

        //linha inferior
        for(int l = colMax-1; l >= colMin; l--)
        {
            printf("%d ", mat[linMax-1][l]);
        }
        linMax--;

        //coluna esquerda
        for(int m = linMax-1; m >= linMin; m--)
        {
            printf("%d ", mat[m][colMin]);
        }
        colMin++;
    }

    return SUCESSO;
}