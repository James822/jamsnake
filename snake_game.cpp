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
    m_snake.move();
    const Block &head = m_snake.getBlocks().front();
    const Fruit &fruit = m_snake.getFruit();

    // making sure the new fruit does not overlapp with a snake block
    if( head.getX() == fruit.getX() && head.getY() == fruit.getY() )
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
    }
}

std::deque<Block> SnakeGame::getBlocks() const
{
    Fruit f = m_snake.getFruit();
    Block fruit_block{ f.getX(), f.getY() };
    std::deque<Block> total_blocks = m_snake.getBlocks();
    total_blocks.push_back(fruit_block);
    return total_blocks;
}