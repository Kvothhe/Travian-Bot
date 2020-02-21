#include "headers.h"

int maxTime(int a, int b, int c, int d)
{
    int r = 0;

    if(a > r)
        r = a;
    if(b > r)
        r = b;
    if(c > r)
        r = c;
    if(d > r)
        r = d;
    printf("Dormir %d mins\n", r/60);
    return r;
}

int tenhoRec(FILE* file, int* stuff)
{
    int r = 0;
    float tempo = 0;
    float mad, bar, fer, cer;
    float a,b,c,d;

    lookFor("class=\"value value",file);
    mad = recursoInfo(file);
    lookFor("class=\"value value",file);
    bar = recursoInfo(file);
    lookFor("class=\"value value",file);
    fer = recursoInfo(file);
    lookFor("class=\"value value",file);
    cer = recursoInfo(file);

    r = (mad < stuff[0] && bar < stuff[2] && fer < stuff[4] && cer < stuff[6]);

    if(r == 0)
    {
        a = ((mad - stuff[0])/ stuff[1])*3600;
        b = ((bar - stuff[2])/ stuff[3])*3600;
        c = ((fer - stuff[4])/ stuff[5])*3600;
        d = ((cer - stuff[6])/ stuff[7])*3600;


        tempo = maxTime(a, b,c,d);

        sleep(tempo);
    }

    return r;
}

int minCampo(int* idCampos, int max)
{
    int i = 1;
    int indice = -1;

    for(; i < 19; i++)
    {
        if(idCampos[i] < max)
            max = idCampos[i], indice = i;
    }

    return indice;
}

void criarUrl(int x)
{
    char* c = "build.php?id=";
    

    if (x >= 10)
    {
        c = addchar(c, '1');
        c = addchar(c,x - 10 + '0');
    }
    else
    {
        c = addchar(c, x + '0');
    }

    c = addchar(c,'\"');


    char sc[] = "wget -q --load-cookies=cookies.txt -O dorf.html \"https://ts1.lusobrasileiro.travian.com/";

    strcat(sc,c);

    //sc = addchar(sc,EOF);

    system(sc);
}

