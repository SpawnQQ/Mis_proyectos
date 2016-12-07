#include<stdlib.h>
#include <stdio.h>
#include<stdbool.h>

typedef struct pieza p;

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
															matriz_setPieza(m,i,j,'V',true,'V',i,j);
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

void mostrar_tablero(p (*m)[8]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			printf("%c%c ",m[i][j].tipo_pieza.nombre,m[i][j].color);
		}
		printf("\n");

	}
}
