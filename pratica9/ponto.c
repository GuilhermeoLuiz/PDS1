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

//funcao para verificar se um ponto pertence ao retangulo
void verificaPonto(retangulo ret, ponto p)
{
    if((ret.a.x > p.x) || (ret.b.x < p.x) || (ret.a.y < p.y) || (ret.b.y > p.y))
        printf("O ponto nao pertence ao retangulo\n");
    else
        printf("O ponto pertence ao retangulo");
}

//funcao main
int main(int argc, char* argv[])
{
    retangulo ret;
    ponto p;
    printf("Digite as coordenadas do ponto a: ");
    scanf("%f %f", &ret.a.x, &ret.a.y);
    printf("%.2f %.2f\n", ret.a.x, ret.a.y);

    //restricoes dos valores do ponto b
    do
    {
        printf("Digite as coordenadas do ponto b: ");
        scanf("%f %f", &ret.b.x, &ret.b.y);
        if((ret.b.x <= ret.a.x) || (ret.b.y >= ret.a.y))
            printf("Coordenada Invalida\n");
    }while((ret.b.x <= ret.a.x) || (ret.b.y >= ret.a.y));

        printf("Digite as coordenadas do ponto a ser verificado: ");
        scanf("%f %f", &p.x, &p.y);
        verificaPonto(ret, p);

    //encerra programa
    return SUCESSO;
}//guilhermeoluiz