#include "headers.h"

int questCmd(char* cmd)
{
  CURLcode ret;
  CURL *hnd;
  struct curl_slist *slist1;

  slist1 = NULL;
  slist1 = curl_slist_append(slist1, "Host: ts1.lusobrasileiro.travian.com");
  slist1 = curl_slist_append(slist1, "Origin: https://ts1.lusobrasileiro.travian.com");

  hnd = curl_easy_init();
  curl_easy_setopt(hnd, CURLOPT_BUFFERSIZE, 102400L);
  curl_easy_setopt(hnd, CURLOPT_URL, "https://ts1.lusobrasileiro.travian.com/ajax.php?cmd=quest");
  curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 1L);
  curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, cmd);
  //curl_easy_setopt(hnd, CURLOPT_POSTFIELDSIZE_LARGE, (curl_off_t)91);
  curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, slist1);
  curl_easy_setopt(hnd, CURLOPT_USERAGENT, "curl/7.68.0");
  curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);
  curl_easy_setopt(hnd, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_2TLS);
  curl_easy_setopt(hnd, CURLOPT_SSL_VERIFYPEER, 0L);
  curl_easy_setopt(hnd, CURLOPT_SSL_VERIFYHOST, 0L);
  curl_easy_setopt(hnd, CURLOPT_COOKIEFILE, "cookiescURL.txt");
  curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
  curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 1L);
  //curl_easy_setopt(hnd, CURLOPT_VERBOSE, 1L);

  /* Here is a list of options the curl code used that cannot get generated
     as source easily. You may select to either not use them or implement
     them yourself.

  CURLOPT_WRITEDATA set to a objectpointer
  CURLOPT_INTERLEAVEDATA set to a objectpointer
  CURLOPT_WRITEFUNCTION set to a functionpointer
  CURLOPT_READDATA set to a objectpointer
  CURLOPT_READFUNCTION set to a functionpointer
  CURLOPT_SEEKDATA set to a objectpointer
  CURLOPT_SEEKFUNCTION set to a functionpointer
  CURLOPT_ERRORBUFFER set to a objectpointer
  CURLOPT_STDERR set to a objectpointer
  CURLOPT_HEADERFUNCTION set to a functionpointer
  CURLOPT_HEADERDATA set to a objectpointer

  */

  ret = curl_easy_perform(hnd);

  curl_easy_cleanup(hnd);
  hnd = NULL;
  curl_slist_free_all(slist1);
  slist1 = NULL;

  return (int)ret;
}

void quests(int* stuff, int* idCampos, FILE* logfile)
{
	//system("netstat -tlpen | grep 8080");
	//char loginCmd[300] = "curl -k -s https://ts1.lusobrasileiro.travian.com/login.php -c cookiescURL.txt -d \"name=";
	//strcat(loginCmd,user);
	//strcat(loginCmd,"&password=");
	//strcat(loginCmd, pass);
	//strcat(loginCmd, "\"");

	//system(loginCmd);

	//17 Battle quests, 14 economy, 9 world
	changeVillage(1,logfile);
	char token[80];
	char num[5]; 
	int j;
	lerDorf1(stuff, idCampos, 0, logfile, token);

	for(int i = 1, j = 1; i < 18; i++)
	{
		//lerDorf1(stuff, idCampos, 0, logfile, token);
		char* cmd;
		cmd = malloc(sizeof(char)*500);
		if(i < 10)
			strcpy(cmd, "cmd=quest&questTutorialId=Battle_0"), j = i;
	    else
	    	strcpy(cmd, "cmd=quest&questTutorialId=Battle_1"), j = i - 10;
	    sprintf(num, "%d", j);
	    strcat(cmd, num);
	    strcat(cmd, "&action=reward&ajaxToken=");
	    strcat(cmd, token);
	    
	    //printf("%s\n", cmd);
	    questCmd(cmd);

	    free(cmd);
	}
	for(int i = 1, j = 1; i < 15; i++)
	{
		//lerDorf1(stuff, idCampos, 0, logfile, token);
		char* cmd;
		cmd = malloc(sizeof(char)*500);
		if(i < 10)
			strcpy(cmd, "cmd=quest&questTutorialId=Economy_0"), j = i;
	    else
	    	strcpy(cmd, "cmd=quest&questTutorialId=Economy_1"), j = i - 10;
	    sprintf(num, "%d", j);
	    strcat(cmd, num);
	    strcat(cmd, "&action=reward&ajaxToken=");
	    strcat(cmd, token);
	    
	    //printf("%s\n", cmd);
	    questCmd(cmd);

	    free(cmd);
	}
	for(int i = 1, j = 1; i < 10; i++)
	{
		//lerDorf1(stuff, idCampos, 0, logfile, token);
		char* cmd;
		cmd = malloc(sizeof(char)*500);
		if(i < 10)
			strcpy(cmd, "cmd=quest&questTutorialId=World_0"), j = i;
	    else
	    	strcpy(cmd, "cmd=quest&questTutorialId=World_1"), j = i - 10;
	    sprintf(num, "%d", j);
	    strcat(cmd, num);
	    strcat(cmd, "&action=reward&ajaxToken=");
	    strcat(cmd, token);
	    
	    //printf("%s\n", cmd);
	    questCmd(cmd);

	    free(cmd);
	}
} 