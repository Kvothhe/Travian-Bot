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

void automaticLogin()
{

	char user[20];
	char password[50];
	int menu = 0;

	FILE* fileLogin;
	char* login = "wget -q --save-cookies cookies.txt --keep-session-cookies --post-data 'name=";
	//fopen("login.txt","r+");
	printf("1- Usar login existente\n2- Novo login\n");
	scanf("%d", &menu);

	if(menu == 1)
	{
		if((fileLogin = fopen("login.txt", "r")) == NULL)
		{
			printf("Login inexistente!\n");
			exit(1);
		}

		fscanf(fileLogin,"%s\n", user);
		fscanf(fileLogin,"%s\n", password);

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

	login = concatenar(login, user	);
	login = concatenar(login,"&password=");
	login = concatenar(login, password);
	login = concatenar(login, "' --delete-after https://ts1.lusobrasileiro.travian.com/login.php");
	system(login);
}
