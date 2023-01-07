#include <stdio.h>
int cmdflag[16];

int checkval(char a , char b , char c , char d);
int get_command();
int runcommand(int cmdnum);
void print_commands();

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

int runcommand(int cmdnum){
    if(cmdnum==0){
        print_commands();
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
    printf("command isn't valid , try again or see command palette with <<prc >>");

}


int get_command() {
    char x , y , z , u;
    scanf("%c%c%c%c", &x , &y , &z , &u );
    checkval(x , y , z , u);
    
}

int main (){
printf("if you are a noobie and dont know the commands you can use <<prc >> command to see them :)\n\n");
get_command(); 
FILE *fp;
fp = fopen("root//asghar//asharmargazide.txt", "w");    
}