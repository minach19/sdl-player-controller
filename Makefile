prog:tache.o main.o
	gcc tache.o main.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c
menu.o:menu.c
	gcc -c tache.c
