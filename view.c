#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void clearScreen(){ 
    system("cls");
}

void showGame(struct gameData* data){
    clearScreen();


    
    int field = 0;

    for(int i = 0; i < MAP_SIZE; ++i){
        for(int j = 0; j < MAP_SIZE; ++j){
            if(hasThatKey(field++, data->snake)){
                printf(" # ");
            }
            else if(field == data->eggPosition){
                printf(" O ");
            }
            else{
                printf("   ");
            }
        }
        printf(" |\n");
    }

    printf("________________________________________________\n");
    
    //calculateView(data);
    //printf(data->viewData);
    printf("Score: %d", data->score);
    
}


void calculateView(struct gameData* data){
    char* viewData = data->viewData;
    int field = 0;
    int resultIndex = 0;
    for(int i = 0; i < MAP_SIZE; ++i){
        for(int j = 0; j < MAP_SIZE; ++j){
            if(hasThatKey(field++, data->snake)){
                viewData[resultIndex++] = ' ';
                viewData[resultIndex++] = '#';
                viewData[resultIndex++] = ' ';
            }
            else if(field == data->eggPosition){
                viewData[resultIndex++] = ' ';
                viewData[resultIndex++] = 'o';
                viewData[resultIndex++] = ' ';
            }
            else{
                viewData[resultIndex++] = ' ';
                viewData[resultIndex++] = ' ';
                viewData[resultIndex++] = ' ';
            }


            viewData[resultIndex++] = '|';
            viewData[resultIndex++] = '\n';
        }
    }
}

