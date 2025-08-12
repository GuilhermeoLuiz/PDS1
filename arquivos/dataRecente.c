//bibliotecas e definicoes
#define SUCESSO 0
#define TAM_PALAVRA 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcao principal
int main(int argc, char* argv[])
{
    //abre arquivo
    FILE *arq;
    arq = fopen("datas.txt", "r");
    if(arq == NULL){
        printf("O seu arquivo nao foi aberto com sucesso\n");
        return SUCESSO;
    }

    //cria estrutura para ler arquivo e obter data mais recente
    int dia, mes, ano;
    if(fscanf(arq, "%d/%d/%d", &dia, &mes, &ano) == 3)
    {
        int diaTmp, mesTmp, anoTmp;
        while(fscanf(arq, "%d/%d/%d", &diaTmp, &mesTmp, &anoTmp) == 3)
        {
            if(anoTmp >= ano)
            {
                if(mesTmp >= mes)
                {
                    if(diaTmp >= dia)
                    {
                        dia = diaTmp;
                        mes = mesTmp;
                        ano = anoTmp;
                    }
                }
            }
        } 
        //imprime data mais recente
        printf("%02d/%02d/%04d\n", dia, mes, ano);
    }
    //fecha arquivo
    fclose(arq);

    //encerra programa
    return SUCESSO;
}