void evoluiCampo(int x, int* stuff, int* idCampos)
{
    int j;
    char c[200];
    char sc[200] = "wget -q --load-cookies=cookies.txt -O dorf.html \"https://ts1.lusobrasileiro.travian.com/";
    char c2;
    int cond = 0;

    criarUrl(x);

    FILE* filedorf;

    if(x < 19)
        filedorf = fopen("dorf.html","r+");
    else
        filedorf = fopen("build.html","r+");
    

    cond = tenhoRec(filedorf, stuff);
    printf("cond %d\n", cond);

    if(cond)
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
        concat(sc, c);

        //printf("%s\n", sc);
        system(sc);
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

    system("wget -q --load-cookies=cookies.txt -O dorf1.html https://ts2.lusobrasileiro.travian.com/dorf1.php");
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

void nivelar(int* stuff, int* idCampos, int modo)
{
    int valor, emCons;

    if(modo == 0)
    {   
        printf("Valor a evoluir:");
        scanf("%d", &valor);
        printf("Valor: %d\n", valor);
    }
    else
    {
        valor = modo;
    }
    

    int start = 0;
    int x = 0;


    while(x != -1)
    {
        int random = rand() % 150;
        lerDorf1(stuff, idCampos, 0);
        printf("Leu a Dorf1\n");
        emCons = emConstr();
        printf("Está em construção nos próximos %d minutos\n", emCons/60);

        if(!emCons)
        {
            x = minCampo(idCampos, valor);
            if (x != -1)
            {
                printf("Evoluir id: %d\n", x);
                evoluiCampo(x, stuff, idCampos);
            }
        }

        printf("Iteração: %d\nRandom: %d\n", start, random);

        sleep(emCons + random);
        printf("Vai adicionar iteração\n");
        start++;
    }

}

int nivelBuild(int id)
{
    char c;
    char* stri;
    
    stri = malloc(sizeof(char)*120);

    stri = "wget -q --load-cookies=cookies.txt -O build.html \"https://ts1.lusobrasileiro.travian.com/build.php?id=";

    stri = addchar(stri, id/10 + '0');
    stri = addchar(stri, (id - (id/10)*10) + '0');
    stri = addchar(stri,'\"');
        
    system(stri);

    int r = 0;

    FILE* ficheiro;

    ficheiro = fopen("build.html","r+");

    lookFor("Níve",ficheiro);

	r = recursoInfo(ficheiro);
    
    fclose(ficheiro);
    
    return r;
}

void EvolId (int* stuff, int* idCampos, int modo, int bid, int bate)
{ 
    int id,ate, start = 0;
    int emCons, x = 0;

    if(modo == 0)
    {
        printf("Id a evoluir:");
        scanf("%d", &id);
        printf("Até nivel:");
        scanf("%d", &ate);
    }
    else
    {
        id = bid;
        ate = bate;
    }

    while(x != ate)
    {
        int random = rand() % 120;
        lerDorf1(stuff, idCampos, 0);
        printf("Leu a Dorf1\n");
        emCons = emConstr();
        printf("Está em construção nos próximos %d minutos\n", emCons/60);

        if(!emCons)
        {
            x = nivelBuild(id);
            printf("Evoluir id: %d de nivel: %d\n", id, x);
            evoluiCampo(id, stuff, idCampos);
        }

        printf("Iteração: %d\nRandom: %d\n", start, random);

        sleep(emCons + random);
        printf("Vai adicionar iteração\n");
        start++;
    }

}

void proZ(char* lin)
{
    system("wget -q --load-cookies=cookies.txt -O quartel.html \"https://ts1.lusobrasileiro.travian.com/build.php?id=22\"");

    FILE* ficheiro; 
    ficheiro = fopen("quartel.html","r");
    
    char c;
    int i = 0;

    lookFor("hidden", ficheiro);
    lookFor("z", ficheiro);
    lookFor("value", ficheiro);


    while((c = getc(ficheiro)) != '\"')
    {
        //lin[i] = malloc(sizeof(char));
        //printf("C = %c\n", c);
        lin[i] = c;
        i++;
    }

    lin[i] = 0;    

    fclose(ficheiro);
}


void treinarTropas()
{
    char in1[4], in2[4];
    int a, b;

    printf("Falanges a treinar (MAX: 9999): \n");
    scanf("%d", &a);
    printf("Espadachins a treinar (MAX: 9999): \n");
    scanf("%d", &b);
    
    sprintf(in1,"%d", a);
    sprintf(in2,"%d", b);

    char z[10];

    proZ(z);
    
    char s[200] = "wget -q --load-cookies=cookies.txt --post-data 'id=22&z=";
    concat(s, z);
    concat(s, "&a=2&s=1&did=16674&t1=");
    concat(s, in1);
    concat(s,"&t2=");
    concat(s, in2);
    concat(s, "&s1=ok' --delete-after \"https://ts1.lusobrasileiro.travian.com/build.php?id=22\"");

    system(s);
}


int xyToSum(int x, int y)
{
    int sum = 0;

    sum = (201 + x) + (200 - y)*401;
    // printf("Z = %d\n", sum);

    return sum;
}

void generateA1(int x, int y)
{
    FILE* file;

    file = fopen("atak.html", "r");

    char time[15], check[15], cx[4], cy[4];
    char c;
    int i;

    sprintf(cx,"%d",x);
    sprintf(cy,"%d",y);

    lookFor("hidden",file);
    lookFor("value", file);

    for(i = 0; (c = getc(file)) != '\"'; i++)
        time[i] = c;

    time[i] = 0; 

    lookFor("hidden",file);
    lookFor("value", file);

    for(i = 0; (c = getc(file)) != '\"'; i++)
        check[i] = c;

    check[i] = 0; 

    fclose(file);

    system("rm a1.txt 2>/dev/null");
    file = fopen("a1.txt","w");
    fprintf(file, "timestamp=");
    fprintf(file, "%s", time);
    fprintf(file, "&timestamp_checksum=");
    fprintf(file, "%s", check);
    fprintf(file, "&b=1&currentDid=16674&troops[0][t1]&troops[0][t4]&troops[0][t7]&troops[0][t9]&troops[0][t2]=5&troops[0][t5]&troops[0][t8]&troops[0][t10]&troops[0][t3]&troops[0][t6]&troops[0][t11]&dname&x=");
    fprintf(file, "%s", cx);
    fprintf(file, "&y=");
    fprintf(file, "%s", cy);
    fprintf(file, "&c=4&s1=ok");
    fclose(file);
}

void generateA2(int x, int y, char* chZ, int modo)
{
    FILE* file;

    file = fopen("atak.html", "r");

    char time[15], check[15], cx[4], cy[4], w[10], a[15];
    char c;
    int i;

    sprintf(cx,"%d",x);
    sprintf(cy,"%d",y);

    lookFor("timestamp",file);
    lookFor("value", file);

    for(i = 0; (c = getc(file)) != '\"'; i++)
        time[i] = c;

    time[i] = 0; 

    //printf("%s\n",time);

    lookFor("hidden",file);
    lookFor("value", file);

    for(i = 0; (c = getc(file)) != '\"'; i++)
        check[i] = c;

    check[i] = 0; 

    lookFor("hidden",file);
    lookFor("hidden",file);
    lookFor("value", file);

    for(i = 0; (c = getc(file)) != '\"'; i++)
        w[i] = c;

    w[i] = 0; 

    lookFor("submit",file);
    lookFor("submit",file);
    lookFor("submit",file);
    lookFor("value", file);

    for(i = 0; (c = getc(file)) != '\"'; i++)
        a[i] = c;

    a[i] = 0;


    fclose(file);

    system("rm a2.txt 2>/dev/null");
    file = fopen("a2.txt","w");
    fprintf(file, "redeployHero&timestamp=");
    fprintf(file, "%s", time);
    fprintf(file, "&timestamp_checksum=");
    fprintf(file, "%s", check);
    fprintf(file, "&id=39&w=");
    fprintf(file, "%s", w);
    fprintf(file, "&c=4&kid=");
    fprintf(file, "%s", chZ);
    fprintf(file, "&troops[0][t1]>=0&troops[0][t2]>=5&troops[0][t3]>=0&troops[0][t4]>=0&troops[0][t5]>=0&troops[0][t6]>=0&troops[0][t7]>=0&troops[0][t8]>=0&troops[0][t9]>=0&troops[0][t10]>=0&troops[0][t11]>=0&currentDid=16674&b=2&dname&x=");
    fprintf(file, "%s", cx);
    fprintf(file, "&y=");
    fprintf(file, "%s", cy);
    fprintf(file, "&a=");
    fprintf(file, "%s", a);
    fclose(file);
}

void sendAtak(int x, int y, int modo)
{
    int z = xyToSum(x,y);

    char strZ[10];

    sprintf(strZ,"%d",z);

    char s[200] = "wget -q --load-cookies=cookies.txt -O atak.html \"https://ts1.lusobrasileiro.travian.com/build.php?id=39&tt=2&z=";
    concat(s, strZ);
    concat(s, "\"");

    system(s);

    generateA1(x, y);

    system("wget -q --load-cookies=cookies.txt --post-file=a1.txt -O atak.html \"https://ts1.lusobrasileiro.travian.com/build.php?gid=16&tt=2\"");

    generateA2(x, y, strZ, modo);

    system("wget -q --load-cookies=cookies.txt --post-file=a2.txt -O atak.html \"https://ts1.lusobrasileiro.travian.com/build.php?gid=16&tt=2\"");
}

void atakList(int lista)
{
    FILE *file;
    
    if(lista = 1)
        file = fopen("atakL.txt","r");
    else
        file = fopen("farmlist.txt","r");
        
    int x, y, modo, i;

    for(i = 0; i < 5; i++)
    {
        fscanf(file,"%d %d %d\n", &modo, &x, &y);
        sendAtak(x,y,modo);
    }

    fclose(file);
}
