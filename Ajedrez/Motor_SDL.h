#define WIDTH 460
#define HEIGHT 380
#define BPP 24
#define MASK 255,255,255

SDL_Surface *tablero, *screen, *bloque;
SDL_Surface *Pw, *Pb,*Rw,*Rb,*Nw,*Nb,*Bw,*Bb,*Qw,*Qb,*Kw,*Kb;
SDL_Rect dest;
SDL_Event event;
SDL_Event tecla;
int done = 0;
Uint8 *keys;

tablero_x=50;
tablero_y=10;

struct tipoFuente{
  SDL_Surface *imagen;
  int ancho, alto;
  int anchoLetra, altoLetra;
  int primeraLetra;
} fuente;

void inicio_SDL(){
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

	//peon = SDL_LoadBMP("imagenes/Reina4.bmp");
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

	keys = SDL_GetKeyState(NULL);
}

// (x,y)=50,8 8a
// (x,y)=50,52 7a
// (x,y)=50,96 6a
// (x,y)=
// f(x,y)=x,44*n, si el primer n es 8  Para la columna, para la fila deberia ser similar

int escribirLetra(int x, int y, char letra) {
  SDL_Rect destino, origen; 
  int fila, columna;
  int letrasPorFila, letrasPorColumna;
  
  letrasPorFila = fuente.ancho/fuente.anchoLetra;
  letrasPorColumna = fuente.alto/fuente.altoLetra;
  fila = letra / letrasPorColumna;
  columna = letra % letrasPorColumna;
  origen.x = columna * fuente.anchoLetra;
  origen.y = fila * fuente.altoLetra;
  origen.w = 16;
  origen.h = 16;
  destino.x = x;
  destino.y = y;
  SDL_BlitSurface(fuente.imagen, &origen, screen, &destino);
}

