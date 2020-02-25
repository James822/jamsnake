#include "fruit.hpp"

#include <stdlib.h>

Fruit Fruit::genRandFruit(int x, int y)
{
    int new_x = rand() % (x + 1);
    int new_y = rand() % (y + 1);
    
    return Fruit(new_x, new_y);
}