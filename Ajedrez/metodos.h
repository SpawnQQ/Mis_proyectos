#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define ESCAPE 27 

int modalidad=0;
int archivo=0; 
bool cambio_mod=false;
bool cambio_arch=false;
SDL_Event eventos_menu;
int forzar_termino=0;

typedef struct pieza p;
void matriz_setPieza( p (*m)[8],int i, int j,char color, int turno,char nombre,int posicion_1,int posicion_2);

void tablero_inicio(p (*m)[8]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(i==1){
				matriz_setPieza(m,i,j,'b',1,'P',i,j);
			}else{
				if(i==6){
					matriz_setPieza(m,i,j,'w',1,'P',i,j);	
				}else{
					if(i==0 && (j==0 || j==7)){
						matriz_setPieza(m,i,j,'b',1,'R',i,j);					
					}else{
						if(i==7 && (j==0 || j==7)){
							matriz_setPieza(m,i,j,'w',1,'R',i,j);
						}else{
							if(i==0 && (j==1 || j==6)){
								matriz_setPieza(m,i,j,'b',1,'N',i,j);
							}else{
								if(i==7 && (j==1 || j==6)){
									matriz_setPieza(m,i,j,'w',1,'N',i,j);
								}else{
									if(i==0 && (j==2 || j==5)){
										matriz_setPieza(m,i,j,'b',1,'B',i,j);
									}else{
										if(i==7 && (j==2 || j==5)){
											matriz_setPieza(m,i,j,'w',1,'B',i,j);
										}else{
											if(i==0 && j==3){
												matriz_setPieza(m,i,j,'b',1,'Q',i,j);
											}else{
												if(i==0 && j==4){
													matriz_setPieza(m,i,j,'b',1,'K',i,j);
												}else{
													if(i==7 && j==3){
														matriz_setPieza(m,i,j,'w',1,'Q',i,j);
													}else{
														if(i==7 && j==4){
															matriz_setPieza(m,i,j,'w',1,'K',i,j);
														}else{
															matriz_setPieza(m,i,j,'V',0,'V',i,j);
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
			}
		}
	}
}

//Funcion para cambiar el valor de una casilla de la matriz
void matriz_setPieza( p (*m)[8],int i, int j,char color, int turno,char nombre,int posicion_1,int posicion_2){
	m[i][j].color=color;
	m[i][j].primer_turno=turno;
	m[i][j].tipo_pieza.nombre=nombre;
	m[i][j].tipo_pieza.posicion[0]=posicion_1;
	m[i][j].tipo_pieza.posicion[1]=posicion_2;
}

//Fuente de donde saque los colores
//http://bitmote.com/index.php?post/2012/11/19/Using-ANSI-Color-Codes-to-Colorize-Your-Bash-Prompt-on-Linux
void mostrar_tablero(p (*m)[8]){
	printf("   a  b  c  d  e  f  g  h\n");
	for(int i=0;i<8;i++){
		printf(" %d ", 9-(i+1));
		for(int j=0;j<8;j++){
			if((j+i+(8*i))%2==0){
				if(m[i][j].tipo_pieza.nombre=='V'){
					//Si la casilla es par 33
					printf("\033[0;33;43m%c%c ",m[i][j].tipo_pieza.nombre,m[i][j].color);
					printf("\033[0m");
				}else{
					if(m[i][j].color=='w'){
						//Si la casilla es par
						printf("\033[0;1;37;43m%c%c ",m[i][j].tipo_pieza.nombre,m[i][j].color);
						printf("\033[0m");
					}else{
						//Si la casilla es par
						printf("\033[0;1;43m%c%c ",m[i][j].tipo_pieza.nombre,m[i][j].color);
						printf("\033[0m");
					}
					
				}	
			}else{
				if(m[i][j].tipo_pieza.nombre=='V'){
					//Si la casilla es impar 31
					printf("\033[0;31;41m%c%c ",m[i][j].tipo_pieza.nombre,m[i][j].color);
					printf("\033[0m");
				}else{
					if(m[i][j].color=='w'){
						printf("\033[0;1;37;41m%c%c ",m[i][j].tipo_pieza.nombre,m[i][j].color);
						printf("\033[0m");
					}else{
						printf("\033[0;1;41m%c%c ",m[i][j].tipo_pieza.nombre,m[i][j].color);
						printf("\033[0m");
					}
				}	
			}
		}
		printf(" %d ", 9-(i+1));
		printf("\n");
	}
	printf("   a  b  c  d  e  f  g  h\n");
}

void desarrollo_partida_custom(p (*m)[8],int termino_partida, int turnos[]){
	p respaldo[8][8];
	int cantidad_turnos=turnos[0];
	cantidad_turnos++;
	char seleccion_pieza[2];
	char posicion[2];
	char pieza_mov[2];
	char pieza_remov[2];
	int mov_permitido=1;
	int conocer_jaque;

	//Sabemos el jugador, dividiendo la cantidad de turnos por 2, asi sabemos si el turno es par o impar
	int jugador=cantidad_turnos%2;
	//Iniciamos la partida
	cargar_tablero_sdl(m);
	while(termino_partida==0){
		conocer_jaque=0;
		actualizar_PAP(cantidad_turnos,m);
		if(jaque(cantidad_turnos,m)){
			conocer_jaque=1;
			if(jaque_mate(cantidad_turnos,m)){
				forzar_termino=1;
				termino_partida=1;

				if(cantidad_turnos%2==0){
					SDL_WM_SetCaption("¡Victoria de las blancas!","Ajedrez 1.0v");
				}else{
					SDL_WM_SetCaption("¡Victoria de las negras!","Ajedrez 1.0v");
				}

				goto fin_partida_custom;
			}else{ 
				printf("Tu rey esta en jaque!!\n");
			}
		}
		if(cantidad_turnos%2!=0 && conocer_jaque==0){
			SDL_WM_SetCaption("Turno de las blancas","Ajedrez 1.0v");
		}else{
			if(cantidad_turnos%2==0 && conocer_jaque==0){
				SDL_WM_SetCaption("Turno de las negras","Ajedrez 1.0v");
			}else{
				if(cantidad_turnos%2!=0 && conocer_jaque==1){
					SDL_WM_SetCaption("¡El rey blanco esta en jaque!","Ajedrez 1.0v");
				}else{
					if(cantidad_turnos%2==0 && conocer_jaque==1){
						SDL_WM_SetCaption("¡El rey negro esta en jaque!","Ajedrez 1.0v");
					}
				}
			}
			
		}
		
		printf("Jugador %d, seleccione pieza a mover: \n",jugador*(-1)+2);
		lectura_datos(seleccion_pieza);
		if(cambio_mod==true){
			goto fin_partida_custom;
		}
		if(cambio_arch==true){
			goto fin_partida_custom;
		}

		//scanf("\n%s", &seleccion_pieza);
		////system("clear");
		input(seleccion_pieza);
		if(verificacion_seleccion_pieza(m,seleccion_pieza,jugador)==0 ){
			printf("Error de tipeo, porfavor seleccione nuevamente\n");
			cargar_tablero_sdl(m);
		}else{
			if(mover_restringido(seleccion_pieza,m)==0){

				printf("Pieza con movimiento restringido. Porfavor elegir otra\n");
				cargar_tablero_sdl(m);
			}else{
				int inicio_fila=transformar_num(seleccion_pieza[0]);
				int inicio_columna=transformar_num(seleccion_pieza[1]);
				//jaque_elegir si retorna 0, no hay ningun movimiento de la pieza elejida que resguarde al rey
				if(jaque_elegir(cantidad_turnos,inicio_fila,inicio_columna,m)==0){

					printf("Movimiento no permitido. No puedes dejar vulnerable a tu rey.\n");
					cargar_tablero_sdl(m);
				}else{
					//Este while, sirve para verificar que el movimiento ingresado sea correcto
					do{
						cargar_tablero_sdl(m);
						contorno_unico(seleccion_pieza[0],seleccion_pieza[1]);
						printf("Pieza %c%c, posicion %s. Ingrese un movimiento: \n",m[inicio_fila][inicio_columna].tipo_pieza.nombre,m[inicio_fila][inicio_columna].color,&seleccion_pieza);
						lectura_datos(posicion);
						if(cambio_mod==true){
							goto fin_partida_custom;
						}

						if(cambio_arch==true){
							goto fin_partida_custom;
						}

						input(posicion);
						if(validacion_entrada(posicion)==1){
							int destino_fila=transformar_num(posicion[0]);
							int destino_columna=transformar_num(posicion[1]);
						
							pieza_mov[0]=m[inicio_fila][inicio_columna].tipo_pieza.nombre;
							pieza_mov[1]=m[inicio_fila][inicio_columna].color;

							pieza_remov[0]=m[destino_fila][destino_columna].tipo_pieza.nombre;
							pieza_remov[1]=m[destino_fila][destino_columna].color;

							respaldar_tablero(respaldo,m);

							elegir_movimiento_pieza(inicio_fila,inicio_columna,destino_fila,destino_columna, m, &mov_permitido);
							//Preguntamos si el movimiento es valido, no es valido, repetira la pregunta
							if(mov_permitido==1){
								//Si el movimiento es permitido
								if(jaque(cantidad_turnos,m)){
									//Verificamos si el movimiento efectuado deja vulnerable al rey
									//system("clear");
									respaldar_tablero(m,respaldo);
									printf("Movimiento no permitido. No puedes dejar vulnerable a tu rey.\n");
									mov_permitido=0;
								}else{
									promocion_peon(destino_fila,destino_columna,respaldo,m);
									//Aca va la funcion del sonido
									//system("/usr/bin/mpg123 -q /home/dahaka/Mis_proyectos/Ajedrez/tablero0.1.mp3");
									movimientos_historial(cantidad_turnos,seleccion_pieza,posicion,pieza_mov,pieza_remov);
									cantidad_turnos++;
									jugador=cantidad_turnos%2;
									//system("clear");
									cargar_tablero_sdl(m);
									guardar_partida(m,cantidad_turnos);
								}
								
							}else{
								//system("clear");
								printf("Movimiento no permitido\n");
							}
						}else{
							//system("clear");
							printf("Movimiento no permitido\n");
							mov_permitido=0;
						}	
					}while(mov_permitido==0);
				}
			}
		}
	}
	fin_partida_custom: ;
}


//################################################### Desarollo del juego ###################################################

void desarrollo_partida_multi(p (*m)[8],int termino_partida, int turnos[]){
	char direccion[15];
	char host;
	printf("Desea ser servidor o cliente? ");
	scanf("\n%c", &host);
	if(host=='s'){
		create_server();
	}else{
		printf("Porfavor ingrese direccion\n");
		scanf("\n%s", &direccion);
		conect_server(direccion);
	}

	p respaldo[8][8];
	int cantidad_turnos=turnos[0];
	cantidad_turnos++;
	char seleccion_pieza[2];
	char posicion[2];
	char pieza_mov[2];
	char pieza_remov[2];
	int mov_permitido=1;
	int conocer_jaque;

	//Sabemos el jugador, dividiendo la cantidad de turnos por 2, asi sabemos si el turno es par o impar
	int jugador=cantidad_turnos%2;
	//Iniciamos la partida
	cargar_tablero_sdl(m);
	while(termino_partida==0){
		conocer_jaque=0;
		actualizar_PAP(cantidad_turnos,m);
		if(jaque(cantidad_turnos,m)){
			conocer_jaque=1;
			if(jaque_mate(cantidad_turnos,m)){
				termino_partida=1;
				forzar_termino=1;
				if(cantidad_turnos%2==0){
					if(host=='s'){
						SDL_WM_SetCaption("¡Derrota!","Ajedrez 1.0v");
					}else{
						SDL_WM_SetCaption("¡Victoria!","Ajedrez 1.0v");
					}
				}else{
					if(host=='s'){
						SDL_WM_SetCaption("¡Victoria!","Ajedrez 1.0v");
					}else{
						SDL_WM_SetCaption("¡Derrota!","Ajedrez 1.0v");
					}
				}
				goto fin_partida_multi;
			}else{ 
				printf("Tu rey esta en jaque!!\n");
			}
		}
		if(cantidad_turnos%2!=0 && conocer_jaque==0){
			if(host=='s'){
				SDL_WM_SetCaption("Turno de las blancas. Esperando datos del cliente...","Ajedrez 1.0v");
			}else{
				SDL_WM_SetCaption("Turno de las blancas. Ejecute una accion.","Ajedrez 1.0v");
			}
		}else{
			if(cantidad_turnos%2==0 && conocer_jaque==0){
				if(host=='s'){
					SDL_WM_SetCaption("Turno de las negras. Ejecute una accion.","Ajedrez 1.0v");
				}else{
					SDL_WM_SetCaption("Turno de las negras. Esperando datos del servidor...","Ajedrez 1.0v");
				}
			}else{
				if(cantidad_turnos%2!=0 && conocer_jaque==1){
					if(host=='s'){
						SDL_WM_SetCaption("¡El rey blanco esta en jaque!. Esperando datos del cliente...","Ajedrez 1.0v");
					}else{
						SDL_WM_SetCaption("¡El rey blanco esta en jaque!. Ejecute una accion.","Ajedrez 1.0v");
					}
				}else{
					if(cantidad_turnos%2==0 && conocer_jaque==1){
						if(host=='s'){
							SDL_WM_SetCaption("¡El rey negro esta en jaque!. Ejecute una accion.","Ajedrez 1.0v");
						}else{
							SDL_WM_SetCaption("¡El rey negro esta en jaque!. Esperando datos del servidor...","Ajedrez 1.0v");
						}
					}
				}
			}
			
		}
		
		printf("Jugador %d, seleccione pieza a mover: \n",jugador*(-1)+2);

		if(host=='s'){
			if(cantidad_turnos%2==0){
				send_cliente(seleccion_pieza);
			}else{
				recv_servidor(seleccion_pieza);
			}
		}else{
			if(cantidad_turnos%2==0){
				recv_cliente(seleccion_pieza);
			}else{
				send_servidor(seleccion_pieza);
			}
		}

		if(cambio_mod==true){
			goto fin_partida_multi;
		}
		//lectura_datos(seleccion_pieza);

		//scanf("\n%s", &seleccion_pieza);
		////system("clear");
		input(seleccion_pieza);
		if(verificacion_seleccion_pieza(m,seleccion_pieza,jugador)==0 ){
			printf("Error de tipeo, porfavor seleccione nuevamente\n");
			cargar_tablero_sdl(m);
		}else{
			if(mover_restringido(seleccion_pieza,m)==0){

				printf("Pieza con movimiento restringido. Porfavor elegir otra\n");
				cargar_tablero_sdl(m);
			}else{
				int inicio_fila=transformar_num(seleccion_pieza[0]);
				int inicio_columna=transformar_num(seleccion_pieza[1]);
				//jaque_elegir si retorna 0, no hay ningun movimiento de la pieza elejida que resguarde al rey
				if(jaque_elegir(cantidad_turnos,inicio_fila,inicio_columna,m)==0){

					printf("Movimiento no permitido. No puedes dejar vulnerable a tu rey.\n");
					cargar_tablero_sdl(m);
				}else{
					//Este while, sirve para verificar que el movimiento ingresado sea correcto
					do{
						cargar_tablero_sdl(m);

						//Color del contorno de la casilla seleccionada

						if(host=='s'){
							if(cantidad_turnos%2==0){
								contorno_unico_azul(seleccion_pieza[0],seleccion_pieza[1]);
							}else{
								contorno_unico_rojo(seleccion_pieza[0],seleccion_pieza[1]);
							}
						}else{
							if(cantidad_turnos%2==0){
								contorno_unico_rojo(seleccion_pieza[0],seleccion_pieza[1]);
							}else{
								contorno_unico_azul(seleccion_pieza[0],seleccion_pieza[1]);
							}
						}
						
						printf("Pieza %c%c, posicion %s. Ingrese un movimiento: \n",m[inicio_fila][inicio_columna].tipo_pieza.nombre,m[inicio_fila][inicio_columna].color,&seleccion_pieza);
						
						if(host=='s'){
							if(cantidad_turnos%2==0){
								send_cliente(posicion);
							}else{
								recv_servidor(posicion);
							}
						}else{
							if(cantidad_turnos%2==0){
								recv_cliente(posicion);
							}else{
								send_servidor(posicion);
							}
						}

						if(cambio_mod==true){
							goto fin_partida_multi;
						}

						//lectura_datos(posicion);
						input(posicion);
						if(validacion_entrada(posicion)==1){
							int destino_fila=transformar_num(posicion[0]);
							int destino_columna=transformar_num(posicion[1]);
						
							pieza_mov[0]=m[inicio_fila][inicio_columna].tipo_pieza.nombre;
							pieza_mov[1]=m[inicio_fila][inicio_columna].color;

							pieza_remov[0]=m[destino_fila][destino_columna].tipo_pieza.nombre;
							pieza_remov[1]=m[destino_fila][destino_columna].color;

							respaldar_tablero(respaldo,m);

							elegir_movimiento_pieza(inicio_fila,inicio_columna,destino_fila,destino_columna, m, &mov_permitido);
							//Preguntamos si el movimiento es valido, no es valido, repetira la pregunta
							if(mov_permitido==1){
								//Si el movimiento es permitido
								if(jaque(cantidad_turnos,m)){
									//Verificamos si el movimiento efectuado deja vulnerable al rey
									//system("clear");
									respaldar_tablero(m,respaldo);
									printf("Movimiento no permitido. No puedes dejar vulnerable a tu rey.\n");
									mov_permitido=0;
								}else{
									promocion_peon(destino_fila,destino_columna,respaldo,m);
									//Aca va la funcion del sonido
									//system("/usr/bin/mpg123 -q /home/dahaka/Mis_proyectos/Ajedrez/tablero0.1.mp3");
									movimientos_historial(cantidad_turnos,seleccion_pieza,posicion,pieza_mov,pieza_remov);
									cantidad_turnos++;
									jugador=cantidad_turnos%2;
									//system("clear");
									cargar_tablero_sdl(m);
									guardar_partida(m,cantidad_turnos);
								}
								
							}else{
								//system("clear");
								printf("Movimiento no permitido\n");
							}
						}else{
							//system("clear");
							printf("Movimiento no permitido\n");
							mov_permitido=0;
						}	
					}while(mov_permitido==0);
				}
			}
		}
	}
	fin_partida_multi: ;
}
void inicio_partida(p (*m)[8],int termino_partida, int turno[]){
	creacion_historial();
	tablero_inicio(m);
	if(modalidad==0){
		desarrollo_partida_custom(m,termino_partida, turno);
	}else{
		if(modalidad==1){
			desarrollo_partida_multi(m,termino_partida, turno);
		}
	}
	while(forzar_termino==0){
		if(cambio_mod==true){
			cambio_mod=false;
			if(modalidad==0){
				creacion_historial();
				tablero_inicio(m);
				termino_partida=0;
				turno[0]=0;
				desarrollo_partida_custom(m,termino_partida, turno);
			}else{
				if(modalidad==1){

					creacion_historial();
					tablero_inicio(m);
					termino_partida=0;
					turno[0]=0;
					desarrollo_partida_multi(m,termino_partida, turno);
				}
			}
		}
		if(cambio_arch==true){
			cambio_arch=false;
			if(archivo==0){
				if(modalidad==0){
					//Deberia cargar el historial
					creacion_historial();
					tablero_inicio(m);
					termino_partida=0;
					turno[0]=0;
					desarrollo_partida_custom(m,termino_partida, turno);
				}else{
					/*
					if(modalidad==1){
						creacion_historial();
						tablero_inicio(m);
						termino_partida=0;
						turno[0]=0;
						desarrollo_partida_multi(m,termino_partida, turno);
					}*/
					//No puedes cargar partida ni iniciar partida nueva en modo multijugador.
				}
			}else{
				if(archivo==2){
					if(modalidad==0){
						//Deberia cargar el historial
						cargar_partida(m,turno);
						turno[0]--;
						desarrollo_partida_custom(m,termino_partida, turno);
					}else{
						/*
						if(modalidad==1){
							cargar_partida(m,turno);
							turno[0]--;
							desarrollo_partida_multi(m,termino_partida, turno);
						}
						*/
					}
				}
			}			
		}
	}
	

}

void continuar_partida(p (*m)[8],int termino_partida, int turno[]){
	cargar_partida(m,turno);
	turno[0]--;
	desarrollo_partida_custom(m,termino_partida, turno);
}
int verificacion_seleccion_pieza(p (*m)[8], char seleccion[2],int jugador){
	int i_posicion=transformar_num(seleccion[0]);
	int j_posicion=transformar_num(seleccion[1]);

	//El rango de la pieza seleccionada esta dentro del tablero
	if((i_posicion>-1 && i_posicion<8) && (j_posicion>-1 && j_posicion<8)){
		if(jugador==1){
			if(m[i_posicion][j_posicion].color=='w'){

				//Si la posicion seleccionada esta dentro del dominio, es el jugador 1 y el color de la pieza es BLANCO
				return 1;
			}else{
				printf("Error con posicion seleccionada %c%c, a usted le pertenecen las piezas blancas\n",seleccion[0],seleccion[1]);
				return 0;
			}	
		}else{
			if(m[i_posicion][j_posicion].color=='b'){

				//Si la posicion seleccionada esta dentro del dominio, es el jugador 2 y el color de la pieza es NEGRO
				return 1;
			}else{
				printf("Error con posicion seleccionada %c%c, a ustede le pertenecen las piezas negras\n",seleccion[0],seleccion[1]);
				return 0;
			}
		}			
	}else{
		printf("Ingrese una posicion valida\n");
		return 0;
	}
}

int validacion_entrada(char posicion_final[2]){
	if(posicion_final[0]==NULL || posicion_final[1]==NULL){
		return 0;
	}else{
		return 1;
	}
}

int transformar_num(char* numero){
	if(numero=='8' || numero=='a'){
		return 0;
	}else{
		if(numero=='7' || numero=='b'){
			return 1;
		}else{
			if(numero=='6' || numero=='c'){
				return 2;
			}else{
				if(numero=='5' || numero=='d'){
					return 3;
				}else{
					if(numero=='4' || numero=='e'){
						return 4;	
					}else{
						if(numero=='3' || numero=='f'){
							return 5;
						}else{
							if(numero=='2' || numero=='g'){
								return 6;
							}else{
								if(numero=='1' || numero=='h'){
									return 7;								
								}else{
									return -1;
								}
							}
						}
					}
				}
			}
		}
	}
}

void input(char seleccion[2]){
	//numero=fila y letra=columna. Entonces si numero > letra, significa que numero es una letra
	int numero,letra;
	char aux;
	numero=(int)seleccion[0];
	letra=(int)seleccion[1];
	if(numero > letra){
		aux=seleccion[0];
		seleccion[0]=seleccion[1];
		seleccion[1]=aux;
	}
}

void respaldar_tablero(p (*respaldo)[8],p (*m)[8]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			respaldo[i][j].color=m[i][j].color;
			respaldo[i][j].primer_turno=m[i][j].primer_turno;
			respaldo[i][j].tipo_pieza.nombre=m[i][j].tipo_pieza.nombre;
			respaldo[i][j].tipo_pieza.posicion[0]=m[i][j].tipo_pieza.posicion[0];
			respaldo[i][j].tipo_pieza.posicion[1]=m[i][j].tipo_pieza.posicion[1];
		}
	}	
}

//Promocion peon force que se convirtiera en reina, se planea crear una interfaz en sdl para que el usuario escoga pieza.

void promocion_peon(int destino_fila, int destino_columna,p (*respaldo)[8] ,p (*m)[8]){
	if(m[destino_fila][destino_columna].tipo_pieza.nombre=='P' && (destino_fila==0 || destino_fila==7)){
		char seleccion_pieza;
		int aux=0;
		if(m[destino_fila][destino_columna].color=='w'){
			if(destino_fila==0){
				while(aux==0){
					//promocion();
					printf("Promocion de peon, escoga pieza: Q o q -Reina-, B o b -Alfil-, N o n -Caballo-, R o r -Torre-\n");
					//Validar
					seleccion_pieza='Q';
					//scanf("\n%c", &seleccion_pieza);
					if(seleccion_pieza=='Q' || seleccion_pieza=='q'){
						m[destino_fila][destino_columna].tipo_pieza.nombre='Q';
						aux=1;
					}else{
						if(seleccion_pieza=='B' || seleccion_pieza=='b'){
							m[destino_fila][destino_columna].tipo_pieza.nombre='B';
							aux=1;
						}else{
							if(seleccion_pieza=='N' || seleccion_pieza=='n'){
								m[destino_fila][destino_columna].tipo_pieza.nombre='N';
								aux=1;
							}else{
								if(seleccion_pieza=='R' || seleccion_pieza=='r'){
									m[destino_fila][destino_columna].tipo_pieza.nombre='R';
									aux=1;
								}else{
									//system("clear");
									printf("Error, porfavor ingrese una pieza valida.\n");
									cargar_tablero_sdl(respaldo);
								}
							}
						}
					}
				}
			}
		}else{
			if(destino_fila==7){
				while(aux==0){

					printf("Promocion de peon, escoga pieza: Q o q -Reina-, B o b -Alfil-, N o n -Caballo-, R o r -Torre-\n");
					//Validar
					seleccion_pieza='Q';
					//scanf("\n%c", &seleccion_pieza);
					if(seleccion_pieza=='Q' || seleccion_pieza=='q'){
						m[destino_fila][destino_columna].tipo_pieza.nombre='Q';
						aux=1;
					}else{
						if(seleccion_pieza=='B' || seleccion_pieza=='b'){
							m[destino_fila][destino_columna].tipo_pieza.nombre='B';
							aux=1;
						}else{
							if(seleccion_pieza=='N' || seleccion_pieza=='n'){
								m[destino_fila][destino_columna].tipo_pieza.nombre='N';
								aux=1;
							}else{
								if(seleccion_pieza=='R' || seleccion_pieza=='r'){
									m[destino_fila][destino_columna].tipo_pieza.nombre='R';
									aux=1;
								}else{
									//system("clear");
									printf("Error, porfavor ingrese una pieza valida.\n");
									cargar_tablero_sdl(respaldo);
								}
							}
						}
					}
				}
			}
		}
	}
}

void menu(char opcion){
	int salir=0;
	int R=0,G=0,B=0,x,y;
	int turno[1];
	turno[0]=0;
	if(opcion=='a'){
		menu_archivo();
		while(salir==0){
		if(SDL_PollEvent(&eventos_menu)){

			if( eventos_menu.type == SDL_MOUSEBUTTONDOWN ){
				//En caso de que el eventos_menu capturado fuera la presión del botón izquierdo del mouse se continuara con el código entre llaves

				if( eventos_menu.button.button == SDL_BUTTON_LEFT ){
					x = eventos_menu.button.x;
					y = eventos_menu.button.y;

					if((y >= 31 && y < 55) && (x >= 0 && x<150)){
						//Partida nueva
						cambio_arch=true;
						archivo=0;
						salir=1;
					}else{
						if((y >= 55 && y < 85) && (x >= 0 && x<150)){
							//Guardar partida
							cambio_arch=true;
							archivo=1;
							salir=1;
						}else{
							if((y >= 85 && y < 115) && (x >= 0 && x<150)){
								//Cargar partida
								cambio_arch=true;
								archivo=2;
								salir=1;
							}else{
								if((y >= 115 && y < 145) && (x >= 0 && x<150)){
									//Historial
									cambio_arch=true;
									archivo=3;
									salir=1;
								}else{
									salir=1;
								}
							}
						}
					}
				}
			}
		}		
	}


	}else{
		if(opcion=='m'){
			menu_modo();
			while(salir==0){
			if(SDL_PollEvent(&eventos_menu)){

				if( eventos_menu.type == SDL_MOUSEBUTTONDOWN ){
					//En caso de que el eventos_menu capturado fuera la presión del botón izquierdo del mouse se continuara con el código entre llaves

					if( eventos_menu.button.button == SDL_BUTTON_LEFT ){
						x = eventos_menu.button.x;
						y = eventos_menu.button.y;

						if((y >= 31 && y < 61 ) && (x >= 65 && x<215)){
							cambio_mod=true;
							modalidad=0;
							salir=1;
						}else{
							if((y >= 61 && y < 91) && (x >= 65 && x<215)){
								cambio_mod=true;
								modalidad=1;
								salir=1;
							}else{
								if((y >= 91 && y < 115) && (x >= 65 && x<215)){
									cambio_mod=true;
									modalidad=2;
									salir=1;
								}else{
									salir=1;
								}
							}
						}
					}
				}
			}		
		}

		}else{
			if(opcion=='c'){

			}else{
				if(opcion=='s'){

				}
			}
		}
	}

}