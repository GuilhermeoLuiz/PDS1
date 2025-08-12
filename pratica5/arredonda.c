//bibliotecas e definicoes
#define SUCESSO 0
#include <stdio.h>

//funcao para arredondar float
float arredonda(float n) {
	float resto;
	if(n >= 0){
		resto = n - ((int) n);
	    if(resto < 0.25){
	    		n = (int) n;
	    }
	    else if((resto >= 0.25) && (resto < 0.75)){
	    	n = (int)n + 0.5;

	    }
	    else if(resto >= 0.75){
	    	n = (int) n + 1;
	    }
	    else printf("Erro inesperado!");
	}

	else if(n < 0){
		resto = n - ((int)n);
	    if(resto > -0.25){
	    		n = (int) n;
	    }
	    else if((resto <= -0.25) && (resto > -0.75)){
	    	n = ((int)n) - 0.5;

	    }
	    else if(resto <= 0.75){
	    	n = ((int)n) - 1;
	    }
	    else printf("Erro inesperado!");
	}
	else printf("Erro inesperado!");

	return n;
}

//funcao para arredondar float
void arredondaNotas(float *endNota1, float *endNota2, float *endNota3) {
    *endNota1 = arredonda(*endNota1);
    *endNota2 = arredonda(*endNota2);
    *endNota3 = arredonda(*endNota3);
}

//funcao main
int main(int argc, char const *argv[])
{
	float x = -7.99, y = -2.2, z = -3.476;

	arredondaNotas(&x,&y,&z);
	printf("%f %f %f\n", x, y, z);

	//encerra programa
	return SUCESSO;
}