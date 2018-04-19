<?php
class pieza_vacia extends pieza{
	var $nombre;
	var $posicion;
	var $color;

	public function __construct($pos)
	{
		$this->nombre = "-";
		$this->color = "-";
		$this->posicion[0] = $pos[0];
		$this->posicion[1] = $pos[1];
	}

	public function getNombre()
	{
		return $this->nombre;
	}

	public function getPosicion()
	{
		return $this->posicion;
	}

	public function getColor()
	{
		return $this->color;
	}

	public function movimiento($posicion_destino)
	{
		
	}

	public function movimiento_especial()
	{

	}

}
?>