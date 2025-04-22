//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para arredondar numero float
float arredonda(float num){
	if(num > 0){
		if((num - ((int) num)) >= 0.5){
			num = (int) (1 + num);
		}
		else if((num - ((int) num)) < 0.5){
			num = (int) num;
		}
	}
	else if (num < 0){
		if((num - ((int) num)) <= -0.5){
			num = (int) (num - 1);
		}
		else if((num - ((int) num)) > -0.5){
			num = (int) num;
		}
	}
	//finaliza funcao
	return num;
}


//funcao main
int main(int argc, char* argv[]){

    //declara variavel e chama funcao
    float num = -2.65;
    printf("%f\n", arredonda(num));

    //encerra programa
    return SUCESSO;
}