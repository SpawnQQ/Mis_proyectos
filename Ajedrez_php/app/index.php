<?php
	include "class/pieza.php";
	include "class/pieza_blanca.php";
	include "class/pieza_negra.php";
	include "class/pieza_vacia.php";
	include "class/peon_blanco.php";
	include "class/peon_negro.php";
	include "metodos.php";

	$tablero = iniciar_tablero();
	mostrar_tablero($tablero);
	#iniciar_juego($tablero);

?>