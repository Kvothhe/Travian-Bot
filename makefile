main: main.c read.c login.c headers.h
	gcc -o main main.c headers.h read.c login.c