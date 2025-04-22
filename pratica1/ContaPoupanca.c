//Pratica1-PDS1 TrocaValores
#define SUCESSO 0
#include <stdio.h>

int main() {

    //primeiro mes, cria conta e adiciona saldo
    float saldo = 0, juros = 0.0056;
    saldo += 789.54;

    //segundo mes, rendimento e deposito
    saldo += juros * saldo;
    saldo += 303.2;

    //terceiro mes, rendimento e saque
    saldo += juros * saldo;
    saldo -= 58.25;

    //quarto mes, rendimento
    saldo += juros * saldo;
    printf("%.2f\n", saldo);

    return SUCESSO;
}