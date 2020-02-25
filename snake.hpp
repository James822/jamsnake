#ifndef SNAKE_HPP_02347
#define SNAKE_HPP_02347

#include "block.hpp"
#include "enum_direction.hpp"

#include <vector>

class Snake
{
    private:
        // first element is the head
        std::vector<Block> m_blocks{};

        // direction it is moving
        Direction m_dir{Direction::RIGHT};

        void addBlock();

    public:
        Snake(Block starting_pos);

        void move();

        void changeDirection(Direction dir) { m_dir = dir; }

        std::vector<Block> getBlocks() const { return m_blocks; }
};

#endif