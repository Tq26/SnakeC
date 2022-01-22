
#ifndef SNAKE_GAME_HEADER
#define SNAKE_GAME_HEADER

static int MAP_SIZE_N = 16;


enum directions {forward, backward, left, right};

struct gameData{

    struct snake* snake;

    int eggPosition;


};


struct snake {

    struct body* body;

    int lenght;

    int snakeDirection;
};

struct body {

    int field;
    struct body* nextbody;

};

//Game:
struct gameData* initialize();
int advanceGame(struct gameData* data);

//Snake:
void moveSnake(struct snake* snake, int isHitAnEgg);
void pushBody(struct snake* snake ,int position);


#endif