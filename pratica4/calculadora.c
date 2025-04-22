//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>


//funcao main
int main(int argc, char* argv[]){

    //declara variaveis
    float num1, num2, resultado;
    char op;

    //obtem numeros e operador
    printf("Calculadora - TGoL\n");
    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);
    printf("Soma(+) - Subtracao(-) - Multiplicacao(*) - Divisao(/)\n");
    printf("Digite o operador: ");
    scanf(" %c", &op);
    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    //calcula numeros
    switch(op){
    case '+':
    	resultado = num1 + num2;
    	printf("%.2f %c %.2f = %.2f\n", num1, op, num2, resultado);
    	break;
    case '-':
    	resultado = num1 - num2;
    	printf("%.2f %c %.2f = %.2f\n", num1, op, num2, resultado);
    	break;
    case '*':
    	resultado = num1 * num2;
    	printf("%.2f %c %.2f = %.2f\n", num1, op, num2, resultado);
    	break;
    case '/':
    	if(num2 != 0){
    		resultado = num1 / num2;
    		printf("%.2f %c %.2f = %.2f\n", num1, op, num2, resultado);
    	}
    	else if(num2 == 0){
    		printf("Impossivel a divisao por zero (0).\n");
    	}
    	break;
    default:
    	printf("Operador invalido.\n");
    }
    
    
    //encerra programa
    return SUCESSO;
}