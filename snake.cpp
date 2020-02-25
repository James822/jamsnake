#include "block.hpp"
#include "enum_direction.hpp"
#include "snake.hpp"

void Snake::addBlock()
{

}

Snake::Snake(Block starting_pos)
{
    m_blocks.push_back(starting_pos);
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

    for(int i{0}; i < m_blocks.size() - 1; ++i)
    {
        int new_x{};
        int new_y{};
        Block &curr =  m_blocks.at(i);
        Block &behind =  m_blocks.at(i + 1);
        new_x = curr.getX() - behind.getX();
        new_y = curr.getY() - behind.getY();
        curr = Block{ new_x, new_y };
    }


}
