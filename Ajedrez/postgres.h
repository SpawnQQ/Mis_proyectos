void conexion_postgres(){

	PGconn *conn;
	PGresult *res;

	int i,j;

	conn = PQconnectdb("user=postgres dbname=db_desarrollo");

	if (PQstatus(conn) != CONNECTION_BAD){
		//Estadisticas
		//Users
		res = PQexec(conn, "select * from users");
		if (res != NULL && PGRES_TUPLES_OK == PQresultStatus(res)){
			for (i = PQntuples(res)-1; i >= 0; i--){
				for (j = PQnfields(res)-1; j >= 0; j--)
					printf("%s\t",PQgetvalue(res,i,j));
					printf("\n");
			}
		PQclear(res);
		}else{
			printf("Error, no existe la tabla...\n");
		}
	}else{
		printf("Error conexion base de datos...\n");
	}

	PQfinish(conn);
}

void logear(){
	//ATENCION, nose si seran mas caracteres o menos
	char nusuario[50];
	printf("Ingrese nombre de usuario");
	scanf("\n%s", &nusuario);

	PGconn *conn;
	PGresult *res;

	int i,j;

	conn = PQconnectdb("user=postgres dbname=db_desarrollo");

	if (PQstatus(conn) != CONNECTION_BAD){
		//Estadisticas
		//Users
		res = PQexec(conn, "select * from users");
		if (res != NULL && PGRES_TUPLES_OK == PQresultStatus(res)){
			for (i = PQntuples(res)-1; i >= 0; i--){
					printf("%s\n",PQgetvalue(res,i,PQnfields(res)-1));
					printf("%s\n",PQgetvalue(res,i,2));

					if(nusuario==PQgetvalue(res,i,2)){
						printf("ESTAMOS LOCOOOOOOOOOOOOS!!!!");
					}
			}
		PQclear(res);
		}else{
			printf("Error, no existe la tabla...\n");
		}
	}else{
		printf("Error conexion base de datos...\n");
	}

	PQfinish(conn);
}