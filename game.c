#include <conio.h>
#include <stdlib.h>
#include  <stdio.h>
#include <unistd.h>
#include <time.h>

#include "header.h"


struct gameData* initialize(){

    struct gameData* data = malloc(sizeof(struct gameData));
    struct snake* snake = malloc(sizeof(struct snake));
    snake->snakeDirection = backward;
    snake->body = NULL;
    snake->lenght = 0;
    pushBody(snake, 1);
    pushBody(snake, 2);
    pushBody(snake, 3);
    pushBody(snake, 4);
    pushBody(snake, 5);
    pushBody(snake, 5+ MAP_SIZE);
    pushBody(snake, 5+ MAP_SIZE * 2);


    data->snake = snake;
    data->score = 0;
    placeEgg(data);


    data->viewData = malloc(MAP_SIZE);
    int viewLength = MAP_SIZE * VIEW_LENGTH + 1;
    for(int i = 0; i < MAP_SIZE; ++i){
        data->viewData[i] = malloc(viewLength);
    }


    return data;
}

int userInput(struct gameData* data){
    printf("Userinput started.\n");
    int* snakeDirection = &(data->snake->snakeDirection);
   
    int result = 1;
    if(kbhit()){
        char keyInput = getch();
        switch (keyInput)
        {
        case 'a':
            if(*snakeDirection != right){
                *snakeDirection = left;
            }
            break;
        case 'd':
            if(*snakeDirection != left){
                *snakeDirection = right;
            }
            break;
        case 'w':
            if(*snakeDirection != backward){
                *snakeDirection = forward;
            }
            break;
        case 's':
            if(*snakeDirection != forward){
                *snakeDirection = backward;
            }
            break;
        case 'q':
            result = 0;
        }
        
    }
    printf("Userinput ended, result: %d\n", result);
    return result;
}

int advanceGame(struct gameData* data){
    
    printf("advanceGame started.\n");
    int result = userInput(data);
    showGame(data);
    sleep(GAME_SPEED);
    moveSnake(data);
    printf("advanceGame ended. result is %d\n", result);
    return result;
}

void placeEgg(struct gameData* data){
    srand(time(NULL));
    data->eggPosition = rand() % (MAP_SIZE * MAP_SIZE);
}


void delete(struct gameData* data){
    printf("Free:");
    free(data->snake->body->nextbody);
    printf("body, ");
    free(data->snake->body);
    printf("snake, ");
    free(data->snake);
    printf("viewData, ");
    free(data->viewData);
    printf("data\n");
    free(data);
}