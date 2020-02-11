#include "headers.h"

int tenhoRec(FILE* file, int* stuff)
{
    int r = 0;
    int mad, bar, fer, cer;

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

void criarUrl(int x)
{
    char* c = malloc(200*sizeof(char));
    c = "build.php?id=";
    printf("%s\n", c);

    if (x >= 10)
    {
        c = addchar(c, '1');
        c = addchar(c,x - 10 + '0');
        printf("%s\n", c);
    }
    else
    {
        c = addchar(c, x + '0');
    }

    c = addchar(c,'\"');
    printf("%s\n", c);
    c = concatenar("wget -q --load-cookies=cookies.txt -O dorf.html \"https://ts1.lusobrasileiro.travian.com/",c);

    c = addchar(c,0);
    printf("%s\n", c);
    system(c);
    free(c);
}

void evoluiCampo(int x, int* stuff, int* idCampos)
{
    int j;
    char* c = malloc(200*sizeof(char));
    char* sc = malloc(200*sizeof(char));
    char c2;

    criarUrl(x);

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

            c[j] = c2;
            fscanf(filedorf, "%c", &c2);
        //    printf("%d\n", j);
        }
        //printf("HERE\n");
        c[j] = 34;
        c[j+1] = 0;
        sc = concatenar("wget -q --load-cookies=cookies.txt -O dorf.html \"https://ts1.lusobrasileiro.travian.com/", c);

        printf("%s\n", sc);
        system(sc);
        system("rm dorf.html 2>/dev/null");
        free(c);
        free(sc);
        fclose(filedorf);
    }
    else
    {
        fclose(filedorf);
        free(c);
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
        {
            lookFor("timer", ficheiro);
            lookFor("value", ficheiro);
            emCons = recursoInfo(ficheiro);
        }
    }
    fclose(ficheiro);

    return emCons;
}

void nivelar(int* stuff, int* idCampos)
{
    int valor, emCons;


    printf("Valor a evoluir:");
    scanf("%d", &valor);
    printf("Valor: %d\n", valor);

    int start = 0;
    int x = 0;


    while(start < 600 && x != -1)
    {
        int random = rand() % 120;
        lerDorf1(stuff, idCampos, 0);
        printf("Leu a Dorf1\n");
        emCons = emConstr();
        printf("Está em construção nos próximos %d minutos\n", emCons/60);

        if(!emCons)
        {
            x = minCampo(idCampos, valor);
            printf("Evoluir id: %d\n", x);
            evoluiCampo(x, stuff, idCampos);
        }

        printf("Iteração: %d\nRandom: %d\n", start, random);

        sleep(emCons + random);
        printf("Vai adicionar iteração\n");
        start++;
    }

}
