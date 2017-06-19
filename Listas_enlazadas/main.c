#include <stdlib.h>
#include <stdio.h>
#include "estructuras.h"
#include "metodos.h"

int main(){
	_lista* lista;
	_info info;
	strncpy(info.descripcion,"Hola mundo, como esta",50);
	info.numero=100;
	agregar_lista(info);

	strncpy(info.descripcion,"Hola mundo, nose",50);
	info.numero=150;
	agregar_lista(info);

	mostrar();
}