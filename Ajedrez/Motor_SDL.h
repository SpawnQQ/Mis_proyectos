#define WIDTH 500
#define HEIGHT 460
#define BPP 24
#define MASK 255,255,255

SDL_Surface *tablero, *screen, *bloque;
SDL_Surface *Pw, *Pb,*Rw,*Rb,*Nw,*Nb,*Bw,*Bb,*Qw,*Qb,*Kw,*Kb;
SDL_Rect dest;
SDL_Event event;
SDL_Event tecla;
int done = 0;
Uint8 *keys;

SDL_MouseButtonEvent button;

TTF_Font *fuente;
SDL_Surface *texto = NULL;
SDL_Surface *texto_dos = NULL;
SDL_Color color_fuente = {0, 0, 0};
SDL_Color color_fondo = { 210,210,210};

tablero_x=50;
tablero_y=50;

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

	SDL_WM_SetCaption("Ajedrez 1.0v","Ajedrez 1.0v");

	//peon = SDL_LoadBMP("imagenes/Reina4.bmp");
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 210,210,210));

	TTF_Init();

	keys = SDL_GetKeyState(NULL);
}

// (x,y)=50,8 8a
// (x,y)=50,52 7a
// (x,y)=50,96 6a
// (x,y)=
// f(x,y)=x,44*n, si el primer n es 8  Para la columna, para la fila deberia ser similar
void agregar_contorno(){
	lineRGBA(screen, tablero_x, tablero_y, tablero_x+352, tablero_y, 0, 0, 0, 255);
	lineRGBA(screen, tablero_x, tablero_y, tablero_x, tablero_y+352, 0, 0, 0, 255);
	lineRGBA(screen, tablero_x+352, tablero_y, tablero_x+352, tablero_y+352, 0, 0, 0, 255);
	lineRGBA(screen, tablero_x, tablero_y+352, tablero_x+352, tablero_y+352, 0, 0, 0, 255);
}

