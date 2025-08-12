#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SUCESSO 0

//verifica se matriz e valida para inteiros ]0,100]
int validaMatriz(int lin, int col, int k)
{
    if((lin <= 0) || (lin > 100) || (col <= 0) || (col > 100) || (k <= 0) || (k >= 100))
    {
        return 0;
    }
    return 1;
}

//preenche matriz com numeros pseudo-aleatorios
void preencheAleatorios(int lin, int col, int k, int mat[lin][col])
{
    srand(time(NULL));
    for(int i = 0; i < lin;i++)
    {
        for(int j = 0; j < col; j++)
        {
            mat[i][j] = 1+(rand()%k);
        }
    }
}

//preenche matriz com 1
void preencheUm(int lin, int col, int mat[lin][col])
{
    for(int i = 0; i < lin;i++)
    {
        for(int j = 0; j < col; j++)
        {
            mat[i][j] = 1;
        }
    }
}

//imprime matriz
void imprimeMatriz(int lin, int col, int mat[lin][col])
{
    for(int i = 0; i < lin;i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

//identifica sequencia de elementos e adiciona as casas em zero na matriz tmp
void verificaLinha(int lin, int col, int mat[lin][col], int tmp[lin][col])
{
    for(int i = 0; i < lin;i++)
    {
        int cont = 0;
        for(int j = 0; j < col; j++)
        {
            if((j != (col-1) && (mat[i][j] == mat[i][j+1])))
            {
                cont++;
            }
            else
            {
                if(cont >= 2)
                {
                    for(int k = j; k >= j - cont; k--)
                    {
                        tmp[i][k] = 0;
                    }
                }
                cont = 0;
            }
        }
    }
}

//identifica sequencia de elementos e adiciona as casas em zero na matriz tmp
void verificaColunas(int lin, int col, int mat[lin][col], int tmp[lin][col])
{
    for(int i = 0; i < col; i++)
    {
        int cont = 0;
        for(int j = 0; j < lin; j++)
        {
           if((j != (lin-1) && (mat[j][i] == mat[j+1][i]))) 
           {
                cont++;
           }
           else
           {
                if(cont >= 2)
                {
                    for(int k = j; k >= j - cont; k--)
                    {
                        tmp[k][i] = 0;
                    }
                }
                cont = 0;
           }
        }
    }
}


int main()
{
    int lin,col,k;
    scanf("%d %d %d", &lin, &col, &k);
    if(validaMatriz(lin, col, k) == 0)
    {
        return 0;
    }
    int mat[lin][col];

    //preenche matriz com numeros aleatorios
    preencheAleatorios(lin, col, k, mat);

    //exibe matriz original
    imprimeMatriz(lin, col, mat);

    int tmp[lin][col];
    //cria matriz temporaria para armazenar os zero e preenche com 1
    preencheUm(lin, col, tmp);

    //modifica sequencia em linhas
    verificaLinha(lin, col, mat, tmp);

    //modifica sequencia em colunas
    verificaColunas(lin, col, mat, tmp);

    //imprime matriz temporaria
    imprimeMatriz(lin, col, tmp);

    return SUCESSO;
}