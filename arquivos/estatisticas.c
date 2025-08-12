//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <stdlib.h>

//verifica primo
int ehPrimo(int num)
{
    if(num < 2)
    {
        return 0;
    }

    for (int i = 2; i * i <= num; ++i)
    {
        if((num % i) == 0)
        {
            return 0;
        }
    }
    return 1;
}

//funcao principal
int main(int argc, char* argv[])
{
    //abre arquivo
    FILE *arq;
    arq = fopen("case.txt", "r");
    if(arq == NULL){
        printf("O seu arquivo nao foi aberto com sucesso\n");
        return SUCESSO;
    }

    //le dados do arquivo e obtem estatisticas
    int num, soma = 0, maior = 0, menor = 0, mediaPar = 0, nPrimos = 0, quantidade = 0;
    if(fscanf(arq, "%d", &num) != EOF)
    {
        maior = num;
        menor = num;
        do
        {
            soma += num;
            if(num > maior)
            {
                maior = num;
            }
            if(num < menor)
            {
                menor = num;
            }
            if((num % 2) == 0)
            {
                mediaPar += num;
                quantidade++;
            }
            if(ehPrimo(num) == 1)
            {
                nPrimos++;
            }

        }while(fscanf(arq, "%d", &num) != EOF);

    }
    //libera ponteiro de arquivo
    fclose(arq);

    //imprime estatisticas
    printf("A soma é: %d\n", soma);
    printf("O maior número é: %d\n", maior);
    printf("O menor número é: %d\n", menor);
    printf("A média dos pares é: %.2f\n", (quantidade!= 0) ? ((float)mediaPar/quantidade) : 0.00);
    printf("O número de primos é: %d\n", nPrimos);

    //encerra programa
    return SUCESSO;
}