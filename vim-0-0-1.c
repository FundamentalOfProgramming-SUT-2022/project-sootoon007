#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <math.h>
#include <windows.h>

int cmdflag[16];
char filer[6] = {'-' , '-' , 'f' , 'i' , 'l' , 'e'};
char str[5] = {'-' , '-' , 's' , 't' , 'r'};
char poser[5] = {'-' , '-' , 'p' , 'o' , 's'};
char sizer[5] = {'-' , 's' , 'i' , 'z' , 'e'};
char addressrep[100][100];


void zeroaddress(){
    for ( int counter1 = 0 ; counter1 < 10000 ; counter1++){
        addressrep[counter1/100][counter1%100] = NULL ;
    }
}
int checkval(char a , char b , char c , char d);
int get_command();
int runcommand(int cmdnum);
void print_commands();

void addressmaker(int i , int j , char adress[]) {
    for ( int jj = 0 ; jj < j ; jj++){
         addressrep[i][jj] = adress[jj];
         addressrep[i][jj+1] = '\0' ;
    }
     
}

char cmd[16][4]={
'p' , 'r' , 'c' , ' ',
'm' , 'a' , 'f' , ' ',
'i' , 'a' , 't' , ' ',
'c' , 'a' , 't' , ' ',
'r' , 'm' , 'v' , ' ',
'c' , 'o' , 'p' , ' ',
'c' , 'u' , 't' , ' ',
'p' , 's' , 't' , ' ',
'f' , 'n' , 'd' , ' ',
'r' , 'p' , 'c' , ' ',
'g' , 'r' , 'p' , ' ',
'u' , 'n' , 'd' , ' ',
'c' , 'l' , 'p' , ' ',
'c' , 'm' , 'p' , ' ',
's' , 'd' , 't' , ' ',
'f' , 'o' , 'g' , ' '
};
int flag = 0 ;


int isorbe(char addd[]){
    int check = fopen(addd , "r");
    if ( check != 0){
        printf("what are you doing dude , file already exist !! \n");
        fclose(addd);
    }
        FILE * ptr =fopen(addd , "w");
        fclose(ptr);
        
}


int maf(){
    zeroaddress();
    char temp;
    int a = 0 , flag = 0;
    char aray[6];
    char address[100];
    scanf("%s" , &aray);
    for(int z=0 ; z < 6 ; z++){
        if(aray[z] != filer[z]){
            printf("you should use <<--file>> befor your address dude\n");
            return 0;
        }
    }
    scanf(" ");
    int counter2 = 0;
    scanf("%c" , &temp);
        if(temp != '"'){
            address[0] = temp ; 
            counter2 = 1;
        }

    for (counter2 ; counter2 < 100 ; counter2++){
        scanf("%c" , &temp );
        if(temp == '"'){
            address[counter2] = '\0' ;
            counter2 += 150 ;
        }
        if(temp != '\n' ){
            address[counter2] = temp ;
            address[counter2+1]='\0';
        }
        else{
            counter2 += 150 ;
        }
    }
    for(int counter1 = 0 ; counter1 < 100 ; counter1++){
        if(address[counter1] == '/'){
            addressmaker(a , counter1  , address);
            a++;
            continue;
        }
    }
    a = 0;
    for (int addr = 0 ; addr < 100 && addressrep[addr][0] != NULL; addr++){
        int ret = 0;
        ret = mkdir(addressrep[addr] , 0755);
        }
        isorbe(address);

}

int cat(){
    char tempcat ;
    char tempscan ;
    char addresscat[100] , cats[1000000];
    char aray2[6];
    scanf("%s" , &aray2);
    for(int z=0 ; z < 6 ; z++){
        if(aray2[z] != filer[z]){
            printf("you should use <<--file>> befor your address dude\n");
            return 0;
        }
    }
    scanf(" ");
    int counter3 = 0;
    scanf("%c" , &tempcat);
        if(tempcat != '"'){
            addresscat[0] = tempcat ; 
            counter3 = 1;
        }

    for (counter3 ; counter3 < 100 ; counter3++){
        scanf("%c" , &tempcat );
        if(tempcat == '"'){
            addresscat[counter3] = '\0' ;
            counter3 += 150 ;
        }
        if(tempcat != '\n' ){
            addresscat[counter3] = tempcat ;
            addresscat[counter3+1]='\0';
        }
        else{
            counter3 += 150 ;
        }
    }
    printf("\n");
    FILE *cat = fopen(addresscat , "r");
    if(cat == NULL){
        printf("the file you intered doesn't exist bro !! \n");
        return 0;
    }   
        printf("--------------------------------------------------------------------------------------\n");
        while(fgets(cats , 1000000 , cat)){
            printf("%s" , cats);
        }
        fclose(cat);
        printf("\n--------------------------------------------------------------------------------------");
    
}

