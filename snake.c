#include <stdio.h>
#include <stdlib.h>

#include "header.h"


//snake is like a linked list.

void moveSnake(struct snake* snake, int isHitAnEgg){

    struct body* ptr = snake->body;

    if(isHitAnEgg){
        //make snake longer
    }   
    else{
        //just move without growing
        

        //some error here.
        while(ptr->nextbody->nextbody != NULL){
            ptr = ptr->nextbody;
        }

        struct body* tail = ptr;
        ptr->nextbody = NULL;

        tail->nextbody = snake->body;

        struct body* newHead = tail;
        
        enum directions dir = snake->snakeDirection;

        switch (dir)
        {
        case forward:
            newHead->field += MAP_SIZE_N;
            break;
        
        case backward:
            newHead->field -= MAP_SIZE_N;
            break;

        case left:
            --newHead->field;
            break;

        case right:
            ++newHead->field;
            break;
        }
    }
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



