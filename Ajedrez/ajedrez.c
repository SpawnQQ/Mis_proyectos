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
#include <SDL/SDL_net.h>
#include <Motor_SDL.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <manejo_socket.h>

int main(){
	int turno[1];
	turno[0]=0;
	inicio_SDL();
	typedef struct pieza p;
	p m[8][8];
	int termino_partida=0;
	creacion_historial();
	while(done == 0){
		inicio_partida(&m,termino_partida,turno);
		//continuar_partida(&m,termino_partida,turno);

		done=1;
	}
	salir();
}