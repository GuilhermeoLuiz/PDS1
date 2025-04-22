//Pratica1-PDS1 TrocaValores
#define SUCESSO 0
#include <stdio.h>

int main() {

    //Declara variveis e atribui valores trocados
    float a = 3.14159, b = 2.71828;

    //Mecanismo para destrocar os valores das variaveis
    float aux;
    aux = a;
    a = b;
    b = aux;

    //Imprime valores
    printf("Pi = %f\n", b);
    printf("Euler = %f\n", a);

    return SUCESSO;
}
