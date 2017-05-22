#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_net.h>

int main(){
int salir=0;
SDL_Init(SDL_INIT_VIDEO);
SDLNet_Init();
IPaddress ip;
SDLNet_ResolveHost(&ip,NULL,1234);

const char * text="Hola cliente!\n";

TCPsocket server=SDLNet_TCP_Open(&ip);
TCPsocket client;
char text_client[100];
while(salir==0){
	client=SDLNet_TCP_Accept(server);
	if(client){
		//El cliente pudo comunicarse
		SDLNet_TCP_Send(client,text, strlen(text)+1);
		SDLNet_TCP_Close(client);
		salir=1;
	}	
}
SDLNet_TCP_Recv(server,text_client,100);
printf("%s",text_client);
SDLNet_TCP_Close(server);
SDLNet_Quit();
return 0;
}