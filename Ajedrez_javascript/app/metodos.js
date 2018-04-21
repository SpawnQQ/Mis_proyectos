var peon_blanco = require ('./class/peon_blanco.js');

function tablero () {
	this.board = [];
	for (i = 0; i < 8; i++ ) {
		this.board[i] = [];
		for ( j = 0; j < 8; j++ ) {
			this.board[i][j] = 0;
		}
	}
}

tablero.prototype.iniciar = function() {
	for (i = 0; i < 8; i++ ) {
		this.board[i] = [];
		for ( j = 0; j < 8; j++ ) {
			this.board[i][j] = new peon_blanco(Array(i,j)) ;
		}
	}
};

tablero.prototype.mostrar = function() {
	console.(this.board);
};

module.exports = tablero;