void agregar_referencia(p (*m)[8]){
	int fila=14	,columna=0;
	fuente=TTF_OpenFont( "fuentes/pixel.ttf", 40 );

	for(int i=0;i<8;i++){
		if(i==0){
				texto=TTF_RenderText_Shaded(fuente,"8", color_fuente ,color_fondo);
				SDL_Rect textLocation = { tablero_x-30, tablero_y+columna, 0, 0 };
				SDL_BlitSurface(texto, NULL, screen, &textLocation);

				texto=TTF_RenderText_Shaded(fuente,"8", color_fuente ,color_fondo);
				SDL_Rect textLocation2 = { tablero_x+367, tablero_y+columna, 0, 0 };
				SDL_BlitSurface(texto, NULL, screen, &textLocation2);
				columna=columna+44;
			}else{
				if(i==1){
					texto=TTF_RenderText_Shaded(fuente,"7", color_fuente ,color_fondo);
					SDL_Rect textLocation = { tablero_x-30,tablero_y+columna, 0, 0 };
					SDL_BlitSurface(texto, NULL, screen, &textLocation);

					texto=TTF_RenderText_Shaded(fuente,"7", color_fuente ,color_fondo);
					SDL_Rect textLocation2 = { tablero_x+367, tablero_y+columna, 0, 0 };
					SDL_BlitSurface(texto, NULL, screen, &textLocation2);
					columna=columna+44;
				}else{
					if(i==2){
						texto=TTF_RenderText_Shaded(fuente,"6", color_fuente ,color_fondo);
						SDL_Rect textLocation = { tablero_x-30, tablero_y+columna, 0, 0 };
						SDL_BlitSurface(texto, NULL, screen, &textLocation);

						texto=TTF_RenderText_Shaded(fuente,"6", color_fuente ,color_fondo);
						SDL_Rect textLocation2 = { tablero_x+367, tablero_y+columna, 0, 0 };
						SDL_BlitSurface(texto, NULL, screen, &textLocation2);
						columna=columna+44;
					}else{
						if(i==3){
							texto=TTF_RenderText_Shaded(fuente,"5", color_fuente ,color_fondo);
							SDL_Rect textLocation = { tablero_x-30, tablero_y+columna, 0, 0 };
							SDL_BlitSurface(texto, NULL, screen, &textLocation);

							texto=TTF_RenderText_Shaded(fuente,"5", color_fuente ,color_fondo);
							SDL_Rect textLocation2 = { tablero_x+367, tablero_y+columna, 0, 0 };
							SDL_BlitSurface(texto, NULL, screen, &textLocation2);
							columna=columna+44;
						}else{
							if(i==4){
								texto=TTF_RenderText_Shaded(fuente,"4", color_fuente ,color_fondo);
								SDL_Rect textLocation = { tablero_x-30, tablero_y+columna, 0, 0 };
								SDL_BlitSurface(texto, NULL, screen, &textLocation);

								texto=TTF_RenderText_Shaded(fuente,"4", color_fuente ,color_fondo);
								SDL_Rect textLocation2 = { tablero_x+367, tablero_y+columna, 0, 0 };
								SDL_BlitSurface(texto, NULL, screen, &textLocation2);
								columna=columna+44;
							}else{
								if(i==5){
									texto=TTF_RenderText_Shaded(fuente,"3", color_fuente ,color_fondo);
									SDL_Rect textLocation = { tablero_x-30, tablero_y+columna, 0, 0 };
									SDL_BlitSurface(texto, NULL, screen, &textLocation);

									texto=TTF_RenderText_Shaded(fuente,"3", color_fuente ,color_fondo);
									SDL_Rect textLocation2 = { tablero_x+367, tablero_y+columna, 0, 0 };
									SDL_BlitSurface(texto, NULL, screen, &textLocation2);
									columna=columna+44;
								}else{
									if(i==6){
										texto=TTF_RenderText_Shaded(fuente,"2", color_fuente ,color_fondo);
										SDL_Rect textLocation = { tablero_x-30, tablero_y+columna, 0, 0 };
										SDL_BlitSurface(texto, NULL, screen, &textLocation);

										texto=TTF_RenderText_Shaded(fuente,"2", color_fuente ,color_fondo);
										SDL_Rect textLocation2 = { tablero_x+367, tablero_y+columna, 0, 0 };
										SDL_BlitSurface(texto, NULL, screen, &textLocation2);
										columna=columna+44;
									}else{
										if(i==7){
											texto=TTF_RenderText_Shaded(fuente,"1", color_fuente ,color_fondo);
											SDL_Rect textLocation = { tablero_x-30, tablero_y+columna, 0, 0 };
											SDL_BlitSurface(texto, NULL, screen, &textLocation);

											texto=TTF_RenderText_Shaded(fuente,"1", color_fuente ,color_fondo);
											SDL_Rect textLocation2 = { tablero_x+367, tablero_y+columna, 0, 0 };
											SDL_BlitSurface(texto, NULL, screen, &textLocation2);
											columna=columna+44;
										}	
									}
								}
							}
						}
					}
				}
			}
		for(int j=0;j<8;j++){
			if(i==0){
				if(j==0){
					texto=TTF_RenderText_Shaded(fuente,"A", color_fuente ,color_fondo);
					SDL_Rect textLocation = { fila+tablero_x, tablero_y-43, 0, 0 };
					SDL_BlitSurface(texto, NULL, screen, &textLocation);

					texto=TTF_RenderText_Shaded(fuente,"A", color_fuente ,color_fondo);
					SDL_Rect textLocation2 = { fila+tablero_x, tablero_y+360, 0, 0 };
					SDL_BlitSurface(texto, NULL, screen, &textLocation2);
					fila=fila+44;
				}else{
					if(j==1){
						texto=TTF_RenderText_Shaded(fuente,"B", color_fuente ,color_fondo);
						SDL_Rect textLocation = { fila+tablero_x, tablero_y-43, 0, 0 };
						SDL_BlitSurface(texto, NULL, screen, &textLocation);

						texto=TTF_RenderText_Shaded(fuente,"B", color_fuente ,color_fondo);
						SDL_Rect textLocation2 = { fila+tablero_x, tablero_y+360, 0, 0 };
						SDL_BlitSurface(texto, NULL, screen, &textLocation2);
						fila=fila+44;
					}else{
						if(j==2){
							texto=TTF_RenderText_Shaded(fuente,"C", color_fuente ,color_fondo);
							SDL_Rect textLocation = { fila+tablero_x, tablero_y-43, 0, 0 };
							SDL_BlitSurface(texto, NULL, screen, &textLocation);

							texto=TTF_RenderText_Shaded(fuente,"C", color_fuente ,color_fondo);
							SDL_Rect textLocation2 = { fila+tablero_x, tablero_y+360, 0, 0 };
							SDL_BlitSurface(texto, NULL, screen, &textLocation2);
							fila=fila+44;
						}else{
							if(j==3){
								texto=TTF_RenderText_Shaded(fuente,"D", color_fuente ,color_fondo);
								SDL_Rect textLocation = { fila+tablero_x, tablero_y-43, 0, 0 };
								SDL_BlitSurface(texto, NULL, screen, &textLocation);

								texto=TTF_RenderText_Shaded(fuente,"D", color_fuente ,color_fondo);
								SDL_Rect textLocation2 = { fila+tablero_x, tablero_y+360, 0, 0 };
								SDL_BlitSurface(texto, NULL, screen, &textLocation2);
								fila=fila+44;
							}else{
								if(j==4){
									texto=TTF_RenderText_Shaded(fuente,"E", color_fuente ,color_fondo);
									SDL_Rect textLocation = { fila+tablero_x, tablero_y-43, 0, 0 };
									SDL_BlitSurface(texto, NULL, screen, &textLocation);

									texto=TTF_RenderText_Shaded(fuente,"E", color_fuente ,color_fondo);
									SDL_Rect textLocation2 = { fila+tablero_x, tablero_y+360, 0, 0 };
									SDL_BlitSurface(texto, NULL, screen, &textLocation2);
									fila=fila+44;
								}else{
									if(j==5){
										texto=TTF_RenderText_Shaded(fuente,"F", color_fuente ,color_fondo);
										SDL_Rect textLocation = { fila+tablero_x, tablero_y-43, 0, 0 };
										SDL_BlitSurface(texto, NULL, screen, &textLocation);

										texto=TTF_RenderText_Shaded(fuente,"F", color_fuente ,color_fondo);
										SDL_Rect textLocation2 = { fila+tablero_x, tablero_y+360, 0, 0 };
										SDL_BlitSurface(texto, NULL, screen, &textLocation2);
										fila=fila+44;
									}else{
										if(j==6){
											texto=TTF_RenderText_Shaded(fuente,"G", color_fuente ,color_fondo);
											SDL_Rect textLocation = { fila+tablero_x, tablero_y-43, 0, 0 };
											SDL_BlitSurface(texto, NULL, screen, &textLocation);

											texto=TTF_RenderText_Shaded(fuente,"G", color_fuente ,color_fondo);
											SDL_Rect textLocation2 = { fila+tablero_x, tablero_y+360, 0, 0 };
											SDL_BlitSurface(texto, NULL, screen, &textLocation2);
											fila=fila+44;
										}else{
											if(j==7){
												texto=TTF_RenderText_Shaded(fuente,"H", color_fuente ,color_fondo);
												SDL_Rect textLocation = { fila+tablero_x, tablero_y-43, 0, 0 };
												SDL_BlitSurface(texto, NULL, screen, &textLocation);

												texto=TTF_RenderText_Shaded(fuente,"H", color_fuente ,color_fondo);
												SDL_Rect textLocation2 = { fila+tablero_x, tablero_y+360, 0, 0 };
												SDL_BlitSurface(texto, NULL, screen, &textLocation2);
												fila=fila+44;
											}	
										}
									}
								}
							}
						}
					}
				}
			}	
		}
	}
	SDL_FreeSurface(texto);

}

