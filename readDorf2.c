#include "headers.h"

void readDorf2()
{
    system("wget -q --load-cookies=cookies.txt -O dorf2.html https://ts1.lusobrasileiro.travian.com/dorf2.php");

    FILE * file;    
    file = fopen("dorf2.html", "r");

    lookFor("buildingSlot a19",file);

}
