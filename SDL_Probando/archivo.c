#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#define WIDTH 720	
#define HEIGHT 650
#define BPP 24

SDL_Surface *tablero, *screen;
SDL_Rect dest;
SDL_Event event;
int done = 0;
Uint8 *keys;

struct nave{
    int x,y;
} minave;

int main(){


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

	tablero = SDL_LoadBMP("imagenes/tablero.bmp");
	if(tablero == NULL)
	{
    	printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
    	exit(1);
	}

	minave.x = 50;
	minave.y = 10;

	dest.x = minave.x;
	dest.y = minave.y;
	dest.w = tablero -> w;
	dest.h = tablero -> h;

	SDL_BlitSurface(tablero, NULL, screen, &dest);
	SDL_Flip(screen);
	SDL_FreeSurface(tablero);

	keys = SDL_GetKeyState(NULL);
	 // Esperamos la pulsación de una tecla para salir 
	while(done == 0)
{
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_KEYDOWN) {done = 1;}
    }
} 
	return 0;
}