#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct pieza p;
void elegir_movimiento_pieza(int inicio_fila,int inicio_columna, int destino_fila, int destino_columna, p (*m)[8],int *mov_permitido) {
	if(m[inicio_fila][inicio_columna].tipo_pieza.nombre=='P'){
		mover_peon(inicio_fila,inicio_columna,destino_fila, destino_columna, *m,mov_permitido);
	}else{
		if(m[inicio_fila][inicio_columna].tipo_pieza.nombre=='H'){
			mover_caballo(inicio_fila,inicio_columna,destino_fila, destino_columna, m,mov_permitido);
		}else{
			if (m[inicio_fila][inicio_columna].tipo_pieza.nombre=='R'){
				mover_torre(inicio_fila,inicio_columna,destino_fila, destino_columna, m,mov_permitido);
			}else{
				if(m[inicio_fila][inicio_columna].tipo_pieza.nombre=='B'){
					mover_alfil(inicio_fila,inicio_columna,destino_fila, destino_columna, m,mov_permitido);
				}else{
					if(m[inicio_fila][inicio_columna].tipo_pieza.nombre=='Q'){
						mover_reina(inicio_fila,inicio_columna,destino_fila, destino_columna, m,mov_permitido);
					}else{
						if(m[inicio_fila][inicio_columna].tipo_pieza.nombre=='K'){
							mover_rey(inicio_fila,inicio_columna,destino_fila, destino_columna, m,mov_permitido);
						}
					}
				}
			}
		}
	}
}

//Buscamos los casos posibles para el mov, si no cumple ningun caso posible, el movimiento no se podra realizar
void mover_peon(int inicio_fila,int inicio_columna, int destino_fila, int destino_columna, p (*m)[8],int *mov_permitido){
	if(m[inicio_fila][inicio_columna].primer_turno==true){
		//Puede avanzar dos espacios
		//Si la pieza es blanca -w-
		if(m[inicio_fila][inicio_columna].color=='w'){
			//Esta vacio y avanzo 2 espacios hacia adelante o esta vacio y avanzo 1 espacio hacia adelante
			if(m[destino_fila][destino_columna].color=='V' && ((destino_fila==inicio_fila-2 && destino_columna==inicio_columna) || (destino_fila==inicio_fila-1 && destino_columna==inicio_columna))){
				//Si avanza 2 espacios, me sirve para preguntar si al avanzar 2 espacios estan vacias las 2 casillas que avanza
				if(destino_fila==inicio_fila-2){
					if(m[destino_fila+1][destino_columna].color=='V'){
						//Esta condicion soo cuenta para el siguiente turno, resrvo el espacio vacio detras del peon
						realizar_movimiento(inicio_fila,inicio_columna,destino_fila,destino_columna,m);
						//Reservamos el color a la casilla que esta al paso
						m[destino_fila+1][destino_columna].color='w';
						*mov_permitido=1;
					}else{
						printf("Hay un obstaculo en su camino\n");
						*mov_permitido=0;
					}
				}else{
					//Si avanzo 1 solo espacio, este vacia esa casilla de destino
					realizar_movimiento(inicio_fila,inicio_columna,destino_fila,destino_columna,m);
					*mov_permitido=1;
				}
			}else{
				printf("Movimiento no permitido\n");
				*mov_permitido=0;
			}
		}else{
			//Si no, si la pieza es negra -b-
			if(m[destino_fila][destino_columna].color=='V' && ((destino_fila==inicio_fila+2 && destino_columna==inicio_columna) || (destino_fila==inicio_fila+1 && destino_columna==inicio_columna))){
				//Si avanza 2 espacios, me sirve para preguntar si al avanzar 2 espacios estan vacias las 2 casillas que avanza
				if(destino_fila==inicio_fila+2){
					if(m[destino_fila-1][destino_columna].color=='V'){
						//Esta condicion soo cuenta para el siguiente turno, resrvo el espacio vacio detras del peon
						realizar_movimiento(inicio_fila,inicio_columna,destino_fila,destino_columna,m);
						//Reservamos el color a la casilla que esta al paso
						m[destino_fila-1][destino_columna].color='b';
						*mov_permitido=1;
					}else{
						printf("Hay un obstaculo en su camino\n");
						*mov_permitido=0;
					}
				}else{
					//Si avanzo 1 solo espacio, este vacia esa casilla de destino
					realizar_movimiento(inicio_fila,inicio_columna,destino_fila,destino_columna,m);
					*mov_permitido=1;
				}
			}else{
				printf("Movimiento no permitido\n");
				*mov_permitido=0;

			}

		}
	}else{
		//Movimiento del peon si este ya no es primera vez que se utiliza
		if(m[inicio_fila][inicio_columna].color=='w'){
			//Esta vacio y avanzo 2 espacios hacia adelante o esta vacio y avanzo 1 espacio hacia adelante
			if(m[destino_fila][destino_columna].color=='V' && (destino_fila==inicio_fila-1 && destino_columna==inicio_columna)){
				//Si avanza 2 espacios, me sirve para preguntar si al avanzar 2 espacios estan vacias las 2 casillas que avanza
				realizar_movimiento(inicio_fila,inicio_columna,destino_fila,destino_columna,m);
				*mov_permitido=1;
			}else{	
				printf("Hay un obstaculo en su camino\n");
				 *mov_permitido=0;
			}
		}else{
			//Si no, si la pieza es negra -b-
			if(m[destino_fila][destino_columna].color=='V' && (destino_fila==inicio_fila+1 && destino_columna==inicio_columna)){
				//Si avanza 2 espacios, me sirve para preguntar si al avanzar 2 espacios estan vacias las 2 casillas que avanza
				realizar_movimiento(inicio_fila,inicio_columna,destino_fila,destino_columna,m);
				*mov_permitido=1;
			}else{
				printf("Hay un obstaculo en su camino\n");
				 *mov_permitido=0;
			}
		}
	}
	//Ataque peon 
	if(*mov_permitido==0){
		//Deberia definir el comer una pieza, si y solo si no han efectuado un movimiento antes
		if(m[inicio_fila][inicio_columna].color=='w'){
			if(m[destino_fila][destino_columna].color=='b' && ((destino_fila==inicio_fila-1 && destino_columna==inicio_columna-1) || (destino_fila==inicio_fila-1 && destino_columna==inicio_columna+1))){
				//Si el peon se mueve en diagonal y la pieza es negra, entonces comera al rival
				//Hay que restringir que este sea el rey
				peon_al_paso(destino_fila,destino_columna,m);
				realizar_movimiento(inicio_fila,inicio_columna,destino_fila,destino_columna,m);
				*mov_permitido=1;
			}else{
				printf("No hay pieza que comer\n");
				*mov_permitido=0;
			}
		}else{
			//Pieza es negra
			if(m[destino_fila][destino_columna].color=='w' && ((destino_fila==inicio_fila+1 && destino_columna==inicio_columna-1) || (destino_fila==inicio_fila+1 && destino_columna==inicio_columna+1))){
				peon_al_paso(destino_fila,destino_columna,m);
				realizar_movimiento(inicio_fila,inicio_columna,destino_fila,destino_columna,m);
				*mov_permitido=1;
			}else{
				printf("No hay pieza que comer\n");
				*mov_permitido=0;	
			}
		}
	}
}

