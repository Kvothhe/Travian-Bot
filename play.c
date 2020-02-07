#include "headers.h"

int tenhoRec(FILE* file, int* stuff)
{
    int r = 0;
    int mad, bar, fer, cer;
    char c;

    lookFor("class=\"value value",file);
    mad = recursoInfo(file);
    lookFor("class=\"value value",file);
    bar = recursoInfo(file);
    lookFor("class=\"value value",file);
    fer = recursoInfo(file);
    lookFor("class=\"value value",file);
    cer = recursoInfo(file);

    r = (mad < stuff[0] && bar < stuff[2] && fer < stuff[4] && cer < stuff[6]);
    return r;
}

void evoluiCampo(int x, int* stuff)
{
    int j;
    char* c = "build.php?id=";
    char c2;
    if (x >= 10)
    {
         c2 = x - 10 + '0';
        c = addchar(c, '1');
        c = addchar(c, c2);
    }
    else
    {
        c2 = x + '0';
        c = addchar(c, c2);
    }

    c = addchar(c,'\"');
    c = concatenar("wget -q --load-cookies=cookies.txt -O dorf.html \"https://ts1.lusobrasileiro.travian.com/",c);

    system(c);


    FILE* filedorf;

    filedorf = fopen("dorf.html","r+");

    if(tenhoRec(filedorf, stuff))
    {
        lookFor("on.href =", filedorf);

        char* linha = malloc(25);

        fscanf(filedorf, "%c", &c2);
        for(j = 0; c2 != '\''; j++)
        {
            if(c2 == 38)
                skipChar(4,filedorf);

                linha[j] = c2;
            fscanf(filedorf, "%c", &c2);
        }
        linha[j] = '\"';
        c = concatenar("wget -q --load-cookies=cookies.txt -O dorf.html \"https://ts1.lusobrasileiro.travian.com/", linha);

        system(c);
        system("rm dorf.html 2>/dev/null");
        fclose(filedorf);
    }
    else
    {
        fclose(filedorf);
        printf("Sem Recursos!\n");
    }
}
