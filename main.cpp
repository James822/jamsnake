/*
 * This is the main file for the jamsnake project
 */

#include "block.hpp"
#include "enum_direction.hpp"
#include "snake_game.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <ncurses.h>

void draw(SnakeGame game)
{
    clear();

    for(Block b : game.getBlocks())
    {
        move(b.getX(), b.getY());
        printw("H");
    }

    refresh();
}

int main()
{
    // seeding random
    srand(time(NULL));
    SnakeGame game{50, 50}; // small dimensions for now

    // ncurses setup
    initscr();
    cbreak();
    keypad(stdscr, TRUE);	
    timeout(100);

    draw(game);

    // game loop
    while(true)
    {
        int c = getch();
        switch (c)
        {
        case KEY_UP:
            game.changeDirection(Direction::LEFT);
            break;

        case KEY_RIGHT:
            game.changeDirection(Direction::UP);
            break;

        case KEY_DOWN:
            game.changeDirection(Direction::RIGHT);
            break;

        case KEY_LEFT:
            game.changeDirection(Direction::DOWN);
            break;
        
        default:
            break;
        }
        game.tick();
        draw(game);
    }

    endwin();

    return 0;
}