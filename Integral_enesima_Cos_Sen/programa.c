#include <stdlib.h>
#include <stdio.h>
#include <metodos.h>
#include <time.h>

int main(){
	clock_t t_ini, t_fin;
	double secs;
	t_ini = clock();
	double v[2];
	factorial(100000000000,v);
	t_fin = clock();
	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
	printf("\n%lfe+%lf",v[0],v[1]);
	printf("\n%.16g segundos\n", secs);

}