void cargar_tablero_sdl(p (*m)[8]){

	tablero = SDL_LoadBMP("imagenes/tablero_cafe2.bmp");
	dest.x = tablero_x;
	dest.y = tablero_y;
	dest.w = tablero -> w;
	dest.h = tablero -> h;

	SDL_BlitSurface(tablero, NULL, screen, &dest);

	agregar_contorno();

	agregar_referencia(m);
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

void liberar_memoria(){
	TTF_Quit();
	SDL_Quit();
	exit(0);
}

void lectura_datos(char posicion[2]){
int salir=0;
int x = 0, y = 0;
	while(salir==0){
		if(SDL_PollEvent(&event)){

			if( event.type == SDL_MOUSEBUTTONDOWN ){
				//En caso de que el event capturado fuera la presión del botón izquierdo del mouse se continuara con el código entre llaves

				if( event.button.button == SDL_BUTTON_LEFT ){
					x = event.button.x;
					y = event.button.y;
					//Revisa que el mouse aun este dentro del area designada como nuestro boton
					printf("%i, %i\n", x,y);
				}
			}

			if(event.type == SDL_QUIT){ 
				liberar_memoria();
			}
			if(event.type ==SDL_KEYDOWN){
				if(event.key.keysym.sym == SDLK_ESCAPE){
					liberar_memoria();

				}
			}
		}
	}
}