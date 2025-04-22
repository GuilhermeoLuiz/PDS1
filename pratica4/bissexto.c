//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao main
int main(int argc, char* argv[]){

    //declara variavel
    int ano;

    //recebe o ano
    printf("Hello usuario, Vamos verificar se o ano e bissexto\n");
    printf("Digite um ano:");
    scanf("%d", &ano);

    //verifica se e bissexto
    if((((ano%4) == 0) && ((ano%100) != 0)) || (ano%400 == 0)){
        printf("O ano de %d e bissexto.\n", ano);
    }
    else{
        printf("O ano de %d nao e bissexto.\n", ano);
    }

    return SUCESSO;
}