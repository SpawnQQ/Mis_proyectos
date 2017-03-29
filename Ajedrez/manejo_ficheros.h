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