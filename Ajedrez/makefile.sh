echo -e "Compilando..."
gcc ajedrez.c -std=c99 -o ajedrez -I $(pwd ajedrez.c)
clear
echo -e "BIENVENIDO $(whoami)!!!"
echo -e "Ubicacion del programa $(pwd ajedrez.c)"
echo -e "En un sistema $(cat /etc/issue), $(uname -m)"
./ajedrez
echo -e "Programa finalizado"