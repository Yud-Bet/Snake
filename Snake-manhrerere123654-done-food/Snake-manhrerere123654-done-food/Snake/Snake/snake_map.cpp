#include "snake_map.h"
#include <iostream>
#include "my_console.h"

snake_map::snake_map(int width, int height)
{
    w = width;
    h = height;
    s_map = new char* [h];
    for (int i = 0; i < h; i++)
    {
        s_map[i] = new char[w];
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == 0 || j == 0 || j == w - 1 || i == h - 1)
            {
                s_map[i][j] = '#';
            }
            else s_map[i][j] = ' ';
        }
    }
}

bool snake_map::is_map_being_eaten(coord head)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s_map[i][j] != ' ')
            {
                if (head.x == j && head.y == i)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void snake_map::print_map()
{
    gotoxy(0, 0);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s_map[i][j] != ' ')
            {
                gotoxy(j, i);
                std::cout << char(254);
            }
        }
    }
}
