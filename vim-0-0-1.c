#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <math.h>
// #include <windows.h>

int cmdflag[16];
char filer[6] = {'-', '-', 'f', 'i', 'l', 'e'};
char str[5] = {'-', '-', 's', 't', 'r'};
char poser[5] = {'-', '-', 'p', 'o', 's'};
char sizer[5] = {'-', 's', 'i', 'z', 'e'};
char addressrep[100][100];
char *clipboard;
char chert;

void zeroaddress()
{
    for (int counter1 = 0; counter1 < 10000; counter1++)
    {
        addressrep[counter1 / 100][counter1 % 100] = NULL;
    }
}
void shift(char *, long long, long long);
int checkval(char a, char b, char c, char d);
int get_command();
int runcommand(int cmdnum);
void print_commands();
int maf();
int cat();
void cmp();
int fnd();
int runcummand(int);
void pardazesh(char g[], long long);
int insert();
long long remover(char *, int, int);
int cop(int);
int rmv();
int pst();

void addressmaker(int i, int j, char adress[])
{
    for (int jj = 0; jj < j; jj++)
    {
        addressrep[i][jj] = adress[jj];
        addressrep[i][jj + 1] = '\0';
    }
}

char cmd[16][4] = {
    'p', 'r', 'c', ' ',
    'm', 'a', 'f', ' ',
    'i', 'a', 't', ' ',
    'c', 'a', 't', ' ',
    'r', 'm', 'v', ' ',
    'c', 'o', 'p', ' ',
    'c', 'u', 't', ' ',
    'p', 's', 't', ' ',
    'f', 'n', 'd', ' ',
    'r', 'p', 'c', ' ',
    'g', 'r', 'p', ' ',
    'u', 'n', 'd', ' ',
    'c', 'l', 'p', ' ',
    'c', 'm', 'p', ' ',
    's', 'd', 't', ' ',
    'f', 'o', 'g', ' '};
int flag = 0;

int isorbe(char addd[])
{
    FILE *check = fopen(addd, "r");
    if (check != NULL)
    {
        printf("what are you doing dude , file already exist !! \n");
        fclose(check);
    }
    FILE *ptr = fopen(addd, "w");
    fclose(ptr);
}

int maf()
{
    zeroaddress();
    char temp;
    int a = 0, flag = 0;
    char aray[6];
    char address[100];
    scanf("%s", &aray);
    for (int z = 0; z < 6; z++)
    {
        if (aray[z] != filer[z])
        {
            printf("you should use <<--file>> befor your address dude\n");
            return 0;
        }
    }
    scanf(" ", chert);
    int counter2 = 0;
    scanf("%c", &temp);
    if (temp != '"')
    {
        address[0] = temp;
        counter2 = 1;
    }

    for (counter2; counter2 < 100; counter2++)
    {
        scanf("%c", &temp);
        if (temp == '"')
        {
            address[counter2] = '\0';
            counter2 += 150;
        }
        if (temp != '\n')
        {
            address[counter2] = temp;
            address[counter2 + 1] = '\0';
        }
        else
        {
            counter2 += 150;
        }
    }
    for (int counter1 = 0; counter1 < 100; counter1++)
    {
        if (address[counter1] == '/')
        {
            addressmaker(a, counter1, address);
            a++;
            continue;
        }
    }
    a = 0;
    for (int addr = 0; addr < 100 && addressrep[addr][0] != NULL; addr++)
    {
        int ret = 0;
        ret = mkdir(addressrep[addr], 0755);
    }
    isorbe(address);
}

int cat()
{
    char tempcat;
    char tempscan;
    char addresscat[100], cats[1000000];
    char aray2[6];
    scanf("%s", &aray2);
    for (int z = 0; z < 6; z++)
    {
        if (aray2[z] != filer[z])
        {
            printf("you should use <<--file>> befor your address dude\n");
            return 0;
        }
    }
    scanf(" ", chert);
    int counter3 = 0;
    scanf("%c", &tempcat);
    if (tempcat != '"')
    {
        addresscat[0] = tempcat;
        counter3 = 1;
    }

    for (counter3; counter3 < 100; counter3++)
    {
        scanf("%c", &tempcat);
        if (tempcat == '"')
        {
            addresscat[counter3] = '\0';
            counter3 += 150;
        }
        if (tempcat != '\n')
        {
            addresscat[counter3] = tempcat;
            addresscat[counter3 + 1] = '\0';
        }
        else
        {
            counter3 += 150;
        }
    }
    printf("\n");
    FILE *cat = fopen(addresscat, "r");
    if (cat == NULL)
    {
        printf("the file you intered doesn't exist bro !! \n");
        return 0;
    }
    printf("--------------------------------------------------------------------------------------\n");
    while (fgets(cats, 1000000, cat))
    {
        printf("%s", cats);
    }
    fclose(cat);
    printf("\n--------------------------------------------------------------------------------------\n");
}

