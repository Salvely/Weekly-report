#include <conio.h>
#include "game_init.hh"

void update(game &g, board &b)
{
    // get the current snake head
    std::pair<int, int> head = b.s.position[0];
    int x = head.first;
    int y = head.second;

    // get the snake tail
    std::pair<int, int> tail = b.s.position.back();
    int tail_x = tail.first;
    int tail_y = tail.second;

    // obtain the next position
    switch (b.s.direction)
    {
    case UP:
        x -= 1;
        break;
    case DOWN:
        x += 1;
        break;
    case RIGHT:
        y += 1;
        break;
    case LEFT:
        y -= 1;
        break;
    default:
        break;
    }

    // if the next position is '#' or snake body, exit the game
    if (b.arr[x][y] == '#' || (b.arr[x][y] == 'S' && x != tail_x && y != tail_y))
    {
        g.end = true;
        return;
    }

    // if the next poistion is food
    if (b.arr[x][y] == '$')
    {
        g.score += 1;
        place_food(b);
    }
    else
    {
        b.arr[tail_x][tail_y] = ' ';
        b.s.position.pop_back();
    }
    b.s.position.push_front(std::pair<int, int>(x, y));
    b.arr[x][y] = 'S';

    if (b.s.position.size() == b.plain)
    {
        g.end = true;
        std::cout << "You Success!" << std::endl;
    }
}