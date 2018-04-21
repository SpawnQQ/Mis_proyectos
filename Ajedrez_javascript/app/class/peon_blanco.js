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

peon_blanco.prototype.movimiento = function() {
	console.log("Peon blanco");
}

module.exports = peon_blanco;