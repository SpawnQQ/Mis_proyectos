echo -e "Compilando..."
gcc ajedrez.c -std=c99 -o ajedrez -I /home/dahaka/Mis_proyectos/Ajedrez
echo -e "Ejecutando..."
./ajedrez
echo -e "Programa finalizado"