#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void buscar_rey(char color,int posicion[2],p (*m)[8]){
	if(color=='w'){
		//Buscamos el rey blanco
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(m[i][j].tipo_pieza.nombre=='K' && m[i][j].color=='w'){
						posicion[0]=i;
						posicion[1]=j;
				}
			}
		}
	}else{
		//Buscamos el rey negro 
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(m[i][j].tipo_pieza.nombre=='K' && m[i][j].color=='b'){
						posicion[0]=i;
						posicion[1]=j;
				}
			}
		}
	}
}
int jaque(int turno, p (*m)[8]){
	if(turno%2!=0){
		//pieza blanca

	}else{
		
	}
}

int jaque_peon(char color,int fila_rey,int columna_rey,p (*m)[8]){
	if(color=='w'){
		//Abajo derecha
		if(verificacion_dominio(fila_rey+1,columna_rey+1) && m[fila_rey+1][columna_rey+1].tipo_pieza.nombre=='P' && m[fila_rey+1][columna_rey+1].color=='b'){
			return 1;
		}else{
			//Abajo izquierda
			if(verificacion_dominio(fila_rey+1,columna_rey-1)  && m[fila_rey+1][columna_rey-1].tipo_pieza.nombre=='P' && m[fila_rey+1][columna_rey-1].color=='b'){
				return 1;
			}else{
				return 0;
			}	
		}
	}else{
		//Arriba derecha
		if(verificacion_dominio(fila_rey-1,columna_rey+1) && m[fila_rey-1][columna_rey+1].tipo_pieza.nombre=='P' && m[fila_rey-1][columna_rey+1].color=='w'){
			return 1;
		}else{
			//Arriba izquierda
			if(verificacion_dominio(fila_rey-1,columna_rey-1) && m[fila_rey-1][columna_rey-1].tipo_pieza.nombre=='P' && m[fila_rey-1][columna_rey-1].color=='w'){
				return 1;
			}else{
				return 0;
			}	
		}
	}
}


int jaque_caballo(char color,int fila_rey,int columna_rey,p (*m)[8]){
	if(color=='w'){
		//Arriba izquierda
		if(verificacion_dominio(fila_rey-2,columna_rey-1) && m[fila_rey-2][columna_rey-1].tipo_pieza.nombre=='N' && m[fila_rey-2][columna_rey-1].color=='b'){
			return 1;
		}else{
			//Arriba derecha
			if(verificacion_dominio(fila_rey-2,columna_rey+1) && m[fila_rey-2][columna_rey+1].tipo_pieza.nombre=='N' && m[fila_rey-2][columna_rey+1].color=='b'){
				return 1;
			}else{
				//Abajo izquierda
				if(verificacion_dominio(fila_rey+2,columna_rey-1) && m[fila_rey+2][columna_rey-1].tipo_pieza.nombre=='N' && m[fila_rey+2][columna_rey-1].color=='b'){
					return 1;
				}else{
					//Abajo derecha
					if(verificacion_dominio(fila_rey+2,columna_rey+1) && m[fila_rey+2][columna_rey+1].tipo_pieza.nombre=='N' && m[fila_rey+2][columna_rey+1].color=='b'){
						return 1;
					}else{
						//Izquierda arriba
						if(verificacion_dominio(fila_rey-1,columna_rey-2) && m[fila_rey-1][columna_rey-2].tipo_pieza.nombre=='N' && m[fila_rey-1][columna_rey-2].color=='b'){
							return 1;
						}else{
							//Izquierda abajo
							if(verificacion_dominio(fila_rey+1,columna_rey-2) && m[fila_rey+1][columna_rey-2].tipo_pieza.nombre=='N' && m[fila_rey+1][columna_rey-2].color=='b'){
								return 1;
							}else{
								//Derecha arriba
								if(verificacion_dominio(fila_rey-1,columna_rey+2) && m[fila_rey-1][columna_rey+2].tipo_pieza.nombre=='N' && m[fila_rey-1][columna_rey+2].color=='b'){
									return 1;
								}else{
									//Derecha abajo
									if(verificacion_dominio(fila_rey+1,columna_rey+2) && m[fila_rey+1][columna_rey+2].tipo_pieza.nombre=='N' && m[fila_rey+1][columna_rey+2].color=='b'){
										return 1;
									}else{
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}else{
		//Arriba izquierda
		if(verificacion_dominio(fila_rey-2,columna_rey-1) && m[fila_rey-2][columna_rey-1].tipo_pieza.nombre=='N' && m[fila_rey-2][columna_rey-1].color=='w'){
			return 1;
		}else{
			//Arriba derecha
			if(verificacion_dominio(fila_rey-2,columna_rey+1) && m[fila_rey-2][columna_rey+1].tipo_pieza.nombre=='N' && m[fila_rey-2][columna_rey+1].color=='w'){
				return 1;
			}else{
				//Abajo izquierda
				if(verificacion_dominio(fila_rey+2,columna_rey-1) && m[fila_rey+2][columna_rey-1].tipo_pieza.nombre=='N' && m[fila_rey+2][columna_rey-1].color=='w'){
					return 1;
				}else{
					//Abajo derecha
					if(verificacion_dominio(fila_rey+2,columna_rey+1) && m[fila_rey+2][columna_rey+1].tipo_pieza.nombre=='N' && m[fila_rey+2][columna_rey+1].color=='w'){
						return 1;
					}else{
						//Izquierda arriba
						if(verificacion_dominio(fila_rey-1,columna_rey-2) && m[fila_rey-1][columna_rey-2].tipo_pieza.nombre=='N' && m[fila_rey-1][columna_rey-2].color=='w'){
							return 1;
						}else{
							//Izquierda abajo
							if(verificacion_dominio(fila_rey+1,columna_rey-2) && m[fila_rey+1][columna_rey-2].tipo_pieza.nombre=='N' && m[fila_rey+1][columna_rey-2].color=='w'){
								return 1;
							}else{
								//Derecha arriba
								if(verificacion_dominio(fila_rey-1,columna_rey+2) && m[fila_rey-1][columna_rey+2].tipo_pieza.nombre=='N' && m[fila_rey-1][columna_rey+2].color=='w'){
									return 1;
								}else{
									//Derecha abajo
									if(verificacion_dominio(fila_rey+1,columna_rey+2) && m[fila_rey+1][columna_rey+2].tipo_pieza.nombre=='N' && m[fila_rey+1][columna_rey+2].color=='w'){
										return 1;
									}else{
										return 0;
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

int jaque_torre(char color,int fila_rey,int columna_rey,p (*m)[8]){
	
}