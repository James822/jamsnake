#ifndef SNAKE_GAME_HPP_25629
#define SNAKE_GAME_HPP_25629

#include "block.hpp"
#include "fruit.hpp"
#include "snake.hpp"

#include <deque>

/*
 * Class representing the *model* for snake.
 * Provides public methods for controllers to "play" the game and public methods 
 * to view the game.
 * The game is made up of "blocks" which are unit-less, it is left to the programmer 
 * to decide what the size of blocks should be when attempting to draw/render the game.
 * 
 * Initialize with dimensions of the game, the coordinate system for x and y goes
 * from [0 - width] and [0 - height] respectively
 */
class SnakeGame
{
    private:
        int m_width; 
        int m_height;
        Snake m_snake;

        // takes care of deleting old fruit as well
        void spawnFruit();

    public:
        SnakeGame(int width, int height);

        void tick();

        // returns blocks of fruit and snake
        std::deque<Block> getBlocks() const;

        void changeDirection(Direction dir);
};

#endif
