#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct tipo{
	char nombre;
	int posicion[2];
};

struct pieza{
	char color;
	struct tipo tipo_pieza;
	int primer_turno;
	struct pieza *enlace;
};