int runcommand(int cmdnum){
    if(cmdnum == 0){
        print_commands();
    }
    else if(cmdnum == 1){
        maf();
    }
    else if(cmdnum == 2){
        insert();
    }
    else if(cmdnum == 3){
        cat();
    }
    else if(cmdnum == 4){
        rmv();
    }
}

void shift(char zt[] , long long a , long long z){
    for(z ; z < a ; z++){
        zt[z] = zt[z+1];
    }
    zt[a] = '\0';
}

void pardazesh(char mt[] , long long h ){
    if(mt[h] == '"' && mt[h-1] == '/'){
        mt[h-1] = '"';
        mt[h] = '\0';
    }
    if( mt[0] == '"'){
        shift(mt , h , 0);
        mt[h-1] = '\0' ; 
    }
    if( mt[0] == '/' && mt[1] == '"'){
        shift(mt , h , 0);
    }
    


     for ( long long mat = 0 ; mat <= h ; mat++ ){
        if ( mt[mat] == 92 && mt[mat+1] == 92){
                shift(mt , h , mat);
                mat += 1 ;
                continue;
            }
          if (mt[mat] == 92 && mt[mat+1] == 'n' ){
            mt[mat] = '\n';
            shift(mt , h , mat+1);
            continue;
          }
          
     }
}

long long sakhtmatn(char txt[] , char nim[] , char nim2[] , int a , int b){
     int khatk = 1 ;
     int chark = 0 ;
     long long pp = 0 ;
     while(khatk < a && txt[pp] != '\0'){
        nim[pp] = txt[pp];
        nim[pp+1] = '\0';
        if(txt[pp] == '\n'){
            khatk++;
        }
        pp++;
     }
     if(txt[pp] == '\0'){
        for(int x = 0 ; x < a-khatk ; x++){
            nim[pp+x] = '\n';
            nim[pp+x+1] = '\0';
        }
        for(int y = 0 ; y < b ; y++){
            nim[pp+a-khatk+y] = ' ';
            nim[pp+a-khatk+y+1] = '\0';
        }
     }
     if(khatk == a){
        for(int zz = 0 ; zz < b ; zz++){
            if(txt[pp+zz] != '\n' && txt[pp+zz] != '\0'){
                nim[pp+zz] = txt[pp+zz];
                nim[pp+zz+1] = '\0' ;
            }
            else if(txt[pp+zz] == '\0' || txt[pp+zz] == '\n'){
                for(int aaa = 0 ; aaa < (b-zz-2) ; aaa++){
                    txt[pp+zz+aaa] = ' ';
                    txt[pp+zz+aaa+1] = '\0';
                }
            }
        }
     }
     for(long long gg = pp+b ; txt[gg] != '\0' ; gg++){
        nim2[gg-pp-b] = txt[gg] ;
        nim2[gg-pp-b+1] = '\0';
     }
     return pp ;
}

