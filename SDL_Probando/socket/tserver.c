#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
 
 
int main(){
 
int sockfd, bytenumero;
struct sockaddr_in re;
int sin_size, confd;
long bff, erecv;
char buf[1024];
 
sockfd = socket(AF_INET, SOCK_STREAM, 0);
 
re.sin_family = AF_INET;
re.sin_port = htons(33371);
re.sin_addr.s_addr = INADDR_ANY;
memset(re.sin_zero, 0, 8);
 
bind(sockfd, (struct sockaddr*)&re, sizeof(struct sockaddr));
 
sin_size = sizeof(struct sockaddr_in);
 
listen(sockfd, 10);
 
sockfd = accept(sockfd, (struct sockaddr *)&re, &sin_size);
 
recv(sockfd, &bff, sizeof(long), 0);
 
send(sockfd, "listo", 5, 0);
 
printf("%d", bff);
 
FILE *flito = fopen("salida.txt", "wb");
 
erecv = 0;
bytenumero = 0;
 
while(erecv < bff){
    
    bytenumero = recv(sockfd, buf, sizeof(buf), 0);
    fwrite(buf, 1, bytenumero, flito);
    
    erecv = erecv + bytenumero;
    printf("%d", erecv);
    
}
 
 
fclose(flito);
close(sockfd);
 
return 0;
 
}