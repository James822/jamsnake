/*
 * This is the main file for the jamsnake project
 */

#include "snake_game.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void draw()
{

}

int main()
{
    // seeding random
    srand(time(NULL));
    SnakeGame game{1000, 1000}; // small dimensions for now

    draw();

    // game loop
    while(true)
    {
        game.tick();
        draw();
    }

    return 0;
}