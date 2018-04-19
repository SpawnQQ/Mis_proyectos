<?php
	function iniciar_tablero()
	{

		for ($i = 0; $i < 8; $i++) 
		{
			for ($j = 0; $j < 8; $j++) 
			{
				if ($i == 1) 
				{
					$tablero[$i][$j] = new peon_negro(array($i, $j));
				}
				else
				{
					if ($i == 6) 
					{
						$tablero[$i][$j] = new peon_blanco(array($i, $j));
					}
					else
					{
						$tablero[$i][$j] = new pieza_vacia(array($i, $j));
					}	
				}
			}
		}

		return $tablero;
	}

	function mostrar_tablero($tablero)
	{
		foreach ($tablero as $i => $fila) 
		{
			foreach ($fila as $j => $columna) 
			{
				print $tablero[$i][$j]->getNombre().$tablero[$i][$j]->getColor()." ";
			}
			print "\n";
		}
	}

	function iniciar_juego(&$tablero)
	{
		$termino_juego = false;
		while($termino_juego != true)
		{
			
		}
	}
?>