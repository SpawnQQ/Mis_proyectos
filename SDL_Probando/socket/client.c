#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char **argv){

  if(argc<2){
    printf("<host> <puerto>\n");
    return 1;
  }

  //Declaración de la estructura con información para la conexión
  struct sockaddr_in cliente;

  //Declaración de la estructura con información del host
  struct hostent *servidor;

  //Asignacion
  servidor = gethostbyname(argv[1]);

  //Comprobación
  if(servidor == NULL){
    printf("Host erróneo\n");
    return 1;
  }

  int puerto, conexion;
  char buffer[100];

  //Asignación del socket
  conexion = socket(AF_INET, SOCK_STREAM, 0);

  //conversion del argumento
  puerto=(atoi(argv[2]));

  //Rellena toda la estructura de 0's
  //La función bzero() es como memset() pero inicializando a 0 todas la variables
  bzero((char *)&cliente, sizeof((char *)&cliente)); 

  //asignacion del protocolo
  cliente.sin_family = AF_INET; 

   //asignacion del puerto
  cliente.sin_port = htons(puerto);

  //bcopy(); copia los datos del primer elemendo en el segundo con el tamaño máximo 
  //del tercer argumento.
  bcopy((char *)servidor->h_addr, (char *)&cliente.sin_addr.s_addr, sizeof(servidor->h_length));

  //cliente.sin_addr = *((struct in_addr *)servidor->h_addr); //<--para empezar prefiero que se usen
  //inet_aton(argv[1],&cliente.sin_addr); //<--alguna de estas dos funciones

  //conectando con el host
  if(connect(conexion,(struct sockaddr *)&cliente, sizeof(cliente)) < 0){ 
    printf("Error conectando con el host\n");
    close(conexion);
    return 1;
  }

  //inet_ntoa(); está definida en <arpa/inet.h>
  printf("Conectado con %s:%d\n",inet_ntoa(cliente.sin_addr),htons(cliente.sin_port));
  printf("Escribe un mensaje: ");
  fgets(buffer, 100, stdin);

  //envio
  send(conexion, buffer, 100, 0);
  bzero(buffer, 100);

  //recepción
  recv(conexion, buffer, 100, 0);
  printf("%s", buffer);
return 0;
}