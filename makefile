main: main.c headers.h quests.c login.c read.c play.c inAPlayers.c hero.c
	gcc -g -o main main.c headers.h quests.c login.c read.c play.c inAPlayers.c hero.c -lcurl
