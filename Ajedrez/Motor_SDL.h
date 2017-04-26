#define WIDTH 460
#define HEIGHT 380
#define BPP 24
#define MASK 255,255,255

SDL_Surface *tablero, *screen, *peon;
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
					peon=IMG_Load("imagenes/piezas/Pw.png");
					if(peon == NULL)
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

					dest.w = peon -> w;
					dest.h = peon -> h;

					SDL_BlitSurface(peon, NULL, screen, &dest);
					SDL_Flip (screen);
					SDL_FreeSurface(peon);
				}else{
					if(m[i][j].tipo_pieza.nombre=='R' ){
						peon=IMG_Load("imagenes/piezas/Rw.png");
						if(peon == NULL)
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

						dest.w = peon -> w;
						dest.h = peon -> h;

						SDL_BlitSurface(peon, NULL, screen, &dest);
						SDL_Flip (screen);
						SDL_FreeSurface(peon);
					}else{
						if(m[i][j].tipo_pieza.nombre=='N' ){
							peon=IMG_Load("imagenes/piezas/Nw.png");
							if(peon == NULL)
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

							dest.w = peon -> w;
							dest.h = peon -> h;

							SDL_BlitSurface(peon, NULL, screen, &dest);
							SDL_Flip (screen);
							SDL_FreeSurface(peon);
						}else{
							if(m[i][j].tipo_pieza.nombre=='B' ){
								peon=IMG_Load("imagenes/piezas/Bw.png");
								if(peon == NULL)
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

								dest.w = peon -> w;
								dest.h = peon -> h;

								SDL_BlitSurface(peon, NULL, screen, &dest);
								SDL_Flip (screen);
								SDL_FreeSurface(peon);
							}else{
								if(m[i][j].tipo_pieza.nombre=='Q' ){
									peon=IMG_Load("imagenes/piezas/Qw.png");
									if(peon == NULL)
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

									dest.w = peon -> w;
									dest.h = peon -> h;

									SDL_BlitSurface(peon, NULL, screen, &dest);
									SDL_Flip (screen);
									SDL_FreeSurface(peon);
								}else{
									if(m[i][j].tipo_pieza.nombre=='K' ){
										peon=IMG_Load("imagenes/piezas/Kw.png");
										if(peon == NULL)
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

										dest.w = peon -> w;
										dest.h = peon -> h;

										SDL_BlitSurface(peon, NULL, screen, &dest);
										SDL_Flip (screen);
										SDL_FreeSurface(peon);
									}
								}
							}
						}
					}
				}
			}else{
				//Negras
				if(m[i][j].tipo_pieza.nombre=='P' ){
					peon=IMG_Load("imagenes/piezas/Pb.png");
					if(peon == NULL)
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

					dest.w = peon -> w;
					dest.h = peon -> h;

					SDL_BlitSurface(peon, NULL, screen, &dest);
					SDL_Flip (screen);
					SDL_FreeSurface(peon);
				}else{
					if(m[i][j].tipo_pieza.nombre=='R' ){
						peon=IMG_Load("imagenes/piezas/Rb.png");
						if(peon == NULL)
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

						dest.w = peon -> w;
						dest.h = peon -> h;

						SDL_BlitSurface(peon, NULL, screen, &dest);
						SDL_Flip (screen);
						SDL_FreeSurface(peon);
					}else{
						if(m[i][j].tipo_pieza.nombre=='N' ){
							peon=IMG_Load("imagenes/piezas/Nb.png");
							if(peon == NULL)
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

							dest.w = peon -> w;
							dest.h = peon -> h;

							SDL_BlitSurface(peon, NULL, screen, &dest);
							SDL_Flip (screen);
							SDL_FreeSurface(peon);
						}else{
							if(m[i][j].tipo_pieza.nombre=='B' ){
								peon=IMG_Load("imagenes/piezas/Bb.png");
								if(peon == NULL)
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

								dest.w = peon -> w;
								dest.h = peon -> h;

								SDL_BlitSurface(peon, NULL, screen, &dest);
								SDL_Flip (screen);
								SDL_FreeSurface(peon);
							}else{
								if(m[i][j].tipo_pieza.nombre=='Q' ){
									peon=IMG_Load("imagenes/piezas/Qb.png");
									if(peon == NULL)
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

									dest.w = peon -> w;
									dest.h = peon -> h;

									SDL_BlitSurface(peon, NULL, screen, &dest);
									SDL_Flip (screen);
									SDL_FreeSurface(peon);
								}else{
									if(m[i][j].tipo_pieza.nombre=='K' ){
										peon=IMG_Load("imagenes/piezas/Kb.png");
										if(peon == NULL)
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

										dest.w = peon -> w;
										dest.h = peon -> h;

										SDL_BlitSurface(peon, NULL, screen, &dest);
										SDL_Flip (screen);
										SDL_FreeSurface(peon);
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