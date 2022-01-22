#include <stdio.h>
#include <stdlib.h>

#include "header.h"


//snake is like a linked list.

void moveSnake(struct gameData* data){

    struct body* ptr = data->snake->body;


    if(data->snake->lenght == 1){
        data->snake->body->field = countNewPosition(data->snake->body->field, data->snake->snakeDirection);
    }

}

int countNewPosition(int currentPosition, enum directions dir){
    int res;

    switch (dir)
    {
    case forward:
        res = currentPosition - MAP_SIZE_N;
        break;
    case backward:
        res = currentPosition + MAP_SIZE_N;
        break;
    case left:
        res = --currentPosition;
        break;
    case right:
        res = ++currentPosition;
        break;
    }

    return res;
}

void addNewHead(struct gameData* data){
    struct body* newBody = malloc(sizeof(struct body*));
    
    struct body* ptr = data->snake->body;
    newBody->nextbody = ptr;
    newBody->field = countNewPosition(ptr->field, data->snake->snakeDirection);
    data->snake->body = newBody;

}


void pushBody(struct snake* snake ,int position){

    printf("PushBody started!\n");
    struct body* ptr = snake->body;
    struct body* newBody = malloc(sizeof(struct body*));
    newBody->field = position;
    newBody->nextbody = NULL;
    printf("Allocation finished!\n");

    if(ptr == NULL){
        snake->body = newBody;
        printf("Head added!\n");
    }
    else{
        while(ptr->nextbody != NULL){
            ptr = ptr->nextbody;
        }   

        ptr->nextbody = newBody;
        printf("New tail added!\n");
    }
    ++(snake->lenght);
}



