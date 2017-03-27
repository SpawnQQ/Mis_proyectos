void creacion_historial(){
   FILE *fp;
   fp = fopen ( "historial.txt", "w+" );
   fprintf(fp, "Historial de movimientos");
   fclose ( fp );
}

void movimientos_historial(char inicio_mov[2],char final_mov[2],char pieza_mov[2],char pieza_remov[2], p (*m)[8]){

}