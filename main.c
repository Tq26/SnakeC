#include<stdio.h>
#include<stdlib.h>

#include"header.h"

int main(){

    struct gameData* data = initialize();
    while(advanceGame(data));
    
    delete(data);
    printf("exit\n");
    return 1;

}