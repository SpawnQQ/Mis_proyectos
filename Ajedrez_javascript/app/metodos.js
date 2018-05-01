var peon_blanco = require ('./class/peon_blanco.js');
var peon_negro = require ('./class/peon_negro.js');
var pieza_vacia = require ('./class/pieza_vacia.js');

/*
global.window.addEventListener('keydown', function(event) {
  switch (event.keyCode) {
    case 38: // Up
      Game.player.moveUp();
    break;
  }
}, false);
*/

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
			if( i == 1) {
				this.board[i][j] = new peon_negro(Array(i,j));
			}else{
				if( i == 6 ){
					this.board[i][j] = new peon_blanco(Array(i,j));
				}else{
					this.board[i][j] = new pieza_vacia(Array(i,j));
				}
			}
			
		}
	}
	//this.board[6][1] = new peon_negro(Array(6,1));
};

tablero.prototype.mostrar = function() {
	console.log("");
	for (i = 0; i < 8; i++ ) {
		console.log(this.board[i][0].name+this.board[i][0].color+" "+this.board[i][1].name+this.board[i][1].color+" "+this.board[i][2].name+this.board[i][2].color+" "+this.board[i][3].name+this.board[i][3].color+" "+this.board[i][4].name+this.board[i][4].color+" "+this.board[i][5].name+this.board[i][5].color+" "+this.board[i][6].name+this.board[i][6].color+" "+this.board[i][7].name+this.board[i][7].color);
	}
	console.log("");
};

tablero.prototype.verificarSeleccion = function(posicion_seleccion) {
	if (posicion_seleccion[0] > 0 && posicion_seleccion[1] < 9){
		return true;
	}else{
		return false;
	}
}

tablero.prototype.realizarMovimiento = function(posicion_seleccion, posicion_destino) {
	//delete this.board[posicion_destino[0]][posicion_destino[1]];
	if(this.verificarSeleccion(posicion_seleccion) && this.board[posicion_seleccion[0]][posicion_seleccion[1]].movimiento(this.board, posicion_seleccion, posicion_destino)){
		//console.log(this.board[posicion_seleccion[0]][posicion_seleccion[1]].movimiento(posicion_destino));
		
		console.log("Antes: \n"+this.board[posicion_seleccion[0]][posicion_seleccion[1]].name+this.board[posicion_seleccion[0]][posicion_seleccion[1]].color+", "+this.board[posicion_seleccion[0]][posicion_seleccion[1]].position+", "+this.board[posicion_seleccion[0]][posicion_seleccion[1]].firstMove+", "+this.board[posicion_seleccion[0]][posicion_seleccion[1]].score+"\n"+
		this.board[posicion_destino[0]][posicion_destino[1]].name+this.board[posicion_destino[0]][posicion_destino[1]].color+", "+this.board[posicion_destino[0]][posicion_destino[1]].position+", "+this.board[posicion_destino[0]][posicion_destino[1]].firstMove+", "+this.board[posicion_destino[0]][posicion_destino[1]].score);
	
		this.board[posicion_destino[0]][posicion_destino[1]] = this.board[posicion_seleccion[0]][posicion_seleccion[1]];
		this.board[posicion_seleccion[0]][posicion_seleccion[1]] = new pieza_vacia(posicion_seleccion);

		console.log("Despues: \n"+this.board[posicion_seleccion[0]][posicion_seleccion[1]].name+this.board[posicion_seleccion[0]][posicion_seleccion[1]].color+", "+this.board[posicion_seleccion[0]][posicion_seleccion[1]].position+", "+this.board[posicion_seleccion[0]][posicion_seleccion[1]].firstMove+", "+this.board[posicion_seleccion[0]][posicion_seleccion[1]].score+"\n"+
		this.board[posicion_destino[0]][posicion_destino[1]].name+this.board[posicion_destino[0]][posicion_destino[1]].color+", "+this.board[posicion_destino[0]][posicion_destino[1]].position+", "+this.board[posicion_destino[0]][posicion_destino[1]].firstMove+", "+this.board[posicion_destino[0]][posicion_destino[1]].score);

	}else{
		console.log("Movimiento no permitido");
	}
};


tablero.prototype.iniciarJuego = function(juegoActivo){
	while (juegoActivo){
		this.mostrar();

	}
};

module.exports = tablero;