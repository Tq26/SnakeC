#include<stdio.h>
#include<stdlib.h>

#include"header.h"

int main(){

    struct gameData* data = initialize();
    while(advanceGame(data));

    return 1;

}