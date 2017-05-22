void creacion_historial(){
	FILE *fp;
	fp = fopen ( "historial.txt", "w+" );
	fprintf(fp, "Historial de movimientos");
	fclose ( fp );
}

void movimientos_historial(int turno,char inicio_mov[2],char final_mov[2],char pieza_mov[2],char pieza_remov[2]){
	FILE *fp;
	fp = fopen ( "historial.txt", "a" );
	if(pieza_remov[0]=='V' && pieza_remov[1]=='w'){
		fprintf(fp, "\n%d select(%c%c) %c%c goto %c%c remove(Pw)",turno,pieza_mov[0],pieza_mov[1],inicio_mov[0],inicio_mov[1],final_mov[0],final_mov[1]);
	}else{
		if(pieza_remov[0]=='V' && pieza_remov[1]=='b'){
			fprintf(fp, "\n%d select(%c%c) %c%c goto %c%c remove(Pb)",turno,pieza_mov[0],pieza_mov[1],inicio_mov[0],inicio_mov[1],final_mov[0],final_mov[1]);	
		}else{
			if(pieza_remov[0]=='V'){
				fprintf(fp, "\n%d select(%c%c) %c%c goto %c%c",turno,pieza_mov[0],pieza_mov[1],inicio_mov[0],inicio_mov[1],final_mov[0],final_mov[1]);
			}else{
				fprintf(fp, "\n%d select(%c%c) %c%c goto %c%c remove(%c%c)",turno,pieza_mov[0],pieza_mov[1],inicio_mov[0],inicio_mov[1],final_mov[0],final_mov[1],pieza_remov[0],pieza_remov[1]);
			}
		}
	}
	fclose ( fp );
}

void historial_algebraico(int turno, char color,char nombre,  char final_mov[2]){
	FILE *fp;
	fp = fopen ( "historial.txt", "a" );
	
	fclose ( fp );	
}

void guardar_partida(p (*m)[8], int turno){
	FILE *fp;
	fp = fopen ( "partida_guardada.txt", "w+" );
	fprintf(fp,"%d\n",turno);
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(i==0 && j==0){
				fprintf(fp, "%c%c %d%d %d",m[i][j].tipo_pieza.nombre,m[i][j].color,i, j,m[i][j].primer_turno);
			}else{
				fprintf(fp, "\n%c%c %d%d %d",m[i][j].tipo_pieza.nombre,m[i][j].color,i, j,m[i][j].primer_turno);
			}
		}
	}
	fclose ( fp );
}

void cargar_partida(p (*m)[8], int turno[]){
	FILE *fp;
	char posicion_uno,posicion_dos,turno_pieza;
	fp = fopen ( "partida_guardada.txt", "r" );
	if( fp ){
      printf( "Cargando...\n" );
	}else{
   		printf( "Error, no existe ninguna partida guardada\n" );
   	}
   	fscanf( fp,"%d\n",&turno[0]);
   	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			fscanf( fp, "%c%c %c%c %c\n",&m[i][j].tipo_pieza.nombre,&m[i][j].color, &posicion_uno, &posicion_dos, &turno_pieza);
			m[i][j].tipo_pieza.posicion[0]=(int) posicion_uno;
			m[i][j].tipo_pieza.posicion[1]=(int) posicion_dos;
			m[i][j].primer_turno=(int) turno_pieza;
			m[i][j].primer_turno=m[i][j].primer_turno-48;
		}
	}
	fclose ( fp );
}