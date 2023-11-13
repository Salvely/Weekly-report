#ifndef GAME_INIT_H
#define GAME_INIT_H

#include <deque>

// define the user input
enum INPUT_KEY
{
    RIGHT = 77,
    LEFT = 75,
    UP = 72,
    DOWN = 80,
};

// define the snake
typedef struct
{
    INPUT_KEY direction;
    std::deque<std::pair<int, int>> position;
} snake;

// define the game
typedef struct
{
    int score;
    bool end;
    char *name;
} game;

// define the board
typedef struct
{
    char **arr;
    int width;
    int height;
    snake s;
    int plain;
} board;

// define the method to be implemented
void init_game(game &g, char *name);
void init_board(board &b, int width, int height);
void print_board(board &b);
std::pair<int, int> place(board &b, char p);
void place_food(board &b);
#endif