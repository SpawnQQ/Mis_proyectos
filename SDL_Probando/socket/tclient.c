#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
 
 
int main(){
 
 
int leido;
int sockfd, ienv;
long siz;
struct hostent *he;
struct sockaddr_in t_add;
FILE *pfile, *flista;
char bff[5];
char bufer[1024];
 
he = gethostbyname("127.0.0.1");
 
sockfd = socket(AF_INET, SOCK_STREAM, 0);
 
t_add.sin_family = AF_INET;
t_add.sin_port = htons(33371);
t_add.sin_addr = *((struct in_addr*)he->h_addr);
memset(t_add.sin_zero,0, 8);
 
 
  connect(sockfd, (struct sockaddr*)&t_add, sizeof(struct sockaddr));
  
  pfile = fopen("partida_guardada.txt", "rb");
  fseek(pfile, 0, SEEK_END);
  siz = ftell(pfile);
  rewind(pfile);
  
  //zout = htonl(siz);
  
  printf("%ld", siz);
 
  send(sockfd, &siz, sizeof siz, 0);
  
  recv(sockfd, bff, sizeof(bff), 0);
  
  printf("\n%s\n", bff);
  
  ienv = 0;
  leido = 0;

  
  while(!feof(pfile)){
    
    leido = fread(bufer, 1, sizeof(bufer), pfile);
    send(sockfd, bufer, leido, 0);
    ienv = ienv + leido;
    
    printf("%d", ienv);
    
  }
  
  
  fclose(pfile);
  close(sockfd);
  
  return 0;
 
}
