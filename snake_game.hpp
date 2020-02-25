#ifndef SNAKE_GAME_HPP_25629
#define SNAKE_GAME_HPP_25629

#include "fruit.hpp"
#include "snake.hpp"

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
        Snake m_snake;
        Fruit m_fruit;
        int m_width; 
        int m_height;

        // takes care of deleting old fruit as well
        void spawnFruit();

    public:
        SnakeGame(int width, int height) : m_width{width}, m_height{height}
        {

        }

        void tick();
};

#endif
