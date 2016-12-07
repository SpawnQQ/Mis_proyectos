#include<stdlib.h>
#include <stdio.h>
#include<estructuras.h>
#include<metodos.h>

int main(){
	typedef struct pieza p;
	p m[8][8];
	tablero_inicio(&m);
	system("clear");
	mostrar_tablero(&m);
}