void mover_caballo(int inicio_fila,int inicio_columna, int destino_fila, int destino_columna, p (*m)[8],int mov_permitido){

}
void mover_torre(int inicio_fila,int inicio_columna, int destino_fila, int destino_columna, p (*m)[8],int mov_permitido){

}
void mover_alfil(int inicio_fila,int inicio_columna, int destino_fila, int destino_columna, p (*m)[8],int mov_permitido){

}
void mover_reina(int inicio_fila,int inicio_columna, int destino_fila, int destino_columna, p (*m)[8],int mov_permitido){

}
void mover_rey(int inicio_fila,int inicio_columna, int destino_fila, int destino_columna, p (*m)[8],int mov_permitido){

}

void realizar_movimiento(int inicio_fila,int inicio_columna, int destino_fila, int destino_columna, p (*m)[8]){
	int i=m[destino_fila][destino_columna].tipo_pieza.posicion[0];
	int j=m[destino_fila][destino_columna].tipo_pieza.posicion[1];

	//Modificamos destino primeramente
	m[destino_fila][destino_columna].color=m[inicio_fila][inicio_columna].color;
	//Ya tocaste la pieza una vez al menos
	m[destino_fila][destino_columna].primer_turno=false;
	m[destino_fila][destino_columna].tipo_pieza.nombre=m[inicio_fila][inicio_columna].tipo_pieza.nombre;
	m[destino_fila][destino_columna].tipo_pieza.posicion[0]=m[inicio_fila][inicio_columna].tipo_pieza.posicion[0];
	m[destino_fila][destino_columna].tipo_pieza.posicion[1]=m[inicio_fila][inicio_columna].tipo_pieza.posicion[1];

	//Modificamos la pieza que se movio
	m[inicio_fila][inicio_columna].color='V';
	m[inicio_fila][inicio_columna].primer_turno=false;
	m[inicio_fila][inicio_columna].tipo_pieza.nombre='V';
	m[inicio_fila][inicio_columna].tipo_pieza.posicion[0]=i;
	m[inicio_fila][inicio_columna].tipo_pieza.posicion[1]=j;
}

