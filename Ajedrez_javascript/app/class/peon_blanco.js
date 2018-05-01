var pieza_blanca = require ('./pieza_blanca.js');

function peon_blanco(posicion) {
	this.name = "P";
	this.position = posicion.slice();
	this.color = "w";
	this.firstMove = true;
	this.score = 1;
}

Object.defineProperty(peon_blanco.prototype, 'name', {
	get: function() {
		return this.name;
	}
});

Object.defineProperty(peon_blanco.prototype, 'position', {
	get: function() {
		return this.position;
	},
	set: function(posicion){
		this.position = posicion.slice();
	}
});

Object.defineProperty(peon_blanco.prototype, 'color', {
	get: function() {
		return this.color;
	}
});

Object.defineProperty(peon_blanco.prototype, 'firstMove', {
	get: function() {
		return this.firstMove;
	},
	set: function(primerMov){
		this.firstMove = primerMov;
	}
});

Object.defineProperty(peon_blanco.prototype, 'score', {
	get: function() {
		return this.score;
	}
});

peon_blanco.prototype = new pieza_blanca();

peon_blanco.prototype.movimiento = function(board,posicion_seleccion, posicion_destino) {
	if(board[posicion_seleccion[0]][posicion_seleccion[1]].firstMove == true){
		board[posicion_seleccion[0]][posicion_seleccion[1]].firstMove = false;
		if(posicion_destino[0] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[0] - 1 && posicion_destino[1] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[1] && board[posicion_destino[0]][posicion_destino[1]].name == "-"){
			board[posicion_seleccion[0]][posicion_seleccion[1]].position = posicion_destino;
			return true;
		}else{
			//Peon al paso, se debe hacer una verificacion.
			if(posicion_destino[0] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[0] - 2 && posicion_destino[1] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[1] && board[posicion_destino[0]][posicion_destino[1]].name == "-" && board[posicion_destino[0]+1][posicion_destino[1]].name == "-") {
				board[posicion_seleccion[0]][posicion_seleccion[1]].position = posicion_destino;
				return true;
			}else{
				if(posicion_destino[0] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[0] - 1 && posicion_destino[1] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[1] + 1 && board[posicion_destino[0]][posicion_destino[1]].name != "-" && board[posicion_destino[0]][posicion_destino[1]].color != "w"){
					board[posicion_seleccion[0]][posicion_seleccion[1]].position = posicion_destino;
					return true;
				}else{
					if(posicion_destino[0] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[0] - 1 && posicion_destino[1] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[1] - 1 && board[posicion_destino[0]][posicion_destino[1]].name != "-" && board[posicion_destino[0]][posicion_destino[1]].color != "w"){
						board[posicion_seleccion[0]][posicion_seleccion[1]].position = posicion_destino;
						return true;
					}else{
						return false;
					}
				}			
			}
		}
	}else{
		if(posicion_destino[0] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[0] - 1 && posicion_destino[1] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[1] && board[posicion_destino[0]][posicion_destino[1]].name == "-"){
			board[posicion_seleccion[0]][posicion_seleccion[1]].position = posicion_destino;
			return true;
		}else{
			if(posicion_destino[0] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[0] - 1 && posicion_destino[1] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[1] + 1 && board[posicion_destino[0]][posicion_destino[1]].name != "-" && board[posicion_destino[0]][posicion_destino[1]].color != "w"){
				board[posicion_seleccion[0]][posicion_seleccion[1]].position = posicion_destino;
				return true;
			}else{
				if(posicion_destino[0] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[0] - 1 && posicion_destino[1] == board[posicion_seleccion[0]][posicion_seleccion[1]].position[1] - 1 && board[posicion_destino[0]][posicion_destino[1]].name != "-" && board[posicion_destino[0]][posicion_destino[1]].color != "w"){
					board[posicion_seleccion[0]][posicion_seleccion[1]].position = posicion_destino;
					return true;
				}else{
					return false;
				}
			}
		}
	}
}

module.exports = peon_blanco;