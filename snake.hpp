#ifndef SNAKE_HPP_02347
#define SNAKE_HPP_02347

#include "block.hpp"
#include "enum_direction.hpp"
#include "fruit.hpp"

#include <deque>

class Snake
{
    private:
        // first element is the head
        std::deque<Block> m_blocks{};

        // direction it is moving
        Direction m_dir{Direction::RIGHT};

        int m_blocks_to_add{0};
        int m_growth_rate{3};
        Fruit m_fruit; // snake needs to know where fruit is

    public:
        Snake(Block starting_pos);

        Snake(Block starting_pos, int growth_rate);

        void move();

        void updateFruit(Fruit fruit) { m_fruit = fruit; }

        void changeDirection(Direction dir) { m_dir = dir; }

        std::deque<Block> getBlocks() const { return m_blocks; }

        Fruit getFruit() const { return m_fruit; }
};

#endif