void borrar_pieza(int fila, int columna,p (*m)[8]){
	m[fila][columna].color='V';
	m[fila][columna].primer_turno=false;
	m[fila][columna].tipo_pieza.nombre='V';
	m[fila][columna].tipo_pieza.posicion[0]=fila;
	m[fila][columna].tipo_pieza.posicion[1]=columna;
}

void peon_al_paso(int fila_paso,int columna_paso,p (*m)[8]){
	//La idea es dejar el color de la pieza detras. Por ejemplo si Pw avanza dos espacios, VV quedara en Vw
	//y al volver al turno de este jugador en particular, Vw pasara a VV si no han comido esta pieza, En el caso de
	//que se coman la pieza, Vw pasara a VV y Pw que avanzo dos espacios, sera destruido 
	if(m[fila_paso][columna_paso].tipo_pieza.nombre=='V' && m[fila_paso][columna_paso].color=='w'){
		borrar_pieza(fila_paso-1,columna_paso,m);
	}else{
		if(m[fila_paso][columna_paso].tipo_pieza.nombre=='V' && m[fila_paso][columna_paso].color=='b'){
			borrar_pieza(fila_paso+1,columna_paso,m);
		}
	}

}

void actualizar_PAP(int turno,p (*m)[8]){
	//Los peones al paso, se actualizan cada turno
	//Turno 1 pertenece al jugador de piezas blancas
	if(turno%2!=0){
		for(int j=0;j<8;j++){
			if(m[5][j].tipo_pieza.nombre=='V' && m[5][j].color=='w'){
				borrar_pieza(5,j,m);
			}
		}
	}else{
		for(int j=0;j<8;j++){
			if(m[2][j].tipo_pieza.nombre=='V' && m[2][j].color=='b'){
				borrar_pieza(2,j,m);
			}
		}
	}
}

int mover_restringido(char seleccion[2], p (*m)[8]){
	int inicio_fila=transformar_num(seleccion[0]);
	int inicio_columna=transformar_num(seleccion[1]);
	if(m[inicio_fila][inicio_columna].tipo_pieza.nombre=='P'){
		return mover_peon_restringido(inicio_fila,inicio_columna,m);
	}else{
		//Generar la restriccion para las demas piezas
		return 0;
	}
}


int verificacion_dominio(int inicio_fila,int inicio_columna){
	if((inicio_fila>-1 && inicio_fila<8) && (inicio_columna>-1 && inicio_columna<8)){
		return 1;
	}else{
		return 0;
	}
}

//Falta restringir que la resta no salga del tablero
//Que al mover un peon, el rey deje de estar en peligro, se puede hacer en una funcion aparte o una funcion que involucre todas las restricciones
int mover_peon_restringido(int inicio_fila,int inicio_columna, p (*m)[8]){
	if(m[inicio_fila][inicio_columna].color=='w'){
		if(verificacion_dominio(inicio_fila-1,inicio_columna) && m[inicio_fila-1][inicio_columna].color=='V'){	
			return 1;
		}else{
			if((verificacion_dominio(inicio_fila-1,inicio_columna-1) && m[inicio_fila-1][inicio_columna-1].color=='b') || ( verificacion_dominio(inicio_fila-1,inicio_columna+1) && m[inicio_fila-1][inicio_columna+1].color=='b')){
				return 1;
			}else{
				return 0;
			}	
		}
	}else{
		//Pieza negra
		if(verificacion_dominio(inicio_fila+1,inicio_columna) && m[inicio_fila+1][inicio_columna].color=='V'){
			return 1;
		}else{
			if((verificacion_dominio(inicio_fila+1,inicio_columna-1) && m[inicio_fila+1][inicio_columna-1].color=='w') || ( verificacion_dominio(inicio_fila+1,inicio_columna+1) && m[inicio_fila+1][inicio_columna+1].color=='w')){
				return 1;
			}else{
				return 0;
			}
		}
	}
}