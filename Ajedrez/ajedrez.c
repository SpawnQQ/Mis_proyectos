#include <stdlib.h>
#include <stdio.h>
#include <estructuras.h>
#include <metodos.h>
#include <movimiento.h>
#include <manejo_ficheros.h>
#include <jaque_mate.h>
#include <SDL2/SDL.h>  

int main(){
	typedef struct pieza p;
	p m[8][8];
	int termino_partida=0;
	int turno=0;
	creacion_historial();
	inicio_partida(&m,termino_partida,turno);	
}