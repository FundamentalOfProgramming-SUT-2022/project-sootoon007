#include <stdio.h>


int main(){
    char matn[100];
    char add[100];
    scanf("%s" , &add);
    FILE *poin = fopen(add , "r");
    if(poin == NULL){
        printf("no you son of a bitch");
        return 0;
    }
    else{
        fscanf( poin ,"%s" ,&matn);
    }
    printf("%s" , matn);
    fclose(poin);
}