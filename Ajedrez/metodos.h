#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct pieza p;
void matriz_setPieza( p (*m)[8],int i, int j,char color, bool turno,char nombre,int posicion_1,int posicion_2);

void tablero_inicio(p (*m)[8]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(i==1){
				matriz_setPieza(m,i,j,'b',true,'P',i,j);
			}else{
				if(i==6){
					matriz_setPieza(m,i,j,'w',true,'P',i,j);	
				}else{
					if(i==0 && (j==0 || j==7)){
						matriz_setPieza(m,i,j,'b',true,'R',i,j);					
					}else{
						if(i==7 && (j==0 || j==7)){
							matriz_setPieza(m,i,j,'w',true,'R',i,j);
						}else{
							if(i==0 && (j==1 || j==6)){
								matriz_setPieza(m,i,j,'b',true,'H',i,j);
							}else{
								if(i==7 && (j==1 || j==6)){
									matriz_setPieza(m,i,j,'w',true,'H',i,j);
								}else{
									if(i==0 && (j==2 || j==5)){
										matriz_setPieza(m,i,j,'b',true,'B',i,j);
									}else{
										if(i==7 && (j==2 || j==5)){
											matriz_setPieza(m,i,j,'w',true,'B',i,j);
										}else{
											if(i==0 && j==3){
												matriz_setPieza(m,i,j,'b',true,'K',i,j);
											}else{
												if(i==0 && j==4){
													matriz_setPieza(m,i,j,'b',true,'Q',i,j);
												}else{
													if(i==7 && j==3){
														matriz_setPieza(m,i,j,'w',true,'K',i,j);
													}else{
														if(i==7 && j==4){
															matriz_setPieza(m,i,j,'w',true,'Q',i,j);
														}else{
															matriz_setPieza(m,i,j,'V',false,'V',i,j);
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
void matriz_setPieza( p (*m)[8],int i, int j,char color, bool turno,char nombre,int posicion_1,int posicion_2){
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
					//Si la casilla es par
					printf("\033[0;33;43m%c%c ",m[i][j].tipo_pieza.nombre,m[i][j].color);
					printf("\033[0m");
				}else{
					//Si la casilla es par
					printf("\033[0;1;43m%c%c ",m[i][j].tipo_pieza.nombre,m[i][j].color);
					printf("\033[0m");
				}	
			}else{
				if(m[i][j].tipo_pieza.nombre=='V'){
					//Si la casilla es impar
					printf("\033[0;31;41m%c%c ",m[i][j].tipo_pieza.nombre,m[i][j].color);
					printf("\033[0m");
				}else{
					//Si la casilla es par
					printf("\033[0;1;41m%c%c ",m[i][j].tipo_pieza.nombre,m[i][j].color);
					printf("\033[0m");
				}	
			}
		}
		printf(" %d ", 9-(i+1));
		printf("\n");
	}
	printf("   a  b  c  d  e  f  g  h\n");
}

void inicio_partida(p (*m)[8],int termino_partida){
	tablero_inicio(m);
	int cantidad_turnos=1;
	char seleccion_pieza[2];
	char posicion[2];
	char pieza_mov[2];
	char pieza_remov[2];
	int mov_permitido=1;

	//Sabemos el jugador, dividiendo la cantidad de turnos por 2, asi sabemos si el turno es par o impar
	int jugador=cantidad_turnos%2;
	//Iniciamos la partida
	mostrar_tablero(m);
	while(termino_partida==0){
		printf("Jugador %d, seleccione pieza a mover\n",jugador);
		scanf("%s", &seleccion_pieza);
		system("clear");
		if(verificacion_seleccion_pieza(m,seleccion_pieza,jugador)==0 ){
			printf("Error de tipeo, porfavor seleccione nuevamente\n");
			mostrar_tablero(m);
		}else{
			if(mover_restringido(seleccion_pieza,m)==0){
				printf("Pieza con movimiento restringido. Porfavor elegir otra\n");
				mostrar_tablero(m);
			}else{
				//Este while, sirve para verificar que el movimiento ingresado sea correcto
				do{
					int inicio_fila=transformar_num(seleccion_pieza[0]);
					int inicio_columna=transformar_num(seleccion_pieza[1]);

					mostrar_tablero(m);
					printf("Pieza %c%c, posicion %s. Ingrese un movimiento: \n",m[inicio_fila][inicio_columna].tipo_pieza.nombre,m[inicio_fila][inicio_columna].color,&seleccion_pieza);
					scanf("%s", &posicion);

					int destino_fila=transformar_num(posicion[0]);
					int destino_columna=transformar_num(posicion[1]);

					pieza_mov[0]=m[inicio_fila][inicio_columna].tipo_pieza.nombre;
					pieza_mov[1]=m[inicio_fila][inicio_columna].color;

					pieza_remov[0]=m[destino_fila][destino_columna].tipo_pieza.nombre;
					pieza_remov[0]=m[destino_fila][destino_columna].color;

					elegir_movimiento_pieza(inicio_fila,inicio_columna,destino_fila,destino_columna, m, &mov_permitido);
					//Preguntamos si el movimiento es valido, no es valido, repetira la pregunta
					if(mov_permitido==1){
						movimiento_historial(cantidad_turnos,seleccion_pieza,posicion,pieza_mov,pieza_remov);
						cantidad_turnos++;
						jugador=cantidad_turnos%2;
						system("clear");
						mostrar_tablero(m);
					}else{
						system("clear");
						printf("Movimiento no permitido\n");
					}
				}while(mov_permitido==0);
			}
		}
	}
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
				printf("Posicion seleccionada %c%c\n",seleccion[0],seleccion[1]);
				printf("Las piezas BLANCAS -w-, estan asignadas al JUGADOR 1\n");
				return 0;
			}	
		}else{
			if(m[i_posicion][j_posicion].color=='b'){

				//Si la posicion seleccionada esta dentro del dominio, es el jugador 2 y el color de la pieza es NEGRO
				return 1;
			}else{
				printf("Posicion seleccionada %c%c\n",seleccion[0],seleccion[1]);
				printf("Las piezas NEGRAS -b-, estan asignadas al JUGADOR 2\n");
				return 0;
			}
		}			
	}else{
		printf("Ingrese una posicion valida\n");
		return 0;
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