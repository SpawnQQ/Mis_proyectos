echo -e "Primero actualizamos el sistema"
sudo aptitude update && aptitude upgrade
echo -e "Se instala mpg123 para reproducir sonido"
sudo aptitude install mpg123
echo -e "Se instala la libreria curses.h, para getch()"
sudo apt-get install libncurses5-dev libncursesw5-dev