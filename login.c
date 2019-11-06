#include <stdio.h>
#include <stdlib.h>


char* concatenar(char s1[], char s2[]) 
{     
	int i,i2;

	for (i = 0; s1[i]!='\0'; i++);     
	for (i2 = 0; s2[i2]!='\0'; i2++);
	i = i + i2;

	char* string = malloc(i);
	
	for(i = 0; s1[i] != '\0'; i++)
		string[i] = s1[i];
	for(i2 = 0; s2[i2] != '\0'; i2++, i++)
		string[i] = s2[i2];
	
	string[i]='\0';     
	return string; 
}


void automaticLogin(char* name, char* password)
{

	char* login = "wget -q --save-cookies cookies.txt --keep-session-cookies --post-data 'name=";
	login = concatenar(login, name);
	login = concatenar(login,"&password=");
	login = concatenar(login, password);
	login = concatenar(login, "' --delete-after https://ts2.lusobrasileiro.travian.com/login.php");
	//printf("Olá %s\n", login);
	//https://ts2.lusobrasileiro.travian.com/login.php?name=kvothe\&password=amesmadesempre05

	/*
	wget --save-cookies cookies.txt --keep-session-cookies --post-data 'name=kvothe&password=amesmadesempre05' 
	--delete-after https://ts2.lusobrasileiro.travian.com/login.php
	*/

	system(login);
}

