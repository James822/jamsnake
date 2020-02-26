#include "block.hpp"
#include "snake_game.hpp"

#include <deque>

SnakeGame::SnakeGame(int width, int height) : m_width{width}, m_height{height}, 
    m_snake{Block{width / 2, height / 2}}
{
    m_snake.updateFruit(Fruit::genRandFruit(width, height));
}

void SnakeGame::tick()
{
    // making sure the new fruit does not overlapp with a snake block
    if( m_snake.m_fruit_eaten )
    {
        bool overlapped_fruit{true};
        Fruit new_fruit{};
        while(overlapped_fruit)
        {
            new_fruit = Fruit::genRandFruit(m_width, m_height);
            for(Block b : m_snake.getBlocks())
            {
                if(new_fruit.getX() == b.getX() && new_fruit.getY() == b.getY() )
                {
                    continue;
                }
            }
            overlapped_fruit = false;
        }

        m_snake.updateFruit(new_fruit);
        m_snake.m_fruit_eaten = false;
    }
    m_snake.move();
}

std::deque<Block> SnakeGame::getBlocks() const
{
    Fruit f = m_snake.getFruit();
    Block fruit_block{ f.getX(), f.getY() };
    std::deque<Block> total_blocks = m_snake.getBlocks();
    total_blocks.push_back(fruit_block);
    return total_blocks;
}

void SnakeGame::changeDirection(Direction dir)
{
    m_snake.changeDirection(dir);
}