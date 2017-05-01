#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_net.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <socket_sdl.h>


#define WIDTH 800
#define HEIGHT 700
#define BPP 24
#define MASK 255,255,255

SDL_Surface *tablero, *screen, *peon;
SDL_Rect dest;
SDL_Event event;
int done = 0;
Uint8 *keys;

TTF_Font *fuente;
SDL_Surface *texto;
SDL_Surface *imprimir;
SDL_Color color_fuente = {255, 255, 255};
SDL_Color color_fondo = { 0, 0, 0 };

SDL_Rect seccion[8];

struct nave{
    int x,y;
} minave;

int main(){
	char buffer;
	int aux=0;
/*
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
	    printf("No se ha podido iniciar SDL: %s\n", SDL_GetError());
	    exit(1);
	}

	screen = SDL_SetVideoMode(WIDTH, HEIGHT, BPP, SDL_HWSURFACE);
	if(screen == NULL)
	{
    	printf("No se ha podido establecer el modo de vídeo: %s\n", SDL_GetError());
    	exit(1);
	}

	 SDL_WM_SetCaption("Ajedrez 1.0v","Ajedrez 1.0v");

	 if (TTF_Init() != 0)
  	{
  		printf("No se ha podido iniciar TTF: %s\n", SDL_GetError());
    	exit(1);	
  	}
	fuente=TTF_OpenFont( "pixel.ttf", 60 );

	if (fuente == NULL)
   {
   		printf("Error al abrir la color_fuente: %s\n", SDL_GetError());
    	exit(1);
   }

	texto=TTF_RenderText_Shaded(fuente,"Hola tenemos problemas con las fuentes", color_fuente,color_fondo );
	SDL_BlitSurface(texto, NULL, screen, NULL);

	 if (texto == NULL)
   	{
   		printf("Error texto vacio %s\n", SDL_GetError());
    	exit(1);
   	}

   	//SDL_Rect textLocation = { 100, 100, 0, 0 };
   	lineRGBA(screen, 20, 10, 70, 90, 255, 0, 0, 255);
*/
	//SDL_Flip(screen);
	printf("Desea ser servidor o cliente? ");
	scanf("\n%c", &buffer);
	if(buffer=='s'){
		create_server();
	}else{
		conect_server();
	}

	while(1){
		if(buffer=='s'){
			recv_client_server();
		}else{
			send_client_server();
		}
		printf("%i",aux);
		aux++;
	}
	return 0;
}