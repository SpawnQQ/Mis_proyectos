<?php
class peon_negro extends pieza_negra{

	var $nombre;
	var $posicion;
	var $color;
	var $primer_mov;
	var $puntaje;

	public function __construct($pos)
	{
		$this->nombre = "P";
		$this->color = "b";
		$this->primer_mov = true;
		$this->puntaje = 1;
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

	public function getPrimerMov()
	{
		return $this->primer_mov;
	}

	public function getPuntaje()
	{
		return $this->puntaje;
	}

	public function setPosicion($position)
	{	
		$this->posicion[0] = $position[0];
		$this->posicion[1] = $position[1];
	}


	public function setPrimerMov()
	{
		$this->primer_mov = false;
	}

	public function movimiento($posicion_destino)
	{
		if($this->primer_mov == true)
		{
			$this->primer_mov = false;
			if($posicion_destino[0] == $this->posicion[0] - 1 && $posicion_destino[1] == $this->posicion[1])
			{
				$this->setPosition($posicion_destino);
				return true;
			}else{
				return false;
			}
		}else{
			if($posicion_destino[0] == $this->posicion[0] - 1 && $posicion_destino[1] == $this->posicion[1])
			{
				$this->setPosition($posicion_destino);
				return true;
			}else{
				return false;
			}
		}
	}

	public function movimiento_especial()
	{

	}

	public function toString()
	{
		return $this->nombre." ".$this->color." [".$this->posicion[0].",".$this->posicion[1]."]\n".$this->primer_mov." ".$this->puntaje."\n";
	}
	
}
?>