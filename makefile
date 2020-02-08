main: main.c read.c login.c headers.h play.c
	gcc -g -o main main.c headers.h read.c login.c play.c
