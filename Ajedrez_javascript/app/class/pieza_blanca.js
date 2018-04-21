var pieza = require ('./pieza.js');

function pieza_blanca () {
	
}

pieza_blanca.prototype = new pieza();

module.exports = pieza_blanca;