echo -e "Primero actualizamos el sistema"
sudo aptitude update && aptitude upgrade
echo -e "Se instala mpg123 para reproducir sonido"
sudo aptitude install mpg123
echo -e "Se instalara paquetes para graficos"
sudo hg clone https://hg.libsdl.org/SDL SDL
cd SDL
sudo mkdir build
cd build
sudo ../configure
make
sudo make install