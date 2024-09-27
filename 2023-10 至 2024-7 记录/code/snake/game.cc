#include <iostream>
#include "game_init.hh"
#include <conio.h>
#include "game.hh"
#include <unistd.h>

int main(void)
{
    // init the game
    int width;
    int height;
    while (std::cout << "Please enter the width and height of the board:" && std::cin >> width >> height)
    {
        if (width > 3 && height > 3)
        {
            break;
        }
    }
    char *name = new char[20];
    std::cout << "Please enter your name:";
    std::cin >> name;

    game g;
    board b;

    init_game(g, name);
    init_board(b, width, height);

    // the game loop
    while (!g.end)
    {
        sleep(1);
        if (_kbhit())
        {
            _getch();
            int key = _getch();
            INPUT_KEY new_direction = static_cast<INPUT_KEY>(key);
            if (!((b.s.direction == LEFT && new_direction == RIGHT) || 
                (b.s.direction == UP && new_direction == DOWN) ||
                (b.s.direction == RIGHT && new_direction == LEFT) ||
                (b.s.direction == DOWN && new_direction == UP)))
            {
                b.s.direction = new_direction;
            }
            else if(b.s.position.size() == 1) {
                b.s.direction = new_direction;
            }
        }
        update(g, b);
        print_board(b);
        std::cout << "-------------------------" << std::endl;
        sleep(1);
    }

    // end the game
    std::cout << "Game Over!" << std::endl;
    std::cout << "Your Score is: " << g.score << std::endl;

    // clear the game state
    delete[] name;
    for (int i = 0; i < b.height; i++)
    {
        delete[] b.arr[i];
    }
    delete[] b.arr;
}