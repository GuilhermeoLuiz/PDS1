//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <string.h>

//funcao main
int main(int argc, char* argv[])
{
    //declara strings e armazena seus valores
    char strA[50+1], strB[50+1];
    printf("Digite uma frase com ate 50 caracteres.\n");
    fgets(strA, sizeof(strA), stdin);
    printf("Digite uma frase com ate 50 caracteres.\n");
    fgets(strB, sizeof(strB), stdin);

    //elimina o /n
    int tamA = strlen(strA), tamB = strlen(strB), ehSubstring = 0;
    if (strA[tamA - 1] == '\n'){ 
            strA[tamA - 1] = '\0';
            tamA--;
    }
    if (strB[tamB - 1] == '\n'){
            strB[tamB - 1] = '\0';
            tamB--;
    }

    //obtem tamanho e percorre as variaveis comparando-as
    for(int i = 0; (i <= (tamA - tamB)) && (ehSubstring == 0); i++){
        if (strB[0] == strA[i]){
            for(int j = 0; j < tamB; j++){
                if(strB[j] != strA[i+j]){
                    break;
                }
                else if(j == (tamB - 1)){
                    printf("E substring\n"); 
                    ehSubstring = 1;
                }
            }   
        }
    }
    if(ehSubstring == 0){
        printf("Nao e substring\n"); 
    }

    //encerra programa
    return SUCESSO;
}