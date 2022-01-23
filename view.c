#include <stdio.h>
#include <stdlib.h>

#include "header.h"


void clearScreen(){ 
    system("cls");
}


void showGame(struct gameData* data){
    clearScreen();

    int field = 0;

    for(int i = 0; i < MAP_SIZE_N; ++i){
        for(int j = 0; j < MAP_SIZE_N; ++j){
            if(hasThatKey(field++, data->snake)){
                printf(" # ");
            }
            else{
                printf("   ");
            }
        }
        printf(" |\n");
    }

    printf("________________________________________________\n");

}

