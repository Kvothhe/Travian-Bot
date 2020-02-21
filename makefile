main: main.c login.c read.c headers.h play.c inAPlayers.c
	gcc -g -o main main.c headers.h login.c read.c play.c inAPlayers.c
