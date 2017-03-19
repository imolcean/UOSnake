//
// Created by imolcean on 13.03.17.
//

#ifndef UOSNAKE_SNAKE_H
#define UOSNAKE_SNAKE_H


#include <vector>
#include "SCell.h"

class Snake
{
public:
    enum class Direction
    {
        NONE,
        UP,
        LEFT,
        RIGHT,
        DOWN
    };

private:
    Snake::Direction m_direction;
    std::vector<SCell*> m_body;
    int m_toGrow;

    void grow(int bits = 1);

public:
    Snake(SCell* start);
    virtual ~Snake();

    int size() const;

    SCell* getHead() const;

    Snake::Direction getDirection() const;
    void setDirection(Snake::Direction direction);

    void move();

    bool valid() const;
};


#endif //UOSNAKE_SNAKE_H
