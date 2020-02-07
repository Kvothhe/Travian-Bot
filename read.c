#include <stdio.h>
#include <stdlib.h>

#define MAX 15

char* addchar(char s1[], char c)
{
	int i,i2;

	for (i = 0; s1[i]!='\0'; i++);
	i++;

	char* string = malloc(i);

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

	while(string[i] != '\0' && vf != 0)
	{
		//printf("%c %c\n", s1[i], string[i]);

		if(string[i] != c)
			vf = 0;
		++i;
		fscanf(file, "%c", &c);
	}


	return vf;
}

void lookFor(char* string, FILE* file)
{
	char c;
	int i = 0;
	int teste = 1;

	fscanf(file, "%c", &c);
	while(teste)
	{
		if(string[i] == c)
			teste = 1 - eString(string,file,c);
		fscanf(file, "%c", &c);
	}
}

void skipChar(int i, FILE* file)
{
	char c;

	while(i != 0)
		fscanf(file,"%c", &c), --i;

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

void lerDorf1()
{
	char string[5];
	char caracter;
	int teste, linha,copia;
	int i;
	FILE *ficheiro;

	int madeira, madProd, barro, barroProd, ferro, ferroProd, cereal, cerProd, cerLivre, armazem, celeiro;
	int id1, id2, id3, id4, id5, id6, id7, id8, id9, id10, id11, id12, id13, id14, id15, id16, id17, id18;
	int idCampos[17];


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
   			else copia = 0; i = 0;
   		}
   	}

   	printf("----Produção:----\n\n");
   	skipChar(40,ficheiro);
   	madProd = recursoInfo(ficheiro);
   	printf("Produção de Madeira: %d\n", madProd);
   	skipChar(6,ficheiro);
   	barroProd = recursoInfo(ficheiro);
   	printf("Produção de Barro: %d\n", barroProd);
   	skipChar(6,ficheiro);
   	ferroProd = recursoInfo(ficheiro);
   	printf("Produção de Ferro: %d\n", ferroProd);
   	skipChar(6,ficheiro);
   	cerProd = recursoInfo(ficheiro);
   	printf("Produção de Cereal: %d\n", cerProd);
   	skipChar(6,ficheiro);
   	cerLivre = recursoInfo(ficheiro);
   	printf("Cereal livre: %d\n", cerLivre);

   	printf("\n---Armazenado:----\n\n");

   	skipChar(26,ficheiro);
   	madeira = recursoInfo(ficheiro);
   	printf("Madeira: %d\n", madeira);
   	skipChar(6,ficheiro);
   	barro = recursoInfo(ficheiro);
   	printf("Barro: %d\n", barro);
   	skipChar(6,ficheiro);
   	ferro = recursoInfo(ficheiro);
   	printf("Ferro: %d\n", ferro);
   	skipChar(6,ficheiro);
   	cereal = recursoInfo(ficheiro);
   	printf("Cereal: %d\n", cereal);

   	printf("\n---Capacidade:----\n\n");

   	lookFor("l1",ficheiro);
   	skipChar(1,ficheiro);
   	armazem = recursoInfo(ficheiro);
   	printf("Armazem: %d\n", armazem);

   	lookFor("l4",ficheiro);
   	skipChar(1,ficheiro);
   	celeiro = recursoInfo(ficheiro);
   	printf("Celeiro: %d\n", celeiro);
   	fclose(ficheiro);

   	printf("\n---Campos:----\n\n");

	ficheiro = fopen("dorf1.html","r+");
	for(int j = 1; j < 19; j++)
	{
		char* c = "build.php?id=";
		char c2;
		if (j >= 10)
		{
			 c2 = j - 10 + '0';
			c = addchar(c, '1');
			c = addchar(c, c2);
		}
		else
		{
			c2 = j + '0';
			c = addchar(c, c2);
		}
		lookFor(c,ficheiro);
		lookFor("e;ve",ficheiro);
		idCampos[j] = recursoInfo(ficheiro);
	}

   	printf("Bosque 1 nível: %d\n", idCampos[1]);
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

void lerDorf2()
{
   FILE* file;

   system("wget -q --load-cookies=cookies.txt -O dorf1.html https://ts2.lusobrasileiro.travian.com/dorf2.php");
   file = fopen("dorf2.html","r+");
}