void cmp()
{
    char araa3[6], tempo2, str7[5], adrc[200], adrc2[200];
    long long counter18, counter17, tedadhorof5, jaygah4;
    int spaceflag5;
    scanf("%s", &araa3);
    if (strcmp(araa3, "--files"))
    {
        printf("you should use <<--files>> befor your address dude\n");
        return;
    }
    scanf(" ", chert);
    scanf("%c", &tempo2);
    if (tempo2 != '"')
    {
        adrc[0] = tempo2;
        counter17 = 1;
        spaceflag5 = 0;
    }

    for (counter17; counter17 < 200; counter17++)
    {
        scanf("%c", &tempo2);
        if (spaceflag5 == 0 && tempo2 == ' ')
        {
            adrc[counter17] = '\0';
            counter17 += 250;
        }
        else
        {
            if (tempo2 == '"')
            {
                adrc[counter17] = '\0';
                counter17 += 250;
            }
            if (tempo2 != '\n')
            {
                adrc[counter17] = tempo2;
                adrc[counter17 + 1] = '\0';
            }
            else
            {
                counter17 += 250;
            }
        }
    }
    if (spaceflag5 == 1)
        scanf(" ", chert);
    scanf("%c", &tempo2);
    if (tempo2 != '"')
    {
        adrc2[0] = tempo2;
        counter18 = 1;
        spaceflag5 = 0;
    }

    for (counter18; counter18 < 200; counter18++)
    {
        scanf("%c", &tempo2);
        if (spaceflag5 == 0 && tempo2 == ' ')
        {
            adrc2[counter18] = '\0';
            counter18 += 250;
        }
        else
        {
            if (tempo2 == '"')
            {
                adrc2[counter18] = '\0';
                counter18 += 250;
            }
            if (tempo2 != '\n')
            {
                adrc2[counter18] = tempo2;
                adrc2[counter18 + 1] = '\0';
            }
            else
            {
                counter18 += 250;
            }
        }
    }
    long long counter19 = 0;
    int tr = -2;
    long long adrcc = 0;
    long long adrcc2 = 0;
    printf("\n");
    FILE *cmp1 = fopen(adrc, "r");
    FILE *cmp2 = fopen(adrc2, "r");
    char cmp1s[100000], cmp2s[100000];
    if (cmp1 == NULL || cmp2 == NULL)
    {
        printf("one or both of the files you intered doesn't exist bro !! \n");
        return;
    }
    while (fgets(cmp1s, 100000, cmp1))
    {
        adrcc++;
    }
    while (fgets(cmp2s, 1000000, cmp2))
    {
        adrcc2++;
    }
    if (adrcc > adrcc2)
    {
        tr = -1;
    }
    fclose(cmp1);
    fclose(cmp2);
    cmp1 = fopen(adrc, "r");
    cmp2 = fopen(adrc2, "r");
    if (tr == -1)
    {
        for (long long pedar = 0; pedar < adrcc2; pedar++)
        {
            fgets(cmp1s, 1000000, cmp1);
            fgets(cmp2s, 1000000, cmp2);
            counter19++;
            if (strcmp(cmp1s, cmp2s) != 0)
            {
                printf("----------------------------line number =>%4lld----------------------------------------\n", counter19);
                printf("file number one :%s \nfile number two :%s", cmp1s, cmp2s);
                printf("\n--------------------------------------------------------------------------------------\n");
            }
        }
        for (long long pedar = 0; pedar < adrcc - adrcc2; pedar++)
        {
            fgets(cmp1s, 1000000, cmp1);
            counter19++;
            printf("----------------------------line number =>%4lld----------------------------------------\n", counter19);
            printf("file number one :%s \nfile number two :doesn't exist", cmp1s);
            printf("\n--------------------------------------------------------------------------------------\n");
        }
    }
    else
    {
        for (long long pedar = 0; pedar < adrcc; pedar++)
        {
            fgets(cmp1s, 1000000, cmp1);
            fgets(cmp2s, 1000000, cmp2);
            counter19++;
            if (strcmp(cmp1s, cmp2s) != 0)
            {
                printf("----------------------------line number =>%4lld----------------------------------------\n", counter19);
                printf("file number one :%s \nfile number two :%s", cmp1s, cmp2s);
                printf("\n--------------------------------------------------------------------------------------\n");
            }
        }
        for (long long pedar = 0; pedar < adrcc2 - adrcc; pedar++)
        {
            fgets(cmp2s, 1000000, cmp2);
            counter19++;
            printf("----------------------------line number =>%4lld----------------------------------------\n", counter19);
            printf("file number two :%s \nfile number one :doesn't exist", cmp2s);
            printf("\n--------------------------------------------------------------------------------------\n");
        }
    }
    fclose(cmp1);
    fclose(cmp2);

    return;
}

