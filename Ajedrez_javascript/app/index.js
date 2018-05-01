var peon_blanco = require ('./class/peon_blanco.js');
var peon_blanco = require ('./class/peon_negro.js');
var peon_blanco = require ('./class/pieza_vacia.js');

var tablero = require('./metodos.js');

tablero1 = new tablero();

tablero1.iniciar();
/*
tablero1.realizarMovimiento(new Array(1,2), new Array(3,2));
tablero1.realizarMovimiento(new Array(3,2), new Array(4,2));
tablero1.realizarMovimiento(new Array(4,2), new Array(5,2));
tablero1.realizarMovimiento(new Array(5,2), new Array(6,2));
tablero1.realizarMovimiento(new Array(5,2), new Array(6,1));
*/
var juegoActivo = true;

tablero1.iniciarJuego(juegoActivo);