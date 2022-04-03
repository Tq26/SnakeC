#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

static char snakeMark[] = " # ";
static char eggMark[] = " o ";
static char emptyMark[] = " _ ";

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
    printf("Score: %d\n", data->score);
    
}

void calculateView(struct gameData* data){
    int field = 0;
    int dataViewPosition = 0;

    char** viewData = data->viewData;

    for(int i = 0; i < MAP_SIZE; ++i){



    }



    /*
    printf("%d, %d, %d ", strlen(eggMark), strlen(snakeMark), strlen(emptyMark));
    printf("calculateview\n");
    printf("%d\n",MAP_SIZE * MAP_SIZE);
    //printf("%d\n", MAP_SIZE * VIEW_LENGTH);
    for(int i = 0; i < MAP_SIZE; ++i){
        printf("outer loop started! ");
        dataViewPosition = 0;
        for(int j = 0; j < MAP_SIZE; ++j){
            printf("|%d, %d, %d, %d|'", i, j, dataViewPosition, field);
            if(hasThatKey(field++, data->snake)){
                //printf(" # ");
                printf("snake ");
                strcpy(&viewData[i][dataViewPosition], snakeMark);
                printf("snake2 ");
            }
            else if(field == data->eggPosition){
                printf("egg ");
                //printf(" O ");
                strcpy(&viewData[i][dataViewPosition], eggMark);
                printf("egg2 ");
            }
            else{
                printf("empty ");
                //printf("   ");
                strcpy(&viewData[i][dataViewPosition], emptyMark);
                printf("empty2 ");
            }
            //printf("%d\n", dataViewPosition);
            //printf("LINE_END\n");
            dataViewPosition += VIEW_LENGTH;
        }
        printf("line: %s|\n", viewData[i]);
    }


    */

}



