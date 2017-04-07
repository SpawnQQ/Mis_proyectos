#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int sumando(int lim_inferior){

}

float sumatoria(int lim_inferior,int lim_superior){

}

int combinatoria_combinaciones(int n,int k){

}

void entero_ncientifica(long long n,double v[2]){
	double base,exponente,contador=0;
	double nm=(double)n;
	if(nm/10 > 1){
		do{
			nm=nm/10;
			contador++;
		}while(nm/10 > 1);
		base=nm;
		exponente=contador;
	}else{
		base=nm;
		exponente=0;
	}
	v[0]=base;
	v[1]=exponente;
}

void ncientifica(double n[2]){
	double base,exponente,contador=0;
	double nm=(double)n[0];
	if(nm/10 > 1){
		do{
			nm=nm/10;
			contador++;
		}while(nm/10 > 1);
		base=nm;
		exponente=contador;
	}else{
		base=nm;
		exponente=0;
	}
	n[0]=base;
	n[1]=exponente+n[1];
}

void mult_ncientifica(double n[2],double m[2],double resultado[2]){
	double base,exponente;
	base=n[0]*m[0];
	exponente=n[1]+m[1];
	resultado[0]=base;
	resultado[1]=exponente;

	ncientifica(resultado);
}

void factorial(long long n,double resultado[2]){
	double a[2],b[2];
	resultado[0]=1;
	resultado[1]=0;
	while(n!=0){
		entero_ncientifica(n,a);
		mult_ncientifica(a,resultado,resultado);
		n=n-1;
	}
}




int factorial_entero(int n){
	if(n==0)return 1;
	if(n==1)return 1;
	return factorial_entero(n-1);
}