#define SUCESSO 0
#include <stdio.h>
#include <ctype.h>

//funcao para calcular o valor do produto
void valorProduto(float valor, char estado){

    estado = toupper(estado);    
    switch(estado){
        case 'G': 
        valor *= 1.07;
        printf("O valor em MG seria de R$%.2f", valor);
        break;

        case 'P':
        valor *= 1.12;
        printf("O valor em SP seria de R$%.2f", valor);
        break;

        case 'J':
        valor *= 1.15;
        printf("O valor em RJ seria de R$%.2f", valor);
        break;

        case 'S':
        valor *= 1.08;
        printf("O valor em MS seria de R$%.2f", valor);
        break;

        default: printf("Estado invalido");
    }
}

//funcao main
int main(int argc, char* argv[]){

    //declara variaveis
    float valor;
    char estado;

    //obtem dados e chama funcao para calcular o valor do produto
    printf("MG(G) - SP(P) - RJ(J) - MS(S) \nDigite o valor do produto, de um espaco e insira a letra do estado: ");
    scanf("%f %c", &valor, &estado);
    valorProduto(valor, estado);

    return SUCESSO;
}