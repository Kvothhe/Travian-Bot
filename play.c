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

int minCampo(int* idCampos, int max)
{
    int i = 1;
    int indice = -1;

    for(; i < 18; i++)
    {
        if(idCampos[i] < max)
            max = idCampos[i], indice = i;
    }

    return indice;
}

void evoluiCampo(int x, int* stuff, int* idCampos)
{
    int j;
    char* c = "build.php?id=";
    char c2;
    char ch;

    char* linha = malloc(50*sizeof(char));


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
        //printf("HERE\n");


        //printf("HERE\n");
        fscanf(filedorf, "%c", &c2);
        //printf("Char = %c\n", c2);
        for(j = 0; c2 != '\''; j++)
        {
            if(c2 == 38)
                skipChar(4,filedorf);

            linha[j] = c2;
            fscanf(filedorf, "%c", &c2);
        //    printf("%d\n", j);
        }
        //printf("HERE\n");
        linha[j] = 34;
        linha[j+1] = 0;
        c = concatenar("wget -q --load-cookies=cookies.txt -O dorf.html \"https://ts1.lusobrasileiro.travian.com/", linha);
        //printf("%s\n", c);
        system(c);
        system("rm dorf.html 2>/dev/null");
        fclose(filedorf);
    }
    else
    {
        fclose(filedorf);
        printf("Sem Recursos para id=%d!\n", x);
    }
}

int emConstr()
{
    FILE* ficheiro;
    char c;
    int emCons = 0;

    ficheiro = fopen("dorf1.html","r+");
    lookFor("Em construçã", ficheiro);
    fscanf(ficheiro, "%c", &c);
    if(c == '<')
    {
        fscanf(ficheiro, "%c", &c);
        if(c == 47)
            emCons = 1;
    }
    fclose(ficheiro);

    return emCons;
}

void nivelar(int* stuff, int* idCampos)
{
    int valor, emCons;
    char c;

    printf("Valor a evoluir:");
    scanf("%d", &valor);
    printf("Valor: %d\n", valor);

    int start = 0;
    int x = 0;


    while(start < 600 && x != -1)
    {
        lerDorf1(stuff, idCampos, 0)

        emCons = emConstr();
        printf("Está em construção: %d\n", emCons);

        if(!emCons)
        {
            x = minCampo(idCampos, valor);
            printf("Evoluir id: %d\n", x);
            evoluiCampo(x, stuff, idCampos);
        }

        printf("Minuto: %d\n", start);

        sleep(50);
        start++;
    }

}
