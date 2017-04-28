#include <stdlib.h>
#include <stdio.h>
#include <estructuras.h>
#include <metodos.h>
#include <movimiento.h>
#include <manejo_ficheros.h>
#include <jaque_mate.h>
#include <tablas.h>
#include <SDL/SDL.h> 
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <Motor_SDL.h>

int main(){

	inicio_SDL();
	typedef struct pieza p;
	p m[8][8];
	int termino_partida=0;
	int turno=0;
	creacion_historial();
	while(done == 0){
		inicio_partida(&m,termino_partida,turno);
		done=1;
	}
}