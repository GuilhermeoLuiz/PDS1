#define SUCESSO 0
#include <stdio.h>

//funcao para somar 1 a um inteiro qualquer
void soma1(int* p){
    (*p)++;
}

//funcao testeSoma1
int testaSoma1(int x){
    int* p = &x;
    soma1(p);
    return x;
}

//funcao main
int main(int argc, char* argv[]){
    //declara variaveis e atribui valor
    int x = 11;
    int *p = &x;

    //chama funcao
    printf("%d\n", testaSoma1(x));

    //retorna 0
    return SUCESSO;
}