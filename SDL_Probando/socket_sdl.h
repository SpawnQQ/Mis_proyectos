#include <stdio.h>
#include <stdlib.h>

#define PORT 5000
#define BLOCK 1024
const char * ip_servidor;

const char * DATOS=".txt";

int puerto;

//############### Servidor ##################
struct sockaddr_in host_servidor, cliente;
socklen_t longc;
//Declaramos una variable que contendrá los mensajes que recibamos
char buffer[100];
int conexion_servidor;
int conexion_cliente;

//############## Cliente ###############
//Declaración de la estructura con información para la conexión
struct sockaddr_in cliente;
//Declaración de la estructura con información del host
struct hostent *conectando_servidor;
int  conexion;


int sockfd, bytenumero;
int sin_size, confd;
long bff, erecv;
char buf[1024];

int leido;
int ienv;
long siz;
struct hostent *he;

char bffc[5];
char bufer[1024];


void create_server(){
	int puerto;
	
	//Debemos declarar una variable que contendrá la longitud de la estructura

	//transforma un string a entero
	puerto = PORT;

	//creamos el socket
	conexion_servidor = socket(AF_INET, SOCK_STREAM, 0);

	//llenamos la estructura de 0's
	bzero((char *)&host_servidor, sizeof(host_servidor));

	//asignamos a la estructura
	host_servidor.sin_family = AF_INET;
	host_servidor.sin_port = htons(puerto);

	//esta macro especifica nuestra dirección
	host_servidor.sin_addr.s_addr = INADDR_ANY; 
	ip_servidor=inet_ntoa(host_servidor.sin_addr);

	//asignamos un puerto al socket
	if(bind(conexion_servidor, (struct sockaddr *)&host_servidor, sizeof(host_servidor)) < 0){ 
		printf("Error al asociar el puerto a la conexion\n");
		close(conexion_servidor);
	}

	//Estamos a la escucha
	listen(conexion_servidor, 3);
	printf("A la escucha en el puerto %d\n", ntohs(host_servidor.sin_port));
	
	//Asignamos el tamaño de la estructura a esta variable
	longc = sizeof(cliente); 

	//Esperamos una conexion
	conexion_cliente = accept(conexion_servidor, (struct sockaddr *)&cliente, &longc);
	
	if(conexion_cliente<0){
	printf("Error al aceptar trafico\n");
	close(conexion_servidor);
	}

	printf("Conectando con %s:%d\n", inet_ntoa(cliente.sin_addr),htons(cliente.sin_port));

}


void conect_server(){

	//Asignacion
	conectando_servidor = gethostbyname("127.0.0.1");

	//Comprobación
	if(conectando_servidor == NULL){
	printf("Host erróneo\n");
	}

	//Asignación del socket
	conexion = socket(AF_INET, SOCK_STREAM, 0);

	//conversion del argumento
	puerto=PORT;

	//Rellena toda la estructura de 0's
	//La función bzero() es como memset() pero inicializando a 0 todas la variables
	bzero((char *)&cliente, sizeof((char *)&cliente)); 

	//asignacion del protocolo
	cliente.sin_family = AF_INET; 

	//asignacion del puerto
	cliente.sin_port = htons(puerto);

	//bcopy(); copia los datos del primer elemendo en el segundo con el tamaño máximo 
	//del tercer argumento.
	bcopy((char *)conectando_servidor->h_addr, (char *)&cliente.sin_addr.s_addr, sizeof(conectando_servidor->h_length));

	//cliente.sin_addr = *((struct in_addr *)conectando_servidor->h_addr); //<--para empezar prefiero que se usen
	//inet_aton(argv[1],&cliente.sin_addr); //<--alguna de estas dos funciones
 	 	
	//conectando con el host
	if(connect(conexion,(struct sockaddr *)&cliente, sizeof(cliente)) < 0){ 
	printf("Error conectando con el host\n");
	close(conexion);
	}
}

void client_socket(){


	//inet_ntoa(); está definida en <arpa/inet.h>
	printf("Conectado con %s:%d\n",inet_ntoa(cliente.sin_addr),htons(cliente.sin_port));
	printf("Escribe un mensaje: ");
	
	scanf("\n%s", &buffer);
	//envio
	send(conexion, buffer, 100, 0);
	bzero(buffer, 100);

	//recepción
	recv(conexion, buffer, 100, 0);
	printf("%s\n", buffer);
}

void server_socket(){

	//Comenzamos a recibir datos del cliente
	if(recv(conexion_cliente, buffer, 100, 0) < 0){

	//Si recv() recibe 0 el cliente ha cerrado la conexion. Si es menor que 0 ha habido algún error.
	printf("Error al recibir los datos\n");
	close(conexion_servidor);
	}else{
	printf("%s\n", buffer);
	}

	bzero((char *)&buffer, sizeof(buffer));

	printf("Escribe un mensaje: ");
	scanf("\n%s", &buffer);
	send(conexion_cliente, buffer, 100, 0);


close(conexion_servidor);
}

void recv_client_server(){
	sin_size = sizeof(struct sockaddr_in);
 
	conexion_cliente = accept(conexion_cliente, (struct sockaddr *)&host_servidor, &sin_size);
	
	recv(conexion_cliente, &bff, sizeof(long), 0);
	
	send(conexion_cliente, "listo", 5, 0);
	
	printf("%d", bff);
	
	FILE *flito = fopen("salida.txt", "wb");
	
	erecv = 0;
	bytenumero = 0;
	
	while(erecv < bff){
	   
		bytenumero = recv(conexion_cliente, buf, sizeof(buf), 0);
	    fwrite(buf, 1, bytenumero, flito);
	   
	    erecv = erecv + bytenumero;
	    printf("%d", erecv);
	    
	}
	 
	 
	fclose(flito);
	close(conexion_cliente);
}

void send_client_server(){
	FILE *pfile, *flista;

	pfile = fopen("partida_guardada.txt", "rb");

	fseek(pfile, 0, SEEK_END);
	siz = ftell(pfile);
	rewind(pfile);
	
	printf("%ld", siz);
 
	send(conexion, &siz, sizeof siz, 0);
	
	recv(conexion, bffc, sizeof(bffc), 0);
	
	printf("\n%s\n", bffc);
	
	ienv = 0;
	leido = 0;

	
	while(!feof(pfile)){
	
	leido = fread(bufer, 1, sizeof(bufer), pfile);
	send(conexion, bufer, leido, 0);
	ienv = ienv + leido;
	
	printf("%d", ienv);
	
  }
  
  
  fclose(pfile);
  close(conexion);
}