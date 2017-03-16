//
// Created by imolcean on 13.03.17.
//

#ifndef UOSNAKE_SNAKE_H
#define UOSNAKE_SNAKE_H


#include <vector>
#include "SDirection.h"
#include "SCoord.h"

class Snake
{
private:
    SDirection m_direction;
    std::vector<SCoord> m_body;
    int m_toGrow;

public:
    Snake(SCoord start, SDirection direction);
    virtual ~Snake();

    int size() const;

    SCoord getHead();

    SDirection getDirection() const;
    void setDirection(SDirection direction);

    bool into() const;

    void grow(int bits = 1);
    int getGrowth() const;

    void move();
};


#endif //UOSNAKE_SNAKE_H
