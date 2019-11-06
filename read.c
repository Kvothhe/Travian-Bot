#include <stdio.h>
#include <stdlib.h>

#define MAX 15

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


	linha = copia = i = 0;
	teste = 1;

	system("wget -q --load-cookies=cookies.txt -O dorf1.html https://ts2.lusobrasileiro.travian.com/dorf1.php");
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
   	lookFor("build.php?id=1",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id1 = recursoInfo(ficheiro);
   	
   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id2 = recursoInfo(ficheiro);
   	
   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id3 = recursoInfo(ficheiro);
   	
   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id4 = recursoInfo(ficheiro);
   	
   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id5 = recursoInfo(ficheiro);
   	
   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id6 = recursoInfo(ficheiro);
   	
   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id7 = recursoInfo(ficheiro);
   
   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id8 = recursoInfo(ficheiro);
   	
   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id9 = recursoInfo(ficheiro);
   	
   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id10 = recursoInfo(ficheiro);
   	
   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id11 = recursoInfo(ficheiro);
   	
   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id12 = recursoInfo(ficheiro);

   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id13 = recursoInfo(ficheiro);
   	
   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id14 = recursoInfo(ficheiro);
   	
   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id15 = recursoInfo(ficheiro);
   	
   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id16 = recursoInfo(ficheiro);
   	
   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id17 = recursoInfo(ficheiro);
   	
   	lookFor("area",ficheiro);
   	lookFor("e;ve",ficheiro);
   	id18 = recursoInfo(ficheiro);
   	
   	printf("Bosque 1 nível: %d\n", id1);
	printf("Bosque 2 nível: %d\n", id3);
	printf("Bosque 3 nível: %d\n", id14);
	printf("Bosque 4 nível: %d\n\n", id17);
	
	printf("Poço de Barro 1 nível: %d\n", id5);
	printf("Poço de Barro 2 nível: %d\n", id6);
	printf("Poço de Barro 3 nível: %d\n", id16);
	printf("Poço de Barro 4 nível: %d\n\n", id18);

	printf("Mina de Ferro 1 nível: %d\n", id4);	
	printf("Mina de Ferro 2 nível: %d\n", id7);
	printf("Mina de Ferro 3 nível: %d\n", id10);
	printf("Mina de Ferro 4 nível: %d\n\n", id11);

	printf("Campo de Cereais 1 nível: %d\n", id2);
	printf("Campo de Cereais 2 nível: %d\n", id8);
	printf("Campo de Cereais 3 nível: %d\n", id9);
	printf("Campo de Cereais 4 nível: %d\n", id12);
	printf("Campo de Cereais 5 nível: %d\n", id13);
	printf("Campo de Cereais 6 nível: %d\n", id15);
	

	printf("\n---------------------------------\n\n");

}

void lerDorf2()
{
   FILE* file;

   system("wget -q --load-cookies=cookies.txt -O dorf1.html https://ts2.lusobrasileiro.travian.com/dorf2.php");
   file = fopen("dorf2.html","r+");
}