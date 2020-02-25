#include "block.hpp"
#include "enum_direction.hpp"
#include "snake.hpp"

Snake::Snake(Block starting_pos)
{
    m_blocks.push_back(starting_pos);
}

Snake::Snake(Block starting_pos, int growth_rate)
{
    m_blocks.push_back(starting_pos);
    m_growth_rate = growth_rate;
}

void Snake::move()
{
    int x{};
    int y{};

    if(m_dir == Direction::UP)
    {
        x = 0;
        y = 1;
    }
    else if(m_dir == Direction::RIGHT)
    {
        x = 1;
        y = 0;
    }
    else if(m_dir == Direction::DOWN)
    {
        x = 0;
        y = -1;
    }
    else
    {
        x = -1;
        y = 0;
    }

    // adds one snake head in the correct direction
    const Block &first = m_blocks.front();
    m_blocks.push_front( Block{ first.getX() + x, first.getY() + y } );

    // check to see if snake head is on fruit
    if(m_blocks.front().getX() == m_fruit.getX() && 
       m_blocks.front().getY() == m_fruit.getY())
    {
        m_blocks_to_add += m_growth_rate;
    }
    
    // if no need to extend the snake length, pop off the last block
    if(m_blocks_to_add == 0)
    {
        m_blocks.pop_back();
    }
    else
    {
        m_blocks_to_add -= 1;
    }
    

}
