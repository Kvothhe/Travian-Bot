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
			lerDorf1(stuff, idCampos);
		if(menu == 2)
			lerDorf1(stuff, idCampos),
			evoluiCampo(5, stuff);

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
