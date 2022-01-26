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

    data->viewData = malloc((MAP_SIZE + 1) * (MAP_SIZE + 1));

    return data;
}

void userInput(struct gameData* data){
    int* snakeDirection = &(data->snake->snakeDirection);
   
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
        }
    }
}

int advanceGame(struct gameData* data){
    
    userInput(data);
    showGame(data);
    sleep(GAME_SPEED);
    moveSnake(data);
    
    return 1;
}

void placeEgg(struct gameData* data){
    srand(time(NULL));
    data->eggPosition = rand() % (MAP_SIZE * MAP_SIZE);
}