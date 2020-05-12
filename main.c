#include "headers.h"

int main()
{
	int menu = 0;
	int stuff[13];
	int idCampos[17];
	char* s;
	char sfd[10];
	FILE * logfile;
	logfile = fopen("log.txt","w");

	automaticLogin(1,logfile);

	while(menu != 11)
	{
		if(menu == 1)
			lerDorf1(stuff, idCampos, 1, logfile, NULL);
		if(menu == 2)
			nivelar(stuff, idCampos, 0, 1, logfile);
		if(menu == 3)
			EvolId(stuff, idCampos, 0, 0, 0, 1, logfile);
		if(menu == 4)
			atakList(2);
		if(menu == 5)
			treinarTropas(0, 1, 0, 0, logfile);
		if(menu == 6)
			createToDoList(logfile);
		if(menu == 7)
			runList(stuff, idCampos, logfile);
		if(menu == 8) 
			quests(stuff, idCampos, logfile);
		if(menu == 9) 
			changeVillage(2, logfile);
		if(menu == 10)
			sendAd();
 
		printf("\n\n ----------------------- ");
// 
		printf("\n1 - Ler Dados Dorf1");
		printf("\n2 - Subir Campos até um certo nivel");
		printf("\n3 - Subir até nivel");
		printf("\n4 - Ataque");
		printf("\n5 - Treinar Tropas");
		printf("\n6 - Create To-Do list");
		printf("\n7 - Correr a lista");
		printf("\n8 - Quests");
		printf("\n9 - Mudar aldeia");
		printf("\n10 - Enviar heroi");
		printf("\n11 - Logout "); 
		printf("\nEscolha uma opcao: ");
		scanf("%d",&menu);
	}

	fclose(logfile);

	return 0;
}
