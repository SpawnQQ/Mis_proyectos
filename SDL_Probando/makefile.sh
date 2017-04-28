gcc -g -Wall -lSDL -lSDL_image -lSDL_ttf -lSDL_gfx $(pkg-config --cflags --libs sdl) -o programa archivo.c -I $(pwd archivo.c)
./programa