#ifndef BLOCK_HPP_08722
#define BLOCK_HPP_08722

class Block
{
    private:
        int m_x;
        int m_y;
    
    public:
        Block(int x, int y) : m_x{x}, m_y{y}
        {}

        int getX() const { return m_x; }
        int getY() const { return m_y; }
};

#endif