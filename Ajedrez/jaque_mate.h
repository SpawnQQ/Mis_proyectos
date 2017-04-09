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

int verificacion_todas_direcciones_jaque(char color,char direccion[2],int fila_rey,int columna_rey,p (*m)[8]){
	if(color=='w'){
		//Arriba aa tope tabla por fila es 0
		if(direccion[0]=='a' && direccion[1]=='a'){
			int fila = fila_rey - 1;
			while (fila >= 0) {
				if(m[fila][columna_rey].color=='V') {
					fila--;
				}else{
					if(m[fila][columna_rey].color=='w'){
						return 0;
					}else{
						if(m[fila][columna_rey].color=='b' && (m[fila][columna_rey].tipo_pieza.nombre=='R' || m[fila][columna_rey].tipo_pieza.nombre=='Q')){
							return 1;
						}	
					}
				}
			}
			//No encontro amenaza
			return 0;
		}else{
			//Abajo bb tope table por fila es 8
			if(direccion[0]=='b' && direccion[1]=='b'){
				int fila = fila_rey + 1;
				while (fila <= 8) {
					if(m[fila][columna_rey].color=='V') {
						fila++;
					}else{
						if(m[fila][columna_rey].color=='w'){
							return 0;
						}else{
							if(m[fila][columna_rey].color=='b' && (m[fila][columna_rey].tipo_pieza.nombre=='R' || m[fila][columna_rey].tipo_pieza.nombre=='Q')){
								return 1;
							}	
						}
					}
				}
				//No encontro amenaza
				return 0;
			}else{
				//Izquierda ii tope table por columna es 0
				if(direccion[0]=='i' && direccion[1]=='i'){
					int columna = columna_rey - 1;
					while (columna >= 0) {
						if(m[fila_rey][columna].color=='V') {
							columna--;
						}else{
							if(m[fila_rey][columna].color=='w'){
								return 0;
							}else{
								if(m[fila_rey][columna].color=='b' && (m[fila_rey][columna].tipo_pieza.nombre=='R' || m[fila_rey][columna].tipo_pieza.nombre=='Q')){







									return 1;
								}	
							}
						}
					}
					//No encontro amenaza
					return 0;
				}else{
					//Derecha tope table por columna es 0
					if(direccion[0]=='d' && direccion[1]=='d'){
						int columna = columna_rey + 1;
						while (columna <= 8) {
							if(m[fila_rey][columna].color=='V') {
								columna++;
							}else{
								if(m[fila_rey][columna].color=='w'){
									return 0;
								}else{
									if(m[fila_rey][columna].color=='b' && (m[fila_rey][columna].tipo_pieza.nombre=='R' || m[fila_rey][columna].tipo_pieza.nombre=='Q')){
										return 1;
									}	
								}
							}
						}
						//No encontro amenaza
						return 0;
					}else{
						//Arriba derecha ad tope tabla por fila es 0 y columna es 8
						if(direccion[0]=='a' && direccion[1]=='d'){
							int fila = fila_rey - 1;
							int columna=columna_rey + 1;
							while (fila >= 0 && columna <= 8) {
								if(m[fila][columna].color=='V') {
									fila--;
									columna++;
								}else{
									if(m[fila][columna].color=='w'){
										return 0;
									}else{
										if(m[fila][columna].color=='b' && (m[fila][columna].tipo_pieza.nombre=='B' || m[fila][columna].tipo_pieza.nombre=='Q')){
											return 1;
										}	
									}
								}
							}
							//No encontro amenaza
							return 0;
						}else{
							//Arriba izquierda ai tope tabla por fila es 0 y columna es 0
							if(direccion[0]=='a' && direccion[1]=='i'){
								int fila = fila_rey - 1;
								int columna=columna_rey - 1;
								while (fila >= 0 && columna >= 0) {
									if(m[fila][columna].color=='V') {
										fila--;
										columna--;
									}else{
										if(m[fila][columna].color=='w'){
											return 0;
										}else{
											if(m[fila][columna].color=='b' && (m[fila][columna].tipo_pieza.nombre=='B' || m[fila][columna].tipo_pieza.nombre=='Q')){
												return 1;
											}	
										}
									}
								}
								//No encontro amenaza
								return 0;
							}else{
								//Abajo derecha bd tope tabla por fila es 8 y columna es 8
								if(direccion[0]=='b' && direccion[1]=='d'){
									int fila = fila_rey + 1;
									int columna=columna_rey + 1;
									while (fila <= 8 && columna <= 8) {
										if(m[fila][columna].color=='V') {
											fila++;
											columna++;
										}else{
											if(m[fila][columna].color=='w'){
												return 0;
											}else{
												if(m[fila][columna].color=='b' && (m[fila][columna].tipo_pieza.nombre=='B' || m[fila][columna].tipo_pieza.nombre=='Q')){
													return 1;
												}	
											}
										}
									}
									//No encontro amenaza
									return 0;
								}else{
									//Abajo Izquierda bi tope tabla por fila es 8 y columna es 0
									if(direccion[0]=='b' && direccion[1]=='i'){
										int fila = fila_rey + 1;
										int columna=columna_rey - 1;
										while (fila <= 8 && columna >= 0) {
											if(m[fila][columna].color=='V') {
												fila++;
												columna--;
											}else{
												if(m[fila][columna].color=='w'){
													return 0;
												}else{
													if(m[fila][columna].color=='b' && (m[fila][columna].tipo_pieza.nombre=='B' || m[fila][columna].tipo_pieza.nombre=='Q')){
														return 1;
													}	
												}
											}
										}
										//No encontro amenaza
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
		//Negras
		//Arriba aa tope tabla por fila es 0
		if(direccion[0]=='a' && direccion[1]=='a'){
			int fila = fila_rey - 1;
			while (fila >= 0) {
				if(m[fila][columna_rey].color=='V') {
					fila--;
				}else{
					if(m[fila][columna_rey].color=='b'){
						return 0;
					}else{
						if(m[fila][columna_rey].color=='w' && (m[fila][columna_rey].tipo_pieza.nombre=='R' || m[fila][columna_rey].tipo_pieza.nombre=='Q')){
							return 1;
						}	
					}
				}
			}
			//No encontro amenaza
			return 0;
		}else{
			//Abajo bb tope table por fila es 8
			if(direccion[0]=='b' && direccion[1]=='b'){
				int fila = fila_rey + 1;
				while (fila <= 8) {
					if(m[fila][columna_rey].color=='V') {
						fila++;
					}else{
						if(m[fila][columna_rey].color=='b'){
							return 0;
						}else{
							if(m[fila][columna_rey].color=='w' && (m[fila][columna_rey].tipo_pieza.nombre=='R' || m[fila][columna_rey].tipo_pieza.nombre=='Q')){
								return 1;
							}	
						}
					}
				}
				//No encontro amenaza
				return 0;
			}else{
				//Izquierda ii tope table por columna es 0
				if(direccion[0]=='i' && direccion[1]=='i'){
					int columna = columna_rey - 1;
					while (columna >= 0) {
						if(m[fila_rey][columna].color=='V') {
							columna--;
						}else{
							if(m[fila_rey][columna].color=='b'){
								return 0;
							}else{
								if(m[fila_rey][columna].color=='w' && (m[fila_rey][columna].tipo_pieza.nombre=='R' || m[fila_rey][columna].tipo_pieza.nombre=='Q')){
									return 1;
								}	
							}
						}
					}
					//No encontro amenaza
					return 0;
				}else{
					//Derecha tope table por columna es 0
					if(direccion[0]=='d' && direccion[1]=='d'){
						int columna = columna_rey + 1;
						while (columna <= 8) {
							if(m[fila_rey][columna].color=='V') {
								columna++;
							}else{
								if(m[fila_rey][columna].color=='b'){
									return 0;
								}else{
									if(m[fila_rey][columna].color=='w' && (m[fila_rey][columna].tipo_pieza.nombre=='R' || m[fila_rey][columna].tipo_pieza.nombre=='Q')){
										return 1;
									}	
								}
							}
						}
						//No encontro amenaza
						return 0;
					}else{
						//Arriba derecha ad tope tabla por fila es 0 y columna es 8
						if(direccion[0]=='a' && direccion[1]=='d'){
							int fila = fila_rey - 1;
							int columna=columna_rey + 1;
							while (fila >= 0 && columna <= 8) {
								if(m[fila][columna].color=='V') {
									fila--;
									columna++;
								}else{
									if(m[fila][columna].color=='b'){
										return 0;
									}else{
										if(m[fila][columna].color=='w' && (m[fila][columna].tipo_pieza.nombre=='B' || m[fila][columna].tipo_pieza.nombre=='Q')){
											return 1;
										}	
									}
								}
							}
							//No encontro amenaza
							return 0;
						}else{
							//Arriba izquierda ai tope tabla por fila es 0 y columna es 0
							if(direccion[0]=='a' && direccion[1]=='i'){
								int fila = fila_rey - 1;
								int columna=columna_rey - 1;
								while (fila >= 0 && columna >= 0) {
									if(m[fila][columna].color=='V') {
										fila--;
										columna--;
									}else{
										if(m[fila][columna].color=='b'){
											return 0;
										}else{
											if(m[fila][columna].color=='w' && (m[fila][columna].tipo_pieza.nombre=='B' || m[fila][columna].tipo_pieza.nombre=='Q')){
												return 1;
											}	
										}
									}
								}
								//No encontro amenaza
								return 0;
							}else{
								//Abajo derecha bd tope tabla por fila es 8 y columna es 8
								if(direccion[0]=='b' && direccion[1]=='d'){
									int fila = fila_rey + 1;
									int columna=columna_rey + 1;
									while (fila <= 8 && columna <= 8) {
										if(m[fila][columna].color=='V') {
											fila++;
											columna++;
										}else{
											if(m[fila][columna].color=='b'){
												return 0;
											}else{
												if(m[fila][columna].color=='w' && (m[fila][columna].tipo_pieza.nombre=='B' || m[fila][columna].tipo_pieza.nombre=='Q')){
													return 1;
												}	
											}
										}
									}
									//No encontro amenaza
									return 0;
								}else{
									//Abajo Izquierda bi tope tabla por fila es 8 y columna es 0
									if(direccion[0]=='b' && direccion[1]=='i'){
										int fila = fila_rey + 1;
										int columna=columna_rey - 1;
										while (fila <= 8 && columna >= 0) {
											if(m[fila][columna].color=='V') {
												fila++;
												columna--;
											}else{
												if(m[fila][columna].color=='b'){
													return 0;
												}else{
													if(m[fila][columna].color=='w' && (m[fila][columna].tipo_pieza.nombre=='B' || m[fila][columna].tipo_pieza.nombre=='Q')){
														return 1;
													}	
												}
											}
										}
										//No encontro amenaza
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

int jaque_torre_alfil_reina(char color,int fila_rey,int columna_rey,p (*m)[8]){
	if(color=='w'){
		if(verificacion_todas_direcciones_jaque('w',"aa",fila_rey,columna_rey,m)==0 && verificacion_todas_direcciones_jaque('w',"bb",fila_rey,columna_rey,m)==0 && verificacion_todas_direcciones_jaque('w',"ii",fila_rey,columna_rey,m)==0 && verificacion_todas_direcciones_jaque('w',"dd",fila_rey,columna_rey,m)==0 && verificacion_todas_direcciones_jaque('w',"ad",fila_rey,columna_rey,m)==0 && verificacion_todas_direcciones_jaque('w',"ai",fila_rey,columna_rey,m)==0 && verificacion_todas_direcciones_jaque('w',"bd",fila_rey,columna_rey,m)==0 && verificacion_todas_direcciones_jaque('w',"bi",fila_rey,columna_rey,m)==0){
			//Sin amenazas
			return 0;
		}else{
			return 1;
		}
	}else{
		if(verificacion_todas_direcciones_jaque('b',"aa",fila_rey,columna_rey,m)==0 && verificacion_todas_direcciones_jaque('b',"bb",fila_rey,columna_rey,m)==0 && verificacion_todas_direcciones_jaque('b',"ii",fila_rey,columna_rey,m)==0 && verificacion_todas_direcciones_jaque('b',"dd",fila_rey,columna_rey,m)==0 && verificacion_todas_direcciones_jaque('b',"ad",fila_rey,columna_rey,m)==0 && verificacion_todas_direcciones_jaque('b',"ai",fila_rey,columna_rey,m)==0 && verificacion_todas_direcciones_jaque('b',"bd",fila_rey,columna_rey,m)==0 && verificacion_todas_direcciones_jaque('b',"bi",fila_rey,columna_rey,m)==0){
			//Sin amenazas
			return 0;
		}else{
			return 1;
		}
	}	
}

int jaque_rey(char color,int fila_rey,int columna_rey,p (*m)[8]){
	if(color=='w'){
		//Arriba
		if(verificacion_dominio(fila_rey-1,columna_rey) && m[fila_rey-1][columna_rey].tipo_pieza.nombre=='K' && m[fila_rey-1][columna_rey].color=='b'){
			return 1;
		}else{
			//Abajo
			if(verificacion_dominio(fila_rey+1,columna_rey) && m[fila_rey+1][columna_rey].tipo_pieza.nombre=='K' && m[fila_rey+1][columna_rey].color=='b'){
				return 1;
			}else{
				//Izquierda
				if(verificacion_dominio(fila_rey,columna_rey-1) && m[fila_rey][columna_rey-1].tipo_pieza.nombre=='K' && m[fila_rey][columna_rey-1].color=='b'){
					return 1;
				}else{
					//Derecha
					if(verificacion_dominio(fila_rey,columna_rey+1) && m[fila_rey][columna_rey+1].tipo_pieza.nombre=='K' && m[fila_rey][columna_rey+1].color=='b'){
						return 1;
					}else{
						//Arriba derecha
						if(verificacion_dominio(fila_rey-1,columna_rey+1) && m[fila_rey-1][columna_rey+1].tipo_pieza.nombre=='K' && m[fila_rey-1][columna_rey+1].color=='b'){
							return 1;
						}else{
							//Arriba izquierda
							if(verificacion_dominio(fila_rey-1,columna_rey-1) && m[fila_rey-1][columna_rey-1].tipo_pieza.nombre=='K' && m[fila_rey-1][columna_rey-1].color=='b'){
								return 1;
							}else{
								//Abajo derecha
								if(verificacion_dominio(fila_rey+1,columna_rey+1) && m[fila_rey+1][columna_rey+1].tipo_pieza.nombre=='K' && m[fila_rey+1][columna_rey+1].color=='b'){
									return 1;
								}else{
									//Abajo izquierda
									if(verificacion_dominio(fila_rey+1,columna_rey-1) && m[fila_rey+1][columna_rey-1].tipo_pieza.nombre=='K' && m[fila_rey+1][columna_rey-1].color=='b'){
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
		//Negro
		//Arriba
		if(verificacion_dominio(fila_rey-1,columna_rey) && m[fila_rey-1][columna_rey].tipo_pieza.nombre=='K' && m[fila_rey-1][columna_rey].color=='w'){
			return 1;
		}else{
			//Abajo
			if(verificacion_dominio(fila_rey+1,columna_rey) && m[fila_rey+1][columna_rey].tipo_pieza.nombre=='K' && m[fila_rey+1][columna_rey].color=='w'){
				return 1;
			}else{
				//Izquierda
				if(verificacion_dominio(fila_rey,columna_rey-1) && m[fila_rey][columna_rey-1].tipo_pieza.nombre=='K' && m[fila_rey][columna_rey-1].color=='w'){
					return 1;
				}else{
					//Derecha
					if(verificacion_dominio(fila_rey,columna_rey+1) && m[fila_rey][columna_rey+1].tipo_pieza.nombre=='K' && m[fila_rey][columna_rey+1].color=='w'){
						return 1;
					}else{
						//Arriba derecha
						if(verificacion_dominio(fila_rey-1,columna_rey+1) && m[fila_rey-1][columna_rey+1].tipo_pieza.nombre=='K' && m[fila_rey-1][columna_rey+1].color=='w'){
							return 1;
						}else{
							//Arriba izquierda
							if(verificacion_dominio(fila_rey-1,columna_rey-1) && m[fila_rey-1][columna_rey-1].tipo_pieza.nombre=='K' && m[fila_rey-1][columna_rey-1].color=='w'){
								return 1;
							}else{
								//Abajo derecha
								if(verificacion_dominio(fila_rey+1,columna_rey+1) && m[fila_rey+1][columna_rey+1].tipo_pieza.nombre=='K' && m[fila_rey+1][columna_rey+1].color=='w'){
									return 1;
								}else{
									//Abajo izquierda
									if(verificacion_dominio(fila_rey+1,columna_rey-1) && m[fila_rey+1][columna_rey-1].tipo_pieza.nombre=='K' && m[fila_rey+1][columna_rey-1].color=='w'){
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