int fnd()
{
    int flagcount = 0, flagbyword = 0, flagat = 0, flagall = 0;
    char araa2[6], tempo, str6[5], adrf[200];
    long long counter16, counter15, tedadhorof4, jaygah3, min, atad;
    char matn3[100000];
    int spaceflag4, flagsb = 0, flagsa = 0;
    scanf("%s", &araa2);
    for (int z = 0; z < 6; z++)
    {
        if (araa2[z] != filer[z])
        {
            printf("you should use <<--file>> befor your address dude\n");
            return 0;
        }
    }
    scanf(" ", chert);
    scanf("%c", &tempo);
    if (tempo != '"')
    {
        adrf[0] = tempo;
        counter15 = 1;
        spaceflag4 = 0;
    }

    for (counter15; counter15 < 200; counter15++)
    {
        scanf("%c", &tempo);
        if (spaceflag4 == 0 && tempo == ' ')
        {
            adrf[counter15] = '\0';
            counter15 += 250;
        }
        else
        {
            if (tempo == '"')
            {
                adrf[counter15] = '\0';
                counter15 += 250;
            }
            if (tempo != '\n')
            {
                adrf[counter15] = tempo;
                adrf[counter15 + 1] = '\0';
            }
            else
            {
                counter15 += 250;
            }
        }
    }
    if (spaceflag4 == 1)
        scanf(" ", chert);
    scanf("%s", &str6);
    for (int z = 0; z < 5; z++)
    {
        if (strcmp(str6, "--str"))
        {
            printf("you should use <<--str>> befor your string dude\n");
            return 0;
        }
    }
    scanf(" ", chert);
    gets(matn3);
    min = strlen(matn3);
    char charad[10];
    // printf("%d\n" , strlen(matn3));
    for (long long cono = 0; cono < strlen(matn3); cono++)
    {
        if (matn3[cono] == '-' && matn3[cono + 1] == 'c' && matn3[cono + 2] == 'o' && matn3[cono + 3] == 'u' && matn3[cono + 4] == 'n' && matn3[cono + 5] == 't')
        {
            flagcount = 1;
            if (cono < min)
                min = cono;
        }
        if (matn3[cono] == '-' && matn3[cono + 1] == 'b' && matn3[cono + 2] == 'y' && matn3[cono + 3] == 'w' && matn3[cono + 4] == 'o' && matn3[cono + 5] == 'r' && matn3[cono + 6] == 'd')
        {
            flagbyword = 1;
            if (cono < min)
                min = cono;
        }
        if (matn3[cono] == '-' && matn3[cono + 1] == 'a' && matn3[cono + 2] == 'l' && matn3[cono + 3] == 'l')
        {
            flagall = 1;
            if (cono < min)
                min = cono;
        }
        if (matn3[cono] == '-' && matn3[cono + 1] == 'a' && matn3[cono + 2] == 't')
        {
            for (int t = cono + 4; (matn3[t] != ' ' && matn3[t] != '\0' && matn3[t] != '\n'); t++)
            {
                charad[t - cono - 4] = matn3[t];
                charad[t - cono - 3] = '\0';
            }
            flagat = 1;
            if (cono < min)
                min = cono;
        }
    }
    atad = atoll(charad);
    matn3[min - 1] = '\0';
    if (matn3[0] == '*')
    {
        flagsb = 1;
        shift(matn3, min, 0);
    }
    if (matn3[min - 1] == '*' && matn3[min - 2] != '\\')
    {
        flagsa = 1;
        matn3[min - 1] = '\0';
    }
    for (long long uo = 0; uo < strlen(matn3); uo++)
    {
        if (matn3[uo] == '\\' && matn3[uo + 1] == '*')
        {
            matn3[uo] = '*';
            for (long long ouu = uo + 1; ouu < min; ouu++)
            {
                matn3[ouu] = matn3[ouu + 1];
                if (matn3[ouu + 2] == '\0')
                {
                    matn3[ouu + 1] = '\0';
                    break;
                }
            }
        }
    }
    // printf("%s\n" , matn3);
    FILE *file = fopen(adrf, "r");
    if (file == NULL)
    {
        printf("what the hell the address you intered doesn't exist , astaghforellah bro :(\n");
        fclose(file);
        return 0;
    }
    char *text5;
    long long numbytes6;
    if (file == NULL)
        return 1;

    fseek(file, 0L, SEEK_END);
    numbytes6 = ftell(file);
    fseek(file, 0L, SEEK_SET);

    text5 = (char *)calloc(numbytes6, sizeof(char));
    if (text5 == NULL)
        return 1;

    fread(text5, sizeof(char), numbytes6, file);
    fclose(file);
    char ghavi;
    if (flagall == 0 && flagat == 0 && flagbyword == 0 && flagcount == 0)
    {
        for (long long cono = 0; cono < numbytes6; cono++)
        {
            ghavi = text5[cono + strlen(matn3)];
            text5[strlen(matn3) + cono] = '\0';
            if (strcmp(text5 + cono, matn3) == 0 && flagsb == 0 && flagsa == 0)
            {
                printf("%lld\n", cono);
                text5[cono + strlen(matn3)] = ghavi;
                return 0;
            }
            else if (strcmp(text5 + cono, matn3) == 0 && flagsb == 1 && flagsa == 0)
            {
                long long cono2 = cono;
                while (text5[cono2 - 1] != ' ' && cono2 >= 0 && text5[cono2 - 1] != '\n')
                {
                    cono2--;
                }
                printf("%lld\n", cono2);
                text5[cono + strlen(matn3)] = ghavi;
                return 0;
            }
            else if (strcmp(text5 + cono, matn3) == 0 && flagsb == 0 && flagsa == 1)
            {
                if (ghavi != '\0' && ghavi != EOF)
                {
                    printf("%lld\n", cono);
                    text5[cono + strlen(matn3)] = ghavi;
                    return 0;
                }
                else
                {
                    cono += numbytes6;
                }
            }
            text5[cono + strlen(matn3)] = ghavi;
        }
        printf("the string you intered dosen't exist in the passage :(\n");
    }
    else if (flagall == 0 && flagat == 0 && flagbyword == 1 && flagcount == 0)
    {
        long long scon = 1;
        for (long long cono = 0; cono < numbytes6; cono++)
        {
            ghavi = text5[cono + strlen(matn3)];
            text5[strlen(matn3) + cono] = '\0';
            if (strcmp(text5 + cono, matn3) == 0 && flagsb == 0 && flagsa == 0)
            {
                for (long long zx = 0; zx < cono; zx++)
                {
                    if ((text5[zx] == ' ' || text5[zx] == '\t' || text5[zx] == '\n' || text5[zx] == '\0') && !(text5[zx - 1] == ' ' || text5[zx - 1] == '\t' || text5[zx - 1] == '\n' || text5[zx - 1] == '\0'))
                    {
                        scon++;
                    }
                }
                printf("%lld\n", scon);
                text5[cono + strlen(matn3)] = ghavi;
                return 0;
            }
            else if (strcmp(text5 + cono, matn3) == 0 && flagsb == 1 && flagsa == 0)
            {
                long long cono2 = cono;
                while (text5[cono2 - 1] != ' ' && cono2 >= 0 && text5[cono2 - 1] != '\n')
                {
                    cono2--;
                }
                for (long long zx = 0; zx < cono2; zx++)
                {
                    if ((text5[zx] == ' ' || text5[zx] == '\t' || text5[zx] == '\n' || text5[zx] == '\0') && !(text5[zx - 1] == ' ' || text5[zx - 1] == '\t' || text5[zx - 1] == '\n' || text5[zx - 1] == '\0'))
                    {
                        scon++;
                    }
                }
                printf("%lld\n", scon);
                text5[cono + strlen(matn3)] = ghavi;
                return 0;
            }
            else if (strcmp(text5 + cono, matn3) == 0 && flagsb == 0 && flagsa == 1)
            {
                if (ghavi != '\0' && ghavi != EOF)
                {
                    for (long long zx = 0; zx < cono; zx++)
                    {
                        if ((text5[zx] == ' ' || text5[zx] == '\t' || text5[zx] == '\n' || text5[zx] == '\0') && !(text5[zx - 1] == ' ' || text5[zx - 1] == '\t' || text5[zx - 1] == '\n' || text5[zx - 1] == '\0'))
                        {
                            scon++;
                        }
                    }
                    printf("%lld\n", scon);
                    text5[cono + strlen(matn3)] = ghavi;
                    return 0;
                }
                else
                {
                    cono += numbytes6;
                }
            }
            text5[cono + strlen(matn3)] = ghavi;
        }
        printf("the string you intered dosen't exist in the passage :(\n");
    }
    else if (flagall == 1 && flagat == 0 && flagbyword == 0 && flagcount == 0)
    {
        int flagv = 0;
        for (long long cono = 0; cono < numbytes6; cono++)
        {

            ghavi = text5[cono + strlen(matn3)];
            text5[strlen(matn3) + cono] = '\0';
            if (strcmp(text5 + cono, matn3) == 0 && flagsb == 0 && flagsa == 0)
            {
                printf("%lld ", cono);
                text5[cono + strlen(matn3)] = ghavi;
                flagv = 1;
                continue;
            }
            else if (strcmp(text5 + cono, matn3) == 0 && flagsb == 1 && flagsa == 0)
            {
                long long cono2 = cono;
                while (text5[cono2 - 1] != ' ' && cono2 >= 0 && text5[cono2 - 1] != '\n')
                {
                    cono2--;
                }
                printf("%lld ", cono2);
                text5[cono + strlen(matn3)] = ghavi;
                flagv = 1;
                continue;
            }
            else if (strcmp(text5 + cono, matn3) == 0 && flagsb == 0 && flagsa == 1)
            {
                if (ghavi != '\0' && ghavi != EOF)
                {
                    printf("%lld ", cono);
                    text5[cono + strlen(matn3)] = ghavi;
                    flagv = 1;
                    continue;
                }
                else
                {
                    cono += numbytes6;
                }
            }
            text5[cono + strlen(matn3)] = ghavi;
        }
        if (flagv != 0)
            printf("\n");
        if (flagv == 0)
            printf("the string you intered dosen't exist in the passage :(\n");
    }
    else if (flagall == 0 && flagat == 0 && flagcount == 1)
    {
        long long flagv = 0;
        for (long long cono = 0; cono < numbytes6; cono++)
        {

            ghavi = text5[cono + strlen(matn3)];
            text5[strlen(matn3) + cono] = '\0';
            if (strcmp(text5 + cono, matn3) == 0 && flagsb == 0 && flagsa == 0)
            {
                // printf("%lld " , cono);
                text5[cono + strlen(matn3)] = ghavi;
                flagv++;
                continue;
            }
            else if (strcmp(text5 + cono, matn3) == 0 && flagsb == 1 && flagsa == 0)
            {
                long long cono2 = cono;
                while (text5[cono2 - 1] != ' ' && cono2 >= 0 && text5[cono2 - 1] != '\n')
                {
                    cono2--;
                }
                // printf("%lld " , cono2);
                text5[cono + strlen(matn3)] = ghavi;
                flagv++;
                continue;
            }
            else if (strcmp(text5 + cono, matn3) == 0 && flagsb == 0 && flagsa == 1)
            {
                if (ghavi != '\0' && ghavi != EOF)
                {
                    // printf("%lld " , cono);
                    text5[cono + strlen(matn3)] = ghavi;
                    flagv++;
                    continue;
                }
                else
                {
                    cono += numbytes6;
                }
            }
            text5[cono + strlen(matn3)] = ghavi;
        }
        printf("%lld\n", flagv);
        return 0;
    }

    else if (flagall == 0 && flagat == 1 && flagbyword == 0 && flagcount == 0)
    {
        long long flagv = 0;
        for (long long cono = 0; cono < numbytes6; cono++)
        {

            ghavi = text5[cono + strlen(matn3)];
            text5[strlen(matn3) + cono] = '\0';
            if (strcmp(text5 + cono, matn3) == 0 && flagsb == 0 && flagsa == 0)
            {
                flagv++;
                if (flagv == atad)
                {
                    printf("%lld\n", cono);
                    text5[cono + strlen(matn3)] = ghavi;
                    return 0;
                }
                else
                {
                    text5[cono + strlen(matn3)] = ghavi;
                    continue;
                }
            }
            else if (strcmp(text5 + cono, matn3) == 0 && flagsb == 1 && flagsa == 0)
            {
                long long cono2 = cono;
                while (text5[cono2 - 1] != ' ' && cono2 >= 0 && text5[cono2 - 1] != '\n')
                {
                    cono2--;
                }
                flagv++;
                if (flagv == atad)
                {
                    printf("%lld\n", cono2);
                    text5[cono + strlen(matn3)] = ghavi;
                    return 0;
                }
                else
                {
                    text5[cono + strlen(matn3)] = ghavi;
                    continue;
                }
            }
            else if (strcmp(text5 + cono, matn3) == 0 && flagsb == 0 && flagsa == 1)
            {
                if (ghavi != '\0' && ghavi != EOF)
                {
                    flagv++;
                    if (flagv == atad)
                    {
                        printf("%lld\n", cono);
                        text5[cono + strlen(matn3)] = ghavi;
                        return 0;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    cono += numbytes6;
                }
            }
            text5[cono + strlen(matn3)] = ghavi;
        }
        printf("the index you intered dosen't exist in the passage :(\n");
    }
    else if (flagall == 1 && flagat == 1)
    {
        printf("sorry , the options -all and -at can't be combined together:__(\n");
        return 0;
    }
    else if (flagall == 1 && flagat == 0 && flagbyword == 1 && flagcount == 0)
    {
        int flagv = 0;
        long long zaq;
        for (long long cono = 0; cono < numbytes6; cono++)
        {

            ghavi = text5[cono + strlen(matn3)];
            text5[strlen(matn3) + cono] = '\0';
            if (strcmp(text5 + cono, matn3) == 0 && flagsb == 0 && flagsa == 0)
            {
                zaq = 0;
                for (long long zaw = 0; zaw < cono; zaw++)
                {
                    if ((text5[zaw] == ' ' || text5[zaw] == '\t' || text5[zaw] == '\n' || text5[zaw] == '\0') && !(text5[zaw - 1] == ' ' || text5[zaw - 1] == '\t' || text5[zaw - 1] == '\n' || text5[zaw - 1] == '\0'))
                    {
                        zaq++;
                    }
                }
                printf("%lld ", zaq);
                text5[cono + strlen(matn3)] = ghavi;
                flagv = 1;
                continue;
            }
            else if (strcmp(text5 + cono, matn3) == 0 && flagsb == 1 && flagsa == 0)
            {
                long long cono2 = cono;
                while (text5[cono2 - 1] != ' ' && cono2 >= 0 && text5[cono2 - 1] != '\n')
                {
                    cono2--;
                }
                zaq = 0;
                for (long long zaw = 0; zaw < cono2; zaw++)
                {
                    if ((text5[zaw] == ' ' || text5[zaw] == '\t' || text5[zaw] == '\n' || text5[zaw] == '\0') && !(text5[zaw - 1] == ' ' || text5[zaw - 1] == '\t' || text5[zaw - 1] == '\n' || text5[zaw - 1] == '\0'))
                    {
                        zaq++;
                    }
                }
                printf("%lld ", zaq);
                text5[cono + strlen(matn3)] = ghavi;
                flagv = 1;
                continue;
            }
            else if (strcmp(text5 + cono, matn3) == 0 && flagsb == 0 && flagsa == 1)
            {
                if (ghavi != '\0' && ghavi != EOF)
                {
                    zaq = 0;
                    for (long long zaw = 0; zaw < cono; zaw++)
                    {
                        if ((text5[zaw] == ' ' || text5[zaw] == '\t' || text5[zaw] == '\n' || text5[zaw] == '\0') && !(text5[zaw - 1] == ' ' || text5[zaw - 1] == '\t' || text5[zaw - 1] == '\n' || text5[zaw - 1] == '\0'))
                        {
                            zaq++;
                        }
                    }
                    printf("%lld ", zaq);
                    text5[cono + strlen(matn3)] = ghavi;
                    flagv = 1;
                    continue;
                }
                else
                {
                    cono += numbytes6;
                }
            }
            text5[cono + strlen(matn3)] = ghavi;
        }
        if (flagv != 0)
            printf("\n");
        if (flagv == 0)
            printf("the string you intered dosen't exist in the passage :(\n");
    }

    else if (flagall == 0 && flagat == 1 && flagbyword == 1 && flagcount == 0)
    {
        long long flagv = 0;
        long long zaq = 0;
        for (long long cono = 0; cono < numbytes6; cono++)
        {

            ghavi = text5[cono + strlen(matn3)];
            text5[strlen(matn3) + cono] = '\0';
            if (strcmp(text5 + cono, matn3) == 0 && flagsb == 0 && flagsa == 0)
            {
                flagv++;
                if (flagv == atad)
                {
                    zaq = 0;
                    for (long long zaw = 0; zaw < cono; zaw++)
                    {
                        if ((text5[zaw] == ' ' || text5[zaw] == '\t' || text5[zaw] == '\n' || text5[zaw] == '\0') && !(text5[zaw - 1] == ' ' || text5[zaw - 1] == '\t' || text5[zaw - 1] == '\n' || text5[zaw - 1] == '\0'))
                        {
                            zaq++;
                        }
                    }
                    printf("%lld\n", zaq + 1);
                    text5[cono + strlen(matn3)] = ghavi;
                    return 0;
                }
                else
                {
                    text5[cono + strlen(matn3)] = ghavi;
                    continue;
                }
            }
            else if (strcmp(text5 + cono, matn3) == 0 && flagsb == 1 && flagsa == 0)
            {
                long long cono2 = cono;
                while (text5[cono2 - 1] != ' ' && cono2 >= 0 && text5[cono2 - 1] != '\n')
                {
                    cono2--;
                }
                flagv++;
                if (flagv == atad)
                {
                    zaq = 0;
                    for (long long zaw = 0; zaw < cono2; zaw++)
                    {
                        if ((text5[zaw] == ' ' || text5[zaw] == '\t' || text5[zaw] == '\n' || text5[zaw] == '\0') && !(text5[zaw - 1] == ' ' || text5[zaw - 1] == '\t' || text5[zaw - 1] == '\n' || text5[zaw - 1] == '\0'))
                        {
                            zaq++;
                        }
                    }
                    printf("%lld\n", zaq + 1);
                    text5[cono + strlen(matn3)] = ghavi;
                    return 0;
                }
                else
                {
                    text5[cono + strlen(matn3)] = ghavi;
                    continue;
                }
            }
            else if (strcmp(text5 + cono, matn3) == 0 && flagsb == 0 && flagsa == 1)
            {
                if (ghavi != '\0' && ghavi != EOF)
                {
                    flagv++;
                    if (flagv == atad)
                    {
                        zaq = 0;
                        for (long long zaw = 0; zaw < cono; zaw++)
                        {
                            if ((text5[zaw] == ' ' || text5[zaw] == '\t' || text5[zaw] == '\n' || text5[zaw] == '\0') && !(text5[zaw - 1] == ' ' || text5[zaw - 1] == '\t' || text5[zaw - 1] == '\n' || text5[zaw - 1] == '\0'))
                            {
                                zaq++;
                            }
                        }
                        printf("%lld\n", zaq + 1);
                        text5[cono + strlen(matn3)] = ghavi;
                        return 0;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    cono += numbytes6;
                }
            }
            text5[cono + strlen(matn3)] = ghavi;
        }
        printf("the index you intered dosen't exist in the passage :(\n");
    }
    else if ((flagall == 1 && flagat == 1) || (flagat == 1 && flagbyword == 1) || (flagat == 1 && flagcount == 1))
    {
        printf("sorry , the options you choose can't be combined together:__(\n");
        return 0;
    }
}

int runcommand(int cmdnum)
{
    if (cmdnum == 0)
    {
        print_commands();
    }
    else if (cmdnum == 1)
    {
        maf();
    }
    else if (cmdnum == 2)
    {
        insert();
    }
    else if (cmdnum == 3)
    {
        cat();
    }
    else if (cmdnum == 4)
    {
        rmv();
    }
    else if (cmdnum == 5)
    {
        cop(0);
    }
    else if (cmdnum == 6)
    {
        cop(1);
    }
    else if (cmdnum == 7)
    {
        pst();
    }
    else if (cmdnum == 8)
    {
        fnd();
    }
    else if (cmdnum == 13)
    {
        cmp();
    }
}

void shift(char zt[], long long a, long long z)
{
    long long bpedar = strlen(zt);
    for (z; z < a; z++)
    {
        zt[z] = zt[z + 1];
    }
    zt[bpedar - 1] = '\0';
}

void pardazesh(char mt[], long long h)
{
    if (mt[0] == '"')
    {
        // printf("yes , %c" , mt[h]);
        shift(mt, h, 0);
        mt[h - 1] = '\0';
    }
    mt[h + 1] = '\0';
    if (mt[h] == '"' && mt[h - 1] == '/')
    { // printf("yessss");
        mt[h - 1] = '"';
        mt[h] = '\0';
    }
    if (mt[0] == '/' && mt[1] == '"')
    {
        shift(mt, h, 0);
    }

    for (long long mat = 0; mat <= h; mat++)
    {
        if (mt[mat] == 92 && mt[mat + 1] == 92)
        {
            shift(mt, h, mat);
            mat += 1;
            continue;
        }
        if (mt[mat] == 92 && mt[mat + 1] == 'n')
        {
            mt[mat] = '\n';
            shift(mt, h, mat + 1);
            continue;
        }
    }
    // printf("\n*%s*\n", mt);
}

long long sakhtmatn(char txt[], char nim[], char nim2[], int a, int b)
{
    int khatk = 1;
    int chark = 0;
    long long pp = 0;
    while (khatk < a && txt[pp] != '\0')
    {
        nim[pp] = txt[pp];
        nim[pp + 1] = '\0';
        if (txt[pp] == '\n')
        {
            khatk++;
        }
        pp++;
    }
    if (txt[pp] == '\0')
    {
        printf("the position you intered doesn't exist in the passage :(( \n");
        return -100;
    }
    if (khatk == a)
    {
        for (int zz = 0; zz < b; zz++)
        {
            if (txt[pp + zz] != '\n' && txt[pp + zz] != '\0')
            {
                nim[pp + zz] = txt[pp + zz];
                nim[pp + zz + 1] = '\0';
            }
            else if (txt[pp + zz] == '\0' || txt[pp + zz] == '\n')
            {
                printf("the position you intered doesn't exist in the passage :(( \n");
                return -100;
            }
        }
    }
    for (long long gg = pp + b; gg < strlen(txt); gg++)
    {
        nim2[gg - pp - b] = txt[gg];
        nim2[gg - pp - b + 1] = '\0';
    }
    return pp;
}

int insert()
{
    long long tedadhorof, jaygah, shoro;
    int posline = 0, poschar = 0;
    char kha[10];
    char po[10];
    int khat, kar, khatco = 1, karco = 0;
    int spaceflag = 1;
    char adressin[100];
    int counter5 = 0;
    long counter6 = 0;
    char tempin;
    char matn[1000000], matnfnl[1000000];
    char araa[6], strx[6];
    char pos[5];
    scanf("%s", &araa);
    for (int z = 0; z < 6; z++)
    {
        if (araa[z] != filer[z])
        {
            printf("you should use <<--file>> befor your address dude\n");
            return 0;
        }
    }
    scanf(" ", chert);
    scanf("%c", &tempin);
    if (tempin != '"')
    {
        adressin[0] = tempin;
        counter5 = 1;
        spaceflag = 0;
    }

    for (counter5; counter5 < 100; counter5++)
    {
        scanf("%c", &tempin);
        if (spaceflag == 0 && tempin == ' ')
        {
            adressin[counter5] = '\0';
            counter5 += 150;
        }
        else
        {
            if (tempin == '"')
            {
                adressin[counter5] = '\0';
                counter5 += 150;
            }
            if (tempin != '\n')
            {
                adressin[counter5] = tempin;
                adressin[counter5 + 1] = '\0';
            }
            else
            {
                counter5 += 150;
            }
        }
    }
    if (spaceflag == 1)
        scanf(" ", chert);
    scanf("%s", &strx);
    for (int z = 0; z < 5; z++)
    {
        if (strx[z] != str[z])
        {
            printf("you should use <<--str>> befor your string dude\n");
            return 0;
        }
    }
    scanf(" ", chert);

    scanf("%c", &matn[counter6]);
    while (matn[counter6] != '\n')
    {
        tedadhorof = counter6;
        counter6++;
        scanf("%c", &matn[counter6]);
    }
    matn[counter6] = '\0';
    // printf("%lld\n" , tedadhorof);
    for (long long c = tedadhorof; c >= 0; c--)
    {
        if (matn[c] == ':')
        {
            jaygah = c;
        }
    }
    for (long long q = jaygah; q >= 0; q--)
    {
        if (matn[q] == 's' && matn[q - 1] == 'o' && matn[q - 2] == 'p' && matn[q - 3] == '-' && matn[q - 4] == '-')
        {
            shoro = q;
            q -= 1000000;
        }
        else if (q < 4)
        {
            printf("where is your <<--pos>> !!\n");
            return 0;
        }
    }
    for (long long q = shoro + 2; q < jaygah; q++)
    {
        kha[q - shoro - 2] = matn[q];
        kha[q - shoro - 1] = '\0';
    }
    for (long long q = jaygah + 1; q <= tedadhorof; q++)
    {
        po[q - jaygah - 1] = matn[q];
        po[q - jaygah] = '\0';
    }
    matn[shoro - 5] = '\0';
    int dd = atoi(kha);
    if (dd == -1)
    {
        printf("where are positions?? \n");
        return 0;
    }
    dd = atoi(po);
    if (dd == -1)
    {
        printf("where are positions?? \n");
        return 0;
    }
    khat = atoi(kha);
    kar = atoi(po);
    FILE *abc = fopen(adressin, "r");
    if (abc == NULL)
    {
        printf("what the hell the address you intered doesn't exist , astaghforellah bro :(\n");
        fclose(abc);
        return 0;
    }
    fclose(abc);
    char cc;
    pardazesh(matn, shoro - 6);
    // printf("%s\n" , matn);
    FILE *textfile;
    char *text;
    long long numbytes;

    textfile = fopen(adressin, "r");
    if (textfile == NULL)
        return 1;

    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);

    text = (char *)calloc(numbytes, sizeof(char));
    if (text == NULL)
        return 1;

    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);

    // printf("%s\n" ,text);
    char *nime1 = (char *)calloc(numbytes + 1000000, sizeof(char));
    char *nime2 = (char *)calloc(numbytes + 1000000, sizeof(char));
    for (long long nbn = 0; nbn < numbytes; nbn++)
    {
        nime1[nbn] = '\0';
        nime2[nbn] = '\0';
    }
    if (khat == 1 && kar == 0 && strlen(text) == 0)
    {
        FILE *fptr = fopen(adressin, "w");
        fprintf(fptr, "%s%s", matn, text);
        fclose(fptr);
        return 0;
    }
    if (sakhtmatn(text, nime1, nime2, khat, kar) == -100)
    {
        return 0;
    }
    // printf("%s\n%s" , nime1 , nime2);
    FILE *fptr = fopen(adressin, "w");
    fprintf(fptr, "%s%s%s", nime1, matn, nime2);
    fclose(fptr);
}

