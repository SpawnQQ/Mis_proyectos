var pieza_negra = require ('./pieza_negra.js');

function peon_negro(posicion) {
	this.name = "P";
	this.position = posicion.slice();
	this.color = "b";
	this.firstMove = true;
	this.score = 1;
}

Object.defineProperty(peon_negro.prototype, 'name', {
	get: function() {
		return this.name;
	}
});

Object.defineProperty(peon_negro.prototype, 'position', {
	get: function() {
		return this.position;
	},
	set: function(posicion){
		this.position = posicion.slice();
	}
});

Object.defineProperty(peon_negro.prototype, 'color', {
	get: function() {
		return this.color;
	}
});

Object.defineProperty(peon_negro.prototype, 'firstMove', {
	get: function() {
		return this.firstMove;
	},
	set: function(primerMov){
		this.firstMove = primerMov;
	}
});

Object.defineProperty(peon_negro.prototype, 'score', {
	get: function() {
		return this.score;
	}
});

peon_negro.prototype = new pieza_negra();

peon_negro.prototype.movimiento = function(board, posicion_seleccion ,posicion_destino) {
	if(board[posicion_seleccion[0]][posicion_seleccion[1]].firstMove == true){
		board[posicion_seleccion[0]][posicion_seleccion[1]].firstMove = false;
		if(posicion_destino[0] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[0] + 1 && posicion_destino[1] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[1] && board[posicion_destino[0]][posicion_destino[1]].name == "-"){
			board[posicion_seleccion[0]][posicion_seleccion[1]].position = posicion_destino;
			return true;
		}else{
			//Peon al paso, se debe hacer una verificacion.
			if(posicion_destino[0] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[0] + 2 && posicion_destino[1] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[1] && board[posicion_destino[0]][posicion_destino[1]].name == "-" && board[posicion_destino[0]-1][posicion_destino[1]].name == "-") {
				board[posicion_seleccion[0]][posicion_seleccion[1]].position = posicion_destino;
				return true;
			}else{
				if(posicion_destino[0] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[0] + 1 && posicion_destino[1] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[1] + 1 && board[posicion_destino[0]][posicion_destino[1]].name != "-" && board[posicion_destino[0]][posicion_destino[1]].color != "b"){
					board[posicion_seleccion[0]][posicion_seleccion[1]].position = posicion_destino;
					return true;
				}else{
					if(posicion_destino[0] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[0] + 1 && posicion_destino[1] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[1] - 1 && board[posicion_destino[0]][posicion_destino[1]].name != "-" && board[posicion_destino[0]][posicion_destino[1]].color != "b"){
						board[posicion_seleccion[0]][posicion_seleccion[1]].position = posicion_destino;
						return true;
					}else{
						return false;
					}
				}			
			}
		}
	}else{
		if(posicion_destino[0] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[0] + 1 && posicion_destino[1] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[1] && board[posicion_destino[0]][posicion_destino[1]].name == "-"){
			board[posicion_seleccion[0]][posicion_seleccion[1]].position = posicion_destino;
			return true;
		}else{
			if(posicion_destino[0] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[0] + 1 && posicion_destino[1] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[1] + 1 && board[posicion_destino[0]][posicion_destino[1]].name != "-" && board[posicion_destino[0]][posicion_destino[1]].color != "b"){
				board[posicion_seleccion[0]][posicion_seleccion[1]].position = posicion_destino;
				return true;
			}else{
				if(posicion_destino[0] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[0] + 1 && posicion_destino[1] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[1] - 1 && board[posicion_destino[0]][posicion_destino[1]].name != "-" && board[posicion_destino[0]][posicion_destino[1]].color != "b"){
					board[posicion_seleccion[0]][posicion_seleccion[1]].position = posicion_destino;
					return true;
				}else{
					return false;
				}
			}	
		}
	}
}

module.exports = peon_negro;