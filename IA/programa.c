#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include <ficheros.h>
#include <perceptron.h>

void lista_aleatoria(int n, float l[]){
	for(int i = 0 ; i < n ; i++){	
		l[i]=(float)(rand()%1000000)/1000000;
	}
}

int main(){
	int n=4;
	float peso[n];
	double resultado;

	lista_aleatoria(n,peso);
	int entrada[n];
	entrada[0]=30;
	entrada[1]=5;
	entrada[2]=25;
	entrada[3]=50;
	resultado=neurona(entrada,peso,n);

	for(int i=0;i<n;i++){
		printf("%i %f\n",entrada[i], peso[i]);
	}
	printf("%f\n", resultado );
}