gcc -g -Wall -lSDL -lSDL_image $(pkg-config --cflags --libs sdl) -o programa archivo.c -I $(pwd archivo.c)
./programa