//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para validar a data
void validaData(int dia, int mes, int ano){

    if ((dia > 0) && (ano > 0)){
        switch(mes){
        case 1: 
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (dia <= 31) printf("Data valida\n");
            else printf("Data invalida\n");
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            if (dia <= 30) printf("Data valida\n");
            else printf("Data invalida\n");
            break;

        case 2:
            if((((ano%4) == 0) && ((ano%100) != 0)) || (ano%400 == 0))
                if(dia <= 29) printf("Data valida\n");
                else printf("Data invalida\n");
            else
                if(dia <= 28) printf("Data valida\n");
                else printf("Data invalida\n");
            break;
        default: printf("Data invalida\n");
        }
    }
    else printf("Data invalida\n");
}

//funcao main
int main(int argc, char* argv[]){

    //declara variaveis
    int dia, mes, ano;

    //obtem dados e chama funcao para validar a data
    printf("Hello usuario, Vamos verificar se a data e valida\n");
    printf("Digite o dia: ");
    scanf("%d", &dia);
    printf("Digite o mes: ");
    scanf("%d", &mes);
    printf("Digite o ano: ");
    scanf("%d", &ano);

    validaData(dia, mes, ano);

    return SUCESSO;
}