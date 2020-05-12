#include "headers.h"

void sendAd()
{
	system("wget -q --load-cookies=cookies.txt \"https://ts1.lusobrasileiro.travian.com/karte.php\" --delete-after");
	system("wget -q --load-cookies=cookies.txt -O hero.html \"https://ts1.lusobrasileiro.travian.com/hero.php?t=3\"");
	FILE* ficheiro;
	int kid;

	ficheiro = fopen("hero.html","r+");

	lookFor("kid", ficheiro);
	lookFor("ue", ficheiro);
	kid = recursoInfo(ficheiro);

	//printf("Kid: %d\n", kid);
	char kidchar[8];

	sprintf(kidchar, "%d", kid);

	char ad[200] = "wget -q --load-cookies=cookies.txt \"https://ts1.lusobrasileiro.travian.com/start_adventure.php?send=1&kid=";
	strcat(ad, kidchar);
	strcat(ad, "&form=list&a=1\" --delete-after");

	system(ad);
}