void cargar_tablero_sdl(p (*m)[8]){
	tablero = SDL_LoadBMP("imagenes/tablero_cafe2.bmp");
	dest.x = tablero_x;
	dest.y = tablero_y;
	dest.w = tablero -> w;
	dest.h = tablero -> h;

	SDL_BlitSurface(tablero, NULL, screen, &dest);

	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(m[i][j].color=='w'){
				if(m[i][j].tipo_pieza.nombre=='P' ){
					Pw=IMG_Load("imagenes/piezas/Pw.png");

					dest.x = tablero_x+(j*44);
					dest.y = (tablero_y-2)+(i*44);

					dest.w = Pw -> w;
					dest.h = Pw -> h;

					SDL_BlitSurface(Pw, NULL, screen, &dest);
					
				}else{
					if(m[i][j].tipo_pieza.nombre=='R' ){
						Rw=IMG_Load("imagenes/piezas/Rw.png");

						dest.x = tablero_x+(j*44);
						dest.y = (tablero_y-2)+(i*44);

						dest.w = Rw -> w;
						dest.h = Rw -> h;

						SDL_BlitSurface(Rw, NULL, screen, &dest);
						
					}else{
						if(m[i][j].tipo_pieza.nombre=='N' ){
							Nw=IMG_Load("imagenes/piezas/Nw.png");

							dest.x = tablero_x+(j*44);
							dest.y = (tablero_y-2)+(i*44);

							dest.w = Nw -> w;
							dest.h = Nw -> h;

							SDL_BlitSurface(Nw, NULL, screen, &dest);
							
						}else{
							if(m[i][j].tipo_pieza.nombre=='B' ){
								Bw=IMG_Load("imagenes/piezas/Bw.png");

								dest.x = tablero_x+(j*44);
								dest.y = (tablero_y-2)+(i*44);

								dest.w = Bw -> w;
								dest.h = Bw -> h;

								SDL_BlitSurface(Bw, NULL, screen, &dest);
								
							}else{
								if(m[i][j].tipo_pieza.nombre=='Q' ){
									Qw=IMG_Load("imagenes/piezas/Qw.png");

									dest.x = tablero_x+(j*44);
									dest.y = (tablero_y-2)+(i*44);

									dest.w = Qw -> w;
									dest.h = Qw -> h;

									SDL_BlitSurface(Qw, NULL, screen, &dest);
									
								}else{
									if(m[i][j].tipo_pieza.nombre=='K' ){
										Kw=IMG_Load("imagenes/piezas/Kw.png");

										dest.x = tablero_x+(j*44);
										dest.y = (tablero_y-2)+(i*44);

										dest.w = Kw -> w;
										dest.h = Kw -> h;

										SDL_BlitSurface(Kw, NULL, screen, &dest);
										
									}
								}
							}
						}
					}
				}
			}else{
				//Negras
				if(m[i][j].tipo_pieza.nombre=='P' ){
					Pb=IMG_Load("imagenes/piezas/Pb.png");

					dest.x = tablero_x+(j*44);
					dest.y = (tablero_y-2)+(i*44);

					dest.w = Pb -> w;
					dest.h = Pb -> h;

					SDL_BlitSurface(Pb, NULL, screen, &dest);
									
				}else{
					if(m[i][j].tipo_pieza.nombre=='R' ){
						Rb=IMG_Load("imagenes/piezas/Rb.png");

						dest.x = tablero_x+(j*44);
						dest.y = (tablero_y-2)+(i*44);

						dest.w = Rb -> w;
						dest.h = Rb -> h;

						SDL_BlitSurface(Rb, NULL, screen, &dest);
												
					}else{
						if(m[i][j].tipo_pieza.nombre=='N' ){
							Nb=IMG_Load("imagenes/piezas/Nb.png");

							dest.x = tablero_x+(j*44);
							dest.y = (tablero_y-2)+(i*44);

							dest.w = Nb -> w;
							dest.h = Nb -> h;

							SDL_BlitSurface(Nb, NULL, screen, &dest);							
							
						}else{
							if(m[i][j].tipo_pieza.nombre=='B' ){
								Bb=IMG_Load("imagenes/piezas/Bb.png");

								dest.x = tablero_x+(j*44);
								dest.y = (tablero_y-2)+(i*44);

								dest.w = Bb -> w;
								dest.h = Bb -> h;

								SDL_BlitSurface(Bb, NULL, screen, &dest);
															
							}else{
								if(m[i][j].tipo_pieza.nombre=='Q' ){
									Qb=IMG_Load("imagenes/piezas/Qb.png");

									dest.x = tablero_x+(j*44);
									dest.y = (tablero_y-2)+(i*44);

									dest.w = Qb -> w;
									dest.h = Qb -> h;

									SDL_BlitSurface(Qb, NULL, screen, &dest);									
									
								}else{
									if(m[i][j].tipo_pieza.nombre=='K' ){
										Kb=IMG_Load("imagenes/piezas/Kb.png");

										dest.x = tablero_x+(j*44);
										dest.y = (tablero_y-2)+(i*44);

										dest.w = Kb -> w;
										dest.h = Kb -> h;

										SDL_BlitSurface(Kb, NULL, screen, &dest);
																		
									}
								}
							}
						}
					}
				}
			}	
		}
	}
	SDL_Flip (screen);

	while(SDL_PollEvent(&tecla)){
		if(tecla.type == SDL_QUIT){ exit(0);}
		if(tecla.type ==SDL_KEYDOWN){
			if(tecla.key.keysym.sym == SDLK_ESCAPE){
				exit(0);
			}
		}
	}

	SDL_FreeSurface(tablero);
	SDL_FreeSurface(Pw);
	SDL_FreeSurface(Rw);
	SDL_FreeSurface(Nw);
	SDL_FreeSurface(Bw);
	SDL_FreeSurface(Qw);
	SDL_FreeSurface(Kw);
	SDL_FreeSurface(Pb);
	SDL_FreeSurface(Rb);
	SDL_FreeSurface(Nb);
	SDL_FreeSurface(Bb);
	SDL_FreeSurface(Qb);
	SDL_FreeSurface(Kb);

}