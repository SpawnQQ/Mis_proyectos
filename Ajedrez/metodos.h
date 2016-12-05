#include<stdlib.h>
#include <stdio.h>
#include<stdbool.h>

typedef struct pieza p;

void tablero_inicio(p (*m)[8]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(i==1){
				m[i][j].color='b';
				m[i][j].primer_turno=true;
				m[i][j].tipo_pieza.nombre='P';
				m[i][j].tipo_pieza.posicion[0]=i;
				m[i][j].tipo_pieza.posicion[1]=j;
			}else{
				if(i==6){
					m[i][j].color='w';
					m[i][j].primer_turno=true;
					m[i][j].tipo_pieza.nombre='P';
					m[i][j].tipo_pieza.posicion[0]=i;
					m[i][j].tipo_pieza.posicion[1]=j;	
				}else{
					if(i==0 && (j==0 || j==7)){
						m[i][j].color='b';
						m[i][j].primer_turno=true;
						m[i][j].tipo_pieza.nombre='R';
						m[i][j].tipo_pieza.posicion[0]=i;
						m[i][j].tipo_pieza.posicion[1]=j;					
					}else{
						if(i==7 && (j==0 || j==7)){
							m[i][j].color='w';
							m[i][j].primer_turno=true;
							m[i][j].tipo_pieza.nombre='R';
							m[i][j].tipo_pieza.posicion[0]=i;
							m[i][j].tipo_pieza.posicion[1]=j;
						}else{
							if(i==0 && (j==1 || j==6)){
								m[i][j].color='b';
								m[i][j].primer_turno=true;
								m[i][j].tipo_pieza.nombre='H';
								m[i][j].tipo_pieza.posicion[0]=i;
								m[i][j].tipo_pieza.posicion[1]=j;
							}else{
								if(i==7 && (j==1 || j==6)){
									m[i][j].color='w';
									m[i][j].primer_turno=true;
									m[i][j].tipo_pieza.nombre='H';
									m[i][j].tipo_pieza.posicion[0]=i;
									m[i][j].tipo_pieza.posicion[1]=j;
								}else{
									if(i==0 && (j==2 || j==5)){
										m[i][j].color='b';
										m[i][j].primer_turno=true;
										m[i][j].tipo_pieza.nombre='B';
										m[i][j].tipo_pieza.posicion[0]=i;
										m[i][j].tipo_pieza.posicion[1]=j;
									}else{
										if(i==7 && (j==2 || j==5)){
											m[i][j].color='w';
											m[i][j].primer_turno=true;
											m[i][j].tipo_pieza.nombre='B';
											m[i][j].tipo_pieza.posicion[0]=i;
											m[i][j].tipo_pieza.posicion[1]=j;
										}else{
											if(i==0 && j==3){
												m[i][j].color='b';
												m[i][j].primer_turno=true;
												m[i][j].tipo_pieza.nombre='K';
												m[i][j].tipo_pieza.posicion[0]=i;
												m[i][j].tipo_pieza.posicion[1]=j;
											}else{
												if(i==0 && j==4){
													m[i][j].color='b';
													m[i][j].primer_turno=true;
													m[i][j].tipo_pieza.nombre='Q';
													m[i][j].tipo_pieza.posicion[0]=i;
													m[i][j].tipo_pieza.posicion[1]=j;
												}else{
													if(i==7 && j==3){
														m[i][j].color='w';
														m[i][j].primer_turno=true;
														m[i][j].tipo_pieza.nombre='K';
														m[i][j].tipo_pieza.posicion[0]=i;
														m[i][j].tipo_pieza.posicion[1]=j;
													}else{
														if(i==7 && j==4){
															m[i][j].color='w';
															m[i][j].primer_turno=true;
															m[i][j].tipo_pieza.nombre='Q';
															m[i][j].tipo_pieza.posicion[0]=i;
															m[i][j].tipo_pieza.posicion[1]=j;
														}else{
															m[i][j].color='V';
															m[i][j].primer_turno=true;
															m[i][j].tipo_pieza.nombre='V';
															m[i][j].tipo_pieza.posicion[0]=i;
															m[i][j].tipo_pieza.posicion[1]=j;
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

void mostrar_tablero(p (*m)[8]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			printf("%c%c ",m[i][j].tipo_pieza.nombre,m[i][j].color);
		}
		printf("\n");

	}
}
