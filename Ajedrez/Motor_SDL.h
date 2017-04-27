#define WIDTH 460
#define HEIGHT 380
#define BPP 24
#define MASK 255,255,255

SDL_Surface *tablero, *screen, *bloque;
SDL_Surface *Pw, *Pb,*Rw,*Rb,*Nw,*Nb,*Bw,*Bb,*Qw,*Qb,*Kw,*Kb;
SDL_Rect dest;
SDL_Event event;
int done = 0;
Uint8 *keys;

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

	tablero = SDL_LoadBMP("imagenes/tablero_cafe2.bmp");
	if(tablero == NULL)
	{
		printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
		exit(1);
	}
	dest.x = 50;
	dest.y = 10;
	dest.w = tablero -> w;
	dest.h = tablero -> h;

	SDL_BlitSurface(tablero, NULL, screen, &dest);
	SDL_Flip(screen);
	SDL_FreeSurface(tablero);

	//peon = SDL_LoadBMP("imagenes/Reina4.bmp");


	keys = SDL_GetKeyState(NULL);
}



void mostrar_tableroSDL(p (*m)[8]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(m[i][j].color=='w'){
				if(m[i][j].tipo_pieza.nombre=='P' ){
					Pw=IMG_Load("imagenes/piezas/Pw.png");
					if(Pw == NULL)
					{
				    	printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
				    	exit(1);
					}

					dest.x = 50+(j*44);
					dest.y = 8+(i*44);

					// (x,y)=50,8 8a
					// (x,y)=50,52 7a
					// (x,y)=50,96 6a
					// (x,y)=
					// f(x,y)=x,44*n, si el primer n es 8  Para la columna, para la fila deberia ser similar

					dest.w = Pw -> w;
					dest.h = Pw -> h;

					SDL_BlitSurface(Pw, NULL, screen, &dest);
					SDL_Flip (screen);
					SDL_FreeSurface(Pw);
				}else{
					if(m[i][j].tipo_pieza.nombre=='R' ){
						Rw=IMG_Load("imagenes/piezas/Rw.png");
						if(Rw == NULL)
						{
					    	printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
					    	exit(1);
						}

						dest.x = 50+(j*44);
						dest.y = 8+(i*44);

						// (x,y)=50,8 8a
						// (x,y)=50,52 7a
						// (x,y)=50,96 6a
						// (x,y)=
						// f(x,y)=x,44*n, si el primer n es 8  Para la columna, para la fila deberia ser similar

						dest.w = Rw -> w;
						dest.h = Rw -> h;

						SDL_BlitSurface(Rw, NULL, screen, &dest);
						SDL_Flip (screen);
						SDL_FreeSurface(Rw);
					}else{
						if(m[i][j].tipo_pieza.nombre=='N' ){
							Nw=IMG_Load("imagenes/piezas/Nw.png");
							if(Nw == NULL)
							{
						    	printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
						    	exit(1);
							}

							dest.x = 50+(j*44);
							dest.y = 8+(i*44);

							// (x,y)=50,8 8a
							// (x,y)=50,52 7a
							// (x,y)=50,96 6a
							// (x,y)=
							// f(x,y)=x,44*n, si el primer n es 8  Para la columna, para la fila deberia ser similar

							dest.w = Nw -> w;
							dest.h = Nw -> h;

							SDL_BlitSurface(Nw, NULL, screen, &dest);
							SDL_Flip (screen);
							SDL_FreeSurface(Nw);
						}else{
							if(m[i][j].tipo_pieza.nombre=='B' ){
								Bw=IMG_Load("imagenes/piezas/Bw.png");
								if(Bw == NULL)
								{
							    	printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
							    	exit(1);
								}

								dest.x = 50+(j*44);
								dest.y = 8+(i*44);

								// (x,y)=50,8 8a
								// (x,y)=50,52 7a
								// (x,y)=50,96 6a
								// (x,y)=
								// f(x,y)=x,44*n, si el primer n es 8  Para la columna, para la fila deberia ser similar

								dest.w = Bw -> w;
								dest.h = Bw -> h;

								SDL_BlitSurface(Bw, NULL, screen, &dest);
								SDL_Flip (screen);
								SDL_FreeSurface(Bw);
							}else{
								if(m[i][j].tipo_pieza.nombre=='Q' ){
									Qw=IMG_Load("imagenes/piezas/Qw.png");
									if(Qw == NULL)
									{
								    	printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
								    	exit(1);
									}

									dest.x = 50+(j*44);
									dest.y = 8+(i*44);

									// (x,y)=50,8 8a
									// (x,y)=50,52 7a
									// (x,y)=50,96 6a
									// (x,y)=
									// f(x,y)=x,44*n, si el primer n es 8  Para la columna, para la fila deberia ser similar

									dest.w = Qw -> w;
									dest.h = Qw -> h;

									SDL_BlitSurface(Qw, NULL, screen, &dest);
									SDL_Flip (screen);
									SDL_FreeSurface(Qw);
								}else{
									if(m[i][j].tipo_pieza.nombre=='K' ){
										Kw=IMG_Load("imagenes/piezas/Kw.png");
										if(Kw == NULL)
										{
									    	printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
									    	exit(1);
										}

										dest.x = 50+(j*44);
										dest.y = 8+(i*44);

										// (x,y)=50,8 8a
										// (x,y)=50,52 7a
										// (x,y)=50,96 6a
										// (x,y)=
										// f(x,y)=x,44*n, si el primer n es 8  Para la columna, para la fila deberia ser similar

										dest.w = Kw -> w;
										dest.h = Kw -> h;

										SDL_BlitSurface(Kw, NULL, screen, &dest);
										SDL_Flip (screen);
										SDL_FreeSurface(Kw);
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
					if(Pb == NULL)
					{
				    	printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
				    	exit(1);
					}

					dest.x = 50+(j*44);
					dest.y = 8+(i*44);

					// (x,y)=50,8 8a
					// (x,y)=50,52 7a
					// (x,y)=50,96 6a
					// (x,y)=
					// f(x,y)=x,44*n, si el primer n es 8  Para la columna, para la fila deberia ser similar

					dest.w = Pb -> w;
					dest.h = Pb -> h;

					SDL_BlitSurface(Pb, NULL, screen, &dest);
					SDL_Flip (screen);
					SDL_FreeSurface(Pb);
				}else{
					if(m[i][j].tipo_pieza.nombre=='R' ){
						Rb=IMG_Load("imagenes/piezas/Rb.png");
						if(Rb == NULL)
						{
					    	printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
					    	exit(1);
						}

						dest.x = 50+(j*44);
						dest.y = 8+(i*44);

						// (x,y)=50,8 8a
						// (x,y)=50,52 7a
						// (x,y)=50,96 6a
						// (x,y)=
						// f(x,y)=x,44*n, si el primer n es 8  Para la columna, para la fila deberia ser similar

						dest.w = Rb -> w;
						dest.h = Rb -> h;

						SDL_BlitSurface(Rb, NULL, screen, &dest);
						SDL_Flip (screen);
						SDL_FreeSurface(Rb);
					}else{
						if(m[i][j].tipo_pieza.nombre=='N' ){
							Nb=IMG_Load("imagenes/piezas/Nb.png");
							if(Nb == NULL)
							{
						    	printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
						    	exit(1);
							}

							dest.x = 50+(j*44);
							dest.y = 8+(i*44);

							// (x,y)=50,8 8a
							// (x,y)=50,52 7a
							// (x,y)=50,96 6a
							// (x,y)=
							// f(x,y)=x,44*n, si el primer n es 8  Para la columna, para la fila deberia ser similar

							dest.w = Nb -> w;
							dest.h = Nb -> h;

							SDL_BlitSurface(Nb, NULL, screen, &dest);
							SDL_Flip (screen);
							SDL_FreeSurface(Nb);
						}else{
							if(m[i][j].tipo_pieza.nombre=='B' ){
								Bb=IMG_Load("imagenes/piezas/Bb.png");
								if(Bb == NULL)
								{
							    	printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
							    	exit(1);
								}

								dest.x = 50+(j*44);
								dest.y = 8+(i*44);

								// (x,y)=50,8 8a
								// (x,y)=50,52 7a
								// (x,y)=50,96 6a
								// (x,y)=
								// f(x,y)=x,44*n, si el primer n es 8  Para la columna, para la fila deberia ser similar

								dest.w = Bb -> w;
								dest.h = Bb -> h;

								SDL_BlitSurface(Bb, NULL, screen, &dest);
								SDL_Flip (screen);
								SDL_FreeSurface(Bb);
							}else{
								if(m[i][j].tipo_pieza.nombre=='Q' ){
									Qb=IMG_Load("imagenes/piezas/Qb.png");
									if(Qb == NULL)
									{
								    	printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
								    	exit(1);
									}

									dest.x = 50+(j*44);
									dest.y = 8+(i*44);

									// (x,y)=50,8 8a
									// (x,y)=50,52 7a
									// (x,y)=50,96 6a
									// (x,y)=
									// f(x,y)=x,44*n, si el primer n es 8  Para la columna, para la fila deberia ser similar

									dest.w = Qb -> w;
									dest.h = Qb -> h;

									SDL_BlitSurface(Qb, NULL, screen, &dest);
									SDL_Flip (screen);
									SDL_FreeSurface(Qb);
								}else{
									if(m[i][j].tipo_pieza.nombre=='K' ){
										Kb=IMG_Load("imagenes/piezas/Kb.png");
										if(Kb == NULL)
										{
									    	printf("No se ha podido cargar la imagen: %s\n", SDL_GetError());
									    	exit(1);
										}

										dest.x = 50+(j*44);
										dest.y = 8+(i*44);

										// (x,y)=50,8 8a
										// (x,y)=50,52 7a
										// (x,y)=50,96 6a
										// (x,y)=
										// f(x,y)=x,44*n, si el primer n es 8  Para la columna, para la fila deberia ser similar

										dest.w = Kb -> w;
										dest.h = Kb -> h;

										SDL_BlitSurface(Kb, NULL, screen, &dest);
										SDL_Flip (screen);
										SDL_FreeSurface(Kb);
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