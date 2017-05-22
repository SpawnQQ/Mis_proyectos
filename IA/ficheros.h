void lee_fichero(int sensor[], int interno[], int limite[], int normas[], int alarma[]){
	FILE *fp;
	int tam=tamano_fichero();
	char nombre[100];
	fp = fopen ( "datos_ia.txt", "r" );
	if( fp ){
      printf( "Cargando...\n" );
	}else{
   		printf( "Error, no existe ninguna partida guardada\n" );
   	}
   	fscanf( fp, "%s\n",nombre);
   	for(int i=0;i<tam;i++){
		fscanf( fp, "%i %i %i %i %i\n",&sensor[i],&interno[i],&limite[i],&normas[i], &alarma[i]);
	}
	fclose ( fp );
}

int tamano_fichero(){
	FILE *fp;
	int res;
	
	fp = fopen("datos_ia.txt", "r");
	rewind(fp);	
	fscanf(fp,"%d *\n", &res);    
    fclose(fp);
   
    return res;
}