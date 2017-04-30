
void server_socket(){
	IPaddress ip;
	SDLNet_ResolveHost(&ip,NULL,1234);

	const char * text="Hola cliente!\n";

	TCPsocket server=SDLNet_TCP_Open(&ip);
	TCPsocket client;

	while(1){
		client=SDLNet_TCP_Accept(server);
		if(client){
			//El cliente pudo comunicarse
			SDLNet_TCP_Send(client,text, strlen(text)+1);
			SDLNet_TCP_Close(client);

		}	
	}
	SDLNet_TCP_Close(server);
	SDLNet_Quit();
}

void client_socket(){
	IPaddress ip;
	SDLNet_ResolveHost(&ip,127.0.0.1,1234);

	const char * text="Hola cliente!\n";

	TCPsocket client=SDLNet_TCP_Open(&ip);;

	char text[100];
	SDLNet_TCP_Recv(client,text,100);
	printf("%s",text);

	SDLNet_TCP_Close(client);
	SDLNet_Quit();
}