long long remover(char *tx, int arr, int brr)
{
    int khatk2 = 1;
    int chark2 = 0;
    long long pp2 = 0;
    while (khatk2 < arr && tx[pp2] != '\0')
    {
        if (tx[pp2] == '\n')
        {
            khatk2++;
        }
        pp2++;
    }
    if (tx[pp2] == '\0')
    {
        return pp2;
    }
    if (khatk2 == arr)
    {
        for (int zz = 0; zz < brr; zz++)
        {
            if (tx[pp2 + zz] != '\n' && tx[pp2 + zz] != '\0')
            {
                if (zz == brr - 1)
                {
                    return pp2 + zz;
                }
            }
            else if (tx[pp2 + zz] == '\0' || tx[pp2 + zz] == '\n')
            {
                return pp2 + zz;
            }
        }
    }
}

int cop(int flager)
{
    char adco[100];
    char arc[6], str3[5];
    char posss[5];
    char tet;
    int counter13, spaceflag3, poskh2, posek2, size3, dire2;
    scanf("%s", &arc);
    for (int v = 0; v < 6; v++)
    {
        if (arc[v] != filer[v])
        {
            printf("you should use <<--file>> befor your address dude\n");
            return 0;
        }
    }
    scanf(" ", chert);
    scanf("%c", &tet);
    if (tet != '"')
    {
        adco[0] = tet;
        counter13 = 1;
        spaceflag3 = 0;
    }

    for (counter13; counter13 < 100; counter13++)
    {
        scanf("%c", &tet);
        if (spaceflag3 == 0 && tet == ' ')
        {
            adco[counter13] = '\0';
            counter13 += 150;
        }
        else
        {
            if (tet == '"')
            {
                adco[counter13] = '\0';
                counter13 += 150;
            }
            if (tet != '\n')
            {
                adco[counter13] = tet;
                adco[counter13 + 1] = '\0';
            }
            else
            {
                counter13 += 150;
            }
        }
    }
    if (spaceflag3 == 1)
        scanf(" ", chert);
    scanf("%s", &str3);
    for (int z = 0; z < 5; z++)
    {
        if (str3[z] != poser[z])
        {
            printf("you should use <<--pos>> befor your string dude\n");
            return 0;
        }
    }
    scanf(" ", chert);
    if (scanf("%d:%d", &poskh2, &posek2) == 0)
        printf("are you god damn serious ??? where is your position ?? :(\n");
    scanf(" ", chert);
    posek2++;
    scanf("%s", &str3);
    if (strcmp(str3, sizer) != 0)
    {
        printf("you should use <<--size>> befor your size !!! \n");
    }
    scanf(" ", chert);
    scanf("%d", &size3);
    scanf(" -%c", &tet);
    if (tet == 'f')
    {
        dire2 = 1;
    }
    else if (tet == 'b')
    {
        dire2 = -1;
    }
    else
    {
        printf("direction isn't valid , it most be either f or b the abrvations of backward and forward ;)\n");
        return 0;
    }

    FILE *abk = fopen(adco, "r");
    if (abk == NULL)
    {
        printf("what the hell the address you intered doesn't exist , astaghforellah bro :(\n");
        fclose(abk);
        return 0;
    }
    fclose(abk);
    FILE *textfile3;
    char *text3;
    long long numbytes3;

    textfile3 = fopen(adco, "r");
    if (textfile3 == NULL)
        return 1;

    fseek(textfile3, 0L, SEEK_END);
    numbytes3 = ftell(textfile3);
    fseek(textfile3, 0L, SEEK_SET);

    text3 = (char *)calloc(numbytes3, sizeof(char));
    char *text3x = (char *)calloc(numbytes3, sizeof(char));
    if (text3 == NULL)
        return 1;
    clipboard = (char *)calloc(numbytes3, sizeof(char));
    for (long long nbn2 = 0; nbn2 < numbytes3; nbn2++)
    {
        clipboard[nbn2] = '\0';
        text3x[nbn2] = '\0';
    }

    fread(text3, sizeof(char), numbytes3, textfile3);
    fclose(textfile3);
    long long noghte2 = remover(text3, poskh2, posek2) - 1;
    if (dire2 == -1)
    {
        clipboard[size3] = '\0';
        for (int ss = 0; ss < size3; ss++)
        {
            if (text3[noghte2 - ss] != '\0')
                clipboard[size3 - ss - 1] = text3[noghte2 - ss];
            else
            {
                ss += size3 + 2;
            }
        }
    }
    else if (dire2 == 1)
    {
        clipboard[size3] = '\0';
        for (int ss = 0; ss < size3; ss++)
        {
            if (text3[noghte2 - ss + size3] != '\0')
                clipboard[size3 - ss - 1] = text3[noghte2 - ss + size3];
            else
            {
                ss += size3 + 2;
            }
        }
    }
    if (flager == 1)
    {
        if (dire2 == -1)
        {
            noghte2 -= size3;
            dire2 = 1;
        }
    }
    if (dire2 == 1)
    {
        long long oxx2 = 0;
        for (long long ox2 = 0; ox2 < numbytes3; ox2++)
        {
            if (ox2 > noghte2 + size3 || ox2 <= noghte2)
            {
                text3x[oxx2] = text3[ox2];
                oxx2++;
            }
        }
        FILE *fptr3 = fopen(adco, "w");
        fprintf(fptr3, "%s", text3x);
        fclose(fptr3);
    }
    if (flager == 0)
    {
        FILE *fptr4 = fopen(adco, "w");
        fprintf(fptr4, "%s", text3);
        fclose(fptr4);
    }
    return 0;
}

