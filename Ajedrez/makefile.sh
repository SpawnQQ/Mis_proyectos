echo -e "Compilando..."
gcc ajedrez.c -std=c99 -o ajedrez -I $(pwd ajedrez.c)
clear
echo "BIENVENIDOs $(whoami)!!!"
echo "Ubicacion del programa $(pwd ajedrez.c)"
echo "Nombre del sistema $(cat /etc/issue), procesador $(uname -m)"
./ajedrez
echo -e "Programa finalizado"