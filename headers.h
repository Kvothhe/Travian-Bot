#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <curl/curl.h>

void automaticLogin(int, FILE*);
int linTam(char*);
int maxTime(int, int, int, int);
void concat(char*, char*);
char* addchar(char*, char);
int eVarr(char* string);
int eString(char*, FILE*, char);
void lookFor(char*, FILE*);
void skipChar(int, FILE*);
int pot(int, int);
int tamanho(int*);
int arrayToInt(int*, int);
int recursoInfo(FILE*);
int searchVillage();
void changeVillage(int, FILE *);
void lerDorf1(int*, int*, int, FILE*, char*);
void evoluiCampo(int, int*, int*, FILE*);
int tenhoRec(FILE*, int*);
int minCampo(int*, int);
void nivelar(int*, int*, int,int, FILE*);
int emConstr(FILE*);
void criarUrl(int);
int xyToSum(int, int);
int nivelBuild(int);
void EvolId (int*, int*, int, int, int, int, FILE*);
void proZ();
void treinarTropas(int, int, int, int, FILE*);
void generateA1(int, int);
void generateA2(int, int, char*, int);
void sendAtak(int, int, int);
void atakList(int);
void inactivePlayers();
void addS(FILE *, int);
void runList(int*, int *, FILE*);
void createToDoList(FILE *);
void quests(int*, int *, FILE*);
void sendAd();