int rmv()
{
    // removetstr –file /root/file1.txt –pos 2:1 -size 3 -b
    char addressrm[100];
    char ar[6], str2[5];
    char poss[5];
    char te;
    int counter12, spaceflag2, poskh, posek, size, dire;
    scanf("%s", &ar);
    for (int v = 0; v < 6; v++)
    {
        if (ar[v] != filer[v])
        {
            printf("you should use <<--file>> befor your address dude\n");
            return 0;
        }
    }
    scanf(" ", chert);
    scanf("%c", &te);
    if (te != '"')
    {
        addressrm[0] = te;
        counter12 = 1;
        spaceflag2 = 0;
    }

    for (counter12; counter12 < 100; counter12++)
    {
        scanf("%c", &te);
        if (spaceflag2 == 0 && te == ' ')
        {
            addressrm[counter12] = '\0';
            counter12 += 150;
        }
        else
        {
            if (te == '"')
            {
                addressrm[counter12] = '\0';
                counter12 += 150;
            }
            if (te != '\n')
            {
                addressrm[counter12] = te;
                addressrm[counter12 + 1] = '\0';
            }
            else
            {
                counter12 += 150;
            }
        }
    }
    if (spaceflag2 == 1)
        scanf(" ", chert);
    scanf("%s", &str2);
    for (int z = 0; z < 5; z++)
    {
        if (str2[z] != poser[z])
        {
            printf("you should use <<--pos>> befor your string dude\n");
            return 0;
        }
    }
    scanf(" ", chert);
    if (scanf("%d:%d", &poskh, &posek) == 0)
        printf("are you god damn serious ??? where is your position ?? :(\n");
    scanf(" ", chert);
    posek++;
    scanf("%s", &str2);
    if (strcmp(str2, sizer) != 0)
    {
        printf("you should use <<--size>> befor your size !!! \n");
    }
    scanf(" ", chert);
    scanf("%d", &size);
    scanf(" -%c", &te);
    if (te == 'f')
    {
        dire = 1;
    }
    else if (te == 'b')
    {
        dire = -1;
    }
    else
    {
        printf("direction isn't valid , it most be either f or b the abrvations of backward and forward ;)\n");
    }

    FILE *abd = fopen(addressrm, "r");
    if (abd == NULL)
    {
        printf("what the hell the address you intered doesn't exist , astaghforellah bro :(\n");
        fclose(abd);
        return 0;
    }
    fclose(abd);
    FILE *textfile2;
    char *text2;
    long long numbytes2;

    textfile2 = fopen(addressrm, "r");
    if (textfile2 == NULL)
        return 1;

    fseek(textfile2, 0L, SEEK_END);
    numbytes2 = ftell(textfile2);
    fseek(textfile2, 0L, SEEK_SET);

    text2 = (char *)calloc(numbytes2, sizeof(char));
    char *text2x = (char *)calloc(numbytes2 - size, sizeof(char));
    if (text2 == NULL)
        return 1;

    fread(text2, sizeof(char), numbytes2, textfile2);
    fclose(textfile2);
    long long noghte = remover(text2, poskh, posek) - 1;
    if (dire == -1)
    {
        long long oxx = 0;
        for (long long ox = 0; ox < numbytes2; ox++)
        {
            if (ox <= noghte - size || ox > noghte)
            {
                text2x[oxx] = text2[ox];
                oxx++;
            }
        }
    }
    else if (dire == 1)
    {
        long long oxx = 0;
        for (long long ox = 0; ox < numbytes2; ox++)
        {
            if (ox > noghte + size || ox <= noghte)
            {
                text2x[oxx] = text2[ox];
                oxx++;
            }
        }
    }

    FILE *fptr3 = fopen(addressrm, "w");
    fprintf(fptr3, "%s", text2x);
    fclose(fptr3);
}

