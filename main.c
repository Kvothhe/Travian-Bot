#include "headers.h"

void main()
{
	int menu = 0;
	char user[20];
	char password[50];

	printf("Username:\n");
	scanf("%s", user);
	printf("Password:\n");
	scanf("%s", password);

	automaticLogin(user,password);

	while(menu != 5)
	{
		if(menu == 1)
			lerDorf1();

		printf("\n\n ----------------------- ");

		printf("\n 1 - Ler Dados Dorf1");
		printf("\n 2 - Opcao 2 ");
		printf("\n 3 - Opcao 3 ");
		printf("\n 4 - Opcao 4 ");
		printf("\n 5 - Logout ");
		printf("\n\n Escolha uma opcao: ");
		scanf("%d",&menu);
	}
}