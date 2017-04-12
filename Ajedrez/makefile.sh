echo -e "Compilando..."
gcc ajedrez.c -std=c99 -o ajedrez -I $(pwd ajedrez.c)
echo -e "Ejecutando desde $(pwd ajedrez.c)"
./ajedrez
echo -e "Programa finalizado"