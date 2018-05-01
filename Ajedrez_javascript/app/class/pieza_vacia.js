var pieza = require ('./pieza.js');

function pieza_vacia (posicion) {
	this.name = "-";
	this.position = posicion.slice();
	this.color = "-";
	this.firstMove = null;
	this.score = 0;
}

pieza_vacia.prototype = new pieza();

module.exports = pieza_vacia;