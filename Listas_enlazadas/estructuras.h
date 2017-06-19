typedef struct _info{
	char descripcion[50];
	int numero;
}_info;

typedef struct _nodo{
	struct _info info;
	struct _nodo* siguiente;
}_nodo;

typedef struct _lista{
	_nodo* primero;
	_nodo* ultimo;
}_lista;