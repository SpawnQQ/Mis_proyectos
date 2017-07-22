#include <postgresql/libpq-fe.h>
#include <SDL/SDL.h> 
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_net.h>
#include <stdlib.h>
#include <stdio.h>
#include <estructuras.h>
#include <metodos.h>
#include <movimiento.h>
#include <manejo_ficheros.h>
#include <jaque_mate.h>
#include <tablas.h>
#include <Motor_SDL.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <manejo_socket.h>
#include <postgres.h>

int main(){
	int turno[1];
	turno[0]=0;
	inicio_SDL();
	typedef struct pieza p;
	p m[8][8];
	int termino_partida=0;
	conexion_postgres();
	logear();
	while(done == 0){
		inicio_partida(&m,termino_partida,turno);
		//continuar_partida(&m,termino_partida,turno);

		done=1;
	}
	salir();
}