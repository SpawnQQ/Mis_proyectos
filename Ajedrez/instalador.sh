echo -e "Primero actualizamos el sistema"
sudo aptitude update && aptitude upgrade
echo -e "Se instala mpg123 para reproducir sonido"
sudo aptitude install mpg123
echo -e "Se instalara paquetes para graficos SDL2"
sudo aptitude install libsdl2-2.0-0
sudo apt-get install libsdl2-dev