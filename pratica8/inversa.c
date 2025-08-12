//biblioteca e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao main
int main(int argc, char* argv[]){

   //define variaveis e obtem valores
    int linhas;
    scanf("%d", &linhas);
    int colunas;
    scanf("%d", &colunas);
    int mat[linhas][colunas];
    
    //armazena valores na matriz
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf(" %d", &mat[i][j]);
        }
    }

    //inverte valores
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++)
            mat[i][j] *= -1;
    }
    
    //imprime matriz
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    return SUCESSO;
}