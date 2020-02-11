#include "headers.h"

void debugg()
{
	char* s = malloc(50*sizeof(char));
	s = concatenar("Ol","asdad asadsdaa");
	s = concatenar("Osdfsl","asdasdaa");
	s = concatenar("Owdasdqql","wda");
	s = concatenar("Oadl","aasda");
}

int main()
{
	int menu = 0;
	int stuff[10];
	int idCampos[17];
	char* s;

	automaticLogin();

	while(menu != 5)
	{
		if(menu == 1)
			lerDorf1(stuff, idCampos, 1);
		if(menu == 2)
			nivelar(stuff, idCampos);
		if(menu == 3)
			debugg();

		printf("\n\n ----------------------- ");

		printf("\n 1 - Ler Dados Dorf1");
		printf("\n 2 - Subir Campos até um certo nivel");
		printf("\n 3 - Opcao 3 ");
		printf("\n 4 - Opcao 4 ");
		printf("\n 5 - Logout ");
		printf("\n\n Escolha uma opcao: ");
		scanf("%d",&menu);
	}

	return 0;
}
