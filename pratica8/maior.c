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

    //realiza funcao
    int maior = mat[0][0];
    int colunaM = 0;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if((mat[i][j] > maior) || ((mat[i][j] == maior) && (j< colunaM))){
               maior = mat[i][j];
               colunaM = j;
            }
        }
    }
    printf("%d\n", colunaM);

    return SUCESSO;
}