int pst()
{
    char adp[100];
    char arc[6], str3[5];
    char posss[5];
    char tetr;
    int counter14, spaceflag4, poskh3, posek4;
    scanf("%s", &arc);
    for (int v = 0; v < 6; v++)
    {
        if (arc[v] != filer[v])
        {
            printf("you should use <<--file>> befor your address dude\n");
            return 0;
        }
    }
    scanf(" ", chert);
    scanf("%c", &tetr);
    if (tetr != '"')
    {
        adp[0] = tetr;
        counter14 = 1;
        spaceflag4 = 0;
    }

    for (counter14; counter14 < 100; counter14++)
    {
        scanf("%c", &tetr);
        if (spaceflag4 == 0 && tetr == ' ')
        {
            adp[counter14] = '\0';
            counter14 += 150;
        }
        else
        {
            if (tetr == '"')
            {
                adp[counter14] = '\0';
                counter14 += 150;
            }
            if (tetr != '\n')
            {
                adp[counter14] = tetr;
                adp[counter14 + 1] = '\0';
            }
            else
            {
                counter14 += 150;
            }
        }
    }
    if (spaceflag4 == 1)
        scanf(" ", chert);
    scanf("%s", &str3);
    for (int z = 0; z < 5; z++)
    {
        if (str3[z] != poser[z])
        {
            printf("you should use <<--pos>> befor your string dude\n");
            return 0;
        }
    }
    scanf(" ", chert);
    if (scanf("%d:%d", &poskh3, &posek4) == 0)
    {
        printf("are you god damn serious ??? where is your position ?? :(\n");
        return 0;
    }
    FILE *abz = fopen(adp, "r");
    if (abz == NULL)
    {
        printf("what the hell the address you intered doesn't exist , astaghforellah bro :(\n");
        fclose(abz);
        return 0;
    }
    // printf("%s\n%s\n%s\n%s\n%d%d" , arc , str3 , adp , poskh3 , posek4);
    FILE *textfile4;
    char *text4;
    long long numbytes4;

    textfile4 = fopen(adp, "r");
    if (textfile4 == NULL)
        return 1;

    fseek(textfile4, 0L, SEEK_END);
    numbytes4 = ftell(textfile4);
    fseek(textfile4, 0L, SEEK_SET);

    text4 = (char *)calloc(numbytes4, sizeof(char));
    char *text4x = (char *)calloc(numbytes4, sizeof(char));
    char *text4xx = (char *)calloc(numbytes4, sizeof(char));
    if (text4 == NULL)
        return 1;
    for (long long nbn2 = 0; nbn2 < numbytes4; nbn2++)
    {
        text4xx[nbn2] = '\0';
        text4x[nbn2] = '\0';
    }

    fread(text4, sizeof(char), numbytes4, textfile4);
    fclose(textfile4);
    long long noghte3 = remover(text4, poskh3, posek4);
    // printf("%lld" , noghte3);
    for (long long nbn3 = 0; nbn3 < numbytes4; nbn3++)
    {
        if (nbn3 <= noghte3)
        {
            text4x[nbn3] = text4[nbn3];
            text4x[nbn3 + 1] = '\0';
        }
        if (nbn3 > noghte3)
        {
            text4xx[nbn3 - noghte3] = text4[nbn3];
            text4xx[nbn3 - noghte3 + 1] = '\0';
        }
    }
    FILE *abb = fopen(adp, "w");
    fprintf(abb, "%s%s%s", text4x, clipboard, text4xx);
    fclose(abb);
}

