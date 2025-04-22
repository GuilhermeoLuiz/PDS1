//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>
#include <math.h>

//funcao para calcular log-logística
float loglcdf(float x, float a, float b){

	float f;

	if (x >= 0){
		f = (1/(1+pow((x/a),b)));
	}
	else if(x < 0){
		f = 0;
	}
	else{
		printf("Aviso: condição inesperada para x = %f\n", x);
    	f = -1;
	}

	return f;
}

//funcao main
int main(int argc, char* argv[]){

    //declara variavel e chama funcao par_ou_impar
    printf("%f\n", loglcdf(-1,0,0));

    //encerra programa
    return SUCESSO;
}