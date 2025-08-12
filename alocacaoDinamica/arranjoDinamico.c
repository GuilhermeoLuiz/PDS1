//bibliotecas e definicoes
#include <stdio.h>
#include <stdlib.h>

float* read_array(int *n)
{
    //armazena valor de p no ponteiro n
    scanf("%d", n);
    
    //aloca n memorias de float
    float* p = (float*)malloc((*n) * sizeof(float));
    
    for(int i = 0; i < *n; i++)
    {
        // printf("a");
        scanf("%f", &p[i]);
    }

    //retorna ponteiro indicando a memoria
    return p;
}

void free_array(float *array)
{
    //libera memoria alocada
    free(array);
}