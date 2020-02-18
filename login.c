#include <stdio.h>
#include <stdlib.h>
#include "headers.h"


int linTam(char* s1)
{
	int i;
	for(i = 0; s1[i] != 0; i++);

	return i;
}


void concat(char s1[], char s2[])
{
	int i,j;

	i = linTam(s1);
	for(j = 0; s2[j] != 0; j++)
		s1[i+j] = s2[j];

	s1[i+j] = 0;
}

void automaticLogin(int x)
{

	char user[20];
	char password[50];
	int menulogin = 1;

	FILE* fileLogin;
	char login[200] = "wget -q --save-cookies cookies.txt --keep-session-cookies --post-data 'name=";

	//fopen("login.txt","r+");
	if(x)
	{
		printf("1- Usar login existente\n2- Novo login\n");
		scanf("%d", &menulogin);
	}

	if(menulogin == 1)
	{
		if((fileLogin = fopen("login.txt", "r")) == NULL)
		{
			printf("Login inexistente!\n");
			exit(1);
		}

		fscanf(fileLogin,"%s\n", user);
		fscanf(fileLogin,"%s\n", password);
		fclose(fileLogin);

	}
	else
	{
		system("rm login.txt 2>/dev/null");
		printf("Username:\n");
		scanf("%s", user);

		printf("Password:\n");
		scanf("%s", password);

		fileLogin = fopen("login.txt","w+");

		fprintf(fileLogin, "%s\n", user);
		fprintf(fileLogin, "%s\n", password);

		fclose(fileLogin);
	}

	concat(login, user);
	concat(login,"&password=");
	concat(login, password);
	concat(login, "' --delete-after https://ts1.lusobrasileiro.travian.com/login.php");
	system(login);
}
