//biblioteca e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao main
int main(int argc, char* argv[]){

   //define variaveis e obtem valores
    int tam;
    scanf("%d", &tam);
    int vet[tam];
    
    //armazena valores no array
    for(int i = 0; i < tam; i++)
        scanf(" %d", &vet[i]);

    //
    for(int i = 0; i < tam; i++){
        int indice_maior = i;
        for(int j = i; j < tam; j++){
            if(vet[j] > vet[indice_maior]){
                indice_maior = j;
            }
        }
        int temp = vet[i];
        vet[i] = vet[indice_maior];
        vet[indice_maior] = temp;
    }

    for(int i = 0; i < tam; i++)
        printf("%d ", vet[i]);
    printf("\n");

    return SUCESSO;
}