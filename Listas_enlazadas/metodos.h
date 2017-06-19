_nodo* primero=NULL;
_nodo* ultimo=NULL;

_nodo* crear_nodo(_info info){
	_nodo* nodo = (_nodo*) malloc(sizeof(_nodo));
	strncpy(nodo->info.descripcion,info.descripcion,50);
	nodo->info.numero=info.numero;
	nodo->siguiente=NULL;
	return nodo;
}

void destruir_nodo(_nodo* nodo){
	free(nodo);
}

void agregar_lista(_info info){
	_nodo* nodo=crear_nodo(info);
	if(primero==NULL){
		primero=nodo;
		ultimo=nodo;
	}else{
		ultimo->siguiente=nodo;
		ultimo=nodo;
	}
}

void mostrar(){
	_nodo* recorre;
	recorre=primero;
	while(recorre!=NULL){
		printf("%s: ",recorre->info.descripcion);
		printf("%i\n",recorre->info.numero);
		recorre=recorre->siguiente;
	}
}