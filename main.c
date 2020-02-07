#include "headers.h"

void main()
{
	int menu = 0;
	int stuff[10];
	int idCampos[17];

	automaticLogin();

	while(menu != 5)
	{
		if(menu == 1)
			lerDorf1(stuff, idCampos, 1);
		if(menu == 2)
			nivelar(stuff, idCampos);

		printf("\n\n ----------------------- ");

		printf("\n 1 - Ler Dados Dorf1");
		printf("\n 2 - Subir Campos até um certo nivel");
		printf("\n 3 - Opcao 3 ");
		printf("\n 4 - Opcao 4 ");
		printf("\n 5 - Logout ");
		printf("\n\n Escolha uma opcao: ");
		scanf("%d",&menu);
	}
}
