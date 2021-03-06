#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void moveSnake(struct gameData* data){

    printf("moveSnake started\n");
    int newPos = countNewPosition(data->snake->body->field, data->snake->snakeDirection);
    if(newPos == data->eggPosition){
        addNewHead(data);
        placeEgg(data);
        data->score += 1;
        printf("snake ate egg\n");
        return;
    }
    
    if(data->snake->lenght == 1){
        data->snake->body->field = newPos;
        printf("snake moved_1\n");
        return;
    }

    addNewHead(data);
    removeTail(data->snake);
    printf("snake_moved\n");
}

int countNewPosition(int currentPosition, enum directions dir){
    int res;

    switch (dir)
    {
    case forward:
        res = currentPosition - MAP_SIZE;

        if(res < 0){
            res = MAP_SIZE * (MAP_SIZE - 1) + res % MAP_SIZE;
        }


        break;
    case backward:
        res = currentPosition + MAP_SIZE;

        if(res >= MAP_SIZE * MAP_SIZE){
            res = res % MAP_SIZE;
        }
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

int hasThatKey(int key, struct snake* snake)
{
    struct body* ptr = snake->body;

    while(ptr != NULL){
        if(ptr->field == key){
            return 1;
        }
        ptr = ptr->nextbody;
    }

    return 0;
}

void addNewHead(struct gameData* data){
    struct body* newBody = malloc(sizeof(struct body*));
    
    struct body* ptr = data->snake->body;
    newBody->nextbody = ptr;
    newBody->field = countNewPosition(ptr->field, data->snake->snakeDirection);
    data->snake->body = newBody;
    data->snake->lenght += 1;
}

void removeTail(struct snake* snake){

    if(snake->body == NULL){
        return;
    }

    struct body* tailPtr = snake->body;
    struct body* beforeTailPtr = tailPtr;

    while(tailPtr->nextbody != NULL){
        tailPtr = tailPtr->nextbody;

        if(tailPtr->nextbody != NULL){
            beforeTailPtr = tailPtr;
        }
    }

    beforeTailPtr->nextbody = NULL;

    free(tailPtr);
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