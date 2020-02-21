#include "headers.h"

void inactivePlayers()
{
    int i;
    char page[4];

    for(i = 0; i < 128 ; i++)
    {
        char s[100] = "https://ts1.lusobrasileiro.travian.com/statistiken.php?id=0&page=";
        char cmd[150] = "wget -q --load-cookies=cookies.txt ";
        sprintf(page,"%d",i);
        concat(s, page);
        concat(cmd, s);
        printf("%s\n", cmd);
    }
}
