#define SUCESSO 0
#include <stdio.h>

//funcao para somar 1 a um inteiro qualquer
void soma1(int* p){
    (*p)++;
}

//funcao main
int main(int argc, char* argv[]){
    //declara variaveis e atribui valor
    int x = 5;
    int *p = &x;
    //chama funcao
    soma1(p);
    return SUCESSO;
}