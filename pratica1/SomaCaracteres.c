//Pratica1-PDS1 SomaCaracteres
#define SUCESSO 0
#include <stdio.h>

int main() {
    //guardando os caracteres em char
    char c1 = 'P';
    char c2 = 'D';
    char c3 = 'S';
    char c4 = '-';
    char c5 = '1';

    int soma = c1 + c2 + c3 + c4 + c5;
    int mult = c1 * c2 * c3 * c4 * c5;

    //imprimindo a soma e multiplicacao dos caracteres
    printf("Soma dos caracteres: %d\n", soma);
    printf("Multiplicacao dos caracteres: %d\n", mult);

    //finalizando a funcao main
    return SUCESSO;
}
