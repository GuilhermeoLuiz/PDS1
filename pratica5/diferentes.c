//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para tornar 0 dois inteiros iguais e somar diferentes
void aumentaOsDiferentes(int* end_var1, int* end_var2) {
    if (*end_var1 == *end_var2){
        *end_var1 = 0;
        *end_var2 = 0;
    }
    else if(*end_var1 != *end_var2){
        *end_var1 += *end_var2;
        *end_var2 = *end_var1;
    }
    else{
        printf("erro inesperado, funcao aumentaOsDiferentes.\n");
    }

}

//funcao main
int main(int argc, char* argv[]){

    //declara variaveis
    int a = -5, b = 5;
    int *x = &a, *y = &b;

    //chama funcao e imprimi novos valores
    aumentaOsDiferentes(x, y);
    printf("%d %d\n", *x, *y);

    //encerra programa
    return SUCESSO;
}