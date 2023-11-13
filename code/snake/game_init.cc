#include "game_init.hh"
#include <cstdlib>
#include <iostream>
#include <algorithm>

/**
 * @brief generate a random number between [1,num]
 *
 * @param num the maximum of the random number
 * @return int the random number generated
 */
int random(int num)
{
    if (num <= 0)
    {
        return 0;
    }
    return (1 + std::rand()) % num + 1;
}

/**
 * @brief the generic method to place some char in the board
 *
 * @param b board
 * @param p the character to be placed
 */
std::pair<int, int> place(board &b, char p)
{
    int xPos_max = b.height - 2;
    int yPos_max = b.width - 2;
    int x = random(xPos_max);
    int y = random(yPos_max);
    if (b.arr[x][y] != ' ')
    {
        return place(b, p);
    }
    else
    {
        b.arr[x][y] = p;
        return std::make_pair(x, y);
    }
}

/**
 * @brief place the food if there is no wall or snake there
 *
 * @param b the game board
 */
void place_food(board &b)
{
    place(b, '$');
}

/**
 * @brief initialize the snake in the board
 *
 * @param b the game board
 */
void place_snake(board &b)
{
    std::pair<int, int> snake_pos = place(b, 'S');
    b.s.position.push_back(snake_pos);
    b.s.direction = RIGHT;
}

/**
 * @brief print the board of the game
 *
 * @param b the game board
 */
void print_board(board &b)
{
    int head_x = b.s.position[0].first;
    int head_y = b.s.position[0].second;
    for (int i = 0; i < b.height; i++)
    {
        for (int j = 0; j < b.width; j++)
        {
            if (i == head_x && j == head_y)
            {
                std::cout << "\033[0;31m" << b.arr[i][j] << "\033[0m"
                          << " ";
            }
            else
            {
                std::cout << b.arr[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Initialize the board
 *
 * @param b the board struct
 * @param width the width of the board
 * @param height the height of the board
 */
void init_board(board &b, int width, int height)
{
    // init the width and height
    b.width = width;
    b.height = height;

    // init the board string and fill it with ` `
    b.arr = new char *[height];
    for (int i = 0; i < height; i++)
    {
        b.arr[i] = new char[width];
        std::fill(b.arr[i], b.arr[i] + (width - 1) + 1, ' ');
    }

    // init the wall around the board
    std::fill(b.arr[0], b.arr[0] + (width - 1) + 1, '#');
    for (int i = 1; i < height - 1; i++)
    {
        b.arr[i][0] = '#';
        b.arr[i][width - 1] = '#';
    }
    std::fill(b.arr[height - 1], b.arr[height - 1] + (width - 1) + 1, '#');

    // calculate the scope of xPos and yPos
    int xPos_max = height - 2;
    int yPos_max = width - 2;

    // init the wall in inside the board
    int wall_num = random(std::min(height - 2, width - 2));
    for (int i = 0; i < wall_num; i++)
    {
        int x = random(xPos_max);
        int y = random(yPos_max);
        b.arr[x][y] = '#';
    }

    // init the food
    place_food(b);

    // init the snake
    place_snake(b);

    b.plain = (width - 2) * (height - 2) - wall_num;
}

/**
 * @brief Initialize the game
 *
 * @param g the game struct
 * @param name the name of the user
 */
void init_game(game &g, char *name)
{
    g.end = false;
    g.name = name;
    g.score = 0;
}