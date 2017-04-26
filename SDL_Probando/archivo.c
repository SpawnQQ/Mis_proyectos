#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define WIDTH 460
#define HEIGHT 380
#define BPP 24
#define MASK 255,255,255

SDL_Surface *tablero, *screen, *peon;
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

	tablero = SDL_LoadBMP("imagenes/tablero_cafe2.bmp");
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

	//peon = SDL_LoadBMP("imagenes/Reina4.bmp");
	peon=IMG_Load("imagenes/piezas/Rw.png");
	if(peon == NULL)
	{
    	printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
    	exit(1);
	}

	dest.x = 50+(7*44);
	dest.y = 8+(0*44);

	// (x,y)=50,8 8a
	// (x,y)=50,52 7a
	// (x,y)=50,96 6a
	// (x,y)=
	// f(x,y)=x,44*n, si el primer n es 8  Para la columna, para la fila deberia ser similar

	dest.w = peon -> w;
	dest.h = peon -> h;

	SDL_BlitSurface(peon, NULL, screen, &dest);
	SDL_Flip (screen);
	SDL_FreeSurface(peon);


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