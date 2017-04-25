gcc -g -Wall -lSDL $(pkg-config --cflags --libs sdl) -o programa archivo.c -I $(pwd archivo.c)
./programa