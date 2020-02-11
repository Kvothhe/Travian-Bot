#include <stdio.h>
#include <stdlib.h>

#define MAX 15

char* addchar(char s1[], char c)
{
	int i;

	for (i = 0; s1[i]!='\0'; i++);
	i++;

	char* string = malloc(i+5);

	for(i = 0; s1[i] != '\0'; i++)
		string[i] = s1[i];
	string[i] = c;

	i++;
	string[i]='\0';
	return string;
}

int eVarr(char* string)
{
	char* s1 = "var r\0";
	int i = 0;
	int vf = 1;
	//printf("%s\n", s1);

	while(i < 5)
	{
		//printf("%c %c\n", s1[i], string[i]);
		if(s1[i] != string[i])
			vf = 0;
		++i;
	}


	return vf;
}
int eString(char* string, FILE* file, char c)
{
	int i = 0;
	int vf = 1;
	//printf("%s\n", s1);

	while(string[i] != '\0' && vf != 0 && c != EOF)
	{
		//printf("%c %c\n", s1[i], string[i]);

		if(string[i] != c)
			vf = 0;
		++i;
		c = getc(file);
	}


	return vf;
}

void lookFor(char* string, FILE* file)
{
	char c;
	int i = 0;
	int teste = 1;

	c = getc(file);
	while(teste && c != EOF)
	{
		if(string[i] == c)
			teste = 1 - eString(string,file,c);
		c = getc(file);
	}
}

void skipChar(int i, FILE* file)
{
	char c;

	while(i != 0)
		c = getc(file), --i;

}

int pot(int x, int n)
{
	int i, p=1;

	for(i=0; i<n;i++)
		p=p*x;

	return p;
}

int tamanho(int* array)
{
	int r = 1;

	while(array[r] != 'z')
		r++;

	return r;
}

int arrayToInt(int* array, int N)
{
	int r = 0;
	int i = 0;

	N--;

	while(N >= 0)
		r += array[i] * pot(10,N), N--,++i;

	return r;
}

int recursoInfo(FILE* ficheiro)
{
	int array[MAX];
	char caracter;

	fscanf(ficheiro,"%c", &caracter);
   	int j = 0;
   	while(47 < caracter && caracter < 58)
   	{
   		array[j] = caracter - 48;
   		++j;
   		fscanf(ficheiro,"%c", &caracter);
   	}

   	array[j] = 'z';

   	j = arrayToInt(array,tamanho(array));

   	return j;
}

