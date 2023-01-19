#include <stdio.h>

void avaz(char m[]){
    m[0] = 'z';
}

int main(){
    char amir[]= "amir";
    avaz(amir);
    printf("%s" , amir);
}