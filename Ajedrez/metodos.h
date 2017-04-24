#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define ESCAPE 27 

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
								matriz_setPieza(m,i,j,'b',true,'N',i,j);
							}else{
								if(i==7 && (j==1 || j==6)){
									matriz_setPieza(m,i,j,'w',true,'N',i,j);
								}else{
									if(i==0 && (j==2 || j==5)){
										matriz_setPieza(m,i,j,'b',true,'B',i,j);
									}else{
										if(i==7 && (j==2 || j==5)){
											matriz_setPieza(m,i,j,'w',true,'B',i,j);
										}else{
											if(i==0 && j==3){
												matriz_setPieza(m,i,j,'b',true,'Q',i,j);
											}else{
												if(i==0 && j==4){
													matriz_setPieza(m,i,j,'b',true,'K',i,j);
												}else{
													if(i==7 && j==3){
														matriz_setPieza(m,i,j,'w',true,'Q',i,j);
													}else{
														if(i==7 && j==4){
															matriz_setPieza(m,i,j,'w',true,'K',i,j);
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

void desarrollo_partida(p (*m)[8],int termino_partida, int cantidad_turnos){
	p respaldo[8][8];
	cantidad_turnos++;
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
		actualizar_PAP(cantidad_turnos,m);
		guardar_partida(m,cantidad_turnos);
		if(jaque(cantidad_turnos,m)){
			if(jaque_mate(cantidad_turnos,m)){
				termino_partida=1;
				goto fin_partida;
			}else{
				printf("Tu rey esta en jaque!!\n");
			}
		}
		printf("Jugador %d, seleccione pieza a mover: \n",jugador*(-1)+2);
		scanf("\n%s", &seleccion_pieza);
		system("clear");
		input(seleccion_pieza);
		if(verificacion_seleccion_pieza(m,seleccion_pieza,jugador)==0 ){
			printf("Error de tipeo, porfavor seleccione nuevamente\n");
			mostrar_tablero(m);
		}else{
			if(mover_restringido(seleccion_pieza,m)==0){
				printf("Pieza con movimiento restringido. Porfavor elegir otra\n");
				mostrar_tablero(m);
			}else{
				int inicio_fila=transformar_num(seleccion_pieza[0]);
				int inicio_columna=transformar_num(seleccion_pieza[1]);
				//jaque_elegir si retorna 0, no hay ningun movimiento de la pieza elejida que resguarde al rey
				if(jaque_elegir(cantidad_turnos,inicio_fila,inicio_columna,m)==0){
					printf("Movimiento no permitido. No puedes dejar vulnerable a tu rey.\n");
					mostrar_tablero(m);
				}else{

					//Este while, sirve para verificar que el movimiento ingresado sea correcto
					do{

						mostrar_tablero(m);
						printf("Pieza %c%c, posicion %s. Ingrese un movimiento: \n",m[inicio_fila][inicio_columna].tipo_pieza.nombre,m[inicio_fila][inicio_columna].color,&seleccion_pieza);
						scanf("%s", &posicion);
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
									system("clear");
									respaldar_tablero(m,respaldo);
									printf("Movimiento no permitido. No puedes dejar vulnerable a tu rey.\n");
									mov_permitido=0;
								}else{
									promocion_peon(destino_fila,destino_columna,respaldo,m);
									system("/usr/bin/mpg123 -q /home/dahaka/Mis_proyectos/Ajedrez/tablero0.1.mp3");
									movimientos_historial(cantidad_turnos,seleccion_pieza,posicion,pieza_mov,pieza_remov);
									cantidad_turnos++;
									jugador=cantidad_turnos%2;
									system("clear");
									mostrar_tablero(m);	
								}
								
							}else{
								system("clear");
								printf("Movimiento no permitido\n");
							}
						}else{
							system("clear");
							printf("Movimiento no permitido\n");
							mov_permitido=0;
						}	
					}while(mov_permitido==0);
				}
			}
		}
	}
	fin_partida: ;
	if(cantidad_turnos%2!=0){
		printf("Jaque mate. Jugador 1 derrotado!\n");
	}else{
		printf("Jaque mate. Jugador 2 derrotado!\n");
	}
}

void inicio_partida(p (*m)[8],int termino_partida, int turno){
	tablero_inicio(m);
	desarrollo_partida(m,termino_partida, turno);
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

void promocion_peon(int destino_fila, int destino_columna,p (*respaldo)[8] ,p (*m)[8]){
	if(m[destino_fila][destino_columna].tipo_pieza.nombre=='P' && (destino_fila==0 || destino_fila==7)){
		char seleccion_pieza;
		int aux=0;
		if(m[destino_fila][destino_columna].color=='w'){
			if(destino_fila==0){
				while(aux==0){
					printf("Promocion de peon, escoga pieza: Q o q -Reina-, B o b -Alfil-, N o n -Caballo-, R o r -Torre-\n");
					//Validar
					scanf("\n%c", &seleccion_pieza);
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
									system("clear");
									printf("Error, porfavor ingrese una pieza valida.\n");
									mostrar_tablero(respaldo);
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
					scanf("\n%c", &seleccion_pieza);
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
									system("clear");
									printf("Error, porfavor ingrese una pieza valida.\n");
									mostrar_tablero(respaldo);
								}
							}
						}
					}
				}
			}
		}
	}
}