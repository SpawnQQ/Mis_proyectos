#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_net.h>

int main(){
	SDL_Init(SDL_INIT_VIDEO);
	SDLNet_Init();
	IPaddress ip;
	SDLNet_ResolveHost(&ip,"127.0.0.1",1234);
	const char * text_servidor="Hola servidor!\n";

	TCPsocket client=SDLNet_TCP_Open(&ip);

	char text[100];
	SDLNet_TCP_Recv(client,text,100);
	printf("%s",text);

	SDLNet_TCP_Send(&ip,text_servidor, strlen(text_servidor)+1);
	SDLNet_TCP_Close(client);
	SDLNet_Quit();
	return 0;
}