#define SUCESSO 0
#include <stdio.h>

//funcao para obter o maior de 5 inteiros
int maiorNum(int num1, int num2, int num3, int num4, int num5){
    
    int maior = num1;

    if (num2 > maior) maior = num2;
    if (num3 > maior) maior = num3;
    if (num4 > maior) maior = num4;
    if (num5 > maior) maior = num5;

    return maior;
}

//funcao para obter o menor de 5 inteiros
int menorNum(int num1, int num2, int num3, int num4, int num5){
    
    int menor = num1;

    if (num2 < menor) menor = num2;
    if (num3 < menor) menor = num3;
    if (num4 < menor) menor = num4;
    if (num5 < menor) menor = num5;

    return menor;
}

//funcao para calcular a quantidade de divisores de 3 entre 5 inteiros
int divisoresDe3(int num1, int num2, int num3, int num4, int num5){
    
    int numDivisores = 0;

    if((num1 % 3) == 0) numDivisores++;
    if((num2 % 3) == 0) numDivisores++;
    if((num3 % 3) == 0) numDivisores++;
    if((num4 % 3) == 0) numDivisores++;
    if((num5 % 3) == 0) numDivisores++;

    return numDivisores;
}

//funcao main
int main(int argc, char* argv[]){

    int num1, num2, num3, num4, num5;
    printf("Hello usario, esse programa vai te retornar entre 5 inteiros:\n\
O maior, o menor e a quantidade de divisores de 3.\n");
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    printf("Digite o terceiro numero: ");
    scanf("%d", &num3);
    printf("Digite o quarto numero: ");
    scanf("%d", &num4);
    printf("Digite o quinto numero: ");
    scanf("%d", &num5);

    printf("Maior: %d\n", maiorNum(num1, num2, num3, num4, num5));
    printf("Menor: %d\n", menorNum(num1, num2, num3, num4, num5));
    printf("Numero de divisores: %d\n", divisoresDe3(num1, num2, num3, num4, num5));

    return SUCESSO;
}