int insert(){
    long long tedadhorof , jaygah , shoro;
    int posline = 0 , poschar = 0 ;
    char kha[10];
    char po[10];
    int khat , kar , khatco = 1 , karco = 0;
    int spaceflag = 1;
    char adressin[100];
    int counter5 = 0;
    long counter6 = 0 ;
    char tempin ;
    char matn[1000000] , matnfnl[1000000];
    char araa[6];
    char pos[5];
    scanf("%s" , &araa);
    for(int z=0 ; z < 6 ; z++){
        if(araa[z] != filer[z]){
            printf("you should use <<--file>> befor your address dude\n");
            return 0;
        }
    }
    scanf(" ");
    scanf("%c" , &tempin);
        if(tempin != '"'){
            adressin[0] = tempin ; 
            counter5 = 1;
            spaceflag = 0 ;
        }

    for (counter5 ; counter5 < 100 ; counter5++){
        scanf("%c" , &tempin );
        if(spaceflag == 0 && tempin == ' '){
            adressin[counter5] = '\0' ;
            counter5 +=150 ;
        }
        else {
        if(tempin == '"'){
            adressin[counter5] = '\0' ;
            counter5 += 150 ;
        }
        if(tempin != '\n' ){
            adressin[counter5] = tempin ;
            adressin[counter5+1]='\0';
        }
        else{
            counter5 += 150 ;
        }
    }}
    if(spaceflag == 1)
    scanf(" ");
    scanf("%s" , &str);
    for(int z=0 ; z < 5 ; z++){
        if(str[z] != str[z]){
            printf("you should use <<--str>> befor your string dude\n");
            return 0;
        }
    }
    scanf(" ");

    scanf("%c" , &matn[counter6]);
    while (matn[counter6] != '\n'){
        tedadhorof = counter6 ;
        counter6++ ;
        scanf("%c" , &matn[counter6]);
    }
    matn[counter6] = '\0' ;
    //printf("%lld\n" , tedadhorof);
    for(long long c = tedadhorof ; c >= 0 ; c--){
        if(matn[c] == ':'){
            jaygah = c ;
        }
    }
    for(long long q = jaygah ; q >= 0 ; q--){
        if(matn[q] == 's'){
            shoro = q ;
            q -= 1000000;
        }
    }
    for(long long q = shoro+2 ; q < jaygah ; q++){
        kha[q-shoro-2] = matn[q];
        kha[q-shoro-1] = '\0'; 
    }
    for(long long q = jaygah+1 ; q <= tedadhorof  ; q++){
        po[q - jaygah -1] = matn[q];
        po[q - jaygah] = '\0'; 
    }
    khat = atoi(kha);
    kar = atoi(po);
    FILE *abc = fopen(adressin , "r");
    if(abc == NULL){
        printf("what the hell the address you intered doesn't exist , astaghforellah bro :(\n");
        fclose(abc);
        return 0 ;
    }
    fclose(abc);
    char cc ;
    pardazesh(matn , shoro-6 );
    //printf("%s\n" , matn);
    FILE    *textfile;
    char    *text;
    long  long  numbytes;
    
    textfile = fopen(adressin, "r");
    if(textfile == NULL)
        return 1;
    
    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);	

    text = (char*)calloc(numbytes, sizeof(char));	
    if(text == NULL)
        return 1;

    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);

    //printf("%s\n" ,text);
    char nime1[1000] , nime2[1000] ;
    sakhtmatn(text , nime1 , nime2 , khat , kar);
    //printf("%s\n%s" , nime1 , nime2);
    FILE *fptr = fopen(adressin , "w");
    fprintf(fptr , "%s%s%s" , nime1 , matn , nime2);
    fclose(fptr);


}

int remover(char* tx , int arr , int brr ){
    int khatk2 = 1 ;
     int chark2 = 0 ;
     long long pp2 = 0 ;
     while(khatk2 < arr && tx[pp2] != '\0'){
        if(tx[pp2] == '\n'){
            khatk2++;
        }
        pp2++;
     }
     if(tx[pp2] == '\0'){
        return pp2-1;
     }
     if(khatk2 == arr){
        for(int zz = 0 ; zz < brr ; zz++){
            if(tx[pp2+zz] != '\n' && tx[pp2+zz] != '\0'){
                if(zz == brr-1){
                    return pp2+zz-1;
                }
            }
            else if(tx[pp2+zz] == '\0' || tx[pp2+zz] == '\n'){
                  return pp2+zz-1;
                }
            }
        }
     }