void print_commands()
{
    printf("to made a file :\t\t maf \n");
    printf("to insert a text :\t\t iat \n");
    printf("to show what's in :\t\t cat \n");
    printf("to remove st from a file :\t rmv \n");
    printf("to copy an str from sw :\t cop \n");
    printf("to cut an str from sw :\t\t cut \n");
    printf("to paste an str in sw :\t\t pst \n");
    printf("to find an str in a file :\t fnd \n");
    printf("to replace an str in a file :\t rpc \n");
    printf("to grep an str in sw :\t\t grp \n");
    printf("to undo the previous move :\t und \n");
    printf("to closing pairs :\t\t clp \n");
    printf("to compare text in two files :\t cmp \n");
    printf("to show the directory tree :\t std \n");
    printf("to do fog :\t\t\t fog \n");
    printf("pleas note that an empty space is needed end of each command !!! \n");
}

void zeromark(int ara[], int n)
{
    for (int qq = 0; qq < n; qq++)
    {
        ara[qq] = 0;
    }
}

int checkval(char a, char b, char c, char d)
{
    int fl = 0;
    char ash;
    for (int i = 0; i < 16; i++)
    {
        if ((a == cmd[i][0]) && (b == cmd[i][1]) && (c == cmd[i][2]) && (d == cmd[i][3]))
        {
            runcommand(i);
            fl = 1;
            return 0;
        }
    }
    if (fl == 0)
    {
        printf("command isn't valid , try again or see command palette with <<prc >>\n");
        scanf("%c", &ash);
        while (ash != '\n')
        {
            scanf("%c", &ash);
        }
        return 0;
    }
}

int get_command()
{
    char x, y, z, u;
    scanf("%c%c%c%c", &x, &y, &z, &u);
    checkval(x, y, z, u);
}

int main()
{
    "\x1b[32m";
    printf("\t\t#########################################################\n");
    printf("\t\t#                                                       #\n");
    printf("\t\t#                                                       #\n");
    printf("\t\t#             welcome to my project habibi              #\n");
    printf("\t\t#                                                       #\n");
    printf("\t\t#                                                       #\n");
    printf("\t\t#########################################################\n");
    printf("if you are a noobie and dont know the commands you can use <<prc >> command to see them :)\n\n");
    "\x1b[0m";
    // clipboard = "salam man be to yar ghadimi";
    get_command();
    while (1)
    {
        scanf("\n", chert);
        get_command();
    }
}
