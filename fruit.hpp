#ifndef FRUIT_HPP_23976
#define FRUIT_HPP_23976

class Fruit
{
    private:
        int m_x{};
        int m_y{};
    
    public:
        Fruit() = default;
        Fruit(int x, int y) : m_x{x}, m_y{y} 
        {}

        int getX() const { return m_x; }
        int getY() const { return m_y; }
};

#endif 