
#ifndef SNAKE_GAME_HEADER
#define SNAKE_GAME_HEADER

static int MAP_SIZE_N = 16;
static int GAME_SPEED = 1;


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
void placeEgg(struct gameData* data);

//Snake:
void moveSnake(struct gameData* data);
void pushBody(struct snake* snake ,int position);
void addNewHead(struct gameData* data);
void removeTail(struct snake* snake);
int hasThatKey(int key, struct snake* snake);
int countNewPosition(int currentPosition, enum directions dir);

//View:
void clearScreen();
void showGame(struct gameData* data);

#endif