void lerDorf1(int* stuff, int* idCampos, int print)
{
	char string[5];
	char caracter;
	int teste, linha,copia;
	int i;
	FILE *ficheiro;

	linha = copia = i = 0;
	teste = 1;

	system("wget -q --load-cookies=cookies.txt -O dorf1.html https://ts1.lusobrasileiro.travian.com/dorf1.php");
	ficheiro = fopen("dorf1.html","r+");

   	while (teste)
   	{

   		fscanf(ficheiro,"%c", &caracter);
   		//printf("%c", caracter);

   		if (caracter == '\n')
   			linha++;

   		if (caracter == 'v')
   			copia = 1;

   		if (copia == 1)
   			string[i] = caracter, ++i;

   		if (i == 5)
   		{
   			if(eVarr(string))
   				copia = teste = 0, i = 0;
   			else copia = 0, i = 0;
   		}
   	}


   	skipChar(40,ficheiro);
   	stuff[1] = recursoInfo(ficheiro);

   	skipChar(6,ficheiro);
   	stuff[3] = recursoInfo(ficheiro);

   	skipChar(6,ficheiro);
   	stuff[5] = recursoInfo(ficheiro);

   	skipChar(6,ficheiro);
   	stuff[7] = recursoInfo(ficheiro);

   	skipChar(6,ficheiro);
   	stuff[8] = recursoInfo(ficheiro);

	skipChar(26,ficheiro);
   	stuff[0] = recursoInfo(ficheiro);
   	skipChar(6,ficheiro);
   	stuff[2] = recursoInfo(ficheiro);

   	skipChar(6,ficheiro);
   	stuff[4] = recursoInfo(ficheiro);

   	skipChar(6,ficheiro);
   	stuff[6] = recursoInfo(ficheiro);


   	lookFor("l1",ficheiro);
   	skipChar(1,ficheiro);
   	stuff[9] = recursoInfo(ficheiro);


   	lookFor("l4",ficheiro);
   	skipChar(1,ficheiro);
   	stuff[10] = recursoInfo(ficheiro);

   	fclose(ficheiro);


	ficheiro = fopen("dorf1.html","r+");
	for(int j = 1; j < 19; j++)
	{
		char* cam = malloc(200*(sizeof(char)));
		cam = "build.php?id=";
		char c2;
		if (j >= 10)
		{
			c2 = j - 10 + '0';
			cam = addchar(cam, '1');
			cam = addchar(cam, c2);
		}
		else
		{
			c2 = j + '0';
			cam = addchar(cam, c2);
		}
		lookFor(cam,ficheiro);
		lookFor("e;ve",ficheiro);
		idCampos[j] = recursoInfo(ficheiro);
		free(cam);
	}

	if(print)
	{
		printf("----Produção:----\n\n");
		printf("Produção de Madeira: %d\n", stuff[1]);
		printf("Produção de Barro: %d\n", stuff[3]);
		printf("Produção de Ferro: %d\n", stuff[5]);
		printf("Produção de Cereal: %d\n", stuff[7]);
		printf("Cereal livre: %d\n", stuff[8]);

		printf("\n---Armazenado:----\n\n");
		printf("Madeira: %d\n", stuff[0]);
		printf("Barro: %d\n", stuff[2]);
		printf("Ferro: %d\n", stuff[4]);
		printf("Cereal: %d\n", stuff[6]);

		printf("\n---Capacidade:----\n\n");
		printf("Armazem: %d\n", stuff[9]);
		printf("Celeiro: %d\n", stuff[10]);
		printf("Bosque 1 nível: %d\n", idCampos[1]);


		printf("\n---Campos:----\n\n");

		printf("Bosque 2 nível: %d\n", idCampos[3]);
		printf("Bosque 3 nível: %d\n", idCampos[14]);
		printf("Bosque 4 nível: %d\n\n", idCampos[17]);

		printf("Poço de Barro 1 nível: %d\n", idCampos[5]);
		printf("Poço de Barro 2 nível: %d\n", idCampos[6]);
		printf("Poço de Barro 3 nível: %d\n", idCampos[16]);
		printf("Poço de Barro 4 nível: %d\n\n", idCampos[18]);

		printf("Mina de Ferro 1 nível: %d\n", idCampos[4]);
		printf("Mina de Ferro 2 nível: %d\n", idCampos[7]);
		printf("Mina de Ferro 3 nível: %d\n", idCampos[10]);
		printf("Mina de Ferro 4 nível: %d\n\n", idCampos[11]);

		printf("Campo de Cereais 1 nível: %d\n", idCampos[2]);
		printf("Campo de Cereais 2 nível: %d\n", idCampos[8]);
		printf("Campo de Cereais 3 nível: %d\n", idCampos[9]);
		printf("Campo de Cereais 4 nível: %d\n", idCampos[12]);
		printf("Campo de Cereais 5 nível: %d\n", idCampos[13]);
		printf("Campo de Cereais 6 nível: %d\n", idCampos[15]);


		printf("\n---------------------------------\n\n");
	}
	fclose(ficheiro);
}

void lerDorf2()
{
   FILE* file;

   system("wget -q --load-cookies=cookies.txt -O dorf1.html https://ts2.lusobrasileiro.travian.com/dorf2.php");
   file = fopen("dorf2.html","r+");
}
