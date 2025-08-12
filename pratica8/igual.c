//biblioteca e definicoes
#define SUCESSO 0
#include <stdio.h>
#define nLinhas 100
#define nColunas 100

int verificamatrizigual(int linA, int colA, int A[nLinhas][nColunas], int linB, int colB, int B[nLinhas][nColunas]){

    if((linA != linB) || (colA != colB))
        return 0;

    for(int i = 0; i < linA; i++)
    {
        for(int j = 0; j < colA; j++)
        {
            if((A[i][j]) != (B[i][j]))
            {
                return 0;
            }
        }
    }

    return 1;
}

//funcao main
int main(int argc, char* argv[]){

   //define variaveis e obtem valores
    int linA, colA, linB, colB;
    int vetA[nLinhas][nColunas];
    int vetB[nLinhas][nColunas];
    scanf("%d", &linA);
    scanf("%d", &colA);

    //armazena valores na matriz
    for(int i = 0; i < linA; i++)
    {
        for(int j = 0; j < colA; j++)
        {
            scanf(" %d", &vetA[i][j]);
        }
    }

    scanf("%d", &linB);
    scanf("%d", &colB);

    //armazena valores na matriz
    for(int i = 0; i < linB; i++)
    {
        for(int j = 0; j < colB; j++)
        {
            scanf(" %d", &vetB[i][j]);
        }
    }
    
    // for(int i = 0; i < linA; i++){
    //     for(int j = 0; j < colA; j++)
    //         printf("%d ", vetB[i][j]);
    //     printf("\n");
    // }

    printf("%d\n", verificamatrizigual(linA, colA, vetA, linB, colB, vetB));

    return SUCESSO;
}