//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao 
void valida_triangulo(float l1, float l2, float l3){
    if((l1 > 0) && (l2 > 0) && (l3 > 0)){
        if((l1 < l2+l3) && (l2 < l1+l3) && (l3 < l1+l2)){
            if((l1 == l2) && (l2==l3)){
                printf("Triangulo equilatero\n");
            }
            if(((l1 != l2) && (l1 != l3) && (l2 == l3)) || ((l1 == l2) && (l1 != l3) && (l2 != l3))){
                printf("Triangulo isosceles\n");
            }
            else if((l1 != l2) && (l1 != l3) && (l2 != l3)){
                printf("Triangulo escaleno\n");
            }
        }
        else printf("Valores invalidos\n");
    }
    else printf("Triangulo invalido\n");
}

//funcao main
int main(int argc, char* argv[]){

    //declara variaveis
    float l1, l2, l3;

    //obtem dados e chama funcao 
    printf("Vamos descobrir o tipo do triangulo\n");
    printf("Digite o lado 1 do triangulo: ");
    scanf("%f", &l1);
    printf("Digite o lado 2 do triangulo: ");
    scanf("%f", &l2);
    printf("Digite o lado 3 do triangulo: ");
    scanf("%f", &l3);

    valida_triangulo(l1, l2, l3);

    return SUCESSO;
}