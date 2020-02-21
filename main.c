#include "headers.h"

int main()
{
	int menu = 0;
	int stuff[10];
	int idCampos[17];
	char* s;
	char sfd[10];
	automaticLogin(1);

	while(menu != 8)
	{
		if(menu == 1)
			lerDorf1(stuff, idCampos, 1);
		if(menu == 2)
			nivelar(stuff, idCampos, 0);
		if(menu == 3)
			EvolId(stuff, idCampos, 0, 0, 0);
		if(menu == 4)
			atakList(2);
		if(menu == 5)
			treinarTropas();
		if(menu == 6)
		{
			//teste();
		}
		if(menu == 7)
			inactivePlayers();

		printf("\n\n ----------------------- ");

		printf("\n1 - Ler Dados Dorf1");
		printf("\n2 - Subir Campos até um certo nivel");
		printf("\n3 - Subir até nivel");
		printf("\n4 - Ataque");
		printf("\n5 - Treinar Tropas");
		printf("\n8 - Logout ");
		printf("\nEscolha uma opcao: ");
		scanf("%d",&menu);
	}

	return 0;
}
