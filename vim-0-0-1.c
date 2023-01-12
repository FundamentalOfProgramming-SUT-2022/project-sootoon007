#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <windows.h>

int cmdflag[16];
char filer[6] = {'-' , '-' , 'f' , 'i' , 'l' , 'e'};
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

    }
    else if(cmdnum == 3){
        cat();
    }
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
