#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct pieza p;
void elegir_movimiento_pieza(int inicio_fila,int inicio_columna, int destino_fila, int destino_columna, p (*m)[8]) {
	if(m[inicio_fila][inicio_columna].tipo_pieza.nombre=='P'){
		mover_peon(inicio_fila,inicio_columna,destino_fila, destino_columna, m);
	}else{
		if(m[inicio_fila][inicio_columna].tipo_pieza.nombre=='H'){
			mover_caballo(inicio_fila,inicio_columna,destino_fila, destino_columna, m);
		}else{
			if (m[inicio_fila][inicio_columna].tipo_pieza.nombre=='R'){
				mover_torre(inicio_fila,inicio_columna,destino_fila, destino_columna, m);
			}else{
				if(m[inicio_fila][inicio_columna].tipo_pieza.nombre=='B'){
					mover_alfil(inicio_fila,inicio_columna,destino_fila, destino_columna, m);
				}else{
					if(m[inicio_fila][inicio_columna].tipo_pieza.nombre=='Q'){
						mover_reina(inicio_fila,inicio_columna,destino_fila, destino_columna, m);
					}else{
						if(m[inicio_fila][inicio_columna].tipo_pieza.nombre=='K'){
							mover_rey(inicio_fila,inicio_columna,destino_fila, destino_columna, m);
						}
					}
				}
			}
		}
	}
}

//Buscamos los casos posibles para el mov, si no cumple ningun caso posible, el movimiento no se podra realizar
void mover_peon(int inicio_fila,int inicio_columna, int destino_fila, int destino_columna, p (*m)[8]){
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
						peon_al_paso();
						realizar_movimiento(inicio_fila,inicio_columna,destino_fila,destino_columna,m);
					}else{
						printf("Hay un obstaculo en su camino\n");
					}
				}else{
					//Si avanzo 1 solo espacio, este vacia esa casilla de destino
					realizar_movimiento(inicio_fila,inicio_columna,destino_fila,destino_columna,m);
				}
			}else{
				printf("Movimiento no permitido\n");
			}
		}else{
			//Si no, si la pieza es negra -b-
			if(m[destino_fila][destino_columna].color=='V' && ((destino_fila==inicio_fila+2 && destino_columna==inicio_columna) || (destino_fila==inicio_fila+1 && destino_columna==inicio_columna))){
				//Si avanza 2 espacios, me sirve para preguntar si al avanzar 2 espacios estan vacias las 2 casillas que avanza
				if(destino_fila==inicio_fila+2){
					if(m[destino_fila-1][destino_columna].color=='V'){
						//Esta condicion soo cuenta para el siguiente turno, resrvo el espacio vacio detras del peon
						peon_al_paso();
						realizar_movimiento(inicio_fila,inicio_columna,destino_fila,destino_columna,m);
					}else{
						printf("Hay un obstaculo en su camino\n");
					}
				}else{
					//Si avanzo 1 solo espacio, este vacia esa casilla de destino
					realizar_movimiento(inicio_fila,inicio_columna,destino_fila,destino_columna,m);
				}
			}else{
				printf("Movimiento no permitido\n");
			}

		}
	}else{
		//Movimiento del peon si este ya no es primera vez que se utiliza
	}
}

void mover_caballo(int inicio_fila,int inicio_columna, int destino_fila, int destino_columna, p (*m)[8]){

}
void mover_torre(int inicio_fila,int inicio_columna, int destino_fila, int destino_columna, p (*m)[8]){

}
void mover_alfil(int inicio_fila,int inicio_columna, int destino_fila, int destino_columna, p (*m)[8]){

}
void mover_reina(int inicio_fila,int inicio_columna, int destino_fila, int destino_columna, p (*m)[8]){

}
void mover_rey(int inicio_fila,int inicio_columna, int destino_fila, int destino_columna, p (*m)[8]){

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

void peon_al_paso(){

}