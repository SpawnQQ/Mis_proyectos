echo -e "Primero actualizamos el sistema"
sudo aptitude update && aptitude upgrade
echo -e "Se instala mpg123 para reproducir sonido"
sudo aptitude install mpg123
echo -e "apt-cache search ^libsdl | grep 1.2 comando para ver los archivos disponibles de libsdl1.2"
echo -e "Se instalara paquetes para graficos SDL"
sudo apt-get install libsdl1.2-dev
sudo apt-get install libsdl-image1.2-dev 
sudo apt-get install libsdl-mixer1.2-dev
sudo apt-get install libsdl-ttf2.0-0 
sudo apt-get install libsdl-ttf2.0-dev
sudo aptitude install libsdl-gfx1.2-dev libsdl-gfx1.2-5