int rmv(){
    //removetstr –file /root/file1.txt –pos 2:1 -size 3 -b
    char addressrm[100];
    char ar[6] , str2[5];
    char poss[5];
    char te;
    int counter12 , spaceflag2 , poskh , posek , size , dire; 
    scanf("%s" , &ar);
    for(int v = 0 ; v < 6 ; v++){
        if(ar[v] != filer[v]){
            printf("you should use <<--file>> befor your address dude\n");
            return 0;
        }
    }
    scanf(" ");
    scanf("%c" , &te);
        if(te != '"'){
            addressrm[0] = te ; 
            counter12 = 1;
            spaceflag2 = 0 ;
        }

    for (counter12 ; counter12 < 100 ; counter12++){
        scanf("%c" , &te );
        if(spaceflag2 == 0 && te == ' '){
            addressrm[counter12] = '\0' ;
            counter12 +=150 ;
        }
        else {
        if(te == '"'){
            addressrm[counter12] = '\0' ;
            counter12 += 150 ;
        }
        if(te != '\n' ){
            addressrm[counter12] = te ;
            addressrm[counter12+1]='\0';
        }
        else{
            counter12 += 150 ;
        }
    }}
    if(spaceflag2 == 1)
    scanf(" ");
    scanf("%s" , &str2);
    for(int z=0 ; z < 5 ; z++){
        if(str2[z] != poser[z]){
            printf("you should use <<--pos>> befor your string dude\n");
            return 0;
        }
    }
    scanf(" ");
    if(scanf("%d:%d" , &poskh , &posek) == 0)
    printf("are you god damn serious ??? where is your position ?? :(\n");
    scanf(" ");
    posek++;
    scanf("%s" , &str2);
    if(strcmp(str2 , sizer) != 0){
        printf("you should use <<--size>> befor your size !!! \n");
    }
    scanf(" ");
    scanf("%d" , &size);
    scanf(" -%c" , &te);
    if(te == 'f'){
        dire = 1;
    }
    else if(te == 'b'){
        dire = -1;
    }
    else{
        printf("direction isn't valid , it most be either f or b the abrvations of backward and forward ;)\n");
    }

    FILE *abd = fopen(addressrm , "r");
    if(abd == NULL){
        printf("what the hell the address you intered doesn't exist , astaghforellah bro :(\n");
        fclose(abd);
        return 0 ;
    }
    fclose(abd);
    FILE    *textfile2;
    char    *text2;
    long  long  numbytes2;
    
    textfile2 = fopen(addressrm, "r");
    if(textfile2 == NULL)
        return 1;
    
    fseek(textfile2, 0L, SEEK_END);
    numbytes2 = ftell(textfile2);
    fseek(textfile2, 0L, SEEK_SET);	

    text2 = (char*)calloc(numbytes2, sizeof(char));	
    if(text2 == NULL)
        return 1;

    fread(text2, sizeof(char), numbytes2, textfile2);
    fclose(textfile2);
    int noghte = remover(text2 , poskh , posek );
    if(dire == -1){
        for (int ss = 0 ; ss < size ; ss++ ){
            if(text2[noghte-ss] != '\0')
             shift(text2 , strlen(text2)-ss , noghte-ss );
             else{
            ss += size+2;
        }
        }
    }
    else if(dire == 1){
        for (int ss = 0 ; ss < size ; ss++ ){
            if(text2[noghte-ss+size] != '\0')
             shift(text2 , strlen(text2)-ss , noghte-ss+size );
             else{
            ss += size+2;
        }
        }
    }
    FILE *fptr3 = fopen(addressrm , "w");
    fprintf(fptr3 , "%s" , text2);
    fclose(fptr3);


}

void print_commands(){
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
    printf("pleas note that an empty space is needed end of each command !!! ");
}


void zeromark(int ara[] ,int n){
    for(int qq=0 ; qq < n ; qq++){
        ara[qq]=0;
    }
}

int checkval(char a , char b , char c , char d){
    for (int i =0 ; i < 16 ; i++){
        if((a==cmd[i][0])&&(b==cmd[i][1])&&(c==cmd[i][2])&&(d==cmd[i][3])){
            runcommand(i);
            return 0;
        }
    }
    printf("command isn't valid , try again or see command palette with <<prc >>\n");

}


int get_command() {
    char x , y , z , u;
    scanf("%c%c%c%c", &x , &y , &z , &u );
    checkval(x , y , z , u);
    
}

int main (){
printf("if you are a noobie and dont know the commands you can use <<prc >> command to see them :)\n\n");
get_command(); 
}
