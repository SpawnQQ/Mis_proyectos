#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <curses.h>

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
				if(m[fila][columna_rey].color=='V' && m[fila][columna_rey].tipo_pieza.nombre=='V') {
					fila--;
				}else{
					if(m[fila][columna_rey].color=='w'){
						return 0;
					}else{
						if(m[fila][columna_rey].color=='b' && (m[fila][columna_rey].tipo_pieza.nombre=='R' || m[fila][columna_rey].tipo_pieza.nombre=='Q')){
							return 1;
						}else{
							return 0;
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
				while (fila <= 7) {
					if(m[fila][columna_rey].color=='V' && m[fila][columna_rey].tipo_pieza.nombre=='V') {
						fila++;
					}else{
						if(m[fila][columna_rey].color=='w'){
							return 0;
						}else{
							if(m[fila][columna_rey].color=='b' && (m[fila][columna_rey].tipo_pieza.nombre=='R' || m[fila][columna_rey].tipo_pieza.nombre=='Q')){
								return 1;
							}else{
								return 0;
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
						if(m[fila_rey][columna].color=='V' && m[fila_rey][columna].tipo_pieza.nombre=='V') {
							columna--;
						}else{
							if(m[fila_rey][columna].color=='w'){
								return 0;
							}else{
								if(m[fila_rey][columna].color=='b' && (m[fila_rey][columna].tipo_pieza.nombre=='R' || m[fila_rey][columna].tipo_pieza.nombre=='Q')){
									return 1;
								}else{
									return 0;
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
						while (columna <= 7) {
							if(m[fila_rey][columna].color=='V' && m[fila_rey][columna].tipo_pieza.nombre=='V') {
								columna++;
							}else{
								if(m[fila_rey][columna].color=='w'){
									return 0;
								}else{
									if(m[fila_rey][columna].color=='b' && (m[fila_rey][columna].tipo_pieza.nombre=='R' || m[fila_rey][columna].tipo_pieza.nombre=='Q')){
										return 1;
									}else{
										return 0;
									}	
								}
							}
						}
						//No encontro amenaza
						return 0;
					}else{
						//Arriba derecha ad tope tabla por fila es 0 y columna es 7
						if(direccion[0]=='a' && direccion[1]=='d'){
							int fila = fila_rey - 1;
							int columna=columna_rey + 1;
							while (fila >= 0 && columna <= 7) {
								if(m[fila][columna].color=='V' && m[fila][columna].tipo_pieza.nombre=='V') {
									fila--;
									columna++;
								}else{
									if(m[fila][columna].color=='w'){
										return 0;
									}else{
										if(m[fila][columna].color=='b' && (m[fila][columna].tipo_pieza.nombre=='B' || m[fila][columna].tipo_pieza.nombre=='Q')){
											return 1;
										}else{
											return 0;
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
									if(m[fila][columna].color=='V' && m[fila][columna].tipo_pieza.nombre=='V') {
										fila--;
										columna--;
									}else{
										if(m[fila][columna].color=='w'){
											return 0;
										}else{
											if(m[fila][columna].color=='b' && (m[fila][columna].tipo_pieza.nombre=='B' || m[fila][columna].tipo_pieza.nombre=='Q')){
												return 1;
											}else{
												return 0;
											}
										}
									}
								}
								//No encontro amenaza
								return 0;
							}else{
								//Abajo derecha bd tope tabla por fila es 7 y columna es 7
								if(direccion[0]=='b' && direccion[1]=='d'){
									int fila = fila_rey + 1;
									int columna=columna_rey + 1;
									while (fila <= 7 && columna <= 7) {
										if(m[fila][columna].color=='V' && m[fila][columna].tipo_pieza.nombre=='V') {
											fila++;
											columna++;
										}else{
											if(m[fila][columna].color=='w'){
												return 0;
											}else{
												if(m[fila][columna].color=='b' && (m[fila][columna].tipo_pieza.nombre=='B' || m[fila][columna].tipo_pieza.nombre=='Q')){
													return 1;
												}else{
													return 0;
												}
											}
										}
									}
									//No encontro amenaza
									return 0;
								}else{
									//Abajo Izquierda bi tope tabla por fila es 7 y columna es 0
									if(direccion[0]=='b' && direccion[1]=='i'){
										int fila = fila_rey + 1;
										int columna=columna_rey - 1;
										while (fila <= 7 && columna >= 0) {
											if(m[fila][columna].color=='V' && m[fila][columna].tipo_pieza.nombre=='V') {
												fila++;
												columna--;
											}else{
												if(m[fila][columna].color=='w'){
													return 0;
												}else{
													if(m[fila][columna].color=='b' && (m[fila][columna].tipo_pieza.nombre=='B' || m[fila][columna].tipo_pieza.nombre=='Q')){
														return 1;
													}else{
														return 0;
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
				if(m[fila][columna_rey].color=='V' && m[fila][columna_rey].tipo_pieza.nombre=='V') {
					fila--;
				}else{
					if(m[fila][columna_rey].color=='b'){
						return 0;
					}else{
						if(m[fila][columna_rey].color=='w' && (m[fila][columna_rey].tipo_pieza.nombre=='R' || m[fila][columna_rey].tipo_pieza.nombre=='Q')){
							return 1;
						}else{
							return 0;
						}	
					}
				}
			}
			//No encontro amenaza
			return 0;
		}else{
			//Abajo bb tope table por fila es 7
			if(direccion[0]=='b' && direccion[1]=='b'){
				int fila = fila_rey + 1;
				while (fila <= 7) {
					if(m[fila][columna_rey].color=='V' && m[fila][columna_rey].tipo_pieza.nombre=='V') {
						fila++;
					}else{
						if(m[fila][columna_rey].color=='b'){
							return 0;
						}else{
							if(m[fila][columna_rey].color=='w' && (m[fila][columna_rey].tipo_pieza.nombre=='R' || m[fila][columna_rey].tipo_pieza.nombre=='Q')){
								return 1;
							}else{
								return 0;
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
						if(m[fila_rey][columna].color=='V' && m[fila_rey][columna].tipo_pieza.nombre=='V') {
							columna--;
						}else{
							if(m[fila_rey][columna].color=='b'){
								return 0;
							}else{
								if(m[fila_rey][columna].color=='w' && (m[fila_rey][columna].tipo_pieza.nombre=='R' || m[fila_rey][columna].tipo_pieza.nombre=='Q')){
									return 1;
								}else{
									return 0;
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
						while (columna <= 7) {
							if(m[fila_rey][columna].color=='V' && m[fila_rey][columna].tipo_pieza.nombre=='V') {
								columna++;
							}else{
								if(m[fila_rey][columna].color=='b'){
									return 0;
								}else{
									if(m[fila_rey][columna].color=='w' && (m[fila_rey][columna].tipo_pieza.nombre=='R' || m[fila_rey][columna].tipo_pieza.nombre=='Q')){
										return 1;
									}else{
										return 0;
									}	
								}
							}
						}
						//No encontro amenaza
						return 0;
					}else{
						//Arriba derecha ad tope tabla por fila es 0 y columna es 7
						if(direccion[0]=='a' && direccion[1]=='d'){
							int fila = fila_rey - 1;
							int columna=columna_rey + 1;
							while (fila >= 0 && columna <= 7) {
								if(m[fila][columna].color=='V' && m[fila][columna].tipo_pieza.nombre=='V') {
									fila--;
									columna++;
								}else{
									if(m[fila][columna].color=='b'){
										return 0;
									}else{
										if(m[fila][columna].color=='w' && (m[fila][columna].tipo_pieza.nombre=='B' || m[fila][columna].tipo_pieza.nombre=='Q')){
											return 1;
										}else{
											return 0;
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
									if(m[fila][columna].color=='V' && m[fila][columna].tipo_pieza.nombre=='V') {
										fila--;
										columna--;
									}else{
										if(m[fila][columna].color=='b'){
											return 0;
										}else{
											if(m[fila][columna].color=='w' && (m[fila][columna].tipo_pieza.nombre=='B' || m[fila][columna].tipo_pieza.nombre=='Q')){
												return 1;
											}else{
												return 0;
											}	
										}
									}
								}
								//No encontro amenaza
								return 0;
							}else{
								//Abajo derecha bd tope tabla por fila es 7 y columna es 7
								if(direccion[0]=='b' && direccion[1]=='d'){
									int fila = fila_rey + 1;
									int columna=columna_rey + 1;
									while (fila <= 7 && columna <= 7) {
										if(m[fila][columna].color=='V' && m[fila][columna].tipo_pieza.nombre=='V') {
											fila++;
											columna++;
										}else{
											if(m[fila][columna].color=='b'){
												return 0;
											}else{
												if(m[fila][columna].color=='w' && (m[fila][columna].tipo_pieza.nombre=='B' || m[fila][columna].tipo_pieza.nombre=='Q')){
													return 1;
												}else{
													return 0;
												}
											}
										}
									}
									//No encontro amenaza
									return 0;
								}else{
									//Abajo Izquierda bi tope tabla por fila es 7 y columna es 0
									if(direccion[0]=='b' && direccion[1]=='i'){
										int fila = fila_rey + 1;
										int columna=columna_rey - 1;
										while (fila <= 7 && columna >= 0) {
											if(m[fila][columna].color=='V' && m[fila][columna].tipo_pieza.nombre=='V') {
												fila++;
												columna--;
											}else{
												if(m[fila][columna].color=='b'){
													return 0;
												}else{
													if(m[fila][columna].color=='w' && (m[fila][columna].tipo_pieza.nombre=='B' || m[fila][columna].tipo_pieza.nombre=='Q')){
														return 1;
													}else{
														return 0;
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

int jaque(int turno, p (*m)[8]){
	int posicion[2];
	if(turno%2!=0){
		//pieza blanca
		buscar_rey('w',posicion,m);
		int fila_rey=posicion[0],columna_rey=posicion[1];
		if(jaque_peon('w',fila_rey,columna_rey,m) || jaque_caballo('w',fila_rey,columna_rey,m) || jaque_torre_alfil_reina('w',fila_rey,columna_rey,m) || jaque_rey('w',fila_rey,columna_rey,m)){
			return 1;
		}else{
			return 0;
		}

	}else{
		buscar_rey('b',posicion,m);
		int fila_rey=posicion[0],columna_rey=posicion[1];
		if(jaque_peon('b',fila_rey,columna_rey,m) || jaque_caballo('b',fila_rey,columna_rey,m) || jaque_torre_alfil_reina('b',fila_rey,columna_rey,m) || jaque_rey('b',fila_rey,columna_rey,m)){
			return 1;
		}else{
			return 0;
		}
	}
}

int all_mov_peon(int turno, int fila_elegido, int columna_elegido, p (*m)[8]){
	int mov_permitido=0;
	//mov arriba
	p respaldo[8][8];
	
	respaldar_tablero(respaldo,m);

	if(fila_elegido-1 >= 0){
		mover_peon(fila_elegido,columna_elegido, fila_elegido-1,columna_elegido, m,&mov_permitido);
	}
	if(mov_permitido==1 && jaque(turno,m)==0){
		//Si me permite el movimiento ,y si el rey no quedo vulnerable
		respaldar_tablero(m,respaldo);
		return 1;
	}else{
		//Abajo
		if(fila_elegido+1 < 8){
			respaldar_tablero(m,respaldo);
			mover_peon(fila_elegido,columna_elegido, fila_elegido+1, columna_elegido, m,&mov_permitido);
		}
		if(mov_permitido==1 && jaque(turno,m)==0){
			//Si me permite el movimiento ,y si el rey no quedo vulnerable
			respaldar_tablero(m,respaldo);
			return 1;
		}else{
			//Arriba 2 espacios
			if(fila_elegido-2 >= 0){
				respaldar_tablero(m,respaldo);
				mover_peon(fila_elegido,columna_elegido, fila_elegido-2, columna_elegido, m,&mov_permitido);
			}
			if(mov_permitido==1 && jaque(turno,m)==0){
				//Si me permite el movimiento ,y si el rey no quedo vulnerable
				respaldar_tablero(m,respaldo);
				return 1;
			}else{
				//Abajo 2 espacios
				if(fila_elegido+2 < 8){
					respaldar_tablero(m,respaldo);
					mover_peon(fila_elegido,columna_elegido, fila_elegido+2, columna_elegido, m,&mov_permitido);
				}
				if(mov_permitido==1 && jaque(turno,m)==0){
					//Si me permite el movimiento ,y si el rey no quedo vulnerable
					respaldar_tablero(m,respaldo);
					return 1;
				}else{
					//Arriba derecha, comer
					//Si se come al rey, generara problemas al buscarlo "Violacion de segmento"
					if(fila_elegido-1 >=0 && columna_elegido+1 < 8 && m[fila_elegido-1][columna_elegido+1].tipo_pieza.nombre != 'K'){
						respaldar_tablero(m,respaldo);
						mover_peon(fila_elegido,columna_elegido, fila_elegido-1, columna_elegido+1, m,&mov_permitido);
					}
					if(mov_permitido==1 && jaque(turno,m)==0){
						//Si me permite el movimiento ,y si el rey no quedo vulnerable
						respaldar_tablero(m,respaldo);
						return 1;
					}else{
						//Arriba izquierda, comer
						if(fila_elegido-1 >= 0 && columna_elegido-1 >= 0 && m[fila_elegido-1][columna_elegido-1].tipo_pieza.nombre != 'K'){
							respaldar_tablero(m,respaldo);
							mover_peon(fila_elegido,columna_elegido, fila_elegido-1, columna_elegido-1, m,&mov_permitido);
						}
						if(mov_permitido==1 && jaque(turno,m)==0){
							//Si me permite el movimiento ,y si el rey no quedo vulnerable
							respaldar_tablero(m,respaldo);
							return 1;
						}else{
							//Abajo derecha, comer
							if(fila_elegido+1 < 8 && columna_elegido+1 < 8 && m[fila_elegido+1][columna_elegido+1].tipo_pieza.nombre != 'K'){
								respaldar_tablero(m,respaldo);
								mover_peon(fila_elegido,columna_elegido, fila_elegido+1, columna_elegido+1, m,&mov_permitido);
							}
							if(mov_permitido==1 && jaque(turno,m)==0){
								//Si me permite el movimiento ,y si el rey no quedo vulnerable
								respaldar_tablero(m,respaldo);
								return 1;
							}else{
								//Abajo izquierda, comer
								if(fila_elegido+1 < 8 && columna_elegido-1 >= 0 && m[fila_elegido+1][columna_elegido-1].tipo_pieza.nombre != 'K'){
									respaldar_tablero(m,respaldo);
									mover_peon(fila_elegido,columna_elegido, fila_elegido+1, columna_elegido-1, m,&mov_permitido);
								}
								if(mov_permitido==1 && jaque(turno,m)==0){
									//Si me permite el movimiento ,y si el rey no quedo vulnerable
									respaldar_tablero(m,respaldo);
									return 1;
								}else{
									//No existe un movimiento de esta pieza, que evite el jaque de 
									respaldar_tablero(m,respaldo);
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

int all_mov_caballo(int turno, int fila_elegido, int columna_elegido, p (*m)[8]){
	int mov_permitido=0;
	
	//Izquierda Arriba
	p respaldo[8][8];
	
	respaldar_tablero(respaldo,m);
	if(fila_elegido-1 >= 0 && columna_elegido-2 >=0 && m[fila_elegido-1][columna_elegido-2].tipo_pieza.nombre != 'K'){
		mover_caballo(fila_elegido,columna_elegido, fila_elegido-1,columna_elegido-2, m,&mov_permitido);
	}
	if(mov_permitido==1 && jaque(turno,m)==0 ){
		//Si me permite el movimiento ,y si el rey no quedo vulnerable
		respaldar_tablero(m,respaldo);
		return 1;
	}else{
		//Izquierda abajo
		if(fila_elegido+1 >= 0 && columna_elegido-2 >=0 && m[fila_elegido+1][columna_elegido-2].tipo_pieza.nombre != 'K'){
			respaldar_tablero(m,respaldo);
			mover_caballo(fila_elegido,columna_elegido, fila_elegido+1,columna_elegido-2, m,&mov_permitido);
		}
		if(mov_permitido==1 && jaque(turno,m)==0){
			//Si me permite el movimiento ,y si el rey no quedo vulnerable
			respaldar_tablero(m,respaldo);
			return 1;
		}else{
			//Derecha arriba
			if(fila_elegido-1 >= 0 && columna_elegido+2 >=0 && m[fila_elegido-1][columna_elegido+2].tipo_pieza.nombre != 'K'){
				respaldar_tablero(m,respaldo);
				mover_caballo(fila_elegido,columna_elegido, fila_elegido-1,columna_elegido+2, m,&mov_permitido);
			}
			if(mov_permitido==1 && jaque(turno,m)==0){
				//Si me permite el movimiento ,y si el rey no quedo vulnerable
				respaldar_tablero(m,respaldo);
				return 1;
			}else{
				//Derecha abajo
				if(fila_elegido+1 >= 0 && columna_elegido+2 >=0 && m[fila_elegido+1][columna_elegido+2].tipo_pieza.nombre != 'K'){
					respaldar_tablero(m,respaldo);
					mover_caballo(fila_elegido,columna_elegido, fila_elegido+1,columna_elegido+2, m,&mov_permitido);
				}
				if(mov_permitido==1 && jaque(turno,m)==0){
					//Si me permite el movimiento ,y si el rey no quedo vulnerable
					respaldar_tablero(m,respaldo);
					return 1;
				}else{
					//Arriba derecha
					if(fila_elegido-2 >= 0 && columna_elegido+1 >=0 && m[fila_elegido-2][columna_elegido+1].tipo_pieza.nombre != 'K'){
						respaldar_tablero(m,respaldo);
						mover_caballo(fila_elegido,columna_elegido, fila_elegido-2,columna_elegido+1, m,&mov_permitido);
					}
					if(mov_permitido==1 && jaque(turno,m)==0){
						//Si me permite el movimiento ,y si el rey no quedo vulnerable
						respaldar_tablero(m,respaldo);
						return 1;
					}else{
						//Arriba izquierda
						if(fila_elegido-2 >= 0 && columna_elegido-1 >=0 && m[fila_elegido-2][columna_elegido-1].tipo_pieza.nombre != 'K'){
							respaldar_tablero(m,respaldo);
							mover_caballo(fila_elegido,columna_elegido, fila_elegido-2,columna_elegido-1, m,&mov_permitido);
						}
						if(mov_permitido==1 && jaque(turno,m)==0){
							//Si me permite el movimiento ,y si el rey no quedo vulnerable
							respaldar_tablero(m,respaldo);
							return 1;
						}else{
							//Abajo derecha
							if(fila_elegido+2 >= 0 && columna_elegido+1 >=0 && m[fila_elegido+2][columna_elegido+1].tipo_pieza.nombre != 'K'){
								respaldar_tablero(m,respaldo);
								mover_caballo(fila_elegido,columna_elegido, fila_elegido+2,columna_elegido+1, m,&mov_permitido);
							}
							if(mov_permitido==1 && jaque(turno,m)==0){
								//Si me permite el movimiento ,y si el rey no quedo vulnerable
								respaldar_tablero(m,respaldo);
								return 1;
							}else{
								//Abajo izquierda
								if(fila_elegido+2 >= 0 && columna_elegido-1 >=0 && m[fila_elegido+2][columna_elegido-1].tipo_pieza.nombre != 'K'){
									respaldar_tablero(m,respaldo);
									mover_caballo(fila_elegido,columna_elegido, fila_elegido+2,columna_elegido-1, m,&mov_permitido);
								}
								if(mov_permitido==1 && jaque(turno,m)==0){
									//Si me permite el movimiento ,y si el rey no quedo vulnerable
									respaldar_tablero(m,respaldo);
									return 1;
								}else{
									respaldar_tablero(m,respaldo);
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

int all_mov_torre(int turno, int fila_elegido, int columna_elegido, p (*m)[8]){
	int mov_permitido=0;
	int i,j;
	p respaldo[8][8];
	
	respaldar_tablero(respaldo,m);
	//Arriba
	for(i=fila_elegido-1;i>=0;i--){
		if(m[i][columna_elegido].tipo_pieza.nombre != 'K'){
			mover_torre(fila_elegido,columna_elegido, i,columna_elegido, m,&mov_permitido);
			if(mov_permitido==1 && jaque(turno,m)==0){
				respaldar_tablero(m,respaldo);
				return 1;
			}
			respaldar_tablero(m,respaldo);
		}
	}
	//Abajo
	for(i=fila_elegido+1;i<8;i++){
		if(m[i][columna_elegido].tipo_pieza.nombre != 'K'){
			mover_torre(fila_elegido,columna_elegido, i,columna_elegido, m,&mov_permitido);
			if(mov_permitido==1 && jaque(turno,m)==0){
				respaldar_tablero(m,respaldo);
				return 1;
			}
			respaldar_tablero(m,respaldo);
		}
	}
	//Izquierda
	for(j=columna_elegido-1;j>=0;j--){
		if(m[fila_elegido][j].tipo_pieza.nombre != 'K'){
			mover_torre(fila_elegido,columna_elegido, fila_elegido,j, m,&mov_permitido);
			if(mov_permitido==1 && jaque(turno,m)==0){
				respaldar_tablero(m,respaldo);
				return 1;
			}
			respaldar_tablero(m,respaldo);
		}
	}
	//Izquierda
	for(j=columna_elegido+1;j<8;j++){
		if(m[fila_elegido][j].tipo_pieza.nombre != 'K'){
			mover_torre(fila_elegido,columna_elegido, fila_elegido,j, m,&mov_permitido);
			if(mov_permitido==1 && jaque(turno,m)==0){
				respaldar_tablero(m,respaldo);
				return 1;
			}
			respaldar_tablero(m,respaldo);
		}
	}
	respaldar_tablero(m,respaldo);
	return 0;
}

int all_mov_alfil(int turno, int fila_elegido, int columna_elegido, p (*m)[8]){
	int mov_permitido=0;
	int i,j;
	p respaldo[8][8];

	respaldar_tablero(respaldo,m);
	//Arriba derecha
	i=fila_elegido-1;
	j=columna_elegido+1;
	while(i>-1 && j<8){
		if(m[i][j].tipo_pieza.nombre != 'K'){
			mover_alfil(fila_elegido,columna_elegido, i,j, m,&mov_permitido);
			if(mov_permitido==1 && jaque(turno,m)==0){
				respaldar_tablero(m,respaldo);
				return 1;
			}
			respaldar_tablero(m,respaldo);
		}
		i--;
		j++;
	}
	//Arriba izquierda
	i=fila_elegido-1;
	j=columna_elegido-1;
	while(i>-1 && j>-1){
		if(m[i][j].tipo_pieza.nombre != 'K'){
			mover_alfil(fila_elegido,columna_elegido, i,j, m,&mov_permitido);
			if(mov_permitido==1 && jaque(turno,m)==0){
				respaldar_tablero(m,respaldo);
				return 1;
			}
			respaldar_tablero(m,respaldo);
		}
		i--;
		j--;
	}
	//Abajo derecha
	i=fila_elegido+1;
	j=columna_elegido+1;
	while(i<8 && j<8){
		if(m[i][j].tipo_pieza.nombre != 'K'){
			mover_alfil(fila_elegido,columna_elegido, i,j, m,&mov_permitido);
			if(mov_permitido==1 && jaque(turno,m)==0){
				respaldar_tablero(m,respaldo);
				return 1;
			}
			respaldar_tablero(m,respaldo);
		}
		i++;
		j++;
	}
	//Abajo izquierda
	i=fila_elegido+1;
	j=columna_elegido-1;
	while(i<8 && j>-1){
		if(m[i][j].tipo_pieza.nombre != 'K'){
			mover_alfil(fila_elegido,columna_elegido, i,j, m,&mov_permitido);
			if(mov_permitido==1 && jaque(turno,m)==0){
				respaldar_tablero(m,respaldo);
				return 1;
			}
			respaldar_tablero(m,respaldo);
		}
		i++;
		j--;
	}
	respaldar_tablero(m,respaldo);
	return 0;	
}	

int all_mov_reina(int turno, int fila_elegido, int columna_elegido, p (*m)[8]){
	int mov_permitido=0;
	int i,j;
	p respaldo[8][8];

	respaldar_tablero(respaldo,m);
	//Arriba
	for(i=fila_elegido-1;i>=0;i--){
		if(m[i][columna_elegido].tipo_pieza.nombre != 'K'){
			mover_reina(fila_elegido,columna_elegido, i,columna_elegido, m,&mov_permitido);
			if(mov_permitido==1 && jaque(turno,m)==0){
				respaldar_tablero(m,respaldo);
				return 1;
			}
			respaldar_tablero(m,respaldo);
		}
	}
	//Abajo
	for(i=fila_elegido+1;i<8;i++){
		if(m[i][columna_elegido].tipo_pieza.nombre != 'K'){
			mover_reina(fila_elegido,columna_elegido, i,columna_elegido, m,&mov_permitido);
			if(mov_permitido==1 && jaque(turno,m)==0){
				respaldar_tablero(m,respaldo);
				return 1;
			}
			respaldar_tablero(m,respaldo);
		}
	}
	//Izquierda
	for(j=columna_elegido-1;j>=0;j--){
		if(m[fila_elegido][j].tipo_pieza.nombre != 'K'){
			mover_reina(fila_elegido,columna_elegido, fila_elegido,j, m,&mov_permitido);
			if(mov_permitido==1 && jaque(turno,m)==0){
				respaldar_tablero(m,respaldo);
				return 1;
			}
			respaldar_tablero(m,respaldo);
		}
	}
	//Izquierda
	for(j=columna_elegido+1;j<8;j++){
		if(m[fila_elegido][j].tipo_pieza.nombre != 'K'){
			mover_reina(fila_elegido,columna_elegido, fila_elegido,j, m,&mov_permitido);
			if(mov_permitido==1 && jaque(turno,m)==0){
				respaldar_tablero(m,respaldo);
				return 1;
			}
			respaldar_tablero(m,respaldo);
		}
	}
	//Arriba derecha
	i=fila_elegido-1;
	j=columna_elegido+1;
	while(i>-1 && j<8){
		if(m[i][j].tipo_pieza.nombre != 'K'){
			mover_reina(fila_elegido,columna_elegido, i,j, m,&mov_permitido);
			if(mov_permitido==1 && jaque(turno,m)==0){
				respaldar_tablero(m,respaldo);
				return 1;
			}
			respaldar_tablero(m,respaldo);
		}
		i--;
		j++;
	}
	//Arriba izquierda
	i=fila_elegido-1;
	j=columna_elegido-1;
	while(i>-1 && j>-1){
		if(m[i][j].tipo_pieza.nombre != 'K'){
			mover_reina(fila_elegido,columna_elegido, i,j, m,&mov_permitido);
			if(mov_permitido==1 && jaque(turno,m)==0){
				respaldar_tablero(m,respaldo);
				return 1;
			}
			respaldar_tablero(m,respaldo);
		}
		i--;
		j--;
	}
	//Abajo derecha
	i=fila_elegido+1;
	j=columna_elegido+1;
	while(i<8 && j<8){
		if(m[i][j].tipo_pieza.nombre != 'K'){
			mover_reina(fila_elegido,columna_elegido, i,j, m,&mov_permitido);
			if(mov_permitido==1 && jaque(turno,m)==0){
				respaldar_tablero(m,respaldo);
				return 1;
			}
			respaldar_tablero(m,respaldo);
		}
		i++;
		j++;
	}
	//Abajo izquierda
	i=fila_elegido+1;
	j=columna_elegido-1;
	while(i<8 && j>-1){
		if(m[i][j].tipo_pieza.nombre != 'K'){
			mover_reina(fila_elegido,columna_elegido, i,j, m,&mov_permitido);
			if(mov_permitido==1 && jaque(turno,m)==0){
				respaldar_tablero(m,respaldo);
				return 1;
			}
			respaldar_tablero(m,respaldo);
		}
		i++;
		j--;
	}
	respaldar_tablero(m,respaldo);
	return 0;
}	

int all_mov_rey(int turno, int fila_elegido, int columna_elegido, p (*m)[8]){
	int mov_permitido=0;
	int i,j;
	p respaldo[8][8];

	respaldar_tablero(respaldo,m);
	//Arriba
	if(fila_elegido-1 >=0 && m[fila_elegido-1][columna_elegido].tipo_pieza.nombre!='K'){
		mover_rey(fila_elegido,columna_elegido, fila_elegido-1,columna_elegido, m,&mov_permitido);
	}
	if(mov_permitido==1 && jaque(turno,m)==0){
		//Si me permite el movimiento ,y si el rey no quedo vulnerable
		respaldar_tablero(m,respaldo);
		return 1;
	}else{
		//Abajo
		if(fila_elegido+1 < 8 && m[fila_elegido+1][columna_elegido].tipo_pieza.nombre!='K'){
			respaldar_tablero(m,respaldo);
			mover_rey(fila_elegido,columna_elegido, fila_elegido+1, columna_elegido, m,&mov_permitido);
		}
		if(mov_permitido==1 && jaque(turno,m)==0){
			//Si me permite el movimiento ,y si el rey no quedo vulnerable
			respaldar_tablero(m,respaldo);
			return 1;
		}else{
			//Derecha
			if(columna_elegido+1 < 8 && m[fila_elegido][columna_elegido+1].tipo_pieza.nombre!='K'){
				respaldar_tablero(m,respaldo);
				mover_rey(fila_elegido,columna_elegido, fila_elegido, columna_elegido+1, m,&mov_permitido);
			}
			if(mov_permitido==1 && jaque(turno,m)==0){
				//Si me permite el movimiento ,y si el rey no quedo vulnerable
				respaldar_tablero(m,respaldo);
				return 1;
			}else{
				//Izquierda
				if(columna_elegido-1 >=0 && m[fila_elegido][columna_elegido-1].tipo_pieza.nombre!='K'){
					respaldar_tablero(m,respaldo);
					mover_rey(fila_elegido,columna_elegido, fila_elegido, columna_elegido-1, m,&mov_permitido);
				}
				if(mov_permitido==1 && jaque(turno,m)==0){
					//Si me permite el movimiento ,y si el rey no quedo vulnerable
					respaldar_tablero(m,respaldo);
					return 1;
				}else{
					//Arriba derecha, comer
					//Si se come al rey, generara problemas al buscarlo "Violacion de segmento"
					if(fila_elegido-1 >=0 && columna_elegido+1 < 8 && m[fila_elegido-1][columna_elegido+1].tipo_pieza.nombre != 'K'){
						respaldar_tablero(m,respaldo);
						mover_rey(fila_elegido,columna_elegido, fila_elegido-1, columna_elegido+1, m,&mov_permitido);
					}
					if(mov_permitido==1 && jaque(turno,m)==0){
						//Si me permite el movimiento ,y si el rey no quedo vulnerable
						respaldar_tablero(m,respaldo);
						return 1;
					}else{
						//Arriba izquierda, comer
						if(fila_elegido-1 >= 0 && columna_elegido-1 >= 0 && m[fila_elegido-1][columna_elegido-1].tipo_pieza.nombre != 'K'){
							respaldar_tablero(m,respaldo);
							mover_rey(fila_elegido,columna_elegido, fila_elegido-1, columna_elegido-1, m,&mov_permitido);
						}
						if(mov_permitido==1 && jaque(turno,m)==0){
							//Si me permite el movimiento ,y si el rey no quedo vulnerable
							respaldar_tablero(m,respaldo);
							return 1;
						}else{
							//Abajo derecha, comer
							if(fila_elegido+1 < 8 && columna_elegido+1 < 8 && m[fila_elegido+1][columna_elegido+1].tipo_pieza.nombre != 'K'){
								respaldar_tablero(m,respaldo);
								mover_rey(fila_elegido,columna_elegido, fila_elegido+1, columna_elegido+1, m,&mov_permitido);
							}
							if(mov_permitido==1 && jaque(turno,m)==0){
								//Si me permite el movimiento ,y si el rey no quedo vulnerable
								respaldar_tablero(m,respaldo);
								return 1;
							}else{
								//Abajo izquierda, comer
								if(fila_elegido+1 < 8 && columna_elegido-1 >= 0 && m[fila_elegido+1][columna_elegido-1].tipo_pieza.nombre != 'K'){
									respaldar_tablero(m,respaldo);
									mover_rey(fila_elegido,columna_elegido, fila_elegido+1, columna_elegido-1, m,&mov_permitido);
								}
								if(mov_permitido==1 && jaque(turno,m)==0){
									//Si me permite el movimiento ,y si el rey no quedo vulnerable
									respaldar_tablero(m,respaldo);
									return 1;
								}else{
									//No existe un movimiento de esta pieza, que evite el jaque de 
									respaldar_tablero(m,respaldo);
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
int jaque_elegir(int turno, int fila_elegido, int columna_elegido, p (*m)[8]){
	if(m[fila_elegido][columna_elegido].color=='w'){
		if(m[fila_elegido][columna_elegido].tipo_pieza.nombre=='P'){
			return all_mov_peon(turno,fila_elegido,columna_elegido,m);
		}else{
			if(m[fila_elegido][columna_elegido].tipo_pieza.nombre=='N'){
				return all_mov_caballo(turno,fila_elegido,columna_elegido,m);
			}else{
				if(m[fila_elegido][columna_elegido].tipo_pieza.nombre=='R'){
					return all_mov_torre(turno,fila_elegido,columna_elegido,m);
				}else{
					if(m[fila_elegido][columna_elegido].tipo_pieza.nombre=='B'){
						return all_mov_alfil(turno,fila_elegido,columna_elegido,m);
					}else{
						if(m[fila_elegido][columna_elegido].tipo_pieza.nombre=='Q'){
							return all_mov_reina(turno,fila_elegido,columna_elegido,m);
						}else{
							if(m[fila_elegido][columna_elegido].tipo_pieza.nombre=='K'){
								return all_mov_rey(turno,fila_elegido,columna_elegido,m);
							}
						}
					}
				}
			}
		}
	}else{
		if(m[fila_elegido][columna_elegido].tipo_pieza.nombre=='P'){
			return all_mov_peon(turno,fila_elegido,columna_elegido,m);
		}else{
			if(m[fila_elegido][columna_elegido].tipo_pieza.nombre=='N'){
				return all_mov_caballo(turno,fila_elegido,columna_elegido,m);
			}else{
				if(m[fila_elegido][columna_elegido].tipo_pieza.nombre=='R'){
					return all_mov_torre(turno,fila_elegido,columna_elegido,m);
				}else{
					if(m[fila_elegido][columna_elegido].tipo_pieza.nombre=='B'){
						return all_mov_alfil(turno,fila_elegido,columna_elegido,m);
					}else{
						if(m[fila_elegido][columna_elegido].tipo_pieza.nombre=='Q'){
							return all_mov_reina(turno,fila_elegido,columna_elegido,m);
						}else{
							if(m[fila_elegido][columna_elegido].tipo_pieza.nombre=='K'){
								return all_mov_rey(turno,fila_elegido,columna_elegido,m);
							}
						}
					}
				}
			}
		}
	}
}