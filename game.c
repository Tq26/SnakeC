#include <stdlib.h>
#include  <stdio.h>
#include <unistd.h>
#include "header.h"


struct gameData* initialize(){

    printf("Initialize started!\n");
    struct gameData* data = malloc(sizeof(struct gameData));
    struct snake* snake = malloc(sizeof(struct snake));
    printf("Gamedata and snake declared and allocated!\n");
    snake->snakeDirection = backward;
    snake->body = NULL;
    snake->lenght = 0;
    pushBody(snake, 1);
    pushBody(snake, 2);
    pushBody(snake, 3);
    pushBody(snake, 4);
    pushBody(snake, 5);
    pushBody(snake, 5+MAP_SIZE_N);
    pushBody(snake, 5+MAP_SIZE_N * 2);

    printf("Setup snake finished!\n");

    data->snake = snake;

    printf("Initialize finished!\n");
    return data;

}

int advanceGame(struct gameData* data){
    
    printf("Game advanced\n");
    showGame(data);
    sleep(GAME_SPEED);
    moveSnake(data);
    
    return 1;
}