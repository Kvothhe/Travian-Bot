#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void automaticLogin();
char* concatenar(char*, char*);
char* addchar(char*, char);
int eVarr(char* string);
int eString(char*, FILE*, char);
void lookFor(char*, FILE*);
void skipChar(int, FILE*);
int pot(int, int);
int tamanho(int*);
int arrayToInt(int*, int);
int recursoInfo(FILE*);
void lerDorf1(int*, int*, int);
void evoluiCampo(int, int*, int*);
int tenhoRec(FILE*, int*);
int minCampo(int*, int);
void nivelar(int*, int*);
int emConstr();
