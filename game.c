#include <stdlib.h>
#include  <stdio.h>
#include <unistd.h>
#include "header.h"


struct gameData* initialize(){

    printf("Initialize started!\n");
    struct gameData* data = malloc(sizeof(struct gameData));
    struct snake* snake = malloc(sizeof(struct snake));
    printf("Gamedata and snake declared and allocated!\n");
    snake->snakeDirection = forward;
    snake->body = NULL;
    snake->lenght = 0;
    pushBody(snake, 1);
    pushBody(snake, 2);
    pushBody(snake, 3);
 

    printf("Setup snake finished!\n");

    data->snake = snake;

    printf("Initialize finished!\n");
    return data;

}

int advanceGame(struct gameData* data){
    
    printf("Game advanced\n");
    sleep(1);
    moveSnake(data);
    
    return 1;
}