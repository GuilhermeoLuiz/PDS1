//Pratica1-PDS1 Calcula o IMC
#define SUCESSO 0
#include <stdio.h>
#include <math.h>

int main() {

    //Declara variaveis e atribui valores
    float pesoB = 122, pesoO = 45, alturaB = 1.84, alturaO = 1.76;
    float pIdeal;

    //imc de Brutus
    float imcB = pesoB/(alturaB*alturaB);

    if (imcB < 16){
        pIdeal = fabs((alturaB*alturaB*18.5) - pesoB);
        printf("%.1f\n", pIdeal);
    }
    else if ((18.5 <= imcB) && (imcB < 25)){
        printf("0\n");
    }
    else if(imcB > 25){
        pIdeal = fabs((alturaB*alturaB*25) - pesoB);
        printf("%.1f\n", pIdeal);
    }

    //imc de Olivia
    float imcO = pesoO/(alturaO*alturaO);

    if (imcO < 16){
        pIdeal = fabs((alturaO*alturaO*18.5) - pesoO);
        printf("%.1f\n", pIdeal);
    }
    else if ((18.5 <= imcO) && (imcO < 25)){
        printf("0\n");
    }
    else if(imcO > 25){
        pIdeal = fabs((alturaO*alturaO*25) - pesoO);
        printf("%.1f\n", pIdeal);
    }

    return SUCESSO;
}