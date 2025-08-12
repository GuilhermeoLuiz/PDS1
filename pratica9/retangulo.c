//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//estrutura de um ponto
typedef struct{
    float x;
    float y;
} ponto;

//estrutura do retangulo
typedef struct{
    ponto a;
    ponto b;
} retangulo;

//funcao para calcular a area do retangulo
float area(retangulo ret){
    return (ret.b.x - ret.a.x) * (ret.a.y - ret.b.y);
}

//funcao para calcular o perimetro do retangulo
float perimetro(retangulo ret){
    return 2 * ((ret.b.x - ret.a.x) + ((ret.a.y - ret.b.y)));
}

//funcao para calcular a diagonal do retangulo
float diagonal(retangulo ret){
    return sqrt((pow(ret.b.x - ret.a.x,2) + pow(ret.a.y - ret.b.y,2)));
}

//funcao main
int main(int argc, char* argv[])
{
    retangulo ret;
    printf("Digite as coordenadas do ponto a: ");
    scanf("%f %f", &ret.a.x, &ret.a.y);
    printf("%.2f %.2f\n", ret.a.x, ret.a.y);

    //restricoes dos valores do ponto b
    do{
        printf("Digite as coordenadas do ponto b: ");
        scanf("%f %f", &ret.b.x, &ret.b.y);
        if((ret.b.x <= ret.a.x) || (ret.b.y >= ret.a.y))
            printf("Coordenada Invalida\n");
    }while((ret.b.x <= ret.a.x) || (ret.b.y >= ret.a.y));
    printf("%.2f %.2f\n", ret.b.x, ret.b.y);


    //imprime funcoes
    printf("Area = %.2f\n", area(ret));
    printf("Perimetro = %.2f\n", perimetro(ret));
    printf("Diagonal = %.2f\n", diagonal(ret));
    

    //encerra programa
    return SUCESSO